
<window id="window" app = "app" title = "title" width = 750 height = 440 decorate = TRUE resizable = TRUE fullscreen = FALSE opacity = 1.0 position = GTK_WIN_POS_CENTER type = GTK_WINDOW_TOPLEVEL color = "#e6cce0" >
<header_bar id="header_bar" title = "Ayyoub" subtitle = "El kouri" settings = TRUE>
</header_bar add_header_bar_to_window(window, header_bar)>
<box id="main_box" orientation = GTK_ORIENTATION_HORIZONTAL align = GTK_ALIGN_CENTER spacing = 0>
<box id="main_box_2" orientation = GTK_ORIENTATION_VERTICAL align = GTK_ALIGN_CENTER spacing = 0>
<image id="image" path = "../assets/w160/ar.png">
</image add_to_box(main_box_2, image, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
</box add_to_box(main_box, main_box_2, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
</box add_to_container(window, main_box)>
</window show_widget(window)>