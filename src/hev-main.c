/* hev-main.c
 * Heiher <admin@heiher.info>
 */

#include <signal.h>

#include "hev-main.h"
#include "hev-scgi-server.h"

static GMainLoop *main_loop = NULL;

static void signal_handler(int signal)
{
	g_main_loop_quit(main_loop);
}

static void signal_register(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGTERM, signal_handler);
}

int main(int argc, char *argv[])
{
	GObject *scgi_server = NULL;

	g_type_init();

	main_loop = g_main_loop_new(NULL, FALSE);
	if(!main_loop)
	  g_error("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);

	scgi_server = hev_scgi_server_new();
	if(!scgi_server)
	  g_error("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);

	hev_scgi_server_start(HEV_SCGI_SERVER(scgi_server));
	signal_register();

	g_main_loop_run(main_loop);

	hev_scgi_server_stop(HEV_SCGI_SERVER(scgi_server));

	g_object_unref(G_OBJECT(scgi_server));
	g_main_loop_unref(main_loop);

	return 0;
}

