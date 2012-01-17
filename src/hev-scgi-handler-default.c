/*
 ============================================================================
 Name        : hev-scgi-handler-default.c
 Author      : Heiher <admin@heiher.info>
 Version     : 0.0.1
 Copyright   : Copyright (C) 2011 everyone.
 Description : 
 ============================================================================
 */

#include "hev-scgi-handler-default.h"

#define HEV_SCGI_HANDLER_DEFAULT_GET_PRIVATE(obj)	(G_TYPE_INSTANCE_GET_PRIVATE((obj), HEV_TYPE_SCGI_HANDLER_DEFAULT, HevSCGIHandlerDefaultPrivate))

typedef struct _HevSCGIHandlerDefaultPrivate HevSCGIHandlerDefaultPrivate;

struct _HevSCGIHandlerDefaultPrivate
{
	gchar c;
};

G_DEFINE_TYPE(HevSCGIHandlerDefault, hev_scgi_handler_default, G_TYPE_OBJECT);

static void hev_scgi_handler_default_dispose(GObject * obj)
{
	HevSCGIHandlerDefault * self = HEV_SCGI_HANDLER_DEFAULT(obj);
	HevSCGIHandlerDefaultPrivate * priv = HEV_SCGI_HANDLER_DEFAULT_GET_PRIVATE(self);

	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);

	G_OBJECT_CLASS(hev_scgi_handler_default_parent_class)->dispose(obj);
}

static void hev_scgi_handler_default_finalize(GObject * obj)
{
	HevSCGIHandlerDefault * self = HEV_SCGI_HANDLER_DEFAULT(obj);
	HevSCGIHandlerDefaultPrivate * priv = HEV_SCGI_HANDLER_DEFAULT_GET_PRIVATE(self);

	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);

	G_OBJECT_CLASS(hev_scgi_handler_default_parent_class)->finalize(obj);
}

static GObject * hev_scgi_handler_default_constructor(GType type, guint n, GObjectConstructParam * param)
{
	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);
	return G_OBJECT_CLASS(hev_scgi_handler_default_parent_class)->constructor(type, n, param);
}

static void hev_scgi_handler_default_constructed(GObject * obj)
{
	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);
}

static void hev_scgi_handler_default_class_init(HevSCGIHandlerDefaultClass * klass)
{
	GObjectClass * obj_class = G_OBJECT_CLASS(klass);

	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);

	obj_class->constructor = hev_scgi_handler_default_constructor;
	obj_class->constructed = hev_scgi_handler_default_constructed;
	obj_class->dispose = hev_scgi_handler_default_dispose;
	obj_class->finalize = hev_scgi_handler_default_finalize;

	g_type_class_add_private(klass, sizeof(HevSCGIHandlerDefaultPrivate));
}

static void hev_scgi_handler_default_init(HevSCGIHandlerDefault * self)
{
	HevSCGIHandlerDefaultPrivate * priv = HEV_SCGI_HANDLER_DEFAULT_GET_PRIVATE(self);
	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);
}

GObject * hev_scgi_handler_default_new(void)
{
	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);
	return g_object_new(HEV_TYPE_SCGI_HANDLER_DEFAULT, NULL);
}

