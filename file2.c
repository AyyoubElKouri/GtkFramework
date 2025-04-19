GtkWidget *c = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_CENTER, 0);

	GtkWidget *cw = create_radio_button("ffff", NULL, NULL, FALSE);

	add_to_box(c, cw, START, TRUE, FALSE, 0, 0, 0, 0, 0);

	GtkWidget *cws = create_radio_button("ss", NULL, cw, FALSE);

	add_to_box(c, cws, START, TRUE, FALSE, 0, 0, 0, 0, 0);

add_to_box(test_box, c, START, FALSE, FALSE, 0, 0, 0, 0, 0);