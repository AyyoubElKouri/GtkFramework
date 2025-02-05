<!-- Start Window -->
<window id = "window" app = "app" width = "800" height = "650">
    
    <!-- Start Header Bar -->
    <header_bar id = "header_bar" title = "Widgets display" subtitle = "This project is made to display our widgets" icon_path = "../assets/Header_bar_icon/apple.png" settings = FALSE>
        
        <!-- Start close button -->
        <button id = "close_button" path_to_image = "../assets/Application_icon/close-icon.png" callback = G_CALLBACK(close_new) data = "app">
        
        </button add_to_header_bar(header_bar, close_button, RIGHT)>
        <!-- End close button -->
        
        <!-- Start more menu button -->
        <menu_button id = "more_menu_button" path_to_image = "../assets/Application_icon/burger-bar.png">

            <!-- Start more menu -->
            <menu id = "more_menu" is_primary = TRUE>

                <!-- Start menu ho made this item -->
                <menu_item id = "ho_made_this" label = "Ho Made This" type = "normal">

                </menu_item add_to_menu(more_menu, ho_made_this)>
                <!-- End menu ho made this item -->

                <!-- Start menu Who is our supervisor item -->
                <menu_item id = "who_is_our_supervisor" label = "Who is our supervisor" type = "normal">

                </menu_item add_to_menu(more_menu, who_is_our_supervisor)>
                <!-- End menu Who is our supervisor item -->
                
                <!-- Start menu contact me item -->
                <menu_item id = "contact_me" label = "Contact me" type = "normal">
                    
                </menu_item add_to_menu(more_menu, contact_me)>
                <!-- End menu contact me item -->
                
            </menu add_to_menu_button(more_menu_button, more_menu)>
            <!-- End more menu -->

        </menu_button add_to_header_bar(header_bar, more_menu_button, RIGHT)>
        <!-- End more menu button -->


    </header_bar add_header_bar_to_window(window, header_bar)>
    <!-- End Header Bar -->

    <!-- Start Main box -->
    <box id = "main_box" orientation = GTK_ORIENTATION_VERTICAL spacing = "5">

        <!-- Start grid box -->
        <box id = "grid_box" orientation = GTK_ORIENTATION_HORIZONTAL spacing = "5">

            <!-- Start grid -->
            <grid id = "grid" rows_spacing = "10" rows_homogeneous = TRUE>

                <!-- Start username entry -->
                <entry id = "username" indicator_text = "Username" visible = TRUE editable = TRUE>

                </entry add_to_grid(grid, username, 0, 0, 1, 1)>
                <!-- End username entry -->

                <!-- Start password entry -->
                <entry id = "password" indicator_text = "Password" visible = FALSE editable = TRUE>

                </entry add_to_grid(grid, password, 1, 0, 1, 1)>
                <!-- End password entry -->

                <!-- Start login button -->
                <button id = "login" label = "Login">

                </button add_to_grid(grid, login, 2, 0, 1, 1)>
                <!-- End login button -->

            </grid add_to_box(grid_box, grid, START, FALSE, FALSE, 0, 0, 0, 0, 0)>
            <!-- End grid -->

        </box add_to_box(main_box, grid_box, START, FALSE, FALSE, 0, 0, 0, 0, 0)>
        <!-- End grid box -->

    </box add_to_container(window, main_box)>
    <!-- End Main box -->
    
</window show_widget(window)>
<!-- End Window -->