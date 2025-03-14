<window id="wind" app = "app" title = "title" width = 800 height = 600 decorate = TRUE resizable = TRUE fullscreen = FALSE opacity = 1.0 position = GTK_WIN_POS_CENTER type = GTK_WINDOW_TOPLEVEL>
<box id="sfdsg" orientation = GTK_ORIENTATION_VERTICAL align = GTK_ALIGN_CENTER spacing = 0>
<grid id="gsdfg" rows_spacing = 0 columns_spacing = 0 rows_homogeneous = TRUE columns_homogeneous = TRUE>
<level_bar id="gfdgf" inverted = FALSE min_value = 0 max_value = 10 default_value = 2 mode = 1 >
</level_bar add_to_grid(gsdfg, gfdgf, 0, 0, 1, 1)>
</grid add_to_box(sfdsg, gsdfg, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
</box add_to_container(wind, sfdsg)>
</window show_widget(wind)>