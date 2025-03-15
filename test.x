<window id="w" app = "app" title = "title" width = 800 height = 600 decorate = TRUE resizable = TRUE fullscreen = FALSE opacity = 1.0 position = GTK_WIN_POS_CENTER type = GTK_WINDOW_TOPLEVEL>
<box id="c" orientation = GTK_ORIENTATION_VERTICAL align = GTK_ALIGN_CENTER spacing = 0>
<radio_button id="cw" label = "ffff" default_state = FALSE>
</radio_button add_to_box(c, cw, START, TRUE, FALSE, 0, 0, 0, 0, 0)>
<radio_button id="cws" label = "ss" id_radio_group_member = "cw" default_state = FALSE>
</radio_button add_to_box(c, cws, START, TRUE, FALSE, 0, 0, 0, 0, 0)>
</box add_to_container(w, c)>
</window show_widget(w)>