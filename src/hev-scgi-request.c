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

#define HEV_SCGI_REQUEST_GET_PRIVATE(obj)	(G_TYPE_INSTANCE_GET_PRIVATE((obj), HEV_TYPE_SCGI_REQUEST, HevSCGIRequestPrivate))

typedef struct _HevSCGIRequestPrivate HevSCGIRequestPrivate;

struct _HevSCGIRequestPrivate
{
	gchar c;
};

G_DEFINE_TYPE(HevSCGIRequest, hev_scgi_request, G_TYPE_OBJECT);

static void hev_scgi_request_dispose(GObject * obj)
{
	HevSCGIRequest * self = HEV_SCGI_REQUEST(obj);
	HevSCGIRequestPrivate * priv = HEV_SCGI_REQUEST_GET_PRIVATE(self);

	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);

	G_OBJECT_CLASS(hev_scgi_request_parent_class)->dispose(obj);
}

static void hev_scgi_request_finalize(GObject * obj)
{
	HevSCGIRequest * self = HEV_SCGI_REQUEST(obj);
	HevSCGIRequestPrivate * priv = HEV_SCGI_REQUEST_GET_PRIVATE(self);

	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);

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
}

GObject * hev_scgi_request_new(void)
{
	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);
	return g_object_new(HEV_TYPE_SCGI_REQUEST, NULL);
}

