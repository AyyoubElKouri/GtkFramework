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
                <paned id = "build_space_paned" orientation = GTK_ORIENTATION_HORIZONTAL default_position = 625 show_handle = TRUE>

                    <!-- Start the first space box -->
                    <box id = "first_space_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>

                        <!-- Start the contents space paned -->
                        <paned id = "contents_space_paned" orientation = GTK_ORIENTATION_VERTICAL default_position = 400 show_handle = TRUE>

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
                                        <box id = "window_case" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>

                                            <!-- Start window label frame -->
                                            <frame id = "window_label_frame" label = NULL>

                                                <!-- Start window label -->
                                                <label id = "window_label" text = "Window" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_RIGHT">
    
                                                </label add_to_frame(window_label_frame, window_label, 5, 5, 0, 0)>
                                                <!-- End window label -->

                                            </frame add_to_box(window_case, window_label_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0)>
                                            <!-- End window label frame -->


                                            <!-- Start window informations frame -->
                                            <frame id = "window_informations_frame" label = NULL>

                                                <!-- Start window informations main box -->
                                                <box id = "window_informations_main_box" orientation = GTK_ORIENTATION_HORIZONTAL align = -1 spacing = 0>
                                                    
                                                    <!-- Start window informations grid -->
                                                    <grid id = "window_informations_grid" rows_spacing = 7 columns_spacing = 7 rows_homogeneous = TRUE columns_homogeneous = FALSE>
        
                                                        <!-- Start window id label -->
                                                        <label id = "window_informations_id_label" text = "Widget ID" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                        </label add_to_grid(window_informations_grid, window_informations_id_label, 0, 0, 1, 1)>
                                                        <!-- End window id label -->

                                                        <!-- Start window id entry -->
                                                        <entry id = "window_informations_id_value" default_text = NULL indicator_text = "must be unique and no space" visible = TRUE editable = TRUE max_lenght = 5 alignment = 0.5>

                                                        </entry add_to_grid(window_informations_grid, window_informations_id_value, 0, 1, 1, 1)>
                                                        <!-- End window id entry -->

                                                        <!-- Start window informations app label -->
                                                        <label id = "window_informations_app_label" text = "Window" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
        
                                                        </label add_to_grid(window_informations_grid, window_informations_app_label, 1, 0, 1, 1)>
                                                        <!-- End window informations app -->
                                                        
                                                        <!-- Start window informations app value -->
                                                        <entry id = "window_informations_app_value" default_text = "app" indicator_text = "Chose App for TOPLEVEL" visible = TRUE editable = TRUE max_lenght = 5 alignment = 0.5>
        
                                                        </entry add_to_grid(window_informations_grid, window_informations_app_value, 1, 1, 1, 1)>
                                                        <!-- End window informations app value -->
        
                                                        <!-- Start window informations type label -->
                                                        <label id = "window_informations_type_label" text = "Type" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
        
                                                        </label add_to_grid(window_informations_grid, window_informations_type_label, 2, 0, 1, 1)>
                                                        <!-- End window informations type label -->
    
                                                        <!-- Start window informations type value -->
                                                        <entry id = "window_informations_type_value" default_text = "GTK_WINDOW_TOPLEVEL" indicator_text = "Chose Type of the window" visible = TRUE editable = TRUE max_lenght = 5 alignment = 0.5>
        
                                                        </entry add_to_grid(window_informations_grid, window_informations_type_value, 2, 1, 1, 1)>
                                                        <!-- End window informations type value -->
    
                                                        <!-- Start window informations title label -->
                                                        <label id = "window_informations_title_label" text = "Title" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
        
                                                        </label add_to_grid(window_informations_grid, window_informations_title_label, 3, 0, 1, 1)>
                                                        <!-- End window informations title label -->
        
                                                        <!-- Start window informations title value -->
                                                        <entry id = "window_informations_title_value" default_text = "title" indicator_text = "Chose Title for TOPLEVEL" visible = TRUE editable = TRUE max_lenght = 5 alignment = 0.5>
        
                                                        </entry add_to_grid(window_informations_grid, window_informations_title_value, 3, 1, 1, 1)>
                                                        <!-- End window informations title value -->
    
                                                        <!-- Start window informations width label -->
                                                        <label id = "window_informations_width_label" text = "Width" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
        
                                                        </label add_to_grid(window_informations_grid, window_informations_width_label, 4, 0, 1, 1)>
                                                        <!-- End window informations width label -->
    
                                                        <!-- Start window informations width value -->
                                                        <spin_button id = "window_informations_width_value" min = 0 max = 1000 step = 10 value = 800 digits = 0 numeric = TRUE>
    
                                                        </spin_button add_to_grid(window_informations_grid, window_informations_width_value, 4, 1, 1, 1)>
                                                        <!-- End window informations width value -->
    
                                                        <!-- Start window informations height label -->
                                                        <label id = "window_informations_height_label" text = "Height" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
        
                                                        </label add_to_grid(window_informations_grid, window_informations_height_label, 5, 0, 1, 1)>
                                                        <!-- End window informations height label -->
    
                                                        <!-- Start window informations height value -->
                                                        <spin_button id = "window_informations_height_value" min = 0 max = 1000 step = 10 value = 600 digits = 0 numeric = TRUE>
    
                                                        </spin_button add_to_grid(window_informations_grid, window_informations_height_value, 5, 1, 1, 1)>
                                                        <!-- End window informations height value -->
    
                                                        <!-- Start window informations resizable label -->
                                                        <label id = "window_informations_resizable_label" text = "Resizable" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
        
                                                        </label add_to_grid(window_informations_grid, window_informations_resizable_label, 6, 0, 1, 1)>
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
    
                                                        </combo_box add_to_grid(window_informations_grid, window_informations_resizable_value, 6, 1, 1, 1)>
                                                        <!-- End window informations resizable value combo box -->
    
                                                        <!-- Start window informations position label -->
                                                        <label id = "window_informations_position_label" text = "Position" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
        
                                                        </label add_to_grid(window_informations_grid, window_informations_position_label, 7, 0, 1, 1)>
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
    
                                                        </combo_box add_to_grid(window_informations_grid, window_informations_position_value, 7, 1, 1, 1)>
                                                        <!-- End window informations position value combo box -->
    
                                                        <!-- Start window informations decorate label -->
                                                        <label id = "window_informations_decorate_label" text = "Decorate" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
        
                                                        </label add_to_grid(window_informations_grid, window_informations_decorate_label, 8, 0, 1, 1)>
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
    
                                                        </combo_box add_to_grid(window_informations_grid, window_informations_decorate_value, 8, 1, 1, 1)>
                                                        <!-- End window informations decorate value combo box -->
    
                                                        <!-- Start window informations icon label -->
                                                        <label id = "window_informations_icon_label" text = "Icon" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
        
                                                        </label add_to_grid(window_informations_grid, window_informations_icon_label, 9, 0, 1, 1)>
                                                        <!-- End window informations icon label -->
    
                                                        <!-- Start window informations icon value -->
                                                        <entry id = "window_informations_icon_value"  indicator_text = "icon path" visible = TRUE editable = TRUE max_length = 20 alignment = 0.5>
    
                                                        </entry add_to_grid(window_informations_grid, window_informations_icon_value, 9, 1, 1, 1)>
                                                        <!-- End window informations icon value -->
    
                                                        <!-- Start window informations opacity label -->
                                                        <label id = "window_informations_opacity_label" text = "Opacity" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
        
                                                        </label add_to_grid(window_informations_grid, window_informations_opacity_label, 10, 0, 1, 1)>
                                                        <!-- End window informations opacity label -->
    
                                                        <!-- Start window informations opacity value -->
                                                        <spin_button id = "window_informations_opacity_value" min = 0 max = 1 step = 0.1 value = 1 digits = 1 numeric = TRUE>
    
                                                        </spin_button add_to_grid(window_informations_grid, window_informations_opacity_value, 10, 1, 1, 1)>
                                                        <!-- End window informations opacity value -->
    
                                                        <!-- Start window informations fullscreen label -->
                                                        <label id = "window_informations_fullscreen_label" text = "Fullscreen" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
        
                                                        </label add_to_grid(window_informations_grid, window_informations_fullscreen_label, 11, 0, 1, 1)>
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
    
                                                        </combo_box add_to_grid(window_informations_grid, window_informations_fullscreen_value, 11, 1, 1, 1)>
                                                        <!-- End window informations fullscreen value combo box -->
    
                                                        <!-- Start window informations add button -->
                                                        <button id = "window_informations_add_button" label = "                                                               Add                                                               ">
    
                                                        </button add_to_grid(window_informations_grid, window_informations_add_button, 12, 0, 2, 1)>
                                                        <!-- End window informations add button -->
    
                                                    </grid add_to_box(window_informations_main_box, window_informations_grid, START, TRUE, FALSE, 0, 21, 21, 0, 0)>
                                                    <!-- End window informations grid -->
    
                                                </box add_to_frame(window_informations_frame, window_informations_main_box, 0, 0, 0, 0)>
                                                <!-- End window informations main box -->

                                            </frame add_to_box(window_case, window_informations_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                            <!-- End window informations frame -->


                                        </box add_to_box(Windows_box, window_case, START, TRUE, TRUE, 0, 7, 0, 0, 0)>
                                        <!-- End Window Case -->


                                        <!-- Start Header Bar Case -->
                                        <box id = "Header_bar_case" orientation = GTK_ORIENTATION_VERTICAL align = GTK_ALIGN_START spacing = 0>

                                            <!-- Start header bar label frame -->
                                            <frame id ="header_bar_label_frame" label = NULL>
                                                
                                                <!-- Start header bar label -->
                                                <label id = "header_bar_label" text = "Header Bar" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                </label add_to_frame(header_bar_label_frame, header_bar_label, 5, 5, 0, 0)>
                                                <!-- End header bar label -->
                                                 
                                            </frame add_to_box(Header_bar_case, header_bar_label_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                            <!-- End header bar label frame -->

                                            <!-- Start header bar informations main box frame -->
                                            <frame id = "header_bar_informations_main_box_frame" label = NULL>

                                                <!-- Start header bar informations main box -->
                                                <box id = "header_bar_informations_main_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>
    
                                                    <!-- Start header bar informations grid -->
                                                    <grid id = "header_bar_informations_grid" rows_spacing = 7 columns_spacing = 7 rows_homogeneous = TRUE columns_homogeneous = FALSE>
                                                        
                                                        <!-- Start header bar id label -->
                                                        <label id = "header_bar_id_label" text = "Widget ID" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                        </label add_to_grid(header_bar_informations_grid, header_bar_id_label, 0, 0, 1, 1)>
                                                        <!-- End header bar id label -->
    
                                                        <!-- Start header bar id entry -->
                                                        <entry id = "header_bar_id_value"  default_text = NULL indicator_text = "must be unique and no space" visible = TRUE editable = TRUE max_lenght = 5 alignment = 0.5>

                                                        </entry add_to_grid(header_bar_informations_grid, header_bar_id_value, 0, 1, 1, 1)>
                                                        <!-- End header bar id entry -->

                                                        <!-- Start header bar informations title label -->
                                                        <label id = "header_bar_informations_title_label" text = "Title" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                        </label add_to_grid(header_bar_informations_grid, header_bar_informations_title_label, 1, 0, 1, 1)>
                                                        <!-- End header bar informations title label -->
    
                                                        <!-- Start header bar informations title value -->
                                                        <entry id = "header_bar_informations_title_value"  indicator_text = "title" visible = TRUE editable = TRUE max_length = 20 alignment = 0.5>
    
                                                        </entry add_to_grid(header_bar_informations_grid, header_bar_informations_title_value, 1, 1, 1, 1)>
                                                        <!-- End header bar informations title value -->
    
                                                        <!-- Start header bar informations subtitle label -->
                                                        <label id = "header_bar_informations_subtitle_label" text = "Subtitle" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                        </label add_to_grid(header_bar_informations_grid, header_bar_informations_subtitle_label, 2, 0, 1, 1)>
                                                        <!-- End header bar informations subtitle label -->
    
                                                        <!-- Start header bar informations subtitle value -->
                                                        <entry id = "header_bar_informations_subtitle_value"  indicator_text = "subtitle" visible = TRUE editable = TRUE max_length = 20 alignment = 0.5>
    
                                                        </entry add_to_grid(header_bar_informations_grid, header_bar_informations_subtitle_value, 2, 1, 1, 1)>
                                                        <!-- End header bar informations subtitle value -->
    
                                                        <!-- Start header bar informations icon label -->
                                                        <label id = "header_bar_informations_icon_label" text = "Icon" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                        </label add_to_grid(header_bar_informations_grid, header_bar_informations_icon_label, 3, 0, 1, 1)>
                                                        <!-- End header bar informations icon label -->
    
                                                        <!-- Start header bar informations icon value -->
                                                        <entry id = "header_bar_informations_icon_value"  indicator_text = "icon path" visible = TRUE editable = TRUE max_length = 20 alignment = 0.5>
    
                                                        </entry add_to_grid(header_bar_informations_grid, header_bar_informations_icon_value, 3, 1, 1, 1)>
                                                        <!-- End header bar informations icon value -->
    
                                                        <!-- Start header bar informations settings label -->
                                                        <label id = "header_bar_informations_settings_label" text = "Settings" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                        </label add_to_grid(header_bar_informations_grid, header_bar_informations_settings_label, 4, 0, 1, 1)>
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
    
                                                        </combo_box add_to_grid(header_bar_informations_grid, header_bar_informations_settings_value, 4, 1, 1, 1)>
                                                        <!-- End header bar informations settings value combo box -->
                                                        
                                                        <!-- Start header bar informations add button -->
                                                        <button id = "header_bar_informations_add_button" label = "                                                               Add                                                               ">
    
                                                        </button add_to_grid(header_bar_informations_grid, header_bar_informations_add_button, 5, 0, 2, 1)>
                                                        <!-- End header bar informations add button -->
    
                                                    </grid add_to_box(header_bar_informations_main_box, header_bar_informations_grid, START, TRUE, FALSE, 0, 14, 0, 14, 0)>
                                                    <!-- End header bar informations grid -->
    
                                                </box add_to_frame(header_bar_informations_main_box_frame, header_bar_informations_main_box, 0, 18, 0, 0)>
                                                <!-- End header bar informations main box -->

                                            </frame add_to_box(Header_bar_case, header_bar_informations_main_box_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                            <!-- End header bar informations main box frame -->


                                        </box add_to_box(Windows_box, Header_bar_case, START, TRUE, TRUE, 0, 25, 0, 0, 0)>
                                        <!-- End Header Bar Case -->

                                        <!-- Start scrolled window Case -->
                                        <box id = "scrolled_window_case" orientation = GTK_ORIENTATION_VERTICAL align = GTK_ALIGN_START spacing = 0>

                                            <!-- Start scrolled window label frame -->
                                            <frame id = "scrolled_window_label_frame" label = NULL>
                                                
                                                <!-- Start scrolled window label -->
                                                <label id = "scrolled_window_label" text = "scrolled window" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                </label add_to_frame(scrolled_window_label_frame, scrolled_window_label, 5, 5, 0, 0)>
                                                <!-- End scrolled window label -->

                                            </frame add_to_box(scrolled_window_case, scrolled_window_label_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                            <!-- End scrolled window label frame -->

                                            <!-- Start scrolled window informations main box frame -->
                                            <frame id = "scrolled_window_informations_main_box_frame" label = NULL>

                                                <!-- Start scrolled window informations main box -->
                                                <box id = "scrolled_window_informations_main_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>
    
                                                    <!-- Start scrolled window informations grid -->
                                                    <grid id = "scrolled_window_informations_grid" rows_spacing = 7 columns_spacing = 7 rows_homogeneous = TRUE columns_homogeneous = FALSE>
    
                                                        <!-- Start scrolled window informations id label -->
                                                        <label id = "scrolled_window_informations_id_label" text = "Widget ID" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                        </label add_to_grid(scrolled_window_informations_grid, scrolled_window_informations_id_label, 0, 0, 1, 1)>
                                                        <!-- End scrolled window informations id label -->

                                                        <!-- Start scrolled window informations id entry -->
                                                        <entry id = "scrolled_window_informations_id_value"  default_text = NULL indicator_text = "must be unique and no space" visible = TRUE editable = TRUE max_lenght = 5 alignment = 0.5>

                                                        </entry add_to_grid(scrolled_window_informations_grid, scrolled_window_informations_id_value, 0, 1, 1, 1)>
                                                        <!-- End scrolled window informations id entry -->

                                                        <!-- Start scrolled window informations horizontal label -->
                                                        <label id = "scrolled_window_informations_horizontal_label" text = "Horizontal" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                        </label add_to_grid(scrolled_window_informations_grid, scrolled_window_informations_horizontal_label, 1, 0, 1, 1)>
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
    
                                                        </combo_box add_to_grid(scrolled_window_informations_grid, scrolled_window_informations_horizontal_value, 1, 1, 1, 1)>
                                                        <!-- End scrolled window informations horizontal value combo box -->
    
                                                        <!-- Start scrolled window informations vertical label -->
                                                        <label id = "scrolled_window_informations_vertical_label" text = "Vertical" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                        </label add_to_grid(scrolled_window_informations_grid, scrolled_window_informations_vertical_label, 2, 0, 1, 1)>
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
    
                                                        </combo_box add_to_grid(scrolled_window_informations_grid, scrolled_window_informations_vertical_value, 2, 1, 1, 1)>
                                                        <!-- End scrolled window informations vertical value combo box -->
    
                                                        <!-- Start scrolled window informations add button -->
                                                        <button id = "scrolled_window_informations_add_button" label = "                                                               Add                                                               ">
    
                                                        </button add_to_grid(scrolled_window_informations_grid, scrolled_window_informations_add_button, 3, 0, 2, 1)>
                                                        <!-- End scrolled window informations add button -->
    
                                                    </grid add_to_box(scrolled_window_informations_main_box, scrolled_window_informations_grid, START, TRUE, FALSE, 0, 14, 0, 0, 0)>
                                                    <!-- End scrolled window informations grid -->
    
                                                </box add_to_frame(scrolled_window_informations_main_box_frame, scrolled_window_informations_main_box, 0, 18, 14, 0)>
                                                <!-- End scrolled window informations main box -->

                                            </frame add_to_box(scrolled_window_case, scrolled_window_informations_main_box_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                            <!-- End scrolled window informations main box frame -->

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

                                        <!-- Start box Case -->
                                        <box id = "Box_case" orientation = GTK_ORIENTATION_VERTICAL align = GTK_ALIGN_START spacing = 0>

                                            <!-- Start box case label frame -->
                                            <frame id = "Box_case_label_frame" label = NULL>

                                                <!-- Start box case label -->
                                                <label id = "Box_case_label" text = "Box" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                </label add_to_frame(Box_case_label_frame, Box_case_label, 5, 5, 0, 0)>
                                                <!-- End box case label -->

                                            </frame add_to_box(Box_case, Box_case_label_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                            <!-- End box case label frame -->

                                            <!-- Start box case informations main box frame -->
                                            <frame id = "Box_case_informations_main_box_frame" label = NULL>

                                                <!-- Start box case informations main box -->
                                                <box id = "Box_case_informations_main_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>
    
                                                    <!-- Start box case informations grid -->
                                                    <grid id = "Box_case_informations_grid" rows_spacing = 7 columns_spacing = 7 rows_homogeneous = TRUE columns_homogeneous = FALSE>
    
                                                        <!-- Start box id label -->
                                                        <label id = "Box_case_informations_id_label" text = "Widget ID" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                        </label add_to_grid(Box_case_informations_grid, Box_case_informations_id_label, 0, 0, 1, 1)>
                                                        <!-- End box id label -->
    
                                                        <!-- Start box id entry -->
                                                        <entry id = "Box_case_informations_id_entry" default_text = NULL indicator_text = "must be unique and no space" visible = TRUE editable = TRUE max_lenght = 5 alignment = 0.5>

                                                        </entry add_to_grid(Box_case_informations_grid, Box_case_informations_id_entry, 0, 1, 1, 1)>
                                                        <!-- End box id entry -->

                                                        <!-- Start box case informations orientation label -->
                                                        <label id = "Box_case_informations_orientation_label" text = "Orientation" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
                                        
                                                        </label add_to_grid(Box_case_informations_grid, Box_case_informations_orientation_label, 1, 0, 1, 1)>
                                                        <!-- End box case informations orientation label -->
    
                                                        <!-- Start box case informations orientation value combo box -->
                                                        <combo_box id = "Box_case_informations_orientation_value">
    
                                                            <!-- Start box case informations orientation value combo box item -->
                                                            <combo_box_item id = "Box_case_informations_orientation_value_item1" label = "GTK_ORIENTATION_HORIZONTAL">
    
                                                            </combo_box_item add_to_combo_box(Box_case_informations_orientation_value, "GTK_ORIENTATION_HORIZONTAL")>
                                                            <!-- End box case informations orientation value combo box item -->
    
                                                            <!-- Start box case informations orientation value combo box item -->
                                                            <combo_box_item id = "Box_case_informations_orientation_value_item2" label = "GTK_ORIENTATION_VERTICAL">
    
                                                            </combo_box_item add_to_combo_box(Box_case_informations_orientation_value, "GTK_ORIENTATION_VERTICAL")>
                                                            <!-- End box case informations orientation value combo box item -->
    
                                                        </combo_box add_to_grid(Box_case_informations_grid, Box_case_informations_orientation_value, 1, 1, 1, 1)>
                                                        <!-- End box case informations orientation value combo box -->
    
                                                        <!-- Start box case informations align label -->
                                                        <label id = "Box_case_informations_align_label" text = "Align" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                        </label add_to_grid(Box_case_informations_grid, Box_case_informations_align_label, 2, 0, 1, 1)>
                                                        <!-- End box case informations align label -->
    
                                                        <!-- Start box case informations align value combo box -->
                                                        <combo_box id = "Box_case_informations_align_value">
    
                                                            <!-- Start box case informations align value combo box item -->
                                                            <combo_box_item id = "Box_case_informations_align_value_item1" label = "GTK_ALIGN_START">
    
                                                            </combo_box_item add_to_combo_box(Box_case_informations_align_value, "GTK_ALIGN_START")>
                                                            <!-- End box case informations align value combo box item -->
    
                                                            <!-- Start box case informations align value combo box item -->
                                                            <combo_box_item id = "Box_case_informations_align_value_item2" label = "GTK_ALIGN_END">
    
                                                            </combo_box_item add_to_combo_box(Box_case_informations_align_value, "GTK_ALIGN_END")>
                                                            <!-- End box case informations align value combo box item -->
    
                                                            <!-- Start box case informations align value combo box item -->
                                                            <combo_box_item id = "Box_case_informations_align_value_item3" label = "GTK_ALIGN_CENTER">
    
                                                            </combo_box_item add_to_combo_box(Box_case_informations_align_value, "GTK_ALIGN_CENTER")>
                                                            <!-- End box case informations align value combo box item -->
    
                                                            <!-- Start box case informations align value combo box item -->
                                                            <combo_box_item id = "Box_case_informations_align_value_item4" label = "-1">
    
                                                            </combo_box_item add_to_combo_box(Box_case_informations_align_value, "-1")>
                                                            <!-- End box case informations align value combo box item -->
    
                                                        </combo_box add_to_grid(Box_case_informations_grid, Box_case_informations_align_value, 2, 1, 1, 1)>
                                                        <!-- End box case informations align value combo box -->
    
                                                        <!-- Start box case informations spacing label -->
                                                        <label id = "Box_case_informations_spacing_label" text = "Spacing" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                        </label add_to_grid(Box_case_informations_grid, Box_case_informations_spacing_label, 3, 0, 1, 1)>
                                                        <!-- End box case informations spacing label -->
    
                                                        <!-- Start box case informations spacing value spin button -->
                                                        <spin_button id = "Box_case_informations_spacing_value" min = "0" max = "100" step = "5" value = "0" digits = "0"" numeric = TRUE>
    
                                                        </spin_button add_to_grid(Box_case_informations_grid, Box_case_informations_spacing_value, 3, 1, 1, 1)>
                                                        <!-- End box case informations spacing value spin button -->
    
                                                        <!-- Start box case informations add button -->
                                                        <button id = "Box_case_informations_add" label = "                                                               Add                                                               ">
    
                                                        </button add_to_grid(Box_case_informations_grid, Box_case_informations_add, 4, 0, 2, 1)>
                                                        <!-- End box case informations add button -->
    
                                                    </grid add_to_box(Box_case_informations_main_box, Box_case_informations_grid, START, TRUE, FALSE, 0, 14, 0, 0, 0)>
                                                    <!-- End box case informations grid -->
    
                                                </box add_to_frame(Box_case_informations_main_box_frame, Box_case_informations_main_box, 5, 18, 14, 0)>
                                                <!-- End box case informations main box -->

                                            </frame add_to_box(Box_case, Box_case_informations_main_box_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                            <!-- End box case informations main box frame -->


                                        </box add_to_box(Containers_box, Box_case, START, TRUE, TRUE, 0, 14, 0, 0, 0)>
                                        <!-- End box Case -->

                                        <!-- Start fixed box -->
                                        <box id = "Fixed_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>

                                            <!-- Start fixed label frame -->
                                            <frame id = "Fixed_label_frame" label = "Fixed" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                <!-- Start fixed label -->
                                                <label id = "Fixed_label" text = "Fixed" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                </label add_to_frame(Fixed_label_frame, Fixed_label, 5, 5, 0, 0)>
                                                <!-- End fixed label -->

                                            </frame add_to_box(Fixed_box, Fixed_label_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0)>
                                            <!-- End fixed label frame -->

                                            <!-- Start fixed grid frame -->
                                            <frame id = "Fixed_grid_frame" label = "Fixed" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                <!-- Start fixed grid -->
                                                <grid id = "Fixed_grid" rows_spacing = 7 columns_spacing = 7 rows_homogeneous = TRUE columns_homogeneous = FALSE>
    
                                                    <!-- Start fixed id label -->
                                                    <label id = "Fixed_id_label" text = "Widget ID" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                    </label add_to_grid(Fixed_grid, Fixed_id_label, 0, 0, 1, 1)>
                                                    <!-- End fixed id label -->

                                                    <!-- Start fixed id entry -->
                                                    <entry id = "Fixed_id_entry" default_text = NULL indicator_text = "must be unique and no space" visible = TRUE editable = TRUE max_lenght = 5 alignment = 0.5>
    
                                                    </entry add_to_grid(Fixed_grid, Fixed_id_entry, 0, 1, 1, 1)>
                                                    <!-- End fixed id entry -->

                                                    <!-- Start fixed add button  -->
                                                    <button id = "Fixed_add" label = "                                                               Add                                                               ">
    
                                                    </button add_to_grid(Fixed_grid, Fixed_add, 1, 0, 2, 1)>
                                                    <!-- End fixed add button  -->
    
                                                </grid add_to_frame(Fixed_grid_frame, Fixed_grid, 14, 14, 14, 0)>
                                                <!-- End fixed grid -->

                                            </frame add_to_box(Fixed_box, Fixed_grid_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0)>
                                            <!-- End fixed grid frame -->


                                        </box add_to_box(Containers_box, Fixed_box, START, TRUE, TRUE, 0, 14, 0, 0, 0)>
                                        <!-- End fixed box -->

                                        <!-- Start frame box -->
                                        <box id = "Frame_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>

                                            <!-- Start frame label frame -->
                                            <frame id = "Frame_label_frame" label = "Frame" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                <!-- Start frame label -->
                                                <label id = "Frame_label" text = "Frame" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                </label add_to_frame(Frame_label_frame, Frame_label, 5, 5, 0, 0)>
                                                <!-- End frame label -->

                                            </frame add_to_box(Frame_box, Frame_label_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0)>
                                            <!-- End frame label frame -->

                                            <!-- Start frame grid frame -->
                                            <frame id = "Frame_grid_frame" label = "Frame" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                <!-- Start frame grid -->
                                                <grid id = "Frame_grid" rows_spacing = 7 columns_spacing = 7 rows_homogeneous = TRUE columns_homogeneous = FALSE>
    
                                                    <!-- Start frame id label -->
                                                    <label id = "Frame_id_label" text = "Widget ID" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                    </label add_to_grid(Frame_grid, Frame_id_label, 0, 0, 1, 1)>
                                                    <!-- End frame id label -->

                                                    <!-- Start frame id entry -->
                                                    <entry id = "Frame_id_entry" default_text = NULL indicator_text = "must be unique and no space" visible = TRUE editable = TRUE max_lenght = 5 alignment = 0.5>
    
                                                    </entry add_to_grid(Frame_grid, Frame_id_entry, 0, 1, 1, 1)>
                                                    <!-- End frame id entry -->
                                                    
                                                    <!-- Start frame title label -->
                                                    <label id = "Frame_title_label" text = "Title" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                    </label add_to_grid(Frame_grid, Frame_title_label, 1, 0, 1, 1)>
                                                    <!-- End frame title label -->
    
                                                    <!-- Start frame title value entry -->
                                                    <entry id = "Frame_title_value" max_length = "20" editable = TRUE>
    
                                                    </entry add_to_grid(Frame_grid, Frame_title_value, 1, 1, 1, 1)>
                                                    <!-- End frame title value entry -->
    
                                                    <!-- Start frame horizontal placement label -->
                                                    <label id = "Frame_horizontal_placement_label" text = "Horizontal placement" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                    </label add_to_grid(Frame_grid, Frame_horizontal_placement_label, 2, 0, 1, 1)>
                                                    <!-- End frame horizontal placement label -->
    
                                                    <!-- Start frame horizontal placement value spin button -->
                                                    <spin_button id = "Frame_horizontal_placement_value" min = "0" max = "1" step = "0.5" value = "0.5" digits = "1" numeric = TRUE>
    
                                                    </spin_button add_to_grid(Frame_grid, Frame_horizontal_placement_value, 2, 1, 1, 1)>
                                                    <!-- End frame horizontal placement value spin button -->
    
                                                    <!-- Start frame vertical placement label -->
                                                    <label id = "Frame_vertical_placement_label" text = "Vertical placement" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                    </label add_to_grid(Frame_grid, Frame_vertical_placement_label, 3, 0, 1, 1)>
                                                    <!-- End frame vertical placement label -->
    
                                                    <!-- Start frame vertical placement value spin button -->
                                                    <spin_button id = "Frame_vertical_placement_value" min = "0" max = "1" step = "0.5" value = "0.5" digits = "1" numeric = TRUE>
    
                                                    </spin_button add_to_grid(Frame_grid, Frame_vertical_placement_value, 3, 1, 1, 1)>
                                                    <!-- End frame vertical placement value spin button -->
    
    
                                                    <!-- Start frame add button  -->
                                                    <button id = "Frame_add" label = "                                                               Add                                                               ">
    
                                                    </button add_to_grid(Frame_grid, Frame_add, 4, 0, 2, 1)>
                                                    <!-- End frame add button  -->
    
                                                </grid add_to_frame(Frame_grid_frame, Frame_grid, 14, 14, 14, 0)>
                                                <!-- End frame grid -->

                                            </frame add_to_box(Frame_box, Frame_grid_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0)>
                                            <!-- End frame grid frame -->

                                        </box add_to_box(Containers_box, Frame_box, START, TRUE, TRUE, 0, 14, 0, 0, 0)>
                                        <!-- End frame box -->

                                        <!-- Start grid box -->
                                        <box id = "Grid_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>

                                            <!-- Start grid label frame -->
                                            <frame id = "Grid_label_frame" label = "Grid" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                <!-- Start grid label -->
                                                <label id = "Grid_label" text = "Grid" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                </label add_to_frame(Grid_label_frame, Grid_label, 5, 5, 0, 0)>
                                                <!-- End grid label -->

                                            </frame add_to_box(Grid_box, Grid_label_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0)>
                                            <!-- End grid label frame -->

                                            <!-- Start grid grid frame -->
                                            <frame id = "Grid_grid_frame" label = "Grid" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                <!-- Start grid grid -->
                                                <grid id = "Grid_grid" rows_spacing = 7 columns_spacing = 7 rows_homogeneous = TRUE columns_homogeneous = FALSE>
    
                                                    <!-- Start grid id label -->
                                                    <label id = "Grid_id_label" text = "Widget ID" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                    </label add_to_grid(Grid_grid, Grid_id_label, 0, 0, 1, 1)>
                                                    <!-- End grid id label -->

                                                    <!-- Start grid id entry -->
                                                    <entry id = "Grid_id_entry" default_text = NULL indicator_text = "must be unique and no space" visible = TRUE editable = TRUE max_lenght = 5 alignment = 0.5>
    
                                                    </entry add_to_grid(Grid_grid, Grid_id_entry, 0, 1, 1, 1)>
                                                    <!-- End grid id entry -->

                                                    <!-- Start grid rows spacing label  -->
                                                    <label id = "Grid_rows_spacing_label" text = "Rows spacing" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                    </label add_to_grid(Grid_grid, Grid_rows_spacing_label, 1, 0, 1, 1)>
                                                    <!-- End grid rows spacing label  -->
    
                                                    <!-- Start grid rows spacing value spin button  -->
                                                    <spin_button id = "Grid_rows_spacing_value" min = "0" max = "100" step = "5" value = "0" digits = 0 numeric = TRUE>
    
                                                    </spin_button add_to_grid(Grid_grid, Grid_rows_spacing_value, 1, 1, 1, 1)>
                                                    <!-- End grid rows spacing value spin button  -->
    
                                                    <!-- Start grid columns spacing label  -->
                                                    <label id = "Grid_columns_spacing_label" text = "Columns spacing" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                    </label add_to_grid(Grid_grid, Grid_columns_spacing_label, 2, 0, 1, 1)>
                                                    <!-- End grid columns spacing label  -->
    
                                                    <!-- Start grid columns spacing value spin button  -->
                                                    <spin_button id = "Grid_columns_spacing_value" min = "0" max = "100" step = "5" value = "0" digits = 0 numeric = TRUE>
    
                                                    </spin_button add_to_grid(Grid_grid, Grid_columns_spacing_value, 2, 1, 1, 1)>
                                                    <!-- End grid columns spacing value spin button  -->
    
                                                    <!-- Start grid rows homogeneous label  -->
                                                    <label id = "Grid_rows_homogeneous_label" text = "Rows homogeneous" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                    </label add_to_grid(Grid_grid, Grid_rows_homogeneous_label, 3, 0, 1, 1)>
                                                    <!-- End grid rows homogeneous label  -->
    
                                                    <!-- Start grid rows homogeneous value combo box  -->
                                                    <combo_box id = "Grid_rows_homogeneous_value">
                                                        
                                                        <!-- Start grid rows homogeneous value combo box item  -->
                                                        <combo_box_item id = "Grid_rows_homogeneous_value_item" label = "TRUE">
                                                        
                                                        </combo_box_item add_to_combo_box(Grid_rows_homogeneous_value, "TRUE")>
                                                        <!-- End grid rows homogeneous value combo box item  -->
    
                                                        <!-- Start grid rows homogeneous value combo box item  -->
                                                        <combo_box_item id = "Grid_rows_homogeneous_value_item" label = "FALSE">
                                                        
                                                        </combo_box_item add_to_combo_box(Grid_rows_homogeneous_value, "FALSE")>
                                                        <!-- End grid rows homogeneous value combo box item  -->
    
                                                    </combo_box add_to_grid(Grid_grid, Grid_rows_homogeneous_value, 3, 1, 1, 1)>
                                                    <!-- End grid rows homogeneous value combo box  -->
    
                                                    <!-- Start grid columns homogeneous label  -->
                                                    <label id = "Grid_columns_homogeneous_label" text = "Columns homogeneous" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                    </label add_to_grid(Grid_grid, Grid_columns_homogeneous_label, 4, 0, 1, 1)>
                                                    <!-- End grid columns homogeneous label  -->
    
                                                    <!-- Start grid columns homogeneous value combo box  -->
                                                    <combo_box id = "Grid_columns_homogeneous_value">
                                                        
                                                        <!-- Start grid columns homogeneous value combo box item  -->
                                                        <combo_box_item id = "Grid_columns_homogeneous_value_item" label = "TRUE">
                                                        
                                                        </combo_box_item add_to_combo_box(Grid_columns_homogeneous_value, "TRUE")>
                                                        <!-- End grid columns homogeneous value combo box item  -->
    
                                                        <!-- Start grid columns homogeneous value combo box item  -->
                                                        <combo_box_item id = "Grid_columns_homogeneous_value_item" label = "FALSE">
                                                        
                                                        </combo_box_item add_to_combo_box(Grid_columns_homogeneous_value, "FALSE")>
                                                        <!-- End grid columns homogeneous value combo box item  -->
    
                                                    </combo_box add_to_grid(Grid_grid, Grid_columns_homogeneous_value, 4, 1, 1, 1)>
                                                    <!-- End grid columns homogeneous value combo box  -->
    
                                                    <!-- Start grid add button  -->
                                                    <button id = "Grid_add" label = "                                                               Add                                                               ">
    
                                                    </button add_to_grid(Grid_grid, Grid_add, 5, 0, 2, 1)>
                                                    <!-- End fixed add button  -->
    
                                                </grid add_to_frame(Grid_grid_frame, Grid_grid, 14, 14, 14, 0)>
                                                <!-- End grid grid -->

                                            </frame add_to_box(Grid_box, Grid_grid_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0)>
                                            <!-- End grid grid frame -->


                                        </box add_to_box(Containers_box, Grid_box, START, TRUE, TRUE, 0, 14, 0, 0, 0)>
                                        <!-- End grid box -->

                                        <!-- Start paned box -->
                                        <box id = "Paned_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>

                                            <!-- Start paned label frame -->
                                            <frame id = "Paned_label_frame" label = "Paned" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                <!-- Start paned label -->
                                                <label id = "Paned_label" text = "Paned" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                </label add_to_frame(Paned_label_frame, Paned_label, 7, 7, 14, 0)>
                                                <!-- End paned label -->

                                            </frame add_to_box(Paned_box, Paned_label_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0)>
                                            <!-- End paned label frame -->

                                            <!-- Start paned grid frame -->
                                            <frame id = "Paned_grid_frame" label = "Paned" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                <!-- Start grid paned -->
                                                <grid id = "Paned_grid" rows_spacing = 7 columns_spacing = 7 rows_homogeneous = TRUE columns_homogeneous = FALSE>
    
                                                    <!-- Start paned id label -->
                                                    <label id = "Paned_id_label" text = "ID" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(Paned_grid, Paned_id_label, 0, 0, 1, 1)>
                                                    <!-- End paned id label -->

                                                    <!-- Start paned id value entry  -->
                                                    <entry id = "Paned_id_value" default_text = NULL indicator_text = "must be unique and no space" visible = TRUE editable = TRUE max_lenght = 5 alignment = 0.5>

                                                    </entry add_to_grid(Paned_grid, Paned_id_value, 0, 1, 1, 1)>
                                                    <!-- End paned id value entry  -->

                                                    <!-- Start paned orientation label  -->
                                                    <label id = "Paned_orientation_label" text = "Orientation" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                    </label add_to_grid(Paned_grid, Paned_orientation_label, 1, 0, 1, 1)>
                                                    <!-- End paned orientation label  -->
    
                                                    <!-- Start paned orientation value combo box  -->
                                                    <combo_box id = "Paned_orientation_value">
                                                        
                                                        <!-- Start paned orientation value combo box item  -->
                                                        <combo_box_item id = "Paned_orientation_value_item" label = "GTK_ORIENTATION_HORIZONTAL">
                                                        
                                                        </combo_box_item add_to_combo_box(Paned_orientation_value, "GTK_ORIENTATION_HORIZONTAL")>
                                                        <!-- End paned orientation value combo box item  -->
    
                                                        <!-- Start paned orientation value combo box item  -->
                                                        <combo_box_item id = "Paned_orientation_value_item" label = "GTK_ORIENTATION_VERTICAL">
                                                        
                                                        </combo_box_item add_to_combo_box(Paned_orientation_value, "GTK_ORIENTATION_VERTICAL")>
                                                        <!-- End paned orientation value combo box item  -->
    
                                                    </combo_box add_to_grid(Paned_grid, Paned_orientation_value, 1, 1, 1, 1)>
                                                    <!-- End paned orientation value combo box  -->
    
                                                    <!-- Start paned default position label  -->
                                                    <label id = "Paned_default_position_label" text = "Default position" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                    </label add_to_grid(Paned_grid, Paned_default_position_label, 2, 0, 1, 1)>
                                                    <!-- End paned default position label  -->
    
                                                    <!-- Start paned default position value spin button  -->
                                                    <spin_button id = "Paned_default_position_value" min = "0" max = "1000" step = "100" value = "500" digits = 0 numeric = TRUE>
    
                                                    </spin_button add_to_grid(Paned_grid, Paned_default_position_value, 2, 1, 1, 1)>
                                                    <!-- End paned default position value spin button  -->
    
                                                    <!-- Start paned show handle label -->
                                                    <label id = "Paned_show_handle_label" text = "Show Handle" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                    </label add_to_grid(Paned_grid, Paned_show_handle_label, 3, 0, 1, 1)>
                                                    <!-- End paned show handle label -->
    
                                                    <!-- Start paned show handle combo box -->
                                                    <combo_box id = "Paned_show_handle_combo_box">
    
                                                        <!-- Start paned show handle combo box item -->
                                                        <combo_box_item id = "combo_box_item">
    
                                                        </combo_box_item add_to_combo_box(Paned_show_handle_combo_box, "TRUE")>
                                                        <!-- End paned show handle combo box item -->
    
                                                        <!-- Start paned show handle combo box item -->
                                                        <combo_box_item id = "combo_box_item">
    
                                                        </combo_box_item add_to_combo_box(Paned_show_handle_combo_box, "FALSE")>
                                                        <!-- End paned show handle combo box item -->
    
                                                    </combo_box add_to_grid(Paned_grid, Paned_show_handle_combo_box, 3, 1, 1, 1)>
                                                    <!-- End paned show handle combo box -->
    
                                                    <!-- Start paned add button  -->
                                                    <button id = "Paned_add" label = "                                                               Add                                                               ">
    
                                                    </button add_to_grid(Paned_grid, Paned_add, 4, 0, 2, 1)>
                                                    <!-- End fixed add button  -->
                                                    
                                                </grid add_to_frame(Paned_grid_frame, Paned_grid, 14, 14, 14, 0)>
                                                <!-- End grid paned -->

                                            </frame add_to_box(Paned_box, Paned_grid_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0)>
                                            <!-- End paned grid frame -->

                                        </box add_to_box(Containers_box, Paned_box, START, TRUE, TRUE, 0, 14, 0, 0, 0)>
                                        <!-- End paned box -->

                                        <!-- Start stack box -->
                                        <box id = "Stack_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>

                                            <!-- Start stack label frame -->
                                            <frame id = "Stack_label_frame" label = "Stack" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                <!-- Start Stack label -->
                                                <label id = "Stack_label" text = "Stack" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                </label add_to_frame(Stack_label_frame, Stack_label, 7, 7, 14, 0)>
                                                <!-- End Stack label -->

                                            </frame add_to_box(Stack_box, Stack_label_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0)>
                                            <!-- End stack label frame -->

                                            <!-- Start stack grid frame -->
                                            <frame id = "Stack_grid_frame" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                <!-- Start Stack grid -->
                                                <grid id = "Stack_grid" rows_spacing = 7 columns_spacing = 7 rows_homogeneous = TRUE columns_homogeneous = FALSE>
    
                                                    <!-- Start stack switcher-widget label -->
                                                    <label id = "stack_switcher_widget_label" text = "Widget ID" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                    </label add_to_grid(Stack_grid, stack_switcher_widget_label, 0, 0, 1, 1)>
                                                    <!-- End Stack switcher-widget label -->
    
                                                    <!-- Start stack switcher-widget entry value -->
                                                    <entry id = "stack_switcher_widget_entry" default_text = NULL indicator_text = "must be unique and no space" visible = TRUE editable = TRUE max_lenght = 5 alignment = 0.5>
    
                                                    </entry add_to_grid(Stack_grid, stack_switcher_widget_entry, 0, 1, 1, 1)>
                                                    <!-- End stack switcher-widget entry value -->
    
                                                    <!-- Start stack transition type label -->
                                                    <label id = "stack_transition_type_label" text = "Transition Type"  size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                    </label add_to_grid(Stack_grid, stack_transition_type_label, 1, 0, 1, 1)>
                                                    <!-- End stack transition type label -->
    
                                                    <!-- Start stack transition type value combo box -->
                                                    <combo_box id = "stack_transition_type_value_combo_box">
    
                                                        <!-- Start stack transition type value combo box item -->
                                                        <combo_box_item id = "stack_transition_type_value_combo_box_item">
    
                                                        </combo_box_item add_to_combo_box(stack_transition_type_value_combo_box, "GTK_STACK_TRANSITION_TYPE_CROSSFADE")>
                                                        <!-- End stack transition type value combo box item -->
    
                                                        <!-- Start stack transition type value combo box item -->
                                                        <combo_box_item id = "stack_transition_type_value_combo_box_item">
    
                                                        </combo_box_item add_to_combo_box(stack_transition_type_value_combo_box, "GTK_STACK_TRANSITION_TYPE_NONE")>
                                                        <!-- End stack transition type value combo box item -->
    
                                                        <!-- Start stack transition type value combo box item -->
                                                        <combo_box_item id = "stack_transition_type_value_combo_box_item">
    
                                                        </combo_box_item add_to_combo_box(stack_transition_type_value_combo_box, "GTK_STACK_TRANSITION_TYPE_SLIDE_LEFT")>
                                                        <!-- End stack transition type value combo box item -->
    
                                                        <!-- Start stack transition type value combo box item -->
                                                        <combo_box_item id = "stack_transition_type_value_combo_box_item">
    
                                                        </combo_box_item add_to_combo_box(stack_transition_type_value_combo_box, "GTK_STACK_TRANSITION_TYPE_SLIDE_RIGHT")>
                                                        <!-- End stack transition type value combo box item -->
    
                                                    </combo_box add_to_grid(Stack_grid, stack_transition_type_value_combo_box, 1, 1, 1, 1)>
                                                    <!-- End stack transition type value combo box -->
    
                                                    <!-- Start stack duration label -->
                                                    <label id = "stack_duration_label" text = "Duration"  size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                    </label add_to_grid(Stack_grid, stack_duration_label, 2, 0, 1, 1)>
                                                    <!-- End stack duration label -->
    
                                                    <!-- Start stack duration value spin button -->
                                                    <spin_button id = "stack_duration_value_spin_button" min = "0" max = "1000" step = "100" value = "500" digits = 0 numeric = TRUE>
    
                                                    </spin_button add_to_grid(Stack_grid, stack_duration_value_spin_button, 2, 1, 1, 1)>
                                                    <!-- End stack duration value spin button -->
    
                                                    <!-- Start stack informations add button -->
                                                    <button id = "stack_informations_add_button" label = "                                                               Add                                                               ">
    
                                                    </button add_to_grid(Stack_grid, stack_informations_add_button, 3, 0, 2, 1)>
                                                    <!-- End stack informations add button -->
    
                                                </grid add_to_frame(Stack_grid_frame, Stack_grid, 14, 14, 14, 14)>
                                                <!-- End Stack grid -->

                                            </frame add_to_box(Stack_box, Stack_grid_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0)>
                                            <!-- End stack grid frame -->


                                        </box add_to_box(Containers_box, Stack_box, START, TRUE, TRUE, 0, 14, 0, 0, 0)>
                                        <!-- End stack box -->

                                        <!-- Start switcher box -->
                                        <box id = "Switcher_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>

                                            <!-- Start switcher label frame -->
                                            <frame id = "Switcher_label_frame" label = "Switcher" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                <!-- Start switcher label -->
                                                <label id = "Switcher_label" text = "Switcher"  size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                </label add_to_frame(Switcher_label_frame, Switcher_label, 7, 7, 14, 0)>
                                                <!-- End switcher label -->

                                            </frame add_to_box(Switcher_box, Switcher_label_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0)>
                                            <!-- End switcher label frame -->

                                            <!-- Start switcher grid frame -->
                                            <frame id = "Switcher_grid_frame" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                <!-- Start Switcher grid -->
                                                <grid id = "Switcher_grid" rows_spacing = 7 columns_spacing = 7 rows_homogeneous = TRUE columns_homogeneous = FALSE>
    
                                                    <!-- Start switcher id label -->
                                                    <label id = "switcher_id_label" text = "Widget ID" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                    </label add_to_grid(Switcher_grid, switcher_id_label, 0, 0, 1, 1)>
                                                    <!-- End switcher id label -->

                                                    <!-- Start switcher id entry value -->
                                                    <entry id = "switcher_id_entry" default_text = NULL indicator_text = "must be unique and no space" visible = TRUE editable = TRUE max_lenght = 5 alignment = 0.5>
    
                                                    </entry add_to_grid(Switcher_grid, switcher_id_entry, 0, 1, 1, 1)>
                                                    <!-- End switcher id entry value -->

                                                    <!-- Start switcher spacing label -->
                                                    <label id = "switcher_spacing_label" text = "Spacing" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                    </label add_to_grid(Switcher_grid, switcher_spacing_label, 1, 0, 1, 1)>
                                                    <!-- End switcher spacing label -->
    
                                                    <!-- Start switcher spacing value spin button -->
                                                    <spin_button id = "switcher_spacing_value_spin_button" min = 0 max = 100 step = 5 value = 5 digits = 0 numeric = TRUE>
    
                                                    </spin_button add_to_grid(Switcher_grid, switcher_spacing_value_spin_button, 1, 1, 1, 1)>
                                                    <!-- End switcher spacing value spin button -->
    
                                                    <!-- Start same size label -->
                                                    <label id = "same_size_label" text = "Same Size" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                    </label add_to_grid(Switcher_grid, same_size_label, 2, 0, 1, 1)>
                                                    <!-- End same size label -->
    
                                                    <!-- Start same size value combo box -->
                                                    <combo_box id = "same_size_value_combo_box">
    
                                                        <!-- Start same size value combo box item -->
                                                        <combo_box_item id = "combo_box_item">
    
                                                        </combo_box_item add_to_combo_box(same_size_value_combo_box, "TRUE")>
                                                        <!-- End same size value combo box item -->
    
                                                        <!-- Start same size value combo box item -->
                                                        <combo_box_item id = "combo_box_item">
    
                                                        </combo_box_item add_to_combo_box(same_size_value_combo_box, "FALSE")>
                                                        <!-- End same size value combo box item -->
    
                                                    </combo_box add_to_grid(Switcher_grid, same_size_value_combo_box, 2, 1, 1, 1)>
                                                    <!-- End same size value combo box -->
    
                                                    <!-- Start switcher informations add button -->
                                                    <button id = "switcher_informations_add_button" label = "                                                               Add                                                               ">
    
                                                    </button add_to_grid(Switcher_grid, switcher_informations_add_button, 3, 0, 2, 1)>
                                                    <!-- End switcher informations add button -->
    
                                                </grid add_to_frame(Switcher_grid_frame, Switcher_grid, 14, 14, 14, 14)>
                                                <!-- End Switcher grid -->

                                            </frame add_to_box(Switcher_box, Switcher_grid_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0)>
                                            <!-- End switcher grid frame -->
                                            

                                        </box add_to_box(Containers_box, Switcher_box, START, TRUE, TRUE, 0, 14, 0, 0, 0)>
                                        <!-- End switcher box -->

                                    </box add_to_scrolled_window(scrolled_containers_window, Containers_box)>
                                    <!-- End Windows box -->

                                </scrolled_window add_to_stack(stack_catalog, scrolled_containers_window, "Containers")>
                                <!-- End Scrolled Containers window -->


                                <!-- Start Scrolled Widgets window -->
                                <scrolled_window id = "scrolled_widgets_window" horizontal = FALSE vertical = TRUE>

                                    <!-- Start Widgets box -->
                                    <box id = "Widgets_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 7>

                                        <!-- Start the button box -->
                                        <box id = "button_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>

                                            <!-- Start button label frame -->
                                            <frame id = "button_label_frame" label = "Button" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                <!-- Start button label --> 
                                                <label id = "button_label" text = "Button"  size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                </label add_to_frame(button_label_frame, button_label, 7, 7, 14, 0)>
                                                <!-- End button label -->

                                            </frame add_to_box(button_box, button_label_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0)>
                                            <!-- End button label frame -->

                                            <!-- Start button grid frame -->
                                            <frame id = "button_grid_frame" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                <!-- Start button grid -->
                                                <grid id = "button_grid" rows_spacing = 7 columns_spacing = 7 rows_homogeneous = TRUE columns_homogeneous = FALSE>

                                                    <!-- Start button id label -->
                                                    <label id = "button_id_label" text = "Widget ID" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(button_grid, button_id_label, 0, 0, 1, 1)>
                                                    <!-- End button id label -->

                                                    <!-- Start button id entry value -->
                                                    <entry id = "button_id_entry" default_text = NULL indicator_text = "must be unique and no space" visible = TRUE editable = TRUE max_lenght = 5 alignment = 0.5>

                                                    </entry add_to_grid(button_grid, button_id_entry, 0, 1, 1, 1)>
                                                    <!-- End button id entry value -->


                                                    <!-- Start button relief label -->
                                                    <label id = "button_relief_label" text = "Relief" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                    </label add_to_grid(button_grid, button_relief_label, 1, 0, 1, 1)>
                                                    <!-- End button relief label -->
    
                                                    <!-- Start button relief combo box -->
                                                    <combo_box id = "button_relief_combo_box">
    
                                                        <!-- Start button relief combo box item -->
                                                        <combo_box_item id = "combo_box_item">
    
                                                        </combo_box_item add_to_combo_box(button_relief_combo_box, "GTK_RELIEF_NONE")>
                                                        <!-- End button relief combo box item -->
    
                                                        <!-- Start button relief combo box item -->
                                                        <combo_box_item id = "combo_box_item">
    
                                                        </combo_box_item add_to_combo_box(button_relief_combo_box, "GTK_RELIEF_NORMAL")>
                                                        <!-- End button relief combo box item -->
                                                    
                                                    </combo_box add_to_grid(button_grid, button_relief_combo_box, 1, 1, 1, 1)>
                                                    <!-- End button relief combo box -->

                                                    <!-- Start button label label -->
                                                    <label id = "button_label_label" text = "Label" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                    </label add_to_grid(button_grid, button_label_label, 2, 0, 1, 1)>
                                                    <!-- End button label label -->

                                                    <!-- Start button label entry -->
                                                    <entry id = "button_label_entry" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                    </entry add_to_grid(button_grid, button_label_entry, 2, 1, 1, 1)>
                                                    <!-- End button label entry -->

                                                    <!-- Start button use underline label -->
                                                    <label id = "button_use_underline_label" text = "Use Underline" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                    </label add_to_grid(button_grid, button_use_underline_label, 3, 0, 1, 1)>
                                                    <!-- End button use underline label -->

                                                    <!-- Start button use underline combo box -->
                                                    <combo_box id = "button_use_underline_combo_box">
    
                                                        <!-- Start button use underline combo box item -->
                                                        <combo_box_item id = "combo_box_item">
    
                                                        </combo_box_item add_to_combo_box(button_use_underline_combo_box, "TRUE")>
                                                        <!-- End button use underline combo box item -->
    
                                                        <!-- Start button use underline combo box item -->
                                                        <combo_box_item id = "combo_box_item">
    
                                                        </combo_box_item add_to_combo_box(button_use_underline_combo_box, "FALSE")>
                                                        <!-- End button use underline combo box item -->
                                                    
                                                    </combo_box add_to_grid(button_grid, button_use_underline_combo_box, 3, 1, 1, 1)>
                                                    <!-- End button use underline combo box -->

                                                    <!-- Start button path to image label -->
                                                    <label id = "button_path_to_image_label" text = "Path to Image" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                    </label add_to_grid(button_grid, button_path_to_image_label, 4, 0, 1, 1)>
                                                    <!-- End button path to image label -->

                                                    <!-- Start button path to image entry -->
                                                    <entry id = "button_path_to_image_entry" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                    </entry add_to_grid(button_grid, button_path_to_image_entry, 4, 1, 1, 1)>
                                                    <!-- End button path to image entry -->

                                                    <!-- Start button callback label -->
                                                    <label id = "button_callback_label" text = "Callback" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                    </label add_to_grid(button_grid, button_callback_label, 5, 0, 1, 1)>
                                                    <!-- End button callback label -->

                                                    <!-- Start button callback entry -->
                                                    <entry id = "button_callback_entry" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                    </entry add_to_grid(button_grid, button_callback_entry, 5, 1, 1, 1)>
                                                    <!-- End button callback entry -->

                                                    <!-- Start button data label -->
                                                    <label id = "button_data_label" text = "Data" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                    </label add_to_grid(button_grid, button_data_label, 6, 0, 1, 1)>
                                                    <!-- End button data label -->

                                                    <!-- Start button data entry -->
                                                    <entry id = "button_data_entry" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                    </entry add_to_grid(button_grid, button_data_entry, 6, 1, 1, 1)>
                                                    <!-- End button data entry -->

                                                    <!-- Start button add button -->
                                                    <button id = "button_add" label = "                                                               Add                                                               ">

                                                    </button add_to_grid(button_grid, button_add, 7, 0, 2, 1)>
                                                    <!-- End button add button -->

                                                </grid add_to_frame(button_grid_frame, button_grid, 14, 14, 14, 14)>
                                                <!-- End button grid -->

                                            </frame add_to_box(button_box, button_grid_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0)>
                                            <!-- End button grid frame -->

                                        </box add_to_box(Widgets_box, button_box, START, FALSE, FALSE, 0, 7, 0, 0, 0)>
                                        <!-- End the button box -->

                                        <!-- Start the check button box -->
                                        <box id = "check_button_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>

                                            <!-- Start the check button label frame -->
                                            <frame id = "check_button_label_frame" label = NULL>

                                                <!-- Start the check button label -->
                                                <label id = "check_button_label" text = "Check Button" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                </label add_to_frame(check_button_label_frame, check_button_label, 7, 7, 14, 14)>
                                                <!-- End the check button label -->

                                            </frame add_to_box(check_button_box, check_button_label_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0)>
                                            <!-- End the check button label frame -->

                                            <!-- Start check button grid frame -->
                                            <frame id = "check_button_grid_frame" label = NULL>

                                                <!-- Start check button grid -->
                                                <grid id = "check_button_grid" rows_spacing = 7 column_spacing = 7 row_homogeneous = TRUE column_homogeneous = FALSE>

                                                    <!-- Start check button id label -->
                                                    <label id = "check_button_id_label" text = "Widget ID" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(check_button_grid, check_button_id_label, 0, 0, 1, 1)>
                                                    <!-- End check button id label -->

                                                    <!-- Start check button id entry -->
                                                    <entry id = "check_button_id_entry" default_text = NULL indicator_text = "must be unique and no space" visible = TRUE editable = TRUE max_lenght = 5 alignment = 0.5>
    
                                                    </entry add_to_grid(check_button_grid, check_button_id_entry, 0, 1, 1, 1)>
                                                    <!-- End check button id entry -->

                                                    <!-- Start check button label label -->
                                                    <label id = "check_button_label_label" text = "Label" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(check_button_grid, check_button_label_label, 1, 0, 1, 1)>
                                                    <!-- End check button label label -->

                                                    <!-- Start check button label entry -->
                                                    <entry id = "check_button_label_entry" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                    </entry add_to_grid(check_button_grid, check_button_label_entry, 1, 1, 1, 1)>
                                                    <!-- End check button label entry -->

                                                    <!-- Start check button active label -->
                                                    <label id = "check_button_active_label" text = "Active" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(check_button_grid, check_button_active_label, 2, 0, 1, 1)>
                                                    <!-- End check button active label -->

                                                    <!-- Start check button active combo box -->
                                                    <combo_box id = "check_button_active_combo_box" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                        <!-- Start check button active combo box item -->
                                                        <combo_box_item id = "combo_box_item">
    
                                                        </combo_box_item add_to_combo_box(check_button_active_combo_box, "TRUE")>
                                                        <!-- End check button active combo box item -->

                                                        <!-- Start check button active combo box item -->
                                                        <combo_box_item id = "combo_box_item">
    
                                                        </combo_box_item add_to_combo_box(check_button_active_combo_box, "FALSE")>
                                                        <!-- End check button active combo box item -->

                                                    </combo_box add_to_grid(check_button_grid, check_button_active_combo_box, 2, 1, 1, 1)>
                                                    <!-- End check button active combo box -->

                                                    <!-- Start check button use underline label -->
                                                    <label id = "check_button_use_underline_label" text = "Use Underline" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(check_button_grid, check_button_use_underline_label, 3, 0, 1, 1)>
                                                    <!-- End check button use underline label -->

                                                    <!-- Start check button use underline combo box -->
                                                    <combo_box id = "check_button_use_underline_combo_box" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                        <!-- Start check button use underline combo box item -->
                                                        <combo_box_item id = "combo_box_item">
    
                                                        </combo_box_item add_to_combo_box(check_button_use_underline_combo_box, "TRUE")>
                                                        <!-- End check button use underline combo box item -->

                                                        <!-- Start check button use underline combo box item -->
                                                        <combo_box_item id = "combo_box_item">
    
                                                        </combo_box_item add_to_combo_box(check_button_use_underline_combo_box, "FALSE")>
                                                        <!-- End check button use underline combo box item -->

                                                    </combo_box add_to_grid(check_button_grid, check_button_use_underline_combo_box, 3, 1, 1, 1)>
                                                    <!-- End check button use underline combo box -->

                                                    <!-- Start check button callback label -->
                                                    <label id = "check_button_callback_label" text = "Callback" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(check_button_grid, check_button_callback_label, 4, 0, 1, 1)>
                                                    <!-- End check button callback label -->

                                                    <!-- Start check button callback entry -->
                                                    <entry id = "check_button_callback_entry" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                    </entry add_to_grid(check_button_grid, check_button_callback_entry, 4, 1, 1, 1)>
                                                    <!-- End check button callback entry -->

                                                    <!-- Start check button data label -->
                                                    <label id = "check_button_data_label" text = "Data" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(check_button_grid, check_button_data_label, 5, 0, 1, 1)>
                                                    <!-- End check button data label -->

                                                    <!-- Start check button data entry -->
                                                    <entry id = "check_button_data_entry" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                    </entry add_to_grid(check_button_grid, check_button_data_entry, 5, 1, 1, 1)>
                                                    <!-- End check button data entry -->

                                                    <!-- Start check button add button -->
                                                    <button id = "check_button_add_button" label = "                                                               Add                                                               ">

                                                    </button add_to_grid(check_button_grid, check_button_add_button, 6, 0, 2, 1)>
                                                    <!-- End check button add button -->

                                                </grid add_to_frame(check_button_grid_frame, check_button_grid, 14, 14, 14, 14)>
                                                <!-- End check button grid -->

                                            </frame add_to_box(check_button_box, check_button_grid_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0)>
                                            <!-- End check button grid frame -->

                                        </box add_to_box(Widgets_box, check_button_box, START, FALSE, FALSE, 0, 0, 0, 0, 0)>
                                        <!-- End the check button box -->

                                        <!-- Start color button box -->
                                        <box id = "color_button_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>

                                            <!-- Start color button label frame -->
                                            <frame id = "color_button_label_frame">

                                                <!-- Start color button label label -->
                                                <label id = "color_button_label_label" text = "Color Button" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                </label add_to_frame(color_button_label_frame, color_button_label_label, 7, 7, 14, 0)>
                                                <!-- End color button label label -->

                                            </frame add_to_box(color_button_box, color_button_label_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0)>
                                            <!-- End color button label frame -->

                                            <!-- Start color button grid frame -->
                                            <frame id = "color_button_grid_frame" label = NULL>

                                                <!-- Start color button grid -->
                                                <grid id = "color_button_grid" rows_spacing = 7 columns_spacing = 7 rows_homogeneous = TRUE columns_homogeneous = FALSE>

                                                    <!-- Start color button id label -->
                                                    <label id = "color_button_id_label" text = "Widget ID" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(color_button_grid, color_button_id_label, 0, 0, 1, 1)>
                                                    <!-- End color button id label -->

                                                    <!-- Start color button id entry -->
                                                    <entry id = "color_button_id_entry" default_text = NULL indicator_text = "must be unique and no space" visible = TRUE editable = TRUE max_lenght = 5 alignment = 0.5>
    
                                                    </entry add_to_grid(color_button_grid, color_button_id_entry, 0, 1, 1, 1)>
                                                    <!-- End color button id entry -->

                                                    <!-- Start color button default color label -->
                                                    <label id = "color_button_default_color_label" text = "Default Color" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(color_button_grid, color_button_default_color_label, 1, 0, 1, 1)>
                                                    <!-- End color button default color label -->

                                                    <!-- Start color button default color color button -->
                                                    <color_button id = "color_button_default_color_color_button">

                                                    </color_button add_to_grid(color_button_grid, color_button_default_color_color_button, 1, 1, 1, 1)>
                                                    <!-- End color button default color color button -->

                                                    <!-- Start color button title label -->
                                                    <label id = "color_button_title_label" text = "Title" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(color_button_grid, color_button_title_label, 2, 0, 1, 1)>
                                                    <!-- End color button title label -->

                                                    <!-- Start color button label entry -->
                                                    <entry id = "color_button_label_entry" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
    
                                                    </entry add_to_grid(color_button_grid, color_button_label_entry, 2, 1, 1, 1)>
                                                    <!-- End color button label entry -->

                                                    <!-- Start color button use alpha label -->
                                                    <label id = "color_button_use_alpha_label" text = "Use Alpha" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(color_button_grid, color_button_use_alpha_label, 3, 0, 1, 1)>
                                                    <!-- End color button use alpha label -->

                                                    <!-- Start color button use alpha combo box -->
                                                    <combo_box id = "color_button_use_alpha_combo_box">
    
                                                        <!-- Start color button use alpha combo box item -->
                                                        <combo_box_item id = "combo_box_item">
        
                                                        </combo_box_item add_to_combo_box(color_button_use_alpha_combo_box, "TRUE")>
                                                        <!-- End color button use alpha combo box item -->
    
                                                        <!-- Start color button use alpha combo box item -->
                                                        <combo_box_item id = "combo_box_item">
        
                                                        </combo_box_item add_to_combo_box(color_button_use_alpha_combo_box, "FALSE")>
                                                        <!-- End color button use alpha combo box item -->               
                                                        
                                                    </combo_box add_to_grid(color_button_grid, color_button_use_alpha_combo_box, 3, 1, 1, 1)>
                                                    <!-- End color button use alpha combo box -->

                                                    <!-- Start color button add button -->
                                                    <button id = "color_button_add_button" label = "                                                               Add                                                               ">

                                                    </button add_to_grid(color_button_grid, color_button_add_button, 4, 0, 2, 1)>
                                                    <!-- End color button add button -->
        
                                                </grid add_to_frame(color_button_grid_frame, color_button_grid, 14, 14, 14, 14)>
                                                <!-- End color button grid -->

                                            </frame add_to_box(color_button_box, color_button_grid_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0)>
                                            <!-- End color button grid frame -->

                                        </box add_to_box(Widgets_box, color_button_box, START, FALSE, FALSE, 0, 0, 0, 0, 0)>
                                        <!-- End color button box -->

                                        <!-- Start combo box box -->
                                        <box id = "combo_box_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>

                                            <!-- Start combo box label frame -->
                                            <frame id = "combo_box_label_frame">

                                                <!-- Start combo box label label -->
                                                <label id = "combo_box_label_label" text = "Combo Box" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                </label add_to_frame(combo_box_label_frame, combo_box_label_label, 7, 7, 14, 0)>
                                                <!-- End combo box label label -->

                                            </frame add_to_box(combo_box_box, combo_box_label_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0)>
                                            <!-- End combo box label frame -->

                                            <!-- Start combox box grid frame -->
                                            <frame id = "combo_box_grid_frame" label = NULL>

                                                <!-- Start combo box grid -->
                                                <grid id = "combo_box_grid" rows_spacing = 7 columns_spacing = 7 rows_homogeneous = TRUE columns_homogeneous = FALSE>

                                                    <!-- Start combo box id label -->
                                                    <label id = "combo_box_id_label" text = "Widget ID" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(combo_box_grid, combo_box_id_label, 0, 0, 1, 1)>
                                                    <!-- End combo box id label -->

                                                    <!-- Start combo box id entry -->
                                                    <entry id = "combo_box_id_entry" default_text = NULL indicator_text = "must be unique and no space" visible = TRUE editable = TRUE max_lenght = 5 alignment = 0.5>
    
                                                    </entry add_to_grid(combo_box_grid, combo_box_id_entry, 0, 1, 1, 1)>
                                                    <!-- End combo box id entry -->

                                                    <!-- Start combo box item1 label -->
                                                    <label id = "combo_box_item1_label" text = "Item 1" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(combo_box_grid, combo_box_item1_label, 1, 0, 1, 1)>
                                                    <!-- End combo box item1 label -->

                                                    <!-- Start combo box item1 entry -->
                                                    <entry id = "combo_box_item1_entry" default_text = "NULL" >
    
                                                    </entry add_to_grid(combo_box_grid, combo_box_item1_entry, 1, 1, 1, 1)>
                                                    <!-- End combo box item1 entry -->

                                                    <!-- Start combo box item2 label -->
                                                    <label id = "combo_box_item2_label" text = "Item 2" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(combo_box_grid, combo_box_item2_label, 2, 0, 1, 1)>
                                                    <!-- End combo box item2 label -->

                                                    <!-- Start combo box item2 entry -->
                                                    <entry id = "combo_box_item2_entry" default_text = "NULL">
    
                                                    </entry add_to_grid(combo_box_grid, combo_box_item2_entry, 2, 1, 1, 1)>
                                                    <!-- End combo box item2 entry -->

                                                    <!-- Start combo box item3 label -->
                                                    <label id = "combo_box_item3_label" text = "Item 3" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(combo_box_grid, combo_box_item3_label, 3, 0, 1, 1)>
                                                    <!-- End combo box item3 label -->

                                                    <!-- Start combo box item3 entry -->
                                                    <entry id = "combo_box_item3_entry" default_text = "NULL">
    
                                                    </entry add_to_grid(combo_box_grid, combo_box_item3_entry, 3, 1, 1, 1)>
                                                    <!-- End combo box item3 entry -->

                                                    <!-- Start combo box add button -->
                                                    <button id = "combo_box_add_button" label = "                                                               Add                                                               ">

                                                    </button add_to_grid(combo_box_grid, combo_box_add_button, 4, 0, 2, 1)>
                                                    <!-- End combo box add button -->

                                                </grid add_to_frame(combo_box_grid_frame, combo_box_grid, 14, 14, 14, 14)>
                                                <!-- End combo box grid -->

                                            </frame add_to_box(combo_box_box, combo_box_grid_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0)>
                                            <!-- End combox box grid frame -->

                                        </box add_to_box(Widgets_box, combo_box_box, START, FALSE, FALSE, 0, 0, 0, 0, 0)>
                                        <!-- End combo box box -->

                                        <!-- Start entry box -->
                                        <box id = "entry_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>

                                            <!-- Start entry label frame -->
                                            <frame id = "entry_label_frame">

                                                <!-- Start entry label label -->
                                                <label id = "entry_label_label" text = "Entry" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                </label add_to_frame(entry_label_frame, entry_label_label, 7, 7, 14, 0)>
                                                <!-- End entry label label -->

                                            </frame add_to_box(entry_box, entry_label_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0)>
                                            <!-- End entry label frame -->

                                            <!-- Start entry box grid frame -->
                                            <frame id = "entry_box_grid_frame" label = NULL>

                                                <!-- Start entry box grid -->
                                                <grid id = "entry_box_grid" rows_spacing = 7 columns_spacing = 7 rows_homogeneous = TRUE columns_homogeneous = FALSE>

                                                    <!-- Start entry id label -->
                                                    <label id = "entry_id_label" text = "Widget ID" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(entry_box_grid, entry_id_label, 0, 0, 1, 1)>
                                                    <!-- End entry id label -->

                                                    <!-- Start entry id entry -->
                                                    <entry id = "entry_id_entry" default_text = NULL indicator_text = "must be unique and no space" visible = TRUE editable = TRUE max_lenght = 5 alignment = 0.5>
    
                                                    </entry add_to_grid(entry_box_grid, entry_id_entry, 0, 1, 1, 1)>
                                                    <!-- End entry id entry -->

                                                    <!-- Start entry default text label -->
                                                    <label id = "entry_default_text_label" text = "Default Text" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(entry_box_grid, entry_default_text_label, 1, 0, 1, 1)>
                                                    <!-- End entry default text label -->

                                                    <!-- Start entry default text entry -->
                                                    <entry id = "entry_default_text_entry" default_text = "NULL">
    
                                                    </entry add_to_grid(entry_box_grid, entry_default_text_entry, 1, 1, 1, 1)>
                                                    <!-- End entry default text entry -->

                                                    <!-- Start entry indicator text label -->
                                                    <label id = "entry_indicator_text_label" text = "Indicator Text" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(entry_box_grid, entry_indicator_text_label, 2, 0, 1, 1)>
                                                    <!-- End entry indicator text label -->

                                                    <!-- Start entry indicator text entry -->
                                                    <entry id = "entry_indicator_text_entry" default_text = "NULL">
    
                                                    </entry add_to_grid(entry_box_grid, entry_indicator_text_entry, 2, 1, 1, 1)>
                                                    <!-- End entry indicator text entry -->

                                                    <!-- Start entry visibility label -->
                                                    <label id = "entry_visibility_label" text = "Visibility" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(entry_box_grid, entry_visibility_label, 3, 0, 1, 1)>
                                                    <!-- End entry visibility label -->

                                                    <!-- Start entry visibility combo box -->
                                                    <combo_box id = "entry_visibility_combo_box">

                                                        <!-- Start entry visibility combo box item1 -->
                                                        <combo_box_item id = "entry_visibility_combo_box_item1">
    
                                                        </combo_box_item add_to_combo_box(entry_visibility_combo_box, "TRUE")>
                                                        <!-- End entry visibility combo box item1 -->

                                                        <!-- Start entry visibility combo box item2 -->
                                                        <combo_box_item id = "entry_visibility_combo_box_item2">
    
                                                        </combo_box_item add_to_combo_box(entry_visibility_combo_box, "FALSE")>
                                                        <!-- End entry visibility combo box item2 -->

                                                    </combo_box add_to_grid(entry_box_grid, entry_visibility_combo_box, 3, 1, 1, 1)>
                                                    <!-- End entry visibility combo box -->

                                                    <!-- Start entry editable label -->
                                                    <label id = "entry_editable_label" text = "Editable" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(entry_box_grid, entry_editable_label, 4, 0, 1, 1)>
                                                    <!-- End entry editable label -->

                                                    <!-- Start entry editable combo box -->
                                                    <combo_box id = "entry_editable_combo_box">

                                                        <!-- Start entry editable combo box item1 -->
                                                        <combo_box_item id = "entry_editable_combo_box_item1">
    
                                                        </combo_box_item add_to_combo_box(entry_editable_combo_box, "TRUE")>
                                                        <!-- End entry editable combo box item1 -->

                                                        <!-- Start entry editable combo box item2 -->
                                                        <combo_box_item id = "entry_editable_combo_box_item2">
    
                                                        </combo_box_item add_to_combo_box(entry_editable_combo_box, "FALSE")>
                                                        <!-- End entry editable combo box item2 -->

                                                    </combo_box add_to_grid(entry_box_grid, entry_editable_combo_box, 4, 1, 1, 1)>
                                                    <!-- End entry editable combo box -->

                                                    <!-- Start entry max length label -->
                                                    <label id = "entry_max_length_label" text = "Max Length" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(entry_box_grid, entry_max_length_label, 5, 0, 1, 1)>
                                                    <!-- End entry max length label -->

                                                    <!-- Start entry max length spin button -->
                                                    <spin_button id = "entry_max_length_spin_button" min = 0 max = 100 value = 20 step = 5 size = 12">

                                                    </spin_button add_to_grid(entry_box_grid, entry_max_length_spin_button, 5, 1, 1, 1)>
                                                    <!-- End entry max length spin button -->

                                                    <!-- Start entry alignment label -->
                                                    <label id = "entry_alignment_label" text = "Alignment" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(entry_box_grid, entry_alignment_label, 6, 0, 1, 1)>
                                                    <!-- End entry alignment label -->

                                                    <!-- Start entry alignment spin button -->
                                                    <spin_button id = "entry_alignment_spin_button" min = 0 max = 1 value = 0 digits = 1 step = 0.5>

                                                    </spin_button add_to_grid(entry_box_grid, entry_alignment_spin_button, 6, 1, 1, 1)>
                                                    <!-- End entry alignment spin button -->

                                                    <!-- Start entry add button -->
                                                    <button id = "entry_add_button" label = "                                                               Add                                                               ">

                                                    </button add_to_grid(entry_box_grid, entry_add_button, 7, 0, 2, 1)>
                                                    <!-- End entry add button -->

                                                </grid add_to_frame(entry_box_grid_frame, entry_box_grid, 14, 14, 14, 14)>
                                                <!-- End entry box grid -->

                                            </frame add_to_box(entry_box, entry_box_grid_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0)>
                                            <!-- End entry box grid frame -->

                                        </box add_to_box(Widgets_box, entry_box, START, FALSE, FALSE, 0, 0, 0, 0, 0)>
                                        <!-- End entry box -->

                                        <!-- Start font button box -->
                                        <box id = "font_button_box" orientation = GTK_ORIENTATION_VERTICAL align = GTK_ALIGN_START spacing = 0>

                                            <!-- Start font button label frame -->
                                            <frame id = "font_button_label_frame" label = NULL>

                                                <label id = "font_button_label" text = "Font Button" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                </label add_to_frame(font_button_label_frame, font_button_label, 7, 7, 14, 14)>
                                                <!-- End font button label -->

                                            </frame add_to_box(font_button_box, font_button_label_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                            <!-- End font button label frame -->

                                            <!-- Start font button grid frame -->
                                            <frame id = "font_button_grid_frame" label = NULL>

                                                <!-- Start font button grid -->
                                                <grid id = "font_button_grid" rows_spacing = 7 columns_spacing = 7 rows_homogeneous = TRUE columns_homogeneous = FALSE>

                                                    <!-- Start font button id label -->
                                                    <label id = "font_button_id_label" text = "Widget ID" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(font_button_grid, font_button_id_label, 0, 0, 1, 1)>
                                                    <!-- End font button id label -->

                                                    <!-- Start font button id entry -->
                                                    <entry id = "font_button_id_entry" default_text = NULL indicator_text = "must be unique and no space" visible = TRUE editable = TRUE max_lenght = 5 alignment = 0.5>

                                                    </entry add_to_grid(font_button_grid, font_button_id_entry, 0, 1, 1, 1)>
                                                    <!-- End font button id entry -->

                                                    <!-- Start font button default font name label -->
                                                    <label id = "font_button_default_font_name_label" text = "Default Font Name" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(font_button_grid, font_button_default_font_name_label, 1, 0, 1, 1)>
                                                    <!-- End font button default font name label -->

                                                    <!-- Start font button default font name entry -->
                                                    <entry id = "font_button_default_font_name_entry" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </entry add_to_grid(font_button_grid, font_button_default_font_name_entry, 1, 1, 1, 1)>
                                                    <!-- End font button default font name entry -->

                                                    <!-- Start font button title label -->
                                                    <label id = "font_button_title_label" text = "Title" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(font_button_grid, font_button_title_label, 2, 0, 1, 1)>
                                                    <!-- End font button title label -->

                                                    <!-- Start font button title entry -->
                                                    <entry id = "font_button_title_entry" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </entry add_to_grid(font_button_grid, font_button_title_entry, 2, 1, 1, 1)>
                                                    <!-- End font button title entry -->

                                                    <!-- Start font button show size label -->
                                                    <label id = "font_button_show_size_label" text = "Show Size" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(font_button_grid, font_button_show_size_label, 3, 0, 1, 1)>
                                                    <!-- End font button show size label -->

                                                    <!-- Start font button show size combo box -->
                                                    <combo_box id = "font_button_show_size_combo_box" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                        <!-- Start font button show size combo box item1 -->
                                                        <combo_box_item id = "font_button_show_size_combo_box_item1">
    
                                                        </combo_box_item add_to_combo_box(font_button_show_size_combo_box, "TRUE")>
                                                        <!-- End font button show size combo box item1 -->

                                                        <!-- Start font button show size combo box item2 -->
                                                        <combo_box_item id = "font_button_show_size_combo_box_item2">
    
                                                        </combo_box_item add_to_combo_box(font_button_show_size_combo_box, "FALSE")>
                                                        <!-- End font button show size combo box item2 -->

                                                    </combo_box add_to_grid(font_button_grid, font_button_show_size_combo_box, 3, 1, 1, 1)>
                                                    <!-- End font button show size combo box -->

                                                    <!-- Start font button use size label -->
                                                    <label id = "font_button_use_size_label" text = "Use Size" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(font_button_grid, font_button_use_size_label, 4, 0, 1, 1)>
                                                    <!-- End font button use size label -->

                                                    <!-- Start font button use size combo box -->
                                                    <combo_box id = "font_button_use_size_combo_box" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                        <!-- Start font button use size combo box item1 -->
                                                        <combo_box_item id = "font_button_use_size_combo_box_item1">
    
                                                        </combo_box_item add_to_combo_box(font_button_use_size_combo_box, "TRUE")>
                                                        <!-- End font button use size combo box item1 -->

                                                        <!-- Start font button use size combo box item2 -->
                                                        <combo_box_item id = "font_button_use_size_combo_box_item2">
    
                                                        </combo_box_item add_to_combo_box(font_button_use_size_combo_box, "FALSE")>
                                                        <!-- End font button use size combo box item2 -->

                                                    </combo_box add_to_grid(font_button_grid, font_button_use_size_combo_box, 4, 1, 1, 1)>
                                                    <!-- End font button use size combo box -->

                                                    <!-- Start font button use font label -->
                                                    <label id ="font_button_use_font_label" text = "Use Font" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(font_button_grid, font_button_use_font_label, 5, 0, 1, 1)>
                                                    <!-- End font button use font label -->

                                                    <!-- Start font button use font combo box -->
                                                    <combo_box id = "font_button_use_font_combo_box" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                        <!-- Start font button use font combo box item1 -->
                                                        <combo_box_item id = "font_button_use_font_combo_box_item1">
    
                                                        </combo_box_item add_to_combo_box(font_button_use_font_combo_box, "TRUE")>
                                                        <!-- End font button use font combo box item1 -->

                                                        <!-- Start font button use font combo box item2 -->
                                                        <combo_box_item id = "font_button_use_font_combo_box_item2">
    
                                                        </combo_box_item add_to_combo_box(font_button_use_font_combo_box, "FALSE")>
                                                        <!-- End font button use font combo box item2 -->

                                                    </combo_box add_to_grid(font_button_grid, font_button_use_font_combo_box, 5, 1, 1, 1)>
                                                    <!-- End font button use font combo box -->

                                                    <!-- Start font button add button -->
                                                    <button id = "font_button_add_button" label = "                                                               Add                                                               ">

                                                    </button add_to_grid(font_button_grid, font_button_add_button, 6, 0, 2, 1)>
                                                    <!-- End font button add button -->
                                                    
                                                </grid add_to_frame(font_button_grid_frame, font_button_grid, 14, 14, 14, 14)>
                                                <!-- End font button grid -->

                                            </frame add_to_box(font_button_box, font_button_grid_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                            <!-- End font button grid frame -->

                                        </box add_to_box(Widgets_box, font_button_box, START, TRUE, TRUE, 0, 7, 0, 0, 0)>
                                        <!-- End font button box -->

                                        <!-- Start image box -->
                                        <box id = "image_box" orientation = GTK_ORIENTATION_VERTICAL spacing = 0>

                                            <!-- Start image label frame -->
                                            <frame id = "image_label_frame" label = NULL>

                                                <!-- Start image label -->
                                                <label id = "image_label" text = "Image" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                </label add_to_frame(image_label_frame, image_label, 7, 7, 14, 14)>
                                                <!-- End image label -->

                                            </frame add_to_box(image_box, image_label_frame, START, TRUE, TRUE, 0, 7, 0, 0, 0)>
                                            <!-- End image label frame -->

                                            <!-- Start image grid frame -->
                                            <frame id = "image_grid_frame" label = NULL>

                                                <!-- Start image grid -->
                                                <grid id = "image_grid" rows_spacing = 7 columns_spacing = 7 rows_homogeneous = TRUE columns_homogeneous = FALSE>

                                                    <!-- Start image id label -->
                                                    <label id = "image_id_label" text = "Widget ID" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(image_grid, image_id_label, 0, 0, 1, 1)>
                                                    <!-- End image id label -->

                                                    <!-- Start image id entry -->
                                                    <entry id = "image_id_entry" default_text = NULL indicator_text = "must be unique and no space" visible = TRUE editable = TRUE max_lenght = 5 alignment = 0.5>

                                                    </entry add_to_grid(image_grid, image_id_entry, 0, 1, 1, 1)>
                                                    <!-- End image id entry -->

                                                    <!-- Start image path label -->
                                                    <label id = "image_path_label" text = "Path" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(image_grid, image_path_label, 1, 0, 1, 1)>
                                                    <!-- End image path label -->

                                                    <!-- Start image path entry -->
                                                    <entry id = "image_path_entry" default_text = NULL indicator_text = NULL visible = TRUE editable = TRUE max_lenght = 100 alignment = 0.5>

                                                    </entry add_to_grid(image_grid, image_path_entry, 1, 1, 1, 1)>
                                                    <!-- End image path entry -->

                                                    <!-- Start image add button -->
                                                    <button id = "image_add_button" label = "                                                               Add                                                               ">

                                                    </button add_to_grid(image_grid, image_add_button, 2, 0, 2, 1)>
                                                    <!-- End image add button -->

                                                </grid add_to_frame(image_grid_frame, image_grid, 14, 14, 14, 14)>
                                                <!-- End image grid -->

                                            </frame add_to_box(image_box, image_grid_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                            <!-- End image grid frame -->

                                        </box add_to_box(Widgets_box, image_box, START, TRUE, TRUE, 0, 7, 0, 0, 0)>
                                        <!-- End image box -->

                                        <!-- Start Label box -->
                                        <box id = "label_box" orientation = GTK_ORIENTATION_VERTICAL spacing = 0>

                                            <!-- Start Label label frame -->
                                            <frame id = "label_label_frame" label = NULL>

                                                <!-- Start Label label -->
                                                <label id = "label_label" text = "Label" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                </label add_to_frame(label_label_frame, label_label, 7, 7, 14, 14)>
                                                <!-- End Label label -->

                                            </frame add_to_box(label_box, label_label_frame, START, TRUE, TRUE, 0, 7, 0, 0, 0)>
                                            <!-- End Label label frame -->

                                            <!-- Start label grid frame -->
                                            <frame id = "label_grid_frame" label = NULL>

                                                <!-- Start label grid  -->
                                                <grid id = "label_grid" rows_spacing = 7 columns_spacing = 7 rows_homogeneous = TRUE columns_homogeneous = FALSE>

                                                    <!-- Start label id label -->
                                                    <label id = "label_id_label" text = "Widget ID" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(label_grid, label_id_label, 0, 0, 1, 1)>
                                                    <!-- End label id label -->

                                                    <!-- Start label id entry -->
                                                    <entry id = "label_id_entry" default_text = NULL indicator_text = "must be unique and no space" visible = TRUE editable = TRUE max_lenght = 5 alignment = 0.5>

                                                    </entry add_to_grid(label_grid, label_id_entry, 0, 1, 1, 1)>
                                                    <!-- End label id entry -->

                                                    <!-- Start label text label -->
                                                    <label id = "label_text_label" text = "Text" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(label_grid, label_text_label, 1, 0, 1, 1)>
                                                    <!-- End label text label -->

                                                    <!-- Start label text entry -->
                                                    <entry id = "label_text_entry" default_text = NULL indicator_text = NULL visible = TRUE editable = TRUE max_lenght = 100 alignment = 0.5>

                                                    </entry add_to_grid(label_grid, label_text_entry, 1, 1, 1, 1)>
                                                    <!-- End label text entry -->

                                                    <!-- Start label size label -->
                                                    <label id = "label_size_label" text = "Size" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(label_grid, label_size_label, 2, 0, 1, 1)>
                                                    <!-- End label size label -->

                                                    <!-- Start label size spin button -->
                                                    <spin_button id = "label_size_spin_button" min = 0 max = 100 step = 5 value = 0>

                                                    </spin_button add_to_grid(label_grid, label_size_spin_button, 2, 1, 1, 1)>
                                                    <!-- End label size spin button -->

                                                    <!-- Start label font label -->
                                                    <label id = "label_font_label" text = "Font" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(label_grid, label_font_label, 3, 0, 1, 1)>
                                                    <!-- End label font label -->

                                                    <!-- Start label font font button -->
                                                    <font_button id = "label_font_font_button" default_font_name = "Arial" title = "font" show_size = TRUE show_style = TRUE use_size = FALSE use_font = FALSE>

                                                    </font_button add_to_grid(label_grid, label_font_font_button, 3, 1, 1, 1)>
                                                    <!-- End label font font button -->

                                                    <!-- Start label color label -->
                                                    <label id = "label_color_label" text = "Color" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(label_grid, label_color_label, 4, 0, 1, 1)>
                                                    <!-- End label color label -->

                                                    <!-- Start label color color button -->
                                                    <color_button id = "label_color_color_button" default_color = "#FFFFFF" title = "coloring" use_alpha = TRUE>

                                                    </color_button add_to_grid(label_grid, label_color_color_button, 4, 1, 1, 1)>
                                                    <!-- End label color color button -->

                                                    <!-- Start label background label -->
                                                    <label id = "label_background_label" text = "Background" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(label_grid, label_background_label, 5, 0, 1, 1)>
                                                    <!-- End label background label -->

                                                    <!-- Start label background color button -->
                                                    <color_button id = "label_background_color_button" default_color = "#000000" title = "coloring" use_alpha = TRUE>

                                                    </color_button add_to_grid(label_grid, label_background_color_button, 5, 1, 1, 1)>
                                                    <!-- End label background color button -->

                                                    <!-- Start label justify label -->
                                                    <label id = "label_justify_label" text = "Justify" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(label_grid, label_justify_label, 6, 0, 1, 1)>
                                                    <!-- End label justify label -->

                                                    <!-- Start label justify combo box -->
                                                    <combo_box id = "label_justify_combo_box" visible = TRUE>

                                                        <!-- Start label justify combo box item -->
                                                        <combo_box_item id = "label_justify_combo_box_item">
                                                        
                                                        </combo_box_item add_to_combo_box(label_justify_combo_box, "GTK_JUSTIFY_CENTER")>
                                                        <!-- End label justify combo box -->

                                                        <!-- Start label justify combo box item -->
                                                        <combo_box_item id = "label_justify_combo_box_item">
                                                        
                                                        </combo_box_item add_to_combo_box(label_justify_combo_box, "GTK_JUSTIFY_LEFT")>
                                                        <!-- End label justify combo box -->

                                                        <!-- Start label justify combo box item -->
                                                        <combo_box_item id = "label_justify_combo_box_item">
                                                        
                                                        </combo_box_item add_to_combo_box(label_justify_combo_box, "GTK_JUSTIFY_RIGHT")>
                                                        <!-- End label justify combo box -->
                                                        
                                                    </combo_box add_to_grid(label_grid, label_justify_combo_box, 6, 1, 1, 1)>
                                                    <!-- End label justify combo box -->

                                                    <!-- Start label use underline label -->
                                                    <label id = "label_use_underline_label" text = "Use Underline" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(label_grid, label_use_underline_label, 7, 0, 1, 1)>
                                                    <!-- End label use underline label -->

                                                    <!-- Start label use underline combo box -->
                                                    <combo_box id = "label_use_underline_combo_box" visible = TRUE>

                                                        <!-- Start label use underline combo box item -->
                                                        <combo_box_item id = "label_use_underline_combo_box_item">
                                                        
                                                        </combo_box_item add_to_combo_box(label_use_underline_combo_box, "TRUE")>
                                                        <!-- End label use underline combo box -->

                                                        <!-- Start label use underline combo box item -->
                                                        <combo_box_item id = "label_use_underline_combo_box_item">
                                                        
                                                        </combo_box_item add_to_combo_box(label_use_underline_combo_box, "FALSE")>
                                                        <!-- End label use underline combo box -->

                                                    </combo_box add_to_grid(label_grid, label_use_underline_combo_box, 7, 1, 1, 1)>
                                                    <!-- End label use underline combo box -->

                                                    <!-- Start label pango weight label -->
                                                    <label id = "label_pango_weight_label" text = "Pango Weight" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(label_grid, label_pango_weight_label, 8, 0, 1, 1)>
                                                    <!-- End label pango weight label -->

                                                    <!-- Start label pango weight combo box -->
                                                    <combo_box id = "label_pango_weight_combo_box" visible = TRUE>

                                                        <!-- Start label pango weight combo box item -->
                                                        <combo_box_item id = "label_pango_weight_combo_box_item">
                                                        
                                                        </combo_box_item add_to_combo_box(label_pango_weight_combo_box, "PANGO_WEIGHT_NORMAL")>
                                                        <!-- End label pango weight combo box -->

                                                        <!-- Start label pango weight combo box item -->
                                                        <combo_box_item id = "label_pango_weight_combo_box_item">
                                                        
                                                        </combo_box_item add_to_combo_box(label_pango_weight_combo_box, "PANGO_WEIGHT_BOLD")>
                                                        <!-- End label pango weight combo box -->

                                                    </combo_box add_to_grid(label_grid, label_pango_weight_combo_box, 8, 1, 1, 1)>
                                                    <!-- End label pango weight combo box -->

                                                    <!-- Start label pango style label -->
                                                    <label id = "label_pango_style_label" text = "Pango Style" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(label_grid, label_pango_style_label, 9, 0, 1, 1)>
                                                    <!-- End label pango style label -->

                                                    <!-- Start label pango style combo box -->
                                                    <combo_box id = "label_pango_style_combo_box">

                                                        <!-- Start label pango style combo box item -->
                                                        <combo_box_item id = "label_pango_style_combo_box_item">
                                                        
                                                        </combo_box_item add_to_combo_box(label_pango_style_combo_box, "PANGO_STYLE_NORMAL")>
                                                        <!-- End label pango style combo box -->

                                                        <!-- Start label pango style combo box item -->
                                                        <combo_box_item id = "label_pango_style_combo_box_item">
                                                        
                                                        </combo_box_item add_to_combo_box(label_pango_style_combo_box, "PANGO_STYLE_ITALIC")>
                                                        <!-- End label pango style combo box -->

                                                    </combo_box add_to_grid(label_grid, label_pango_style_combo_box, 9, 1, 1, 1)>
                                                    <!-- End label pango style combo box -->

                                                    <!-- Start label wrap label -->
                                                    <label id = "label_wrap_label" text = "Wrap" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(label_grid, label_wrap_label, 10, 0, 1, 1)>
                                                    <!-- End label wrap label -->

                                                    <!-- Start label wrap combo box -->
                                                    <combo_box id = "label_wrap_combo_box">

                                                        <!-- Start label wrap combo box item -->
                                                        <combo_box_item id = "label_wrap_combo_box_item">
                                                        
                                                        </combo_box_item add_to_combo_box(label_wrap_combo_box, "TRUE")>
                                                        <!-- End label wrap combo box -->

                                                        <!-- Start label wrap combo box item -->
                                                        <combo_box_item id = "label_wrap_combo_box_item">
                                                        
                                                        </combo_box_item add_to_combo_box(label_wrap_combo_box, "FALSE")>
                                                        <!-- End label wrap combo box -->

                                                    </combo_box add_to_grid(label_grid, label_wrap_combo_box, 10, 1, 1, 1)>
                                                    <!-- End label wrap combo box -->

                                                    <!-- Start label button add -->
                                                    <button id = "label_button_add" label = "                                                               Add                                                               ">

                                                    </button add_to_grid(label_grid, label_button_add, 11, 0, 2, 1)>
                                                    <!-- End label button add -->

                                                </grid add_to_frame(label_grid_frame, label_grid, 14, 14, 14, 14)>
                                                <!-- End label grid -->

                                            </frame add_to_box(label_box, label_grid_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                            <!-- End label grid frame -->

                                        </box add_to_box(Widgets_box, label_box, START, TRUE, TRUE, 0, 7, 0, 0, 0)>
                                        <!-- End Label box -->

                                        <!-- Start level_bar box -->
                                        <box id = "level_bar_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>

                                            <!-- Start level_bar label frame -->
                                            <frame id = "level_bar_label_frame" label = NULL>

                                                <!-- Start level_bar label -->
                                                <label id = "level_bar_label" text = "Level Bar" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
                                                    
                                                </label add_to_frame(level_bar_label_frame, level_bar_label, 7, 7, 14, 0)>
                                                <!-- End level_bar label -->

                                            </frame add_to_box(level_bar_box, level_bar_label_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                            <!-- End level_bar label frame -->

                                            <!-- Start level_bar grid frame -->
                                            <frame id = "level_bar_grid_frame" label = NULL>

                                                <!-- Start level_bar grid -->
                                                <grid id = "level_bar_grid" visible = TRUE rows_spacing = 7 columns_spacing = 7 rows_homogeneous = TRUE columns_homogeneous = FALSE>

                                                    <!-- Start level_bar id label -->
                                                    <label id = "level_bar_id_label" text = "Widget ID" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(level_bar_grid, level_bar_id_label, 0, 0, 1, 1)>
                                                    <!-- End level_bar id label -->

                                                    <!-- Start level_bar id entry -->
                                                    <entry id = "level_bar_id_entry" default_text = NULL indicator_text = "must be unique and no space" visible = TRUE editable = TRUE max_lenght = 5 alignment = 0.5>

                                                    </entry add_to_grid(level_bar_grid, level_bar_id_entry, 0, 1, 1, 1)>
                                                    <!-- End level_bar id entry -->

                                                    <!-- Start level bar min value label -->
                                                    <label id = "level_bar_min_value_label" text = "Min Value" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(level_bar_grid, level_bar_min_value_label, 1, 0, 1, 1)>
                                                    <!-- End level bar min value label -->

                                                    <!-- Start level bar min value spin button -->
                                                    <spin_button id = "level_bar_min_value_spin_button" min = 0 max = 100 step = 1 value = 0 digits = 0 numeric = FALSE>

                                                    </spin_button add_to_grid(level_bar_grid, level_bar_min_value_spin_button, 1, 1, 1, 1)>
                                                    <!-- End level bar min value spin button -->

                                                    <!-- Start level bar max value label -->
                                                    <label id = "level_bar_max_value_label" text = "Max Value" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(level_bar_grid, level_bar_max_value_label, 2, 0, 1, 1)>
                                                    <!-- End level bar max value label -->

                                                    <!-- Start level bar max value spin button -->
                                                    <spin_button id = "level_bar_max_value_spin_button" min = 0 max = 100 step = 1 value = 10 digits = 0 numeric = FALSE>

                                                    </spin_button add_to_grid(level_bar_grid, level_bar_max_value_spin_button, 2, 1, 1, 1)>
                                                    <!-- End level bar max value spin button -->

                                                    <!-- Start level_bar default value label -->
                                                    <label id = "level_bar_default_value_label" text = "Default Value" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(level_bar_grid, level_bar_default_value_label, 3, 0, 1, 1)>
                                                    <!-- End level_bar default value label -->

                                                    <!-- Start level_bar default value spin button -->
                                                    <spin_button id = "level_bar_default_value_spin_button" min = 0 max = 100 step = 1 value = 50 digits = 0 numeric = FALSE>

                                                    </spin_button add_to_grid(level_bar_grid, level_bar_default_value_spin_button, 3, 1, 1, 1)>
                                                    <!-- End level_bar default value spin button -->

                                                    <!-- Start level bar mode label -->
                                                    <label id = "level_bar_mode_label" text = "Mode" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(level_bar_grid, level_bar_mode_label, 4, 0, 1, 1)>
                                                    <!-- End level bar mode label -->

                                                    <!-- Start level bar mode combo box -->
                                                    <combo_box id = "level_bar_mode_combo_box">

                                                        <!-- Start level bar mode combo box item -->
                                                        <combo_box_item id = "level_bar_mode_combo_box_item">
                                                        
                                                        </combo_box_item add_to_combo_box(level_bar_mode_combo_box, "GTK_LEVEL_BAR_MODE_CONTINUOUS")>
                                                        <!-- End level bar mode combo box -->

                                                        <!-- Start level bar mode combo box item -->
                                                        <combo_box_item id = "level_bar_mode_combo_box_item">
                                                        
                                                        </combo_box_item add_to_combo_box(level_bar_mode_combo_box, "GTK_LEVEL_BAR_MODE_DISCRETE")>
                                                        <!-- End level bar mode combo box -->

                                                    </combo_box add_to_grid(level_bar_grid, level_bar_mode_combo_box, 4, 1, 1, 1)>
                                                    <!-- End level bar mode combo box -->

                                                    <!-- Start level_bar reversed label -->
                                                    <label id = "level_bar_reversed_label" text = "Reversed" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(level_bar_grid, level_bar_reversed_label, 5, 0, 1, 1)>
                                                    <!-- End level_bar reversed label -->

                                                    <!-- Start level_bar reversed combo box -->
                                                    <combo_box id = "level_bar_reversed_combo_box">

                                                        <!-- Start level_bar reversed combo box item -->
                                                        <combo_box_item id = "level_bar_reversed_combo_box_item">
                                                        
                                                        </combo_box_item add_to_combo_box(level_bar_reversed_combo_box, "FALSE")>
                                                        <!-- End level_bar reversed combo box -->

                                                        <!-- Start level_bar reversed combo box item -->
                                                        <combo_box_item id = "level_bar_reversed_combo_box_item">
                                                        
                                                        </combo_box_item add_to_combo_box(level_bar_reversed_combo_box, "TRUE")>
                                                        <!-- End level_bar reversed combo box -->

                                                    </combo_box add_to_grid(level_bar_grid, level_bar_reversed_combo_box, 5, 1, 1, 1)>
                                                    <!-- End level_bar reversed combo box -->

                                                    <!-- Start level_bar add button -->
                                                    <button id = "level_bar_add_button" label = "                                                               Add                                                               ">

                                                    </button add_to_grid(level_bar_grid, level_bar_add_button, 6, 0, 2, 1)>
                                                    <!-- End level_bar add button -->

                                                </grid add_to_frame(level_bar_grid_frame, level_bar_grid, 14, 14, 14, 14)>
                                                <!-- End level_bar grid -->

                                            </frame add_to_box(level_bar_box, level_bar_grid_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                            <!-- End level_bar grid frame -->

                                        </box add_to_box(Widgets_box, level_bar_box, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                        <!-- End level_bar box -->

                                        <!-- Start Link button box -->
                                        <box id = "Link_button_box" orientation = GTK_ORIENTATION_VERTICAL spacing = 0>

                                            <!-- Start Link button label frame -->
                                            <frame id = "Link_button_label_frame" label = NULL>

                                                <!-- Start Link button label -->
                                                <label id = "Link_button_label" text = "Link Button" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                </label add_to_frame(Link_button_label_frame, Link_button_label, 7, 7, 14, 1)>
                                                <!-- End Link button label -->

                                            </frame add_to_box(Link_button_box, Link_button_label_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                            <!-- End Link button label frame -->

                                            <!-- Start Link button grid frame -->
                                            <frame id = "Link_button_grid_frame" label = NULL>

                                                <!-- Start Link button grid -->
                                                <grid id = "Link_button_grid" rows_spacing = 7 columns_spacing = 7 rows_homogeneous = TRUE columns_homogeneous = FALSE>

                                                    <!-- Start Link button id label -->
                                                    <label id = "Link_button_id_label" text = "Widget ID" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(Link_button_grid, Link_button_id_label, 0, 0, 1, 1)>
                                                    <!-- End Link button id label -->

                                                    <!-- Start Link button id entry -->
                                                    <entry id = "Link_button_id_entry" default_text = NULL indicator_text = "must be unique and no space" visible = TRUE editable = TRUE max_lenght = 5 alignment = 0.5>

                                                    </entry add_to_grid(Link_button_grid, Link_button_id_entry, 0, 1, 1, 1)>
                                                    <!-- End Link button id entry -->

                                                    <!-- Start Link button url label -->
                                                    <label id = "Link_button_url_label" text = "URL" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(Link_button_grid, Link_button_url_label, 1, 0, 1, 1)>
                                                    <!-- End Link button url label -->

                                                    <!-- Start Link button url entry -->
                                                    <entry id = "Link_button_url_entry">

                                                    </entry add_to_grid(Link_button_grid, Link_button_url_entry, 1, 1, 1, 1)>
                                                    <!-- End Link button url entry -->

                                                    <!-- Start Link button label label -->
                                                    <label id = "Link_button_label_label" text = "Label" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(Link_button_grid, Link_button_label_label, 2, 0, 1, 1)>
                                                    <!-- End Link button label label -->

                                                    <!-- Start Link button label entry -->
                                                    <entry id = "Link_button_label_entry">

                                                    </entry add_to_grid(Link_button_grid, Link_button_label_entry, 2, 1, 1, 1)>
                                                    <!-- End Link button label entry -->

                                                    <!-- Start Link button add button -->
                                                    <button id = "Link_button_add_button" label = "                                                               Add                                                               ">

                                                    </button add_to_grid(Link_button_grid, Link_button_add_button, 3, 0, 2, 1)>
                                                    <!-- End Link button add button -->

                                                </grid add_to_frame(Link_button_grid_frame, Link_button_grid, 14, 14, 14, 14)>
                                                <!-- End Link button grid -->

                                            </frame add_to_box(Link_button_box, Link_button_grid_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                            <!-- End Link button grid frame -->

                                        </box add_to_box(Widgets_box, Link_button_box, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                        <!-- End Link button box -->

                                        <!-- Start menu button box -->
                                        <box id = "menu_button_box" orientation = GTK_ORIENTATION_VERTICAL spacing = 0>

                                            <!-- Start menu_button label frame -->
                                            <frame id = "menu_button_label_frame" label = NULL>

                                                <!-- Start menu_button label -->
                                                <label id = "menu_button_label" text = "Menu Button" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                </label add_to_frame(menu_button_label_frame, menu_button_label, 7, 7, 14, 1)>
                                                <!-- End menu_button label -->

                                            </frame add_to_box(menu_button_box, menu_button_label_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                            <!-- End menu_button label frame -->

                                            <!-- Start menu button grid frame -->
                                            <frame id = "menu_button_grid_frame" label = NULL>

                                                <!-- Start menu button grid -->
                                                <grid id = "menu_button_grid" rows_spacing = 7 columns_spacing = 7 rows_homogeneous = TRUE columns_homogeneous = FALSE>

                                                    <!-- Start menu button id label -->
                                                    <label id = "menu_button_id_label" text = "Widget ID" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(menu_button_grid, menu_button_id_label, 0, 0, 1, 1)>
                                                    <!-- End menu button id label -->

                                                    <!-- Start menu button id entry -->
                                                    <entry id = "menu_button_id_entry" default_text = NULL indicator_text = "must be unique and no space" visible = TRUE editable = TRUE max_lenght = 5 alignment = 0.5>

                                                    </entry add_to_grid(menu_button_grid, menu_button_id_entry, 0, 1, 1, 1)>
                                                    <!-- End menu button id entry -->

                                                    <!-- Start menu button label label -->
                                                    <label id = "menu_button_label_label" text = "Label" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(menu_button_grid, menu_button_label_label, 1, 0, 1, 1)>
                                                    <!-- End menu button label label -->

                                                    <!-- Start menu button label entry -->
                                                    <entry id = "menu_button_label_entry">

                                                    </entry add_to_grid(menu_button_grid, menu_button_label_entry, 1, 1, 1, 1)>
                                                    <!-- End menu button label entry -->

                                                    <!-- Start menu button path to image label -->
                                                    <label id = "menu_button_path_to_image_label" text = "Path to image" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(menu_button_grid, menu_button_path_to_image_label, 2, 0, 1, 1)>

                                                    <!-- Start menu button path to image entry -->
                                                    <entry id = "menu_button_path_to_image_entry" indicator_text = "Chose image or lable">

                                                    </entry add_to_grid(menu_button_grid, menu_button_path_to_image_entry, 2, 1, 1, 1)>
                                                    <!-- End menu button path to image entry -->

                                                    <!-- Start menu button arrow type label -->
                                                    <label id = "menu_button_arrow_type_label" text = "Arrow type" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(menu_button_grid, menu_button_arrow_type_label, 3, 0, 1, 1)>
                                                    <!-- End menu button arrow type label -->

                                                    <!-- Start menu button arrow type combo box -->
                                                    <combo_box id = "menu_button_arrow_type_combo_box">

                                                        <!-- Start menu button arrow type combo box item -->
                                                        <combo_box_item id = "menu_button_arrow_type_combo_box_item" label = "Down">

                                                        </combo_box_item add_to_combo_box(menu_button_arrow_type_combo_box, "GTK_ARROW_DOWN")>
                                                        <!-- End menu button arrow type combo box item -->

                                                        <!-- Start menu button arrow type combo box item -->
                                                        <combo_box_item id = "menu_button_arrow_type_combo_box_item" label = "Up">

                                                        </combo_box_item add_to_combo_box(menu_button_arrow_type_combo_box, "GTK_ARROW_UP")>
                                                        <!-- End menu button arrow type combo box item -->

                                                        <!-- Start menu button arrow type combo box item -->
                                                        <combo_box_item id = "menu_button_arrow_type_combo_box_item" label = "Left">

                                                        </combo_box_item add_to_combo_box(menu_button_arrow_type_combo_box, "GTK_ARROW_LEFT")>
                                                        <!-- End menu button arrow type combo box item -->

                                                        <!-- Start menu button arrow type combo box item -->
                                                        <combo_box_item id = "menu_button_arrow_type_combo_box_item" label = "Right">

                                                        </combo_box_item add_to_combo_box(menu_button_arrow_type_combo_box, "GTK_ARROW_RIGHT")>
                                                        <!-- End menu button arrow type combo box item -->

                                                    </combo_box add_to_grid(menu_button_grid, menu_button_arrow_type_combo_box, 3, 1, 1, 1)>
                                                    <!-- End menu button arrow type combo box -->

                                                    <!-- Start menu button add button -->
                                                    <button id = "menu_button_add_button" label = "                                                               Add                                                               ">

                                                    </button add_to_grid(menu_button_grid, menu_button_add_button, 4, 0, 2, 1)>
                                                    <!-- End menu button add button -->

                                                </grid add_to_frame(menu_button_grid_frame, menu_button_grid, 14, 14, 14, 14)>
                                                <!-- End menu button grid -->

                                            </frame add_to_box(menu_button_box, menu_button_grid_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                            <!-- End menu button grid frame -->

                                        </box add_to_box(Widgets_box, menu_button_box, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                        <!-- End menu button box -->

                                        <!-- Start menu item box -->
                                        <box id = "menu_item_box" orientation = GTK_ORIENTATION_VERTICAL spacing = 0>

                                            <!-- Start menu_item label frame -->
                                            <frame id = "menu_item_label_frame" label = NULL>

                                                <!-- Start menu_item label -->
                                                <label id = "menu_item_label" text = "Menu Item" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                </label add_to_frame(menu_item_label_frame, menu_item_label, 7, 7, 14, 1)>
                                                <!-- End menu_item label -->

                                            </frame add_to_box(menu_item_box, menu_item_label_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                            <!-- End menu_item label frame -->

                                            <!-- Start menu_item grid frame -->
                                            <frame id = "menu_item_grid_frame" label = NULL>

                                                <!-- Start menu_item grid -->
                                                <grid id = "menu_item_grid" rows_spacing = 7 columns_spacing = 7 rows_homogeneous = TRUE columns_homogeneous = FALSE>

                                                    <!-- Start menu item id lebel -->
                                                    <label id = "menu_item_id_label" text = "Widget ID" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(menu_item_grid, menu_item_id_label, 0, 0, 1, 1)>
                                                    <!-- End menu item id lebel -->

                                                    <!-- Start menu item id entry -->
                                                    <entry id = "menu_item_id_entry" default_text = NULL indicator_text = "must be unique and no space" visible = TRUE editable = TRUE max_lenght = 5 alignment = 0.5>

                                                    </entry add_to_grid(menu_item_grid, menu_item_id_entry, 0, 1, 1, 1)>
                                                    <!-- End menu item id entry -->

                                                    <!-- Start menu item label label -->
                                                    <label id = "menu_item_label_label" text = "Label" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(menu_item_grid, menu_item_label_label, 1, 0, 1, 1)>
                                                    <!-- End menu item label label -->

                                                    <!-- Start menu item label entry -->
                                                    <entry id = "menu_item_label_entry">

                                                    </entry add_to_grid(menu_item_grid, menu_item_label_entry, 1, 1, 1, 1)>
                                                    <!-- End menu item label entry -->

                                                    <!-- Start menu item type label -->
                                                    <label id = "menu_item_type_label" text = "Type" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(menu_item_grid, menu_item_type_label, 2, 0, 1, 1)>
                                                    <!-- End menu item type label -->

                                                    <!-- Start menu item type combo box -->
                                                    <combo_box id = "menu_item_type_combo_box">

                                                        <!-- Start menu item type combo box item -->
                                                        <combo_box_item id = "menu_item_type_combo_box_item" label = "normal">

                                                        </combo_box_item add_to_combo_box(menu_item_type_combo_box, "normal")>
                                                        <!-- End menu item type combo box item -->

                                                        <!-- Start menu item type combo box item -->
                                                        <combo_box_item id = "menu_item_type_combo_box_item" label = "separator">

                                                        </combo_box_item add_to_combo_box(menu_item_type_combo_box, "separator")>
                                                        <!-- End menu item type combo box item -->

                                                        <!-- Start menu item type combo box item -->
                                                        <combo_box_item id = "menu_item_type_combo_box_item" label = "check">

                                                        </combo_box_item add_to_combo_box(menu_item_type_combo_box, "check")>
                                                        <!-- End menu item type combo box item -->

                                                        <!-- Start menu item type combo box item -->
                                                        <combo_box_item id = "menu_item_type_combo_box_item" label = "radio">

                                                        </combo_box_item add_to_combo_box(menu_item_type_combo_box, "radio")>
                                                        <!-- End menu item type combo box item -->

                                                    </combo_box add_to_grid(menu_item_grid, menu_item_type_combo_box, 2, 1, 1, 1)>
                                                    <!-- End menu item type combo box -->

                                                    <!-- Start menu item callback label -->
                                                    <label id = "menu_item_callback_label" text = "Callback" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(menu_item_grid, menu_item_callback_label, 3, 0, 1, 1)>
                                                    <!-- End menu item callback label -->

                                                    <!-- Start menu item callback entry -->
                                                    <entry id = "menu_item_callback_entry">

                                                    </entry add_to_grid(menu_item_grid, menu_item_callback_entry, 3, 1, 1, 1)>
                                                    <!-- End menu item callback entry -->

                                                    <!-- Start menu item data label -->
                                                    <label id = "menu_item_data_label" text = "Data" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(menu_item_grid, menu_item_data_label, 4, 0, 1, 1)>
                                                    <!-- End menu item data label -->

                                                    <!-- Start menu item data entry -->
                                                    <entry id = "menu_item_data_entry">

                                                    </entry add_to_grid(menu_item_grid, menu_item_data_entry, 4, 1, 1, 1)>
                                                    <!-- End menu item data entry -->

                                                    <!-- Start menu_item add button -->
                                                    <button id = "menu_item_add_button" label = "                                                               Add                                                              ">

                                                    </button add_to_grid(menu_item_grid, menu_item_add_button, 5, 0, 2, 1)>
                                                    <!-- End menu_item add button -->

                                                </grid add_to_frame(menu_item_grid_frame, menu_item_grid, 14, 14, 14, 14)>
                                                <!-- End menu_item grid -->

                                            </frame add_to_box(menu_item_box, menu_item_grid_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                            <!-- End menu_item grid frame -->

                                        </box add_to_box(Widgets_box, menu_item_box, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                        <!-- End menu item box -->

                                        <!-- Start menu box -->
                                        <box id = "menu_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>

                                            <!-- Start menu label frame -->
                                            <frame id = "menu_label_frame" label = NULL>

                                                <!-- Start menu label -->
                                                <label id = "menu_label" text = "Menu" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                </label add_to_frame(menu_label_frame, menu_label, 7, 7, 14, 1)>
                                                <!-- End menu label -->

                                            </frame add_to_box(menu_box, menu_label_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                            <!-- End menu label frame -->

                                            <!-- Start menu grid frame -->
                                            <frame id = "menu_grid_frame" label = NULL>

                                                <!-- Start menu grid -->
                                                <grid id = "menu_grid" rows_spacing = 7 columns_spacing = 7 rows_homogeneous = TRUE columns_homogeneous = FALSE>

                                                    <!-- Start menu id label -->
                                                    <label id = "menu_id_label" text = "Widget Id" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(menu_grid, menu_id_label, 0, 0, 1, 1)>
                                                    <!-- End menu id label -->

                                                    <!-- Start menu id entry -->
                                                    <entry id = "menu_id_entry" default_text = NULL indicator_text = "must be unique and no space" visible = TRUE editable = TRUE max_lenght = 5 alignment = 0.5>

                                                    </entry add_to_grid(menu_grid, menu_id_entry, 0, 1, 1, 1)>
                                                    <!-- End menu id entry -->

                                                    <!-- Start menu is primary label -->
                                                    <label id = "menu_is_primary_label" text = "Is Primary" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(menu_grid, menu_is_primary_label, 1, 0, 1, 1)>
                                                    <!-- End menu is primary label -->

                                                    <!-- Start menu is primary combo box -->
                                                    <combo_box id = "menu_is_primary_combo_box">

                                                        <!-- Start menu is primary combo box item -->
                                                        <combo_box_item id = "menu_is_primary_combo_box_item" label = "TRUE">

                                                        </combo_box_item add_to_combo_box(menu_is_primary_combo_box, "TRUE")>
                                                        <!-- End menu is primary combo box item -->

                                                        <!-- Start menu is primary combo box item -->
                                                        <combo_box_item id = "menu_is_primary_combo_box_item" label = "FALSE">

                                                        </combo_box_item add_to_combo_box(menu_is_primary_combo_box, "FALSE")>
                                                        <!-- End menu is primary combo box item -->

                                                    </combo_box add_to_grid(menu_grid, menu_is_primary_combo_box, 1, 1, 1, 1)>
                                                    <!-- End menu is primary combo box -->

                                                    <!-- Start menu label label -->
                                                    <label id = "menu_label_label" text = "Label" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(menu_grid, menu_label_label, 2, 0, 1, 1)>
                                                    <!-- End menu label label -->

                                                    <!-- Start menu label entry -->
                                                    <entry id = "menu_label_entry">

                                                    </entry add_to_grid(menu_grid, menu_label_entry, 2, 1, 1, 1)>
                                                    <!-- End menu label entry -->

                                                    <!-- Start menu add button -->
                                                    <button id = "menu_add_button" label = "                                                               Add                                                              ">

                                                    </button add_to_grid(menu_grid, menu_add_button, 3, 0, 2, 1)>
                                                    <!-- End menu add button -->

                                                </grid add_to_frame(menu_grid_frame, menu_grid, 14, 14, 14, 14)>
                                                <!-- End menu grid -->

                                            </frame add_to_box(menu_box, menu_grid_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                            <!-- End menu grid frame -->

                                        </box add_to_box(Widgets_box, menu_box, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                        <!-- End menu box -->

                                        <!-- Start progress bar box -->
                                        <box id = "progress_bar_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>

                                            <!-- Start progress bar label frame -->
                                            <frame id = "progress_bar_label_frame" label = NULL>

                                                <!-- Start progress bar label -->
                                                <label id = "progress_bar_label" text = "Progress Bar" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                </label add_to_frame(progress_bar_label_frame, progress_bar_label, 7, 7, 14, 1)>
                                                <!-- End progress bar label -->

                                            </frame add_to_box(progress_bar_box, progress_bar_label_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                            <!-- End progress bar label frame -->

                                            <!-- Start progress bar grid frame -->
                                            <frame id = "progress_bar_grid_frame" label = NULL>

                                                <!-- Start progress bar grid -->
                                                <grid id = "progress_bar_grid" rows_spacing = 7 columns_spacing = 7 rows_homogeneous = TRUE columns_homogeneous = FALSE>

                                                    <!-- Start progress bar id label -->
                                                    <label id = "progress_bar_id_label" text = "Widget Id" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(progress_bar_grid, progress_bar_id_label, 0, 0, 1, 1)>
                                                    <!-- End progress bar id label -->

                                                    <!-- Start progress bar id entry -->
                                                    <entry id = "progress_bar_id_entry" default_text = NULL indicator_text = "must be unique and no space" visible = TRUE editable = TRUE max_lenght = 5 alignment = 0.5>

                                                    </entry add_to_grid(progress_bar_grid, progress_bar_id_entry, 0, 1, 1, 1)>
                                                    <!-- End progress bar id entry -->

                                                    <!-- Start progress bar text label -->
                                                    <label id = "progress_bar_text_label" text = "Text" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(progress_bar_grid, progress_bar_text_label, 1, 0, 1, 1)>
                                                    <!-- End progress bar text label -->

                                                    <!-- Start progress bar text entry -->
                                                    <entry id = "progress_bar_text_entry">

                                                    </entry add_to_grid(progress_bar_grid, progress_bar_text_entry, 1, 1, 1, 1)>
                                                    <!-- End progress bar text entry -->

                                                    <!-- Start progress bar fraction label -->
                                                    <label id = "progress_bar_fraction_label" text = "Fraction" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(progress_bar_grid, progress_bar_fraction_label, 2, 0, 1, 1)>
                                                    <!-- End progress bar fraction label -->

                                                    <!-- Start progress bar fraction spin_button -->
                                                    <spin_button id = "progress_bar_fraction_spin_button" min = 0 max = 1 step = 0.1 digits = 1 value = 0.0>

                                                    </spin_button add_to_grid(progress_bar_grid, progress_bar_fraction_spin_button, 2, 1, 1, 1)>
                                                    <!-- End progress bar fraction spin_button -->

                                                    <!-- Start level bar show text label -->
                                                    <label id = "level_bar_show_text_label" text = "Show Text" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(progress_bar_grid, level_bar_show_text_label, 3, 0, 1, 1)>
                                                    <!-- End level bar show text label -->

                                                    <!-- Start level bar show text combo box -->
                                                    <combo_box id = "level_bar_show_text_combo_box">

                                                        <!-- Start level bar show text combo box item -->
                                                        <combo_box_item id = "level_bar_show_text_combo_box_item" label = "TRUE">

                                                        </combo_box_item add_to_combo_box(level_bar_show_text_combo_box, "TRUE")>
                                                        <!-- End level bar show text combo box item -->

                                                        <!-- Start level bar show text combo box item -->
                                                        <combo_box_item id = "level_bar_show_text_combo_box_item" label = "FALSE">

                                                        </combo_box_item add_to_combo_box(level_bar_show_text_combo_box, "FALSE")>
                                                        <!-- End level bar show text combo box item -->

                                                    </combo_box add_to_grid(progress_bar_grid, level_bar_show_text_combo_box, 3, 1, 1, 1)>
                                                    <!-- End level bar show text combo box -->

                                                    <!-- Start progress bar pulse label -->
                                                    <label id = "progress_bar_pulse_label" text = "Pulse" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(progress_bar_grid, progress_bar_pulse_label, 4, 0, 1, 1)>
                                                    <!-- End progress bar pulse label -->

                                                    <!-- Start progress bar pulse combo box -->
                                                    <combo_box id = "progress_bar_pulse_combo_box">

                                                        <!-- Start progress bar pulse combo box item --> 
                                                        <combo_box_item id = "progress_bar_pulse_combo_box_item" label = "TRUE">

                                                        </combo_box_item add_to_combo_box(progress_bar_pulse_combo_box, "TRUE")>
                                                        <!-- End progress bar pulse combo box item -->

                                                        <!-- Start progress bar pulse combo box item -->
                                                        <combo_box_item id = "progress_bar_pulse_combo_box_item" label = "FALSE">

                                                        </combo_box_item add_to_combo_box(progress_bar_pulse_combo_box, "FALSE")>
                                                        <!-- End progress bar pulse combo box item -->

                                                    </combo_box add_to_grid(progress_bar_grid, progress_bar_pulse_combo_box, 4, 1, 1, 1)>
                                                    <!-- End progress bar pulse combo box -->

                                                    <!-- Start progress bar inverted label -->
                                                    <label id = "progress_bar_inverted_label" text = "Inverted" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(progress_bar_grid, progress_bar_inverted_label, 5, 0, 1, 1)>
                                                    <!-- End progress bar inverted label -->
                                                     
                                                    <!-- Start progress bar inverted combo box -->
                                                    <combo_box id = "progress_bar_inverted_combo_box">

                                                        <!-- Start progress bar inverted combo box item -->
                                                        <combo_box_item id = "progress_bar_inverted_combo_box_item" label = "TRUE">

                                                        </combo_box_item add_to_combo_box(progress_bar_inverted_combo_box, "TRUE")>
                                                        <!-- End progress bar inverted combo box item -->

                                                        <!-- Start progress bar inverted combo box item -->
                                                        <combo_box_item id = "progress_bar_inverted_combo_box_item" label = "FALSE">

                                                        </combo_box_item add_to_combo_box(progress_bar_inverted_combo_box, "FALSE")>
                                                        <!-- End progress bar inverted combo box item -->

                                                    </combo_box add_to_grid(progress_bar_grid, progress_bar_inverted_combo_box, 5, 1, 1, 1)>
                                                    <!-- End progress bar inverted combo box -->

                                                    <!-- Start progress bar add button -->
                                                    <button id = "progress_bar_add_button" label = "                                                               Add                                                             ">

                                                    </button add_to_grid(progress_bar_grid, progress_bar_add_button, 6, 0, 2, 1)>
                                                    <!-- End progress bar add button -->

                                                </grid add_to_frame(progress_bar_grid_frame, progress_bar_grid, 14, 14, 14, 14)>
                                                <!-- End progress bar grid -->

                                            </frame add_to_box(progress_bar_box, progress_bar_grid_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                            <!-- End progress bar grid frame -->

                                        </box add_to_box(Widgets_box, progress_bar_box, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                        <!-- End progress bar box -->

                                        <!-- Start radio_button box -->
                                        <box id = "radio_button_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>

                                            <!-- Start radio_button label frame -->
                                            <frame id = "radio_button_label_frame" label = NULL>

                                                <!-- Start radio_button label -->
                                                <label id = "radio_button_label" text = "Radio Button" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                </label add_to_frame(radio_button_label_frame, radio_button_label, 7, 7, 14, 1)>
                                                <!-- End radio_button label -->
                                            
                                            </frame add_to_box(radio_button_box, radio_button_label_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                            <!-- End radio_button label frame -->

                                            <!-- Start radio_button grid frame -->
                                            <frame id = "radio_button_grid_frame" label = NULL>

                                                <!-- Start radio_button grid -->
                                                <grid id = "radio_button_grid" rows_spacing = 7 columns_spacing = 7 rows_homogeneous = TRUE columns_homogeneous = FALSE>

                                                    <!-- Start radio_button id label -->
                                                    <label id = "radio_button_id_label" text = "Widget Id" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(radio_button_grid, radio_button_id_label, 0, 0, 1, 1)>
                                                    <!-- End radio_button id label -->

                                                    <!-- Start radio_button id entry -->
                                                    <entry id = "radio_button_id_entry" default_text = NULL indicator_text = "must be unique and no space" visible = TRUE editable = TRUE max_lenght = 5 alignment = 0.5>

                                                    </entry add_to_grid(radio_button_grid, radio_button_id_entry, 0, 1, 1, 1)>
                                                    <!-- End radio_button id entry -->

                                                    <!-- Start radio_button label label -->
                                                    <label id = "radio_button_label_label" text = "Label" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(radio_button_grid, radio_button_label_label, 1, 0, 1, 1)>
                                                    <!-- End radio_button label label -->

                                                    <!-- Start radio_button label entry -->
                                                    <entry id = "radio_button_label_entry" default_text = NULL indicator_text = NULL visible = TRUE editable = TRUE max_lenght = 5 alignment = 0.5>

                                                    </entry add_to_grid(radio_button_grid, radio_button_label_entry, 1, 1, 1, 1)>
                                                    <!-- End radio_button label entry -->

                                                    <!-- Start radio_button path image label -->
                                                    <label id = "radio_button_path_image_label" text = "Path Image" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(radio_button_grid, radio_button_path_image_label, 2, 0, 1, 1)>
                                                    <!-- End radio_button path image label -->

                                                    <!-- Start radio_button path image entry -->
                                                    <entry id = "radio_button_path_image_entry" default_text = NULL indicator_text = "if you chose label let this NULL" visible = TRUE editable = TRUE max_lenght = 5 alignment = 0.5>

                                                    </entry add_to_grid(radio_button_grid, radio_button_path_image_entry, 2, 1, 1, 1)>
                                                    <!-- End radio_button path image entry -->

                                                    <!-- Start radio_button id radio group member label -->
                                                    <label id = "radio_button_id_radio_group_member_label" text = "Id Radio Group Member" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(radio_button_grid, radio_button_id_radio_group_member_label, 3, 0, 1, 1)>
                                                    <!-- End radio_button id radio group member label -->

                                                    <!-- Start radio_button id radio group member entry -->
                                                    <entry id = "radio_button_id_radio_group_member_entry" default_text = NULL indicator_text = NULL visible = TRUE editable = TRUE max_lenght = 5 alignment = 0.5>

                                                    </entry add_to_grid(radio_button_grid, radio_button_id_radio_group_member_entry, 3, 1, 1, 1)>
                                                    <!-- End radio_button id radio group member entry -->

                                                    <!-- Start radio_button default state label -->
                                                    <label id = "radio_button_default_state_label" text = "Default State" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(radio_button_grid, radio_button_default_state_label, 4, 0, 1, 1)>
                                                    <!-- End radio_button default state label -->

                                                    <!-- Start radio_button default state combo box -->
                                                    <combo_box id = "radio_button_default_state_combo_box" visible = TRUE editable = TRUE max_lenght = 5 alignment = 0.5>

                                                        <!-- Start radio_button default state combo box item -->
                                                        <combo_box_item id = "radio_button_default_state_combo_box_item_1" label = "True">
        
                                                        </combo_box_item add_to_combo_box(radio_button_default_state_combo_box, "FALSE")>
                                                        <!-- End radio_button default state combo box item -->

                                                        <!-- Start radio_button default state combo box item -->
                                                        <combo_box_item id = "radio_button_default_state_combo_box_item_2" label = "False">
        
                                                        </combo_box_item add_to_combo_box(radio_button_default_state_combo_box, "TRUE")>
                                                        <!-- End radio_button default state combo box item -->

                                                    </combo_box add_to_grid(radio_button_grid, radio_button_default_state_combo_box, 4, 1, 1, 1)>
                                                    <!-- End radio_button default state combo box -->

                                                    <!-- Start radio_button add button -->
                                                    <button id = "radio_button_add_button" label = "                                                               Add                                                             ">

                                                    </button add_to_grid(radio_button_grid, radio_button_add_button, 5, 0, 2, 1)>
                                                    <!-- End radio_button add button -->

                                                </grid add_to_frame(radio_button_grid_frame, radio_button_grid, 14, 14, 14, 14)>
                                                <!-- End radio_button grid -->

                                            </frame add_to_box(radio_button_box, radio_button_grid_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                            <!-- End radio_button frame -->

                                        </box add_to_box(Widgets_box, radio_button_box, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                        <!-- End radio_button box -->

                                        <!-- Start scale box -->
                                        <box id = "scale_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>

                                            <!-- Start scale label frame -->
                                            <frame id = "scale_label_frame" label = NULL>

                                                <!-- Start scale label -->
                                                <label id = "scale_label" text = "Scale" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
        
                                                </label add_to_frame(scale_label_frame, scale_label, 7, 7, 14, 1)>
                                                <!-- End scale label -->

                                            </frame add_to_box(scale_box, scale_label_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                            <!-- End scale label frame -->

                                            <!-- Start scale grid frame -->
                                            <frame id = "scale_grid_frame" label = NULL>

                                                <!-- Start scale grid -->
                                                <grid id = "scale_grid" rows_spacing = 7 columns_spacing = 7 rows_homogeneous = TRUE columns_homogeneous = FALSE>

                                                    <!-- Start scale id label -->
                                                    <label id = "scale_id_label" text = "Widget Id" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
        
                                                    </label add_to_grid(scale_grid, scale_id_label, 0, 0, 1, 1)>
                                                    <!-- End scale id label -->

                                                    <!-- Start scale id entry -->
                                                    <entry id = "scale_id_entry" visible = TRUE editable = TRUE max_lenght = 5 alignment = 0.5>

                                                    </entry add_to_grid(scale_grid, scale_id_entry, 0, 1, 1, 1)>
                                                    <!-- End scale id entry -->

                                                    <!-- Start scale orientation label -->
                                                    <label id = "scale_orientation_label" text = "Orientation" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">
        
                                                    </label add_to_grid(scale_grid, scale_orientation_label, 1, 0, 1, 1)>
                                                    <!-- End scale orientation label -->

                                                    <!-- Start scale orientation combo box -->
                                                    <combo_box id = "scale_oreintation_combo_box">

                                                        <!-- Start item -->
                                                        <combo_box id = "combo_box_item1">

                                                        </combo_box add_to_combo_box(scale_oreintation_combo_box, "GTK_ORIENTATION_HORIZONTAL")>
                                                        <!-- End item -->

                                                        <!-- Start item -->
                                                        <combo_box id = "combo_box_item2">

                                                        </combo_box add_to_combo_box(scale_oreintation_combo_box, "GTK_ORIENTATION_VERTICAL")>
                                                        <!-- End item -->

                                                    </combo_box add_to_grid(scale_grid, scale_oreintation_combo_box, 1, 1, 1, 1)>
                                                    <!-- End scale orientation combo box -->

                                                    <!-- Start scale min value label -->
                                                    <label id = "scale_min_value_label" text = "Min Value" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(scale_grid, scale_min_value_label, 2, 0, 1, 1)>
                                                    <!-- End scale min value label -->

                                                    <!-- Start scale min value spin button -->
                                                    <spin_button id = "scale_min_value_spin_button" value = 0 min = 0 max = 100 step = 10 >

                                                    </spin_button add_to_grid(scale_grid, scale_min_value_spin_button, 2, 1, 1, 1)>
                                                    <!-- End scale min value spin button -->

                                                    <!-- Start scale max value label -->
                                                    <label id = "scale_max_value_label" text = "Max Value" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(scale_grid, scale_max_value_label, 3, 0, 1, 1)>
                                                    <!-- End scale max value label -->

                                                    <!-- Start scale max value spin button -->
                                                    <spin_button id = "scale_max_value_spin_button" value = 100 min = 0 max = 100 step = 10>

                                                    </spin_button add_to_grid(scale_grid, scale_max_value_spin_button, 3, 1, 1, 1)>
                                                    <!-- End scale max value spin button -->

                                                    <!-- Start scale step label -->
                                                    <label id = "scale_step_label" text = "Step" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(scale_grid, scale_step_label, 4, 0, 1, 1)>
                                                    <!-- End scale step label -->

                                                    <!-- Start scale step spin button -->
                                                    <spin_button id = "scale_step_spin_button" value = 10 min = 0 max = 50 step = 2>

                                                    </spin_button add_to_grid(scale_grid, scale_step_spin_button, 4, 1, 1, 1)>
                                                    <!-- End scale step spin button -->

                                                    <!-- Start scale add button -->
                                                    <button id = "scale_add_button" label = "                                                               Add                                                             ">

                                                    </button add_to_grid(scale_grid, scale_add_button, 5, 0, 2, 1)>
                                                    <!-- End scale add button -->

                                                </grid add_to_frame(scale_grid_frame, scale_grid, 14, 14, 14, 14)>
                                                <!-- End scale grid -->

                                            </frame add_to_box(scale_box, scale_grid_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                            <!-- End scale grid frame -->

                                        </box add_to_box(Widgets_box, scale_box, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                        <!-- End scale box -->

                                        <!-- Start separator box -->
                                        <box id = "separator_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>

                                            <!-- Start separator label frame -->
                                            <frame id ="separator_label_frame" label = NULL>

                                                <!-- Start separator label -->
                                                <label id = "separator_label" text = "Separator" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                </label add_to_frame(separator_label_frame, separator_label, 7, 7, 14, 1)>
                                                <!-- End separator label -->

                                            </frame add_to_box(separator_box, separator_label_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0)>
                                            <!-- End separator label frame -->

                                            <!-- Start separator grid frame -->
                                            <frame id = "separator_grid_frame" label = NULL>

                                                <!-- Start separator grid -->
                                                <grid id = "separator_grid" rows_spacing = 7 columns_spacing = 7 rows_homogeneous = TRUE columns_homogeneous = FALSE>

                                                    <!-- Start separator widget id label -->
                                                    <label id = "separator_widget_id_label" text = "Widget ID" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(separator_grid, separator_widget_id_label, 0, 0, 1, 1)>
                                                    <!-- End separator widget id label -->

                                                    <!-- Start separator widget id entry -->
                                                    <entry id = "separator_widget_id_entry" text = "" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </entry add_to_grid(separator_grid, separator_widget_id_entry, 0, 1, 1, 1)>
                                                    <!-- End separator widget id entry -->

                                                    <!-- Start separator orientation label -->
                                                    <label id = "separator_orientation_label" text = "Orientation" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(separator_grid, separator_orientation_label, 1, 0, 1, 1)>
                                                    <!-- End separator orientation label -->

                                                    <!-- Start separator orientation combobox -->
                                                    <combo_box id = "separator_orientation_combobox" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                        <!-- Start separator orientation combobox item1 -->
                                                        <combo_box_item id = "separator_orientation_combobox_item1" label = "Horizontal">

                                                        </combo_box_item add_to_combo_box(separator_orientation_combobox, "GTK_ORIENTATION_HORIZONTAL")>
                                                        <!-- End separator orientation combobox item1 -->

                                                        <!-- Start separator orientation combobox item2 -->
                                                        <combo_box_item id = "separator_orientation_combobox_item2" label = "Vertical">

                                                        </combo_box_item add_to_combo_box(separator_orientation_combobox, "GTK_ORIENTATION_VERTICAL")>
                                                        <!-- End separator orientation combobox item2 -->

                                                    </combo_box add_to_grid(separator_grid, separator_orientation_combobox, 1, 1, 1, 1)>
                                                    <!-- End separator orientation combobox -->

                                                    <!-- Start separator add button -->
                                                    <button id = "separator_add_button" label = "                                                               Add                                                             ">

                                                    </button add_to_grid(separator_grid, separator_add_button, 2, 0, 2, 1)>
                                                    <!-- End separator add button -->

                                                </grid add_to_frame(separator_grid_frame, separator_grid, 14, 14, 14, 14)>
                                                <!-- End separator grid -->

                                            </frame add_to_box(separator_box, separator_grid_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0)>
                                            <!-- End separator grid frame -->

                                        </box add_to_box(Widgets_box, separator_box, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                        <!-- End separator box -->

                                        <!-- Start spin button box -->
                                        <box id = "spin_button_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>

                                            <!-- Start spin button label frame -->
                                            <frame id = "spin_button_label_frame" label = NULL>

                                                <!-- Start spin button label -->
                                                <label id = "spin_button_label" text = "Spin Button" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                </label add_to_frame(spin_button_label_frame, spin_button_label, 7, 7, 14, 1)>
                                                <!-- End spin button label -->

                                            </frame add_to_box(spin_button_box, spin_button_label_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0)>
                                            <!-- End spin button label frame -->

                                            <!-- Start spin button grid frame -->
                                            <frame id = "spin_button_grid_frame" label = NULL>

                                                <!-- Start spin button grid -->
                                                <grid id = "spin_button_grid" rows_spacing = 7 columns_spacing = 7 rows_homogeneous = TRUE columns_homogeneous = FALSE>

                                                    <!-- Start spin button widget id label -->
                                                    <label id = "spin_button_widget_id_label" text = "Widget ID" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(spin_button_grid, spin_button_widget_id_label, 0, 0, 1, 1)>
                                                    <!-- End spin button widget id label -->

                                                    <!-- Start spin button widget id entry -->
                                                    <entry id = "spin_button_widget_id_entry" text = "must be unique" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </entry add_to_grid(spin_button_grid, spin_button_widget_id_entry, 0, 1, 1, 1)>
                                                    <!-- End spin button widget id entry -->

                                                    <!-- Start spin button min value label -->
                                                    <label id = "spin_button_min_value_label" text = "Min Value" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(spin_button_grid, spin_button_min_value_label, 1, 0, 1, 1)>
                                                    <!-- End spin button min value label -->

                                                    <!-- Start spin button min value spin_button -->
                                                    <spin_button id = "spin_button_min_value_spin_button" value = 0 min = 0 max = 100 step = 10>

                                                    </spin_button add_to_grid(spin_button_grid, spin_button_min_value_spin_button, 1, 1, 1, 1)>
                                                    <!-- End spin button min value spin_button -->

                                                    <!-- Start spin button max value label -->
                                                    <label id = "spin_button_max_value_label" text = "Max Value" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(spin_button_grid, spin_button_max_value_label, 2, 0, 1, 1)>
                                                    <!-- End spin button max value label -->

                                                    <!-- Start spin button max value spin_button -->
                                                    <spin_button id = "spin_button_max_value_spin_button" value = 100 min = 0 max = 100 step = 10>

                                                    </spin_button add_to_grid(spin_button_grid, spin_button_max_value_spin_button, 2, 1, 1, 1)>
                                                    <!-- End spin button max value spin_button -->

                                                    <!-- Start spin button Default Value label -->
                                                    <label id = "spin_button_Default_Value_label" text = "Default Value" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(spin_button_grid, spin_button_Default_Value_label, 3, 0, 1, 1)>
                                                    <!-- End spin button Default Value label -->

                                                    <!-- Start spin button Default Value spin_button -->
                                                    <spin_button id = "spin_button_Default_Value_spin_button" value = 50 min = 0 max = 100 step = 10>

                                                    </spin_button add_to_grid(spin_button_grid, spin_button_Default_Value_spin_button, 3, 1, 1, 1)>
                                                    <!-- End spin button Default Value spin_button -->

                                                    <!-- Start spin button digits label -->
                                                    <label id = "spin_button_digits_label" text = "Digits" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(spin_button_grid, spin_button_digits_label, 4, 0, 1, 1)>
                                                    <!-- End spin button digits label -->

                                                    <!-- Start spin button digits spin_button -->
                                                    <spin_button id = "spin_button_digits_spin_button" value = 0 min = 0 max = 5 step = 1>

                                                    </spin_button add_to_grid(spin_button_grid, spin_button_digits_spin_button, 4, 1, 1, 1)>
                                                    <!-- End spin button digits spin_button -->

                                                    <!-- Start spin button wrap label -->
                                                    <label id = "spin_button_wrap_label" text = "Wrap" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(spin_button_grid, spin_button_wrap_label, 5, 0, 1, 1)>
                                                    <!-- End spin button wrap label -->

                                                    <!-- Start spin button wrap combo_box -->
                                                    <combo_box id = "spin_button_wrap_combo_box">

                                                        <!-- Start combo box item -->
                                                        <combo_box_item id = "spin_button_combo_box_item_1" label = "TRUE">

                                                        </combo_box_item add_to_combo_box(spin_button_wrap_combo_box, "TRUE")>
                                                        <!-- End combo box item -->

                                                        <!-- Start combo box item -->
                                                        <combo_box_item id = "spin_button_combo_box_item_2" label = "FALSE">

                                                        </combo_box_item add_to_combo_box(spin_button_wrap_combo_box, "FALSE")>
                                                        <!-- End combo box item -->

                                                    </combo_box add_to_grid(spin_button_grid, spin_button_wrap_combo_box, 5, 1, 1, 1)>
                                                    <!-- End spin button wrap combo_box -->

                                                    <!-- Start spin button numeric label -->
                                                    <label id = "spin_button_numeric_label" text = "Numeric" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(spin_button_grid, spin_button_numeric_label, 6, 0, 1, 1)>
                                                    <!-- End spin button numeric label -->

                                                    <!-- Start spin button numeric combo_box -->
                                                    <combo_box id = "spin_button_numeric_combo_box">

                                                        <!-- Start combo box item -->
                                                        <combo_box_item id = "spin_button_combo_box_item_3" label = "TRUE">

                                                        </combo_box_item add_to_combo_box(spin_button_numeric_combo_box, "TRUE")>
                                                        <!-- End combo box item -->

                                                        <!-- Start combo box item -->
                                                        <combo_box_item id = "spin_button_combo_box_item_4" label = "FALSE">

                                                        </combo_box_item add_to_combo_box(spin_button_numeric_combo_box, "FALSE")>
                                                        <!-- End combo box item -->

                                                    </combo_box add_to_grid(spin_button_grid, spin_button_numeric_combo_box, 6, 1, 1, 1)>
                                                    <!-- End spin button numeric combo_box -->

                                                    <!-- Start spin button add button -->
                                                    <button id = "spin_button_add_button" label = "                                                               Add                                                             ">

                                                    </button add_to_grid(spin_button_grid, spin_button_add_button, 7, 0, 2, 1)>
                                                    <!-- End spin button add button -->

                                                </grid add_to_frame(spin_button_grid_frame, spin_button_grid, 14, 14, 14, 14)>
                                                <!-- End spin button grid -->

                                            </frame add_to_box(spin_button_box, spin_button_grid_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0)>
                                            <!-- End spin button grid frame -->

                                        </box add_to_box(Widgets_box, spin_button_box, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                        <!-- End spin button box -->

                                        <!-- Start spinner box -->
                                        <box id = "spinner_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>

                                            <!-- Start spinner label frame -->
                                            <frame id = "spinner_label_frame" label = NULL>

                                                <!-- Start spinner label -->
                                                <label id = "spinner_label" text = "Spinner" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                </label add_to_frame(spinner_label_frame, spinner_label, 7, 7, 14, 1)>
                                                <!-- End spinner label -->

                                            </frame add_to_box(spinner_box, spinner_label_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0)>
                                            <!-- End spinner label frame -->

                                            <!-- Start spinner grid frame -->
                                            <frame id = "spinner_grid_frame" label = NULL>

                                                <!-- Start spinner grid -->
                                                <grid id = "spinner_grid" rows_spacing = 7 columns_spacing = 7 rows_homogeneous = TRUE columns_homogeneous = FALSE>

                                                    <!-- Start spinner widget id label -->
                                                    <label id = "spinner_widget_id_label" text = "Widget ID" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(spinner_grid, spinner_widget_id_label, 0, 0, 1, 1)>
                                                    <!-- End spinner widget id label -->

                                                    <!-- Start spinner widget id entry -->
                                                    <entry id = "spinner_widget_id_entry" text = "" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </entry add_to_grid(spinner_grid, spinner_widget_id_entry, 0, 1, 1, 1)>
                                                    <!-- End spinner widget id entry -->

                                                    <!-- Start spinner active label -->
                                                    <label id = "spinner_active_label" text = "Active" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">$

                                                    </label add_to_grid(spinner_grid, spinner_active_label, 1, 0, 1, 1)>
                                                    <!-- End spinner active label -->

                                                    <!-- Start spinner active combo_box -->
                                                    <combo_box id = "spinner_active_combo_box">

                                                        <!-- Start combo box item -->
                                                        <combo_box_item id = "spinner_active_combo_box_item_1" label = "TRUE">

                                                        </combo_box_item add_to_combo_box(spinner_active_combo_box, "TRUE")>
                                                        <!-- End combo box item -->

                                                        <!-- Start combo box item -->
                                                        <combo_box_item id = "spinner_active_combo_box_item_2" label = "FALSE">

                                                        </combo_box_item add_to_combo_box(spinner_active_combo_box, "FALSE")>
                                                        <!-- End combo box item -->

                                                    </combo_box add_to_grid(spinner_grid, spinner_active_combo_box, 1, 1, 1, 1)>
                                                    <!-- End spinner active combo_box -->

                                                    <!-- Start spinner add button -->
                                                    <button id = "spinner_add_button" label = "                                                               Add                                                             ">

                                                    </button add_to_grid(spinner_grid, spinner_add_button, 2, 0, 2, 1)>
                                                    <!-- End spinner add button -->

                                                </grid add_to_frame(spinner_grid_frame, spinner_grid, 14, 14, 14, 14)>
                                                <!-- End spinner grid -->

                                            </frame add_to_box(spinner_box, spinner_grid_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0)>
                                            <!-- End spinner grid frame -->

                                        </box add_to_box(Widgets_box, spinner_box, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                        <!-- End spinner box -->

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