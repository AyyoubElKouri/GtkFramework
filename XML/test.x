<window id="window" app = "app" title = "title" width = 800 height = 600 decorate = TRUE resizable = TRUE fullscreen = FALSE opacity = 1.0 position = GTK_WIN_POS_CENTER type = GTK_WINDOW_TOPLEVEL>
<header_bar id="header_bar" title = "Ayyoub" subtitle = "test" settings = TRUE>
<menu_button id="menu_button" label = "Home" arrow_type = GTK_ARROW_DOWN>
<menu id="menu" is_primary = TRUE label = "menuee">
<menu_item id="Ayyoub" label = "Ayyoub" type = "normal" >
<menu id="submenu" is_primary = FALSE label = "menuee">
<menu_item id="Ayyoub_1" label = "Ayyoub_1" type = "normal" >
</menu_item add_to_menu(submenu, Ayyoub_1)>
<menu_item id="Ayyoub_2" label = "Ayyoub_2" type = "normal" >
</menu_item add_to_menu(submenu, Ayyoub_2)>
</menu add_to_menu_item(Ayyoub, submenu)>
</menu_item add_to_menu(menu, Ayyoub)>
<menu_item id="Yassine" label = "Yassine" type = "normal" >
</menu_item add_to_menu(menu, Yassine)>
<menu_item id="Maryem" label = "Maryem" type = "normal" >
</menu_item add_to_menu(menu, Maryem)>
</menu add_to_menu_button(menu_button, menu)>
</menu_button add_to_header_bar(header_bar, menu_button, LEFT)>
</header_bar add_header_bar_to_window(window, header_bar)>
<box id="main_box" orientation = GTK_ORIENTATION_VERTICAL align = GTK_ALIGN_CENTER spacing = 0>
<box id="main_box_1" orientation = GTK_ORIENTATION_HORIZONTAL align = GTK_ALIGN_CENTER spacing = 0>
<frame id="main_frame" title = "Gtk Projet" horizontal_placement = 0 vertical_placement = 1>
<grid id="main_grid" rows_spacing = 10 columns_spacing = 10 rows_homogeneous = TRUE columns_homogeneous = FALSE>
<label id="username_label" text = "Password" size = 15 font = "Arial" color = "#000000" background = "#f6f5f4" justify = 2 underline = FALSE weight = 400 style = 0 wrap = FALSE>
</label add_to_grid(main_grid, username_label, 0, 0, 1, 1)>
<entry id="username_entry" indicator_text = "password" visible = TRUE editable = TRUE max_length = 25 alignment = 0.5>
</entry add_to_grid(main_grid, username_entry, 0, 1, 1, 1)>
<label id="password_label" text = "Password" size = 15 font = "Arial" color = "#000000" background = "#f6f5f4" justify = 2 underline = FALSE weight = 400 style = 0 wrap = FALSE>
</label add_to_grid(main_grid, password_label, 1, 0, 1, 1)>
<entry id="password_entry" indicator_text = "password" visible = FALSE editable = TRUE max_length = 25 alignment = 0.5>
</entry add_to_grid(main_grid, password_entry, 1, 1, 1, 1)>
<check_button id="check1" label = "check button 2" active = TRUE use_underline = TRUE >
</check_button add_to_grid(main_grid, check1, 2, 0, 1, 1)>
<check_button id="check2" label = "check button 2" active = FALSE use_underline = TRUE >
</check_button add_to_grid(main_grid, check2, 3, 0, 1, 1)>
<radio_button id="radio1" label = "Yassine" default_state = FALSE>
</radio_button add_to_grid(main_grid, radio1, 4, 1, 1, 1)>
<radio_button id="radio2" label = "Yassine" id_radio_group_member = "radio1" default_state = FALSE>
</radio_button add_to_grid(main_grid, radio2, 5, 1, 2, 1)>
<button id="button_submit" label = "Submit" relief = GTK_RELIEF_NORMAL use_underline = TRUE callback = G_CALLBACK(on_click_submit) >
</button add_to_grid(main_grid, button_submit, 6, 1, 2, 1)>
</grid add_to_frame(main_frame, main_grid, 2, 2, 2, 2)>
</frame add_to_box(main_box_1, main_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0)>
</box add_to_box(main_box, main_box_1, START, FALSE, FALSE, 0, 0, 0, 0, 0)>
</box add_to_container(window, main_box)>
</window show_widget(window)>