/*
 ============================================================================
 Name        : hev-scgi-handler.c
 Author      : Heiher <admin@heiher.info>
 Version     : 0.0.1
 Copyright   : Copyright (C) 2011 everyone.
 Description : 
 ============================================================================
 */

#include "hev-scgi-handler.h"

G_DEFINE_INTERFACE(HevSCGIHandler, hev_scgi_handler, G_TYPE_OBJECT);

static void hev_scgi_handler_default_init(HevSCGIHandlerInterface * klass)
{
}

