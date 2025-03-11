<window id="w" app = "app" title = "title" width = 800 height = 600 decorate = TRUE resizable = TRUE fullscreen = TRUE opacity = 1.0 position = GTK_WIN_POS_CENTER type = GTK_WINDOW_TOPLEVEL>
<header_bar id="h" title = "f" subtitle = "sf" settings = TRUE>
</header_bar add_header_bar_to_window(w, h)>
<frame id="frame" title = "myF" horizontal_placement = 1 vertical_placement = 1>
<fixed id="mq" >
</fixed add_to_frame(frame, mq, 3, 3, 3, 3)>
</frame add_to_container(w, frame)>
</window show_widget(w)>
