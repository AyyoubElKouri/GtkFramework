<window id="win_main" app = "app" title = "title" width = 700 height = 600 decorate = TRUE resizable = TRUE fullscreen = FALSE opacity = 1.0 position = GTK_WIN_POS_CENTER type = GTK_WINDOW_TOPLEVEL>
<header_bar id="herder_main" title = "yassine" subtitle = "Default Subtitle" settings = TRUE>
</header_bar add_header_bar_to_window(win_main, herder_main)>
<scrolled_window id="scrolled_win1" horizontal = TRUE vertical = TRUE>
<fixed id="fixed_main" >
<menu_button id="menu_button" label = "hello" arrow_type = GTK_ARROW_DOWN>
<menu id="menu" is_primary = TRUE >
<menu_item id="menu_item_1" label = "yassine" type = "normal" >
</menu_item add_to_menu(menu, menu_item_1)>
<menu_item id="menu_item_2" label = "youssef" type = "normal" >
<menu id="menu_sub" is_primary = FALSE >
<menu_item id="menu_item_3" label = "ahmed" type = "normal" >
</menu_item add_to_menu(menu_sub, menu_item_3)>
<menu_item id="menu_item_4" label = "imade" type = "normal" >
</menu_item add_to_menu(menu_sub, menu_item_4)>
</menu add_to_menu_item(menu_item_2, menu_sub)>
</menu_item add_to_menu(menu, menu_item_2)>
</menu add_to_menu_button(menu_button, menu)>
</menu_button add_to_fixed(fixed_main, menu_button, 20, 30)>
<frame id="frame_check_button" title = "votre experience ave" horizontal_placement = 0 vertical_placement = 1>
<grid id="grid_check_button" rows_spacing = 0 columns_spacing = 15 rows_homogeneous = TRUE columns_homogeneous = TRUE>
<check_button id="check_button_1" label = "faible" active = FALSE use_underline = TRUE >
</check_button add_to_grid(grid_check_button, check_button_1, 0, 0, 1, 1)>
<check_button id="check_button_2" label = "fort" active = FALSE use_underline = TRUE >
</check_button add_to_grid(grid_check_button, check_button_2, 0, 1, 1, 1)>
<check_button id="check_button_3" label = "moyenne" active = FALSE use_underline = TRUE >
</check_button add_to_grid(grid_check_button, check_button_3, 0, 2, 1, 1)>
</grid add_to_frame(frame_check_button, grid_check_button, 5, 5, 5, 5)>
</frame add_to_fixed(fixed_main, frame_check_button, 20, 130)>
<frame id="frame_radio_button" title = "gtk" horizontal_placement = 0 vertical_placement = 1>
<grid id="grid_radio_button" rows_spacing = 0 columns_spacing = 0 rows_homogeneous = TRUE columns_homogeneous = TRUE>
<radio_button id="radio_1" label = "gtk bon" default_state = FALSE>
</radio_button add_to_grid(grid_radio_button, radio_1, 0, 0, 1, 1)>
<radio_button id="radio_2" label = "gtk pas bon" id_radio_group_member = "radio_1" default_state = TRUE>
</radio_button add_to_grid(grid_radio_button, radio_2, 1, 0, 1, 1)>
</grid add_to_frame(frame_radio_button, grid_radio_button, 5, 5, 5, 5)>
</frame add_to_fixed(fixed_main, frame_radio_button, 20, 250)>
<button id="ok_button" label = "ok" relief = GTK_RELIEF_NORMAL use_underline = TRUE callback = G_CALLBACK(on_click_submit) >
</button add_to_fixed(fixed_main, ok_button, 650, 550)>
<button id="annuler_button" label = "Annuler" relief = GTK_RELIEF_NORMAL use_underline = TRUE >
</button add_to_fixed(fixed_main, annuler_button, 500, 550)>
</fixed add_to_scrolled_window(scrolled_win1, fixed_main)>
</scrolled_window add_to_container(win_main, scrolled_win1)>
</window show_widget(win_main)>