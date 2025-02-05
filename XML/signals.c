static void close_new(GtkWidget *widget, gpointer data)
{
    g_application_quit(G_APPLICATION(data));
    // printf("hello\n");
}

