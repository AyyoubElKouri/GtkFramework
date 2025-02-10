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
                                                        <button id = "window_informations_add_button" label = "                                                        Add                                                 ">
    
                                                        </button add_to_grid(window_informations_grid, window_informations_add_button, 11, 0, 2, 1)>
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
                                                        <button id = "header_bar_informations_add_button" label = "                                                        Add                                                 ">
    
                                                        </button add_to_grid(header_bar_informations_grid, header_bar_informations_add_button, 4, 0, 2, 1)>
                                                        <!-- End header bar informations add button -->
    
                                                    </grid add_to_box(header_bar_informations_main_box, header_bar_informations_grid, START, TRUE, FALSE, 0, 14, 0, 21, 21)>
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
                                                        <button id = "scrolled_window_informations_add_button" label = "                                                        Add                                                 ">
    
                                                        </button add_to_grid(scrolled_window_informations_grid, scrolled_window_informations_add_button, 2, 0, 2, 1)>
                                                        <!-- End scrolled window informations add button -->
    
                                                    </grid add_to_box(scrolled_window_informations_main_box, scrolled_window_informations_grid, START, TRUE, FALSE, 0, 14, 0, 0, 0)>
                                                    <!-- End scrolled window informations grid -->
    
                                                </box add_to_frame(scrolled_window_informations_main_box_frame, scrolled_window_informations_main_box, 0, 18, 21, 0)>
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

                                            <!-- Start box case label -->
                                            <label id = "Box_case_label" text = "Box" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                            </label add_to_box(Box_case, Box_case_label, START, TRUE, FALSE, 0, 0, 0, 0, 7)>
                                            <!-- End box case label -->

                                            <!-- Start box case informations main box -->
                                            <box id = "Box_case_informations_main_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>

                                                <!-- Start box case informations grid -->
                                                <grid id = "Box_case_informations_grid" rows_spacing = 7 columns_spacing = 7 rows_homogeneous = TRUE columns_homogeneous = FALSE>

                                                    <!-- Start box case informations orientation label -->
                                                    <label id = "Box_case_informations_orientation_label" text = "Orientation" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(Box_case_informations_grid, Box_case_informations_orientation_label, 0, 0, 1, 1)>
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

                                                    </combo_box add_to_grid(Box_case_informations_grid, Box_case_informations_orientation_value, 0, 1, 1, 1)>
                                                    <!-- End box case informations orientation value combo box -->

                                                    <!-- Start box case informations align label -->
                                                    <label id = "Box_case_informations_align_label" text = "Align" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(Box_case_informations_grid, Box_case_informations_align_label, 1, 0, 1, 1)>
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

                                                    </combo_box add_to_grid(Box_case_informations_grid, Box_case_informations_align_value, 1, 1, 1, 1)>
                                                    <!-- End box case informations align value combo box -->

                                                    <!-- Start box case informations spacing label -->
                                                    <label id = "Box_case_informations_spacing_label" text = "Spacing" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                    </label add_to_grid(Box_case_informations_grid, Box_case_informations_spacing_label, 2, 0, 1, 1)>
                                                    <!-- End box case informations spacing label -->

                                                    <!-- Start box case informations spacing value spin button -->
                                                    <spin_button id = "Box_case_informations_spacing_value" min = "0" max = "100" step = "5" value = "0" digits = "0"" numeric = TRUE>

                                                    </spin_button add_to_grid(Box_case_informations_grid, Box_case_informations_spacing_value, 2, 1, 1, 1)>
                                                    <!-- End box case informations spacing value spin button -->

                                                    <!-- Start box case informations add button -->
                                                    <button id = "Box_case_informations_add" label = "                                                        Add                                                 ">

                                                    </button add_to_grid(Box_case_informations_grid, Box_case_informations_add, 3, 0, 2, 1)>
                                                    <!-- End box case informations add button -->

                                                </grid add_to_box(Box_case_informations_main_box, Box_case_informations_grid, START, TRUE, FALSE, 0, 14, 0, 0, 0)>
                                                <!-- End box case informations grid -->

                                            </box add_to_box(Box_case, Box_case_informations_main_box, START, FALSE, FALSE, 0, 5, 0, 0, 7)>
                                            <!-- End box case informations main box -->

                                        </box add_to_box(Containers_box, Box_case, START, TRUE, TRUE, 0, 14, 0, 0, 0)>
                                        <!-- End box Case -->

                                        <!-- Start fixed box -->
                                        <box id = "Fixed_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>

                                            <!-- Start fixed label -->
                                            <label id = "Fixed_label" text = "Fixed" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                            </label add_to_box(Fixed_box, Fixed_label, START, FALSE, FALSE, 0, 0, 7, 0, 0)>
                                            <!-- End fixed label -->

                                            <!-- Start fixed grid -->
                                            <grid id = "Fixed_grid" rows_spacing = 7 columns_spacing = 7 rows_homogeneous = TRUE columns_homogeneous = FALSE>

                                                <!-- Start fixed add button  -->
                                                <button id = "Fixed_add" label = "                                                        Add                                                 ">

                                                </button add_to_grid(Fixed_grid, Fixed_add, 0, 0, 2, 1)>
                                                <!-- End fixed add button  -->

                                            </grid add_to_box(Fixed_box, Fixed_grid, START, FALSE, FALSE, 0, 0, 0, 0, 0)>
                                            <!-- End fixed grid -->

                                        </box add_to_box(Containers_box, Fixed_box, START, TRUE, TRUE, 0, 14, 0, 0, 0)>
                                        <!-- End fixed box -->

                                        <!-- Start frame box -->
                                        <box id = "Frame_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>

                                            <!-- Start frame label -->
                                            <label id = "Frame_label" text = "Frame" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                            </label add_to_box(Frame_box, Frame_label, START, FALSE, FALSE, 0, 0, 0, 0, 0)>
                                            <!-- End frame label -->

                                            <!-- Start frame grid -->
                                            <grid id = "Frame_grid" rows_spacing = 7 columns_spacing = 7 rows_homogeneous = TRUE columns_homogeneous = FALSE>

                                                <!-- Start frame title label -->
                                                <label id = "Frame_title_label" text = "Title" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                </label add_to_grid(Frame_grid, Frame_title_label, 0, 0, 1, 1)>
                                                <!-- End frame title label -->

                                                <!-- Start frame title value entry -->
                                                <entry id = "Frame_title_value" max_length = "20" editable = TRUE>

                                                </entry add_to_grid(Frame_grid, Frame_title_value, 0, 1, 1, 1)>
                                                <!-- End frame title value entry -->

                                                <!-- Start frame horizontal placement label -->
                                                <label id = "Frame_horizontal_placement_label" text = "Horizontal placement" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                </label add_to_grid(Frame_grid, Frame_horizontal_placement_label, 1, 0, 1, 1)>
                                                <!-- End frame horizontal placement label -->

                                                <!-- Start frame horizontal placement value spin button -->
                                                <spin_button id = "Frame_horizontal_placement_value" min = "0" max = "1" step = "0.5" value = "0.5" digits = "1" numeric = TRUE>

                                                </spin_button add_to_grid(Frame_grid, Frame_horizontal_placement_value, 1, 1, 1, 1)>
                                                <!-- End frame horizontal placement value spin button -->

                                                <!-- Start frame vertical placement label -->
                                                <label id = "Frame_vertical_placement_label" text = "Vertical placement" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                </label add_to_grid(Frame_grid, Frame_vertical_placement_label, 2, 0, 1, 1)>
                                                <!-- End frame vertical placement label -->

                                                <!-- Start frame vertical placement value spin button -->
                                                <spin_button id = "Frame_vertical_placement_value" min = "0" max = "1" step = "0.5" value = "0.5" digits = "1" numeric = TRUE>

                                                </spin_button add_to_grid(Frame_grid, Frame_vertical_placement_value, 2, 1, 1, 1)>
                                                <!-- End frame vertical placement value spin button -->


                                                <!-- Start frame add button  -->
                                                <button id = "Frame_add" label = "                                                        Add                                                 ">

                                                </button add_to_grid(Frame_grid, Frame_add, 3, 0, 2, 1)>
                                                <!-- End frame add button  -->

                                            </grid add_to_box(Frame_box, Frame_grid, START, FALSE, FALSE, 0, 14, 0, 0, 0)>
                                            <!-- End frame grid -->

                                        </box add_to_box(Containers_box, Frame_box, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                        <!-- End frame box -->

                                        <!-- Start grid box -->
                                        <box id = "Grid_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>

                                            <!-- Start grid label -->
                                            <label id = "Grid_label" text = "Grid" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                            </label add_to_box(Grid_box, Grid_label, START, FALSE, FALSE, 0, 0, 0, 0, 0)>
                                            <!-- End grid label -->

                                            <!-- Start grid grid -->
                                            <grid id = "Grid_grid" rows_spacing = 7 columns_spacing = 7 rows_homogeneous = TRUE columns_homogeneous = FALSE>

                                                <!-- Start grid rows spacing label  -->
                                                <label id = "Grid_rows_spacing_label" text = "Rows spacing" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                </label add_to_grid(Grid_grid, Grid_rows_spacing_label, 0, 0, 1, 1)>
                                                <!-- End grid rows spacing label  -->

                                                <!-- Start grid rows spacing value spin button  -->
                                                <spin_button id = "Grid_rows_spacing_value" min = "0" max = "100" step = "5" value = "0" digits = 0 numeric = TRUE>

                                                </spin_button add_to_grid(Grid_grid, Grid_rows_spacing_value, 0, 1, 1, 1)>
                                                <!-- End grid rows spacing value spin button  -->

                                                <!-- Start grid columns spacing label  -->
                                                <label id = "Grid_columns_spacing_label" text = "Columns spacing" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                </label add_to_grid(Grid_grid, Grid_columns_spacing_label, 1, 0, 1, 1)>
                                                <!-- End grid columns spacing label  -->

                                                <!-- Start grid columns spacing value spin button  -->
                                                <spin_button id = "Grid_columns_spacing_value" min = "0" max = "100" step = "5" value = "0" digits = 0 numeric = TRUE>

                                                </spin_button add_to_grid(Grid_grid, Grid_columns_spacing_value, 1, 1, 1, 1)>
                                                <!-- End grid columns spacing value spin button  -->

                                                <!-- Start grid rows homogeneous label  -->
                                                <label id = "Grid_rows_homogeneous_label" text = "Rows homogeneous" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                </label add_to_grid(Grid_grid, Grid_rows_homogeneous_label, 2, 0, 1, 1)>
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

                                                </combo_box add_to_grid(Grid_grid, Grid_rows_homogeneous_value, 2, 1, 1, 1)>
                                                <!-- End grid rows homogeneous value combo box  -->

                                                <!-- Start grid columns homogeneous label  -->
                                                <label id = "Grid_columns_homogeneous_label" text = "Columns homogeneous" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                </label add_to_grid(Grid_grid, Grid_columns_homogeneous_label, 3, 0, 1, 1)>
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

                                                </combo_box add_to_grid(Grid_grid, Grid_columns_homogeneous_value, 3, 1, 1, 1)>
                                                <!-- End grid columns homogeneous value combo box  -->

                                                <!-- Start grid add button  -->
                                                <button id = "Grid_add" label = "                                                        Add                                                 ">

                                                </button add_to_grid(Grid_grid, Grid_add, 4, 0, 2, 1)>
                                                <!-- End fixed add button  -->

                                            </grid add_to_box(Grid_box, Grid_grid, START, FALSE, FALSE, 0, 14, 0, 0, 0)>
                                            <!-- End grid grid -->

                                        </box add_to_box(Containers_box, Grid_box, START, TRUE, TRUE, 0, 14, 0, 0, 0)>
                                        <!-- End grid box -->

                                        <!-- Start paned box -->
                                        <box id = "Paned_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>

                                            <!-- Start paned label -->
                                            <label id = "Paned_label" text = "Paned" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                            </label add_to_box(Paned_box, Paned_label, START, FALSE, FALSE, 0, 0, 0, 0, 0)>
                                            <!-- End paned label -->

                                            <!-- Start grid paned -->
                                            <grid id = "Paned_grid" rows_spacing = 7 columns_spacing = 7 rows_homogeneous = TRUE columns_homogeneous = FALSE>

                                                <!-- Start paned orientation label  -->
                                                <label id = "Paned_orientation_label" text = "Orientation" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                </label add_to_grid(Paned_grid, Paned_orientation_label, 0, 0, 1, 1)>
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

                                                </combo_box add_to_grid(Paned_grid, Paned_orientation_value, 0, 1, 1, 1)>
                                                <!-- End paned orientation value combo box  -->

                                                <!-- Start paned default position label  -->
                                                <label id = "Paned_default_position_label" text = "Default position" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                </label add_to_grid(Paned_grid, Paned_default_position_label, 1, 0, 1, 1)>
                                                <!-- End paned default position label  -->

                                                <!-- Start paned default position value spin button  -->
                                                <spin_button id = "Paned_default_position_value" min = "0" max = "1000" step = "100" value = "500" digits = 0 numeric = TRUE>

                                                </spin_button add_to_grid(Paned_grid, Paned_default_position_value, 1, 1, 1, 1)>
                                                <!-- End paned default position value spin button  -->

                                                <!-- Start paned show handle label -->
                                                <label id = "Paned_show_handle_label" text = "Show Handle" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                </label add_to_grid(Paned_grid, Paned_show_handle_label, 2, 0, 1, 1)>
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

                                                </combo_box add_to_grid(Paned_grid, Paned_show_handle_combo_box, 2, 1, 1, 1)>
                                                <!-- End paned show handle combo box -->

                                                <!-- Start paned add button  -->
                                                <button id = "Paned_add" label = "                                                        Add                                                 ">

                                                </button add_to_grid(Paned_grid, Paned_add, 3, 0, 2, 1)>
                                                <!-- End fixed add button  -->
                                                

                                            </grid add_to_box(Paned_box, Paned_grid, START, FALSE, FALSE, 0, 14, 0, 0, 0)>
                                            <!-- End grid paned -->

                                        </box add_to_box(Containers_box, Paned_box, START, TRUE, TRUE, 0, 14, 0, 0, 10)>
                                        <!-- End paned box -->

                                        <!-- Start stack box -->
                                        <box id = "Stack_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>

                                            <!-- Start Stack label -->
                                            <label id = "Stack_label" text = "Stack" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                            </label add_to_box(Stack_box, Stack_label, START, FALSE, FALSE, 0, 0, 7, 0, 0)>
                                            <!-- End Stack label -->

                                            <!-- Start Stack grid -->
                                            <grid id = "Stack_grid" rows_spacing = 7 columns_spacing = 7 rows_homogeneous = TRUE columns_homogeneous = FALSE>

                                                <!-- Start stack switcher-widget label -->
                                                <label id = "stack_switcher_widget_label" text = "Switcher ID" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                </label add_to_grid(Stack_grid, stack_switcher_widget_label, 0, 0, 1, 1)>
                                                <!-- End Stack switcher-widget label -->

                                                <!-- Start stack switcher-widget entry value -->
                                                <entry id = "stack_switcher_widget_entry" indicator_text = "The switcher ID">

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
                                                <button id = "stack_informations_add_button" label = "                                                        Add                                                 ">

                                                </button add_to_grid(Stack_grid, stack_informations_add_button, 3, 0, 2, 1)>
                                                <!-- End stack informations add button -->

                                            </grid add_to_box(Stack_box, Stack_grid, START, FALSE, FALSE, 0, 0, 0, 0, 0)>
                                            <!-- End Stack grid -->

                                        </box add_to_box(Containers_box, Stack_box, START, TRUE, TRUE, 0, 14, 0, 0, 0)>
                                        <!-- End stack box -->

                                        <!-- Start switcher box -->
                                        <box id = "Switcher_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 10>

                                            <!-- Start switcher label -->
                                            <label id = "Switcher_label" text = "Switcher"  size = 14 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                            </label add_to_box(Switcher_box, Switcher_label, START, TRUE, TRUE, 0, 14, 10, 0, 0)>
                                            <!-- End switcher label -->

                                            <!-- Start Switcher grid -->
                                            <grid id = "Switcher_grid" rows_spacing = 7 columns_spacing = 7 rows_homogeneous = TRUE columns_homogeneous = FALSE>

                                                <!-- Start switcher spacing label -->
                                                <label id = "switcher_spacing_label" text = "Spacing" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                </label add_to_grid(Switcher_grid, switcher_spacing_label, 0, 0, 1, 1)>
                                                <!-- End switcher spacing label -->

                                                <!-- Start switcher spacing value spin button -->
                                                <spin_button id = "switcher_spacing_value_spin_button" min = 0 max = 100 step = 5 value = 5 digits = 0 numeric = TRUE>

                                                </spin_button add_to_grid(Switcher_grid, switcher_spacing_value_spin_button, 0, 1, 1, 1)>
                                                <!-- End switcher spacing value spin button -->

                                                <!-- Start same size label -->
                                                <label id = "same_size_label" text = "Same Size" size = 12 font = "Arial" color = "#000000" background = "#f6f5f4" justify = "GTK_JUSTIFY_LEFT">

                                                </label add_to_grid(Switcher_grid, same_size_label, 1, 0, 1, 1)>
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

                                                </combo_box add_to_grid(Switcher_grid, same_size_value_combo_box, 1, 1, 1, 1)>
                                                <!-- End same size value combo box -->

                                                <!-- Start switcher informations add button -->
                                                <button id = "switcher_informations_add_button" label = "                                                        Add                                                 ">

                                                </button add_to_grid(Switcher_grid, switcher_informations_add_button, 2, 0, 2, 1)>
                                                <!-- End switcher informations add button -->

                                            </grid add_to_box(Switcher_box, Switcher_grid, START, FALSE, FALSE, 0, 0, 0, 0, 0)>
                                            <!-- End Switcher grid -->

                                        </box add_to_box(Containers_box, Switcher_box, START, TRUE, TRUE, 0, 14, 0, 0, 0)>
                                        <!-- End switcher box -->

                                        <!-- Start containers button -->
                                        <button id = "Containers" label = "Containers">
            
                                        </button add_to_box(Containers_box, Containers, START, TRUE, TRUE, 0, 17, 0, 0, 0)>
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