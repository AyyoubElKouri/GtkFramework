
<window id="window" app = "app" title = "title" width = 750 height = 440 decorate = TRUE resizable = TRUE fullscreen = FALSE opacity = 1.0 position = GTK_WIN_POS_CENTER type = GTK_WINDOW_TOPLEVEL >
<header_bar id="header" title = "Ayyoub" subtitle = "Default Subtitle" settings = TRUE>
</header_bar add_header_bar_to_window(window, header)>
<box id="main" orientation = GTK_ORIENTATION_VERTICAL align = GTK_ALIGN_CENTER spacing = 0>
<check_button id="id_1" label = "Choix 1" active = TRUE use_underline = TRUE >
</check_button add_to_box(main, id_1, START, FALSE, FALSE, 0, 0, 0, 0, 0)>
<check_button id="id_2" label = "Choix 2" active = FALSE use_underline = TRUE >
</check_button add_to_box(main, id_2, START, FALSE, FALSE, 0, 0, 0, 0, 0)>
<check_button id="id_3" label = "Choix 3" active = FALSE use_underline = TRUE >
</check_button add_to_box(main, id_3, START, FALSE, FALSE, 0, 0, 0, 0, 0)>
</box add_to_container(window, main)>
</window show_widget(window)>