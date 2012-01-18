/*
 ============================================================================
 Name        : hev-scgi-task-dispatcher.c
 Author      : Heiher <admin@heiher.info>
 Version     : 0.0.1
 Copyright   : Copyright (C) 2011 everyone.
 Description : 
 ============================================================================
 */

#include "hev-scgi-task-dispatcher.h"

#define HEV_SCGI_TASK_DISPATCHER_GET_PRIVATE(obj)	(G_TYPE_INSTANCE_GET_PRIVATE((obj), HEV_TYPE_SCGI_TASK_DISPATCHER, HevSCGITaskDispatcherPrivate))

typedef struct _HevSCGITaskDispatcherPrivate HevSCGITaskDispatcherPrivate;

struct _HevSCGITaskDispatcherPrivate
{
	gchar c;
};

G_DEFINE_TYPE(HevSCGITaskDispatcher, hev_scgi_task_dispatcher, G_TYPE_OBJECT);

static void hev_scgi_task_dispatcher_dispose(GObject * obj)
{
	HevSCGITaskDispatcher * self = HEV_SCGI_TASK_DISPATCHER(obj);
	HevSCGITaskDispatcherPrivate * priv = HEV_SCGI_TASK_DISPATCHER_GET_PRIVATE(self);

	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);

	G_OBJECT_CLASS(hev_scgi_task_dispatcher_parent_class)->dispose(obj);
}

static void hev_scgi_task_dispatcher_finalize(GObject * obj)
{
	HevSCGITaskDispatcher * self = HEV_SCGI_TASK_DISPATCHER(obj);
	HevSCGITaskDispatcherPrivate * priv = HEV_SCGI_TASK_DISPATCHER_GET_PRIVATE(self);

	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);

	G_OBJECT_CLASS(hev_scgi_task_dispatcher_parent_class)->finalize(obj);
}

static GObject * hev_scgi_task_dispatcher_constructor(GType type, guint n, GObjectConstructParam * param)
{
	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);
	return G_OBJECT_CLASS(hev_scgi_task_dispatcher_parent_class)->constructor(type, n, param);
}

static void hev_scgi_task_dispatcher_constructed(GObject * obj)
{
	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);
}

static void hev_scgi_task_dispatcher_class_init(HevSCGITaskDispatcherClass * klass)
{
	GObjectClass * obj_class = G_OBJECT_CLASS(klass);

	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);

	obj_class->constructor = hev_scgi_task_dispatcher_constructor;
	obj_class->constructed = hev_scgi_task_dispatcher_constructed;
	obj_class->dispose = hev_scgi_task_dispatcher_dispose;
	obj_class->finalize = hev_scgi_task_dispatcher_finalize;

	g_type_class_add_private(klass, sizeof(HevSCGITaskDispatcherPrivate));
}

static void hev_scgi_task_dispatcher_init(HevSCGITaskDispatcher * self)
{
	HevSCGITaskDispatcherPrivate * priv = HEV_SCGI_TASK_DISPATCHER_GET_PRIVATE(self);
	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);
}

GObject * hev_scgi_task_dispatcher_new(void)
{
	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);
	return g_object_new(HEV_TYPE_SCGI_TASK_DISPATCHER, NULL);
}

void hev_scgi_task_dispatcher_push(HevSCGITaskDispatcher *self,
			GObject *scgi_task)
{
	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);
}

