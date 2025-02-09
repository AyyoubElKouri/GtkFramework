<!-- Start Window -->
<window id = "window" app = "app" width = 5000 height = 5000>

    <!-- Start Header Bar -->
    <header_bar id = "Header_bar" title = "UIBuilder" subtitle = "Build your UI Application">

    </header_bar add_header_bar_to_window(window, Header_bar)>
    <!-- End Header Bar -->

    <!-- Start the main box -->
    <box id = "main_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>

        <!-- Start App box -->
        <box id = "app_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>

            <!-- Start main paned -->
            <paned id = "main_paned" orientation = GTK_ORIENTATION_HORIZONTAL default_position = 240 show_handle = TRUE>

                <!-- Start the hierarchy widgets box -->
                <box id = "hierarchy_widgets_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>

                    <!-- Start the hierarchy widgets label box -->
                    <box id = "hierarchy_widgets_label_box" orientation = GTK_ORIENTATION_HORIZONTAL align = GTK_ALIGN_START spacing = 0>
    
                        <!-- Start the "Widgets Hierarchy" label -->
                        <label id = "hierarchy_widgets_label" text = "Widgets Hierarchy" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_RIGHT">
    
                        </label add_to_box(hierarchy_widgets_label_box, hierarchy_widgets_label, START, TRUE, FALSE, 0, 0, 0, 0, 7)>
                        <!-- End the "Widgets Hierarchy" label -->
    
                    </box add_to_box(hierarchy_widgets_box, hierarchy_widgets_label_box, START, FALSE, FALSE, 0, 7, 0, 12, 7)>
                    <!-- End the hierarchy widgets label box -->

                    <!-- Start the hierarchy widgets box content -->
                    <box id = "hierarchy_widgets_box_content" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>

                        <!-- Start the test button -->
                        <button id = "test_button" label = "This space is reserved for\n the Widgets Hierarchy">
        
                        </button add_to_box(hierarchy_widgets_box_content, test_button, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                        <!-- End the test button -->

                    </box add_to_box(hierarchy_widgets_box, hierarchy_widgets_box_content, START, TRUE, TRUE, 0, 7, 0, 0, 7)>
                    <!-- End the hierarchy widgets box content -->


                </box add_to_paned(main_paned, hierarchy_widgets_box, FIRST)>
                <!-- End the hierarchy widgets box -->

                <!-- Start the build space paned -->
                <paned id = "build_space_paned" orientation = GTK_ORIENTATION_HORIZONTAL default_position = 710 show_handle = TRUE>

                    <!-- Start the first space box -->
                    <box id = "first_space_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>

                        <!-- Start the contents space paned -->
                        <paned id = "contents_space_paned" orientation = GTK_ORIENTATION_VERTICAL default_position = 500 show_handle = TRUE>

                            <!-- Start the working space box -->
                            <box id = "working_space_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>

                                <!-- Start the working space label box -->
                                <box id = "working_space_label_box" orientation = GTK_ORIENTATION_HORIZONTAL align = GTK_ALIGN_START spacing = 0>
            
                                    <!-- Start the "Working Space" label -->
                                    <label id = "working_space_label" text = "Working Space" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_RIGHT">
            
                                    </label add_to_box(working_space_label_box, working_space_label, START, TRUE, FALSE, 0, 0, 0, 0, 7)>
                                    <!-- End the "Working Space" label -->
        
                                </box add_to_box(working_space_box, working_space_label_box, START, FALSE, FALSE, 0, 0, 0, 12, 7)>
                                <!-- End the working space label box -->
        
                                <!-- Start the working space box content -->
                                <box id = "working_space_box_content" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>
                                    
                                    <!-- Start the working space content frame -->
                                    <frame id = "working_space_frame" label = NULL>

                                        <!-- Start the working space main box -->
                                        <box id = "test_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>

                                            <!-- ------------------------------------------------------------ -->

                                        </box add_to_frame(working_space_frame, test_box, 5, 5, 5, 5)>
                                        <!-- End the working space main box -->

                                    </frame add_to_box(working_space_box_content, working_space_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                    <!-- End the working space content frame -->
        
                                </box add_to_box(working_space_box, working_space_box_content, START, TRUE, TRUE, 0, 7, 7, 0, 0)>
                                <!-- End the working space box content -->

                            </box add_to_paned(contents_space_paned, working_space_box, FIRST)>
                            <!-- End the working space box -->
                             
    
                            <!-- Start the widgets information box -->
                            <box id = "widgets_informations_space" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>

                                <!-- Start the widgets information label box -->
                                <box id = "widgets_informations_label_box" orientation = GTK_ORIENTATION_HORIZONTAL align = GTK_ALIGN_START spacing = 0>
    
                                    <!-- Start the "Widgets Information" label -->
                                    <label id = "widgets_informations_label" text = "Widgets Informations" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_RIGHT">
    
                                    </label add_to_box(widgets_informations_label_box, widgets_informations_label, START, TRUE, FALSE, 0, 0, 0, 0, 7)>
                                    <!-- End the "Widgets Informations" label -->
    
                                </box add_to_box(widgets_informations_space, widgets_informations_label_box, START, FALSE, FALSE, 0, 7, 0, 12, 7)>
                                
                                <!-- Start the widgets information box content -->
                                <box id = "widgets_informations_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>

                                    <!-- Start the test button -->
                                    <button id = "button_test4" label = "This space is reserved for the Widgets Informations">
        
                                    </button add_to_box(widgets_informations_box, button_test4, START, TRUE, TRUE, 0, 7, 0, 0, 0)>
                                    <!-- End the test button -->

                                </box add_to_box(widgets_informations_space, widgets_informations_box, START, TRUE, TRUE, 0, 7, 0, 0, 0)>
                                <!-- End the widgets information box content -->
    
                            </box add_to_paned(contents_space_paned, widgets_informations_space, SECOND)>
                            <!-- End the widgets information box -->

                        </paned add_to_box(first_space_box, contents_space_paned, START, TRUE, TRUE, 0, 7, 0, 7, 7)>
                        <!-- End the contents space paned -->
                    
                    </box add_to_paned(build_space_paned, first_space_box, FIRST)>
                    <!-- End the first space box -->

                    <!-- Start the second space box -->
                    <box id = "second_space_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>

                        <!-- Start the second space label box -->
                        <box id = "second_space_label_box" orientation = GTK_ORIENTATION_HORIZONTAL align = GTK_ALIGN_START spacing = 0>
    
                            <!-- Start the "Widgets Catalog" label -->
                            <label id = "second_space_label" text = "Widgets Catalog" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_RIGHT">
    
                            </label add_to_box(second_space_label_box, second_space_label, START, TRUE, FALSE, 0, 0, 0, 0, 7)>
                            <!-- End the "Widgets Catalog" label -->
    
                        </box add_to_box(second_space_box, second_space_label_box, START, FALSE, FALSE, 0, 7, 0, 12, 7)>
                        <!-- End the second space label box -->

                        <!-- Widgets Catalog content -->
                        <box id = "widgets_catalog_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>

                            <!-- Start switcher Catalog -->
                            <switcher id = "switcher_catalog" spacing = 2 buttons_same_size = TRUE>

                            </switcher add_to_box(widgets_catalog_box, switcher_catalog, START, FALSE, FALSE, 0, 0, 0, 0, 0)>
                            <!-- End switcher Catalog -->

                            <!-- Start stack Catalog -->
                            <stack id = "stack_catalog" switcher = "switcher_catalog" transition_type = GTK_STACK_TRANSITION_TYPE_SLIDE_LEFT_RIGHT transition_duration = 500>

                                
                                <!-- Start scrolled window window -->
                                <scrolled_window id = "scrolled_window_window" horizontal = FALSE vertical = TRUE>

                                    <!-- Start Windows box -->
                                    <box id = "Windows_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 7>

                                        <!-- Start Window Case -->
                                        <box id = "window_case" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 5>

                                            <!-- Start window label -->
                                            <label id = "window_label" text = "Window" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_RIGHT">

                                            </label add_to_box(window_case, window_label, START, FALSE, FALSE, 0, 5, 0, 0, 7)>
                                            <!-- End window label -->

                                            <!-- Start window informations main box -->
                                            <box id = "window_informations_main_box" orientation = GTK_ORIENTATION_HORIZONTAL align = GTK_ALIGN_START spacing = 0>
                                                
                                                <!-- Start window informations grid -->
                                                <grid id = "window_informations_grid" rows_spacing = 7 columns_spacing = 7 rows_homogeneous = TRUE columns_homogeneous = FALSE>
    
                                                    <!-- Start window informations app label -->
                                                    <label id = "window_informations_app_label" text = "Window" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                    </label add_to_grid(window_informations_grid, window_informations_app_label, 0, 0, 1, 1)>
                                                    <!-- End window informations app -->
                                                    
                                                    <!-- Start window informations app value -->
                                                    <entry id = "window_informations_app_value" default_text = "app" indicator_text = "Chose App for TOPLEVEL" visible = TRUE editable = TRUE max_lenght = 5 alignment = 0.5>
    
                                                    </entry add_to_grid(window_informations_grid, window_informations_app_value, 0, 1, 1, 1)>
                                                    <!-- End window informations app value -->
    
                                                    <!-- Start window informations type label -->
                                                    <label id = "window_informations_type_label" text = "Type" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                    </label add_to_grid(window_informations_grid, window_informations_type_label, 1, 0, 1, 1)>
                                                    <!-- End window informations type label -->

                                                    <!-- Start window informations type value -->
                                                    <entry id = "window_informations_type_value" default_text = "GTK_WINDOW_TOPLEVEL" indicator_text = "Chose Type of the window" visible = TRUE editable = TRUE max_lenght = 5 alignment = 0.5>
    
                                                    </entry add_to_grid(window_informations_grid, window_informations_type_value, 1, 1, 1, 1)>
                                                    <!-- End window informations type value -->

                                                    <!-- Start window informations title label -->
                                                    <label id = "window_informations_title_label" text = "Title" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                    </label add_to_grid(window_informations_grid, window_informations_title_label, 2, 0, 1, 1)>
                                                    <!-- End window informations title label -->
    
                                                    <!-- Start window informations title value -->
                                                    <entry id = "window_informations_title_value" default_text = "title" indicator_text = "Chose Title for TOPLEVEL" visible = TRUE editable = TRUE max_lenght = 5 alignment = 0.5>
    
                                                    </entry add_to_grid(window_informations_grid, window_informations_title_value, 2, 1, 1, 1)>
                                                    <!-- End window informations title value -->

                                                    <!-- Start window informations width label -->
                                                    <label id = "window_informations_width_label" text = "Width" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                    </label add_to_grid(window_informations_grid, window_informations_width_label, 3, 0, 1, 1)>
                                                    <!-- End window informations width label -->

                                                    <!-- Start window informations width value -->
                                                    <spin_button id = "window_informations_width_value" min = 0 max = 1000 step = 10 value = 800 digits = 0 numeric = TRUE>

                                                    </spin_button add_to_grid(window_informations_grid, window_informations_width_value, 3, 1, 1, 1)>
                                                    <!-- End window informations width value -->

                                                    <!-- Start window informations height label -->
                                                    <label id = "window_informations_height_label" text = "Height" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                    </label add_to_grid(window_informations_grid, window_informations_height_label, 4, 0, 1, 1)>
                                                    <!-- End window informations height label -->

                                                    <!-- Start window informations height value -->
                                                    <spin_button id = "window_informations_height_value" min = 0 max = 1000 step = 10 value = 600 digits = 0 numeric = TRUE>

                                                    </spin_button add_to_grid(window_informations_grid, window_informations_height_value, 4, 1, 1, 1)>
                                                    <!-- End window informations height value -->

                                                    <!-- Start window informations resizable label -->
                                                    <label id = "window_informations_resizable_label" text = "Resizable" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                    </label add_to_grid(window_informations_grid, window_informations_resizable_label, 5, 0, 1, 1)>
                                                    <!-- End window informations resizable label -->

                                                    <!-- Start window informations resizable value combo box -->
                                                    <combo_box id = "window_informations_resizable_value">

                                                        <!-- Start window informations resizable value combo box item -->
                                                        <combo_box_item id = "window_informations_resizable_value_item1" label = "TRUE">

                                                        </combo_box_item add_to_combo_box(window_informations_resizable_value, "TRUE")>
                                                        <!-- End window informations resizable value combo box item -->

                                                        <!-- Start window informations resizable value combo box item -->
                                                        <combo_box_item id = "window_informations_resizable_value_item2" label = "FALSE">

                                                        </combo_box_item add_to_combo_box(window_informations_resizable_value, "FALSE")>
                                                        <!-- End window informations resizable value combo box item -->

                                                    </combo_box add_to_grid(window_informations_grid, window_informations_resizable_value, 5, 1, 1, 1)>
                                                    <!-- End window informations resizable value combo box -->

                                                    <!-- Start window informations position label -->
                                                    <label id = "window_informations_position_label" text = "Position" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                    </label add_to_grid(window_informations_grid, window_informations_position_label, 6, 0, 1, 1)>
                                                    <!-- End window informations position label -->

                                                    <!-- Start window informations position value combo box -->
                                                    <combo_box id = "window_informations_position_value">

                                                        <!-- Start window informations position value combo box item -->
                                                        <combo_box_item id = "window_informations_position_value_item1" label = "GTK_WIN_POS_CENTER">

                                                        </combo_box_item add_to_combo_box(window_informations_position_value, "GTK_WIN_POS_CENTER")>
                                                        <!-- End window informations position value combo box item -->

                                                        <!-- Start window informations position value combo box item -->
                                                        <combo_box_item id = "window_informations_position_value_item2" label = "GTK_WIN_POS_CENTER_ON_PARENT">

                                                        </combo_box_item add_to_combo_box(window_informations_position_value, "GTK_WIN_POS_CENTER_ON_PARENT")>
                                                        <!-- End window informations position value combo box item -->

                                                        <!-- Start window informations position value combo box item -->
                                                        <combo_box_item id = "window_informations_position_value_item3" label = "GTK_WIN_POS_MOUSE">

                                                        </combo_box_item add_to_combo_box(window_informations_position_value, "GTK_WIN_POS_MOUSE")>
                                                        <!-- End window informations position value combo box item -->

                                                    </combo_box add_to_grid(window_informations_grid, window_informations_position_value, 6, 1, 1, 1)>
                                                    <!-- End window informations position value combo box -->

                                                    <!-- Start window informations decorate label -->
                                                    <label id = "window_informations_decorate_label" text = "Decorate" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                    </label add_to_grid(window_informations_grid, window_informations_decorate_label, 7, 0, 1, 1)>
                                                    <!-- End window informations decorate label -->

                                                    <!-- Start window informations decorate value combo box -->
                                                    <combo_box id = "window_informations_decorate_value">

                                                        <!-- Start window informations decorate value combo box item -->
                                                        <combo_box_item id = "window_informations_decorate_value_item1" label = "TRUE">

                                                        </combo_box_item add_to_combo_box(window_informations_decorate_value, "TRUE")>
                                                        <!-- End window informations decorate value combo box item -->

                                                        <!-- Start window informations decorate value combo box item -->
                                                        <combo_box_item id = "window_informations_decorate_value_item2" label = "FALSE">

                                                        </combo_box_item add_to_combo_box(window_informations_decorate_value, "FALSE")>
                                                        <!-- End window informations decorate value combo box item -->

                                                    </combo_box add_to_grid(window_informations_grid, window_informations_decorate_value, 7, 1, 1, 1)>
                                                    <!-- End window informations decorate value combo box -->

                                                    <!-- Start window informations icon label -->
                                                    <label id = "window_informations_icon_label" text = "Icon" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                    </label add_to_grid(window_informations_grid, window_informations_icon_label, 8, 0, 1, 1)>
                                                    <!-- End window informations icon label -->

                                                    <!-- Start window informations icon value -->
                                                    <entry id = "window_informations_icon_value"  indicator_text = "icon path" visible = TRUE editable = TRUE max_length = 20 alignment = 0.5>

                                                    </entry add_to_grid(window_informations_grid, window_informations_icon_value, 8, 1, 1, 1)>
                                                    <!-- End window informations icon value -->

                                                    <!-- Start window informations opacity label -->
                                                    <label id = "window_informations_opacity_label" text = "Opacity" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                    </label add_to_grid(window_informations_grid, window_informations_opacity_label, 9, 0, 1, 1)>
                                                    <!-- End window informations opacity label -->

                                                    <!-- Start window informations opacity value -->
                                                    <spin_button id = "window_informations_opacity_value" min = 0 max = 1 step = 0.1 value = 1 digits = 1 numeric = TRUE>

                                                    </spin_button add_to_grid(window_informations_grid, window_informations_opacity_value, 9, 1, 1, 1)>
                                                    <!-- End window informations opacity value -->

                                                    <!-- Start window informations fullscreen label -->
                                                    <label id = "window_informations_fullscreen_label" text = "Fullscreen" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                    </label add_to_grid(window_informations_grid, window_informations_fullscreen_label, 10, 0, 1, 1)>
                                                    <!-- End window informations fullscreen label -->

                                                    <!-- Start window informations fullscreen value combo box -->
                                                    <combo_box id = "window_informations_fullscreen_value">

                                                        <!-- Start window informations fullscreen value combo box item -->
                                                        <combo_box_item id = "window_informations_fullscreen_value_item1" label = "TRUE">

                                                        </combo_box_item add_to_combo_box(window_informations_fullscreen_value, "TRUE")>
                                                        <!-- End window informations fullscreen value combo box item -->

                                                        <!-- Start window informations fullscreen value combo box item -->
                                                        <combo_box_item id = "window_informations_fullscreen_value_item2" label = "FALSE">

                                                        </combo_box_item add_to_combo_box(window_informations_fullscreen_value, "FALSE")>
                                                        <!-- End window informations fullscreen value combo box item -->

                                                    </combo_box add_to_grid(window_informations_grid, window_informations_fullscreen_value, 10, 1, 1, 1)>
                                                    <!-- End window informations fullscreen value combo box -->

                                                    <!-- Start window informations add button -->
                                                    <button id = "window_informations_add_button" label = "Add">

                                                    </button add_to_grid(window_informations_grid, window_informations_add_button, 11, 0, 2, 1)>
                                                    <!-- End window informations add button -->

                                                </grid add_to_box(window_informations_main_box, window_informations_grid, START, TRUE, FALSE, 0, 0, 0, 0, 0)>
                                                <!-- End window informations grid -->

                                            </box add_to_box(window_case, window_informations_main_box, START, FALSE, FALSE, 0, 5, 0, 0, 7)>
                                            <!-- End window informations main box -->

                                        </box add_to_box(Windows_box, window_case, START, TRUE, TRUE, 0, 7, 0, 0, 0)>
                                        <!-- End Window Case -->


                                        <!-- Start Header Bar Case -->
                                        <box id = "Header_bar_case" orientation = GTK_ORIENTATION_VERTICAL align = GTK_ALIGN_START spacing = 0>

                                            <!-- Start header bar label -->
                                            <label id = "header_bar_label" text = "Header Bar" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                            </label add_to_box(Header_bar_case, header_bar_label, START, TRUE, FALSE, 0, 0, 0, 0, 7)>
                                            <!-- End header bar label -->

                                            <!-- Start header bar informations main box -->
                                            <box id = "header_bar_informations_main_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>

                                                <!-- Start header bar informations grid -->
                                                <grid id = "header_bar_informations_grid" rows_spacing = 7 columns_spacing = 7 rows_homogeneous = TRUE columns_homogeneous = FALSE>

                                                    <!-- Start header bar informations title label -->
                                                    <label id = "header_bar_informations_title_label" text = "Title" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(header_bar_informations_grid, header_bar_informations_title_label, 0, 0, 1, 1)>
                                                    <!-- End header bar informations title label -->

                                                    <!-- Start header bar informations title value -->
                                                    <entry id = "header_bar_informations_title_value"  indicator_text = "title" visible = TRUE editable = TRUE max_length = 20 alignment = 0.5>

                                                    </entry add_to_grid(header_bar_informations_grid, header_bar_informations_title_value, 0, 1, 1, 1)>
                                                    <!-- End header bar informations title value -->

                                                    <!-- Start header bar informations subtitle label -->
                                                    <label id = "header_bar_informations_subtitle_label" text = "Subtitle" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(header_bar_informations_grid, header_bar_informations_subtitle_label, 1, 0, 1, 1)>
                                                    <!-- End header bar informations subtitle label -->

                                                    <!-- Start header bar informations subtitle value -->
                                                    <entry id = "header_bar_informations_subtitle_value"  indicator_text = "subtitle" visible = TRUE editable = TRUE max_length = 20 alignment = 0.5>

                                                    </entry add_to_grid(header_bar_informations_grid, header_bar_informations_subtitle_value, 1, 1, 1, 1)>
                                                    <!-- End header bar informations subtitle value -->

                                                    <!-- Start header bar informations icon label -->
                                                    <label id = "header_bar_informations_icon_label" text = "Icon" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(header_bar_informations_grid, header_bar_informations_icon_label, 2, 0, 1, 1)>
                                                    <!-- End header bar informations icon label -->

                                                    <!-- Start header bar informations icon value -->
                                                    <entry id = "header_bar_informations_icon_value"  indicator_text = "icon path" visible = TRUE editable = TRUE max_length = 20 alignment = 0.5>

                                                    </entry add_to_grid(header_bar_informations_grid, header_bar_informations_icon_value, 2, 1, 1, 1)>
                                                    <!-- End header bar informations icon value -->

                                                    <!-- Start header bar informations settings label -->
                                                    <label id = "header_bar_informations_settings_label" text = "Settings" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(header_bar_informations_grid, header_bar_informations_settings_label, 3, 0, 1, 1)>
                                                    <!-- End header bar informations settings label -->

                                                    <!-- Start header bar informations settings value combo box -->
                                                    <combo_box id = "header_bar_informations_settings_value">

                                                        <!-- Start header bar informations settings value combo box item -->
                                                        <combo_box_item id = "header_bar_informations_settings_value_item1" label = "TRUE">

                                                        </combo_box_item add_to_combo_box(header_bar_informations_settings_value, "TRUE")>
                                                        <!-- End header bar informations settings value combo box item -->

                                                        <!-- Start header bar informations settings value combo box item -->
                                                        <combo_box_item id = "header_bar_informations_settings_value_item2" label = "FALSE">

                                                        </combo_box_item add_to_combo_box(header_bar_informations_settings_value, "FALSE")>
                                                        <!-- End header bar informations settings value combo box item -->

                                                    </combo_box add_to_grid(header_bar_informations_grid, header_bar_informations_settings_value, 3, 1, 1, 1)>
                                                    <!-- End header bar informations settings value combo box -->
                                                    
                                                    <!-- Start header bar informations add button -->
                                                    <button id = "header_bar_informations_add_button" label = "Add">

                                                    </button add_to_grid(header_bar_informations_grid, header_bar_informations_add_button, 4, 0, 2, 1)>
                                                    <!-- End header bar informations add button -->

                                                </grid add_to_box(header_bar_informations_main_box, header_bar_informations_grid, START, TRUE, FALSE, 0, 14, 0, 0, 0)>
                                                <!-- End header bar informations grid -->

                                            </box add_to_box(Header_bar_case, header_bar_informations_main_box, START, FALSE, FALSE, 0, 5, 0, 0, 7)>
                                            <!-- End header bar informations main box -->

                                        </box add_to_box(Windows_box, Header_bar_case, START, TRUE, TRUE, 0, 25, 0, 0, 0)>
                                        <!-- End Header Bar Case -->

                                        <!-- Start scrolled window Case -->
                                        <box id = "scrolled_window_case" orientation = GTK_ORIENTATION_VERTICAL align = GTK_ALIGN_START spacing = 0>

                                            <!-- Start scrolled window label -->
                                            <label id = "scrolled_window_label" text = "scrolled window" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                            </label add_to_box(scrolled_window_case, scrolled_window_label, START, TRUE, FALSE, 0, 0, 0, 0, 7)>
                                            <!-- End scrolled window label -->

                                            <!-- Start scrolled window informations main box -->
                                            <box id = "scrolled_window_informations_main_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>

                                                <!-- Start scrolled window informations grid -->
                                                <grid id = "scrolled_window_informations_grid" rows_spacing = 7 columns_spacing = 7 rows_homogeneous = TRUE columns_homogeneous = FALSE>

                                                    <!-- Start scrolled window informations horizontal label -->
                                                    <label id = "scrolled_window_informations_horizontal_label" text = "Horizontal" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(scrolled_window_informations_grid, scrolled_window_informations_horizontal_label, 0, 0, 1, 1)>
                                                    <!-- End scrolled window informations horizontal label -->

                                                    <!-- Start scrolled window informations horizontal value combo box -->
                                                    <combo_box id = "scrolled_window_informations_horizontal_value">

                                                        <!-- Start scrolled window informations horizontal value combo box item -->
                                                        <combo_box_item id = "scrolled_window_informations_horizontal_value_item1" label = "TRUE">

                                                        </combo_box_item add_to_combo_box(scrolled_window_informations_horizontal_value, "TRUE")>
                                                        <!-- End scrolled window informations horizontal value combo box item -->

                                                        <!-- Start scrolled window informations horizontal value combo box item -->
                                                        <combo_box_item id = "scrolled_window_informations_horizontal_value_item2" label = "FALSE">

                                                        </combo_box_item add_to_combo_box(scrolled_window_informations_horizontal_value, "FALSE")>
                                                        <!-- End scrolled window informations horizontal value combo box item -->

                                                    </combo_box add_to_grid(scrolled_window_informations_grid, scrolled_window_informations_horizontal_value, 0, 1, 1, 1)>
                                                    <!-- End scrolled window informations horizontal value combo box -->

                                                    <!-- Start scrolled window informations vertical label -->
                                                    <label id = "scrolled_window_informations_vertical_label" text = "Vertical" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(scrolled_window_informations_grid, scrolled_window_informations_vertical_label, 1, 0, 1, 1)>
                                                    <!-- End scrolled window informations vertical label -->

                                                    <!-- Start scrolled window informations vertical value combo box -->
                                                    <combo_box id = "scrolled_window_informations_vertical_value">

                                                        <!-- Start scrolled window informations vertical value combo box item -->
                                                        <combo_box_item id = "scrolled_window_informations_vertical_value_item1" label = "TRUE">

                                                        </combo_box_item add_to_combo_box(scrolled_window_informations_vertical_value, "TRUE")>
                                                        <!-- End scrolled window informations vertical value combo box item -->

                                                        <!-- Start scrolled window informations vertical value combo box item -->
                                                        <combo_box_item id = "scrolled_window_informations_vertical_value_item2" label = "FALSE">

                                                        </combo_box_item add_to_combo_box(scrolled_window_informations_vertical_value, "FALSE")>
                                                        <!-- End scrolled window informations vertical value combo box item -->

                                                    </combo_box add_to_grid(scrolled_window_informations_grid, scrolled_window_informations_vertical_value, 1, 1, 1, 1)>
                                                    <!-- End scrolled window informations vertical value combo box -->

                                                    <!-- Start scrolled window informations add button -->
                                                    <button id = "scrolled_window_informations_add_button" label = "Add">

                                                    </button add_to_grid(scrolled_window_informations_grid, scrolled_window_informations_add_button, 2, 0, 2, 1)>
                                                    <!-- End scrolled window informations add button -->

                                                </grid add_to_box(scrolled_window_informations_main_box, scrolled_window_informations_grid, START, TRUE, FALSE, 0, 14, 0, 0, 0)>
                                                <!-- End scrolled window informations grid -->

                                            </box add_to_box(scrolled_window_case, scrolled_window_informations_main_box, START, FALSE, FALSE, 0, 5, 0, 0, 7)>
                                            <!-- End scrolled window informations main box -->


                                        </box add_to_box(Windows_box, scrolled_window_case, START, TRUE, TRUE, 0, 25, 0, 0, 0)>
                                        <!-- End scrolled window Case -->

                                    </box add_to_scrolled_window(scrolled_window_window, Windows_box)>
                                    <!-- End Windows box -->

                                </scrolled_window add_to_stack(stack_catalog, scrolled_window_window, "Windows")>
                                <!-- End scrolled window window -->


                                <!-- Start Scrolled Containers window -->
                                <scrolled_window id = "scrolled_containers_window" horizontal = FALSE vertical = TRUE>

                                    <!-- Start Containers box -->
                                    <box id = "Containers_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 7>

                                        <!-- Start containers button -->
                                        <button id = "Containers" label = "Containers">
            
                                        </button add_to_box(Containers_box, Containers, START, TRUE, TRUE, 0, 7, 0, 0, 0)>
                                        <!-- End Containers button -->

                                        <!-- Start Containers2 button -->
                                        <button id = "Containers2" label = "Containers">

                                        </button add_to_box(Containers_box, Containers2, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                        <!-- End Containers2 button -->

                                        <!-- Start Containers3 button -->
                                        <button id = "Containers3" label = "Containers">

                                        </button add_to_box(Containers_box, Containers3, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                        <!-- End Containers button -->

                                        <!-- Start Containers4 button -->
                                        <button id = "Containers4" label = "Containers">

                                        </button add_to_box(Containers_box, Containers4, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                        <!-- End Containers4 button -->

                                    </box add_to_scrolled_window(scrolled_containers_window, Containers_box)>
                                    <!-- End Windows box -->

                                </scrolled_window add_to_stack(stack_catalog, scrolled_containers_window, "Containers")>
                                <!-- End Scrolled Containers window -->


                                <!-- Start Scrolled Widgets window -->
                                <scrolled_window id = "scrolled_widgets_window" horizontal = FALSE vertical = TRUE>

                                    <!-- Start Widgets box -->
                                    <box id = "Widgets_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 7>

                                        <!-- Start Widgets button -->
                                        <button id = "Widgets" label = "Widgets">
            
                                        </button add_to_box(Widgets_box, Widgets, START, TRUE, TRUE, 0, 7, 0, 0, 0)>
                                        <!-- End Widgets button -->

                                        <!-- Start Widgets2 button -->
                                        <button id = "Widgets2" label = "Widgets">

                                        </button add_to_box(Widgets_box, Widgets2, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                        <!-- End Widgets2 button -->

                                        <!-- Start Widgets3 button -->
                                        <button id = "Widgets3" label = "Widgets">

                                        </button add_to_box(Widgets_box, Widgets3, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                        <!-- End Widgets3 button -->

                                        <!-- Start Widgets4 button -->
                                        <button id = "Widgets4" label = "Widgets">

                                        </button add_to_box(Widgets_box, Widgets4, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                        <!-- End Widgets4 button -->

                                    </box add_to_scrolled_window(scrolled_widgets_window, Widgets_box)>
                                    <!-- End Widgets box -->

                                </scrolled_window add_to_stack(stack_catalog, scrolled_widgets_window, "Widgets")>
                                <!-- End Scrolled Widgets winodw -->

                            </stack add_to_box(widgets_catalog_box, stack_catalog, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                            <!-- End stack Catalog -->

                        </box add_to_box(second_space_box, widgets_catalog_box, START, TRUE, TRUE, 0, 7, 0, 7, 0)>
                        <!-- End widgets catalog content -->

                    </box add_to_paned(build_space_paned, second_space_box, SECOND)>
                    <!-- End the second space box -->

                </paned add_to_paned(main_paned, build_space_paned, SECOND)>
                <!-- End the build space paned -->

            </paned add_to_box(app_box, main_paned, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
            <!-- End main paned -->

        </box add_to_box(main_box, app_box, START, TRUE, TRUE, 0, 7, 0, 7, 7)>
        <!-- End App box -->
        
        <!-- Start the control box -->
        <box id = "control_box" orientation = GTK_ORIENTATION_HORIZONTAL align = -1 spacing = 0>

            <!-- Start the generate button -->
            <button id = "generate_button" label = "Generate">
    
            </button add_to_box(control_box, generate_button, START, FALSE, FALSE, 0, 0, 0, 0, 7)>
            <!-- End the generate button -->
            
            <!-- Start the drag button -->
            <button id = "drag_button" label = "Drag">

            </button add_to_box(control_box, drag_button, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
            <!-- End the drag button -->

        </box add_to_box(main_box, control_box, START, FALSE, FALSE, 0, 7, 7, 7, 7)>
        <!-- End the control box -->

    </box add_to_container(window, main_box)>
    <!-- End the main box -->

</window show_widget(window)>
<!-- End Window -->