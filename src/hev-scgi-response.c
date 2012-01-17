/*
 ============================================================================
 Name        : hev-scgi-response.c
 Author      : Heiher <admin@heiher.info>
 Version     : 0.0.1
 Copyright   : Copyright (C) 2011 everyone.
 Description : 
 ============================================================================
 */

#include "hev-scgi-response.h"

#define HEV_SCGI_RESPONSE_GET_PRIVATE(obj)	(G_TYPE_INSTANCE_GET_PRIVATE((obj), HEV_TYPE_SCGI_RESPONSE, HevSCGIResponsePrivate))

typedef struct _HevSCGIResponsePrivate HevSCGIResponsePrivate;

struct _HevSCGIResponsePrivate
{
	gchar c;
};

G_DEFINE_TYPE(HevSCGIResponse, hev_scgi_response, G_TYPE_OBJECT);

static void hev_scgi_response_dispose(GObject * obj)
{
	HevSCGIResponse * self = HEV_SCGI_RESPONSE(obj);
	HevSCGIResponsePrivate * priv = HEV_SCGI_RESPONSE_GET_PRIVATE(self);

	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);

	G_OBJECT_CLASS(hev_scgi_response_parent_class)->dispose(obj);
}

static void hev_scgi_response_finalize(GObject * obj)
{
	HevSCGIResponse * self = HEV_SCGI_RESPONSE(obj);
	HevSCGIResponsePrivate * priv = HEV_SCGI_RESPONSE_GET_PRIVATE(self);

	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);

	G_OBJECT_CLASS(hev_scgi_response_parent_class)->finalize(obj);
}

static GObject * hev_scgi_response_constructor(GType type, guint n, GObjectConstructParam * param)
{
	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);
	return G_OBJECT_CLASS(hev_scgi_response_parent_class)->constructor(type, n, param);
}

static void hev_scgi_response_constructed(GObject * obj)
{
	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);
}

static void hev_scgi_response_class_init(HevSCGIResponseClass * klass)
{
	GObjectClass * obj_class = G_OBJECT_CLASS(klass);

	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);

	obj_class->constructor = hev_scgi_response_constructor;
	obj_class->constructed = hev_scgi_response_constructed;
	obj_class->dispose = hev_scgi_response_dispose;
	obj_class->finalize = hev_scgi_response_finalize;

	g_type_class_add_private(klass, sizeof(HevSCGIResponsePrivate));
}

static void hev_scgi_response_init(HevSCGIResponse * self)
{
	HevSCGIResponsePrivate * priv = HEV_SCGI_RESPONSE_GET_PRIVATE(self);
	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);
}

GObject * hev_scgi_response_new(void)
{
	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);
	return g_object_new(HEV_TYPE_SCGI_RESPONSE, NULL);
}

