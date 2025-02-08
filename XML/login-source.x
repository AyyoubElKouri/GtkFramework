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
    
                        <!-- Start the "hierarchy widgets" label -->
                        <label id = "hierarchy_widgets_label" text = "Widgets Hierarchy" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4"  justify = "GTK_JUSTIFY_RIGHT">
    
                        </label add_to_box(hierarchy_widgets_label_box, hierarchy_widgets_label, START, TRUE, FALSE, 0, 0, 0, 0, 7)>
                        <!-- End the "hierarchy widgets" label -->
    
                    </box add_to_box(hierarchy_widgets_box, hierarchy_widgets_label_box, START, FALSE, FALSE, 0, 7, 0, 12, 7)>
                    <!-- End the hierarchy widgets label box -->

                    <!-- Start the test button -->
                    <button id = "test_button"  label = "This space is reserved for\n the Widgets Hierarchy">
    
                    </button add_to_box(hierarchy_widgets_box, test_button, START, TRUE, TRUE, 0, 7, 0, 0, 7)>
                    <!-- End the test button -->

                </box add_to_paned(main_paned, hierarchy_widgets_box, FIRST)>
                <!-- End the hierarchy widgets box -->

                <!-- Start build space paned -->
                <paned id = "build_space_paned" orientation = GTK_ORIENTATION_HORIZONTAL default_position = 860 show_handle = TRUE>

                    <!-- Start middle space box -->
                    <box id = "middle_space_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>

                        <!-- Start the middle space paned -->
                        <paned id = "middle_space_paned" orientation = GTK_ORIENTATION_VERTICAL default_position = 500 show_handle = TRUE>

                            <!-- Start middle space diplay box -->
                            <box id = "middle_space_display_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>

                                <!-- Start the working space label box -->
                                <box id = "working_space_label_box" orientation = GTK_ORIENTATION_HORIZONTAL align = GTK_ALIGN_START spacing = 0>
            
                                    <!-- Start the "working space" label -->
                                    <label id = "working_space_label" text = "Working Space" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4"  justify = "GTK_JUSTIFY_RIGHT">
            
                                    </label add_to_box(working_space_label_box, working_space_label, START, TRUE, FALSE, 0, 0, 0, 0, 7)>
                                    <!-- End the "working space" label -->
        
                                </box add_to_box(middle_space_display_box, working_space_label_box, START, FALSE, FALSE, 0, 0, 0, 12, 7)>
                                <!-- End the working space label box -->
        
                                <!-- Start the test button2 -->
                                <button id = "test_button3"  label = "This space is reserved for the Working Space">
        
                                </button add_to_box(middle_space_display_box, test_button3, START, TRUE, TRUE, 0, 7, 0, 0, 0)>
                                <!-- End the test button2 -->

                            </box add_to_paned(middle_space_paned, middle_space_display_box, FIRST)>
                            <!-- End middle space diplay box -->
                             
    
                            <!-- Start the widgets informations box -->
                            <box id = "widgets_informations_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>

                                <!-- Start the widgets informations label box -->
                                <box id = "widgets_informations_label_box" orientation = GTK_ORIENTATION_HORIZONTAL align = GTK_ALIGN_START spacing = 0>
    
                                    <!-- Start the "widgets informations" label -->
                                    <label id = "widgets_informations_label" text = "Widgets Informations" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4"  justify = "GTK_JUSTIFY_RIGHT">
    
                                    </label add_to_box(widgets_informations_label_box, widgets_informations_label, START, TRUE, FALSE, 0, 0, 0, 0, 7)>
                                    <!-- End the "widgets informations" label -->
    
                                </box add_to_box(widgets_informations_box, widgets_informations_label_box, START, FALSE, FALSE, 0, 7, 0, 12, 7)>
    
                                <!-- Start the button test -->
                                <button id = "button_test4"  label = "This space is reserved for the Widgets Informations">
    
                                </button add_to_box(widgets_informations_box, button_test4, START, TRUE, TRUE, 0, 7, 0, 0, 0)>
                                <!-- End the button test -->
    
                            </box add_to_paned(middle_space_paned, widgets_informations_box, SECOND)>
                            <!-- End the widgets informations box -->

                        </paned add_to_box(middle_space_box, middle_space_paned, START, TRUE, TRUE, 0, 7, 0, 7, 7)>
                        <!-- End the middle space paned -->
                    
                    </box add_to_paned(build_space_paned, middle_space_box, FIRST)>
                    <!-- End middle space box -->

                    <!-- Start the second space box -->
                    <box id = "second_space_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>

                        <!-- Start the second space label box -->
                        <box id = "second_space_label_box" orientation = GTK_ORIENTATION_HORIZONTAL align = GTK_ALIGN_START spacing = 0>
    
                            <!-- Start the "second space" label -->
                            <label id = "second_space_label" text = "Widgets Catalog" size = 14 font = "Arial" color = "#000000" background = "#f6f5f4"  justify = "GTK_JUSTIFY_RIGHT">
    
                            </label add_to_box(second_space_label_box, second_space_label, START, TRUE, FALSE, 0, 0, 0, 0, 7)>
                            <!-- End the "second space" label -->
    
                        </box add_to_box(second_space_box, second_space_label_box, START, FALSE, FALSE, 0, 7, 0, 12, 7)>
                        <!-- End the second space label box -->

                        <!-- Start test button2 -->
                        <button id = "test_button2"  label = "This space is reserved for\n the Widgets Catalog">

                        </button add_to_box(second_space_box, test_button2, START, TRUE, TRUE, 0, 7, 0, 7, 0)>
                        <!-- End test button2 -->

                    </box add_to_paned(build_space_paned, second_space_box, SECOND)>

                </paned add_to_paned(main_paned, build_space_paned, SECOND)>
                <!-- End build space paned -->

            </paned add_to_box(app_box, main_paned, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
            <!-- End main paned -->

        </box add_to_box(main_box, app_box, START, TRUE, TRUE, 0, 7, 0, 7, 7)>
        <!-- End App box -->
        
        <!-- Start the control box -->
        <box id = "control_box" orientation = GTK_ORIENTATION_HORIZONTAL align = -1 spacing = 0>

            <!-- Start the generate button -->
            <button id = "generate_button"  label = "Generate">
    
            </button add_to_box(control_box, generate_button, START, FALSE, FALSE, 0, 0, 0, 0, 7)>
            <!-- End the generate button -->
            
            <!-- Start the drag button -->
            <button id = "drag_button"  label = "Drag">

            </button add_to_box(control_box, drag_button, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
            <!-- End the drag button -->

        </box add_to_box(main_box, control_box, START, FALSE, FALSE, 0, 7, 7, 7, 7)>
        <!-- End the control box -->

    </box add_to_container(window, main_box)>
    <!-- End the main box -->

</window show_widget(window)>
<!-- End Window -->