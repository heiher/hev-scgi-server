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

static void debug_log_handler(const gchar *log_domain,
			GLogLevelFlags log_level,
			const gchar *message,
			gpointer user_data)
{
}

int main(int argc, char *argv[])
{
	GObject *scgi_server = NULL;
	static gboolean debug = FALSE;
	static GOptionEntry option_entries[] =
	{
		{ "debug", 'd', 0, G_OPTION_ARG_NONE,  &debug, "Debug mode", NULL},
		{ NULL }
	};
	GOptionContext *option_context = NULL;
	GError *error = NULL;

	g_type_init();

	if(!g_module_supported())
	  g_error("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);

	option_context = g_option_context_new("");
	g_option_context_add_main_entries(option_context,
				option_entries, NULL);
	if(!g_option_context_parse(option_context, &argc, &argv, &error))
	{
		g_error("%s:%d[%s]=>(%s)", __FILE__, __LINE__, __FUNCTION__,
					error->message);
		g_error_free(error);
	}

	if(!debug)
	  g_log_set_handler(NULL, G_LOG_LEVEL_DEBUG,
				  debug_log_handler, NULL);

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

