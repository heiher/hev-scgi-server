/*
 ============================================================================
 Name        : hev-scgi-request.c
 Author      : Heiher <admin@heiher.info>
 Version     : 0.0.1
 Copyright   : Copyright (C) 2011 everyone.
 Description : 
 ============================================================================
 */

#include "hev-scgi-request.h"

enum
{
	HEADER_STATUS_UNREAD,
	HEADER_STATUS_READING,
	HEADER_STATUS_READED
};

#define HEV_SCGI_REQUEST_GET_PRIVATE(obj)	(G_TYPE_INSTANCE_GET_PRIVATE((obj), HEV_TYPE_SCGI_REQUEST, HevSCGIRequestPrivate))

typedef struct _HevSCGIRequestPrivate HevSCGIRequestPrivate;

struct _HevSCGIRequestPrivate
{
	GInputStream *input_stream;
	guint header_status;
	gchar *header_buffer;
	gsize header_buffer_size;
};

G_DEFINE_TYPE(HevSCGIRequest, hev_scgi_request, G_TYPE_OBJECT);

static void hev_scgi_request_dispose(GObject * obj)
{
	HevSCGIRequest * self = HEV_SCGI_REQUEST(obj);
	HevSCGIRequestPrivate * priv = HEV_SCGI_REQUEST_GET_PRIVATE(self);

	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);

	if(priv->input_stream)
	{
		g_object_unref(priv->input_stream);
		priv->input_stream = NULL;
	}

	G_OBJECT_CLASS(hev_scgi_request_parent_class)->dispose(obj);
}

static void hev_scgi_request_finalize(GObject * obj)
{
	HevSCGIRequest * self = HEV_SCGI_REQUEST(obj);
	HevSCGIRequestPrivate * priv = HEV_SCGI_REQUEST_GET_PRIVATE(self);

	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);

	if(priv->header_buffer)
	{
		g_slice_free1(priv->header_buffer_size,
					priv->header_buffer);
		priv->header_buffer = NULL;
		priv->header_buffer_size = 0;
	}

	G_OBJECT_CLASS(hev_scgi_request_parent_class)->finalize(obj);
}

static GObject * hev_scgi_request_constructor(GType type, guint n, GObjectConstructParam * param)
{
	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);
	return G_OBJECT_CLASS(hev_scgi_request_parent_class)->constructor(type, n, param);
}

static void hev_scgi_request_constructed(GObject * obj)
{
	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);
}

static void hev_scgi_request_class_init(HevSCGIRequestClass * klass)
{
	GObjectClass * obj_class = G_OBJECT_CLASS(klass);

	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);

	obj_class->constructor = hev_scgi_request_constructor;
	obj_class->constructed = hev_scgi_request_constructed;
	obj_class->dispose = hev_scgi_request_dispose;
	obj_class->finalize = hev_scgi_request_finalize;

	g_type_class_add_private(klass, sizeof(HevSCGIRequestPrivate));
}

static void hev_scgi_request_init(HevSCGIRequest * self)
{
	HevSCGIRequestPrivate * priv = HEV_SCGI_REQUEST_GET_PRIVATE(self);

	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);

	priv->input_stream = NULL;
	priv->header_status = HEADER_STATUS_UNREAD;

	priv->header_buffer = NULL;
	priv->header_buffer_size = 0;
}

GObject * hev_scgi_request_new(void)
{
	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);
	return g_object_new(HEV_TYPE_SCGI_REQUEST, NULL);
}

void hev_scgi_request_set_input_stream(HevSCGIRequest *self,
			GInputStream *input_stream)
{
	HevSCGIRequestPrivate *priv = NULL;

	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);
	
	g_return_if_fail(HEV_IS_SCGI_REQUEST(self));
	g_return_if_fail(G_IS_INPUT_STREAM(input_stream));
	priv = HEV_SCGI_REQUEST_GET_PRIVATE(self);

	if(priv->input_stream)
	  g_object_unref(priv->input_stream);

	priv->input_stream = g_object_ref(input_stream);
}

void hev_scgi_request_read_header(HevSCGIRequest *self,
			GFunc callback, gpointer user_data)
{
	HevSCGIRequestPrivate *priv = NULL;

	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);
	
	g_return_if_fail(HEV_IS_SCGI_REQUEST(self));
	g_return_if_fail(callback);
	priv = HEV_SCGI_REQUEST_GET_PRIVATE(self);
	g_return_if_fail(NULL!=priv->input_stream);
	g_return_if_fail(HEADER_STATUS_UNREAD==priv->header_status);
}

