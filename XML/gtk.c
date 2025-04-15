

	GtkWidget *qsdf = create_header_bar("header", "Default Subtitle", NULL, TRUE);

	add_to_box(test_box, qsdf, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	GtkWidget *dernier = create_button(GTK_RELIEF_NORMAL, "yassine", TRUE, NULL, NULL, NULL);

    // Autre traitement ne contient j'amais une déclaration GtkWidget *blabla

    // Fin 
    add_to_box(test_box, dernier, START, FALSE, FALSE, 0, 0, 0, 0, 0);
