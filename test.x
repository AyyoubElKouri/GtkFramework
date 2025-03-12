<window id="w" app = "app" title = "title" width = 800 height = 600 decorate = TRUE resizable = TRUE fullscreen = FALSE opacity = 1.0 position = GTK_WIN_POS_CENTER type = GTK_WINDOW_TOPLEVEL>
<paned id="gdsfg" orientation = 1 default_position = 300 show_handle = TRUE>
<header_bar id="lkes" title = "sgsdg" subtitle = "hs" settings = TRUE>
</header_bar add_to_paned(gdsfg, lkes, 0)>
<header_bar id="lkesg" title = "sgsdg" subtitle = "hs" settings = TRUE>
</header_bar add_to_paned(gdsfg, lkesg, 1)>
</paned add_to_container(w, gdsfg)>
</window show_widget(w)>