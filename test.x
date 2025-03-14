<window id="w" app = "app" title = "title" width = 800 height = 600 decorate = TRUE resizable = TRUE fullscreen = TRUE opacity = 1.0 position = GTK_WIN_POS_CENTER type = GTK_WINDOW_TOPLEVEL>
<box id="fsd" orientation = GTK_ORIENTATION_VERTICAL align = GTK_ALIGN_CENTER spacing = 0>
<button id="fs" label = "g" relief = GTK_RELIEF_NORMAL use_underline = TRUE >
</button add_to_box(fsd, fs, START, FALSE, FALSE, 0, 0, 0, 0, 0)>
</box add_to_container(w, fsd)>
</window show_widget(w)>
