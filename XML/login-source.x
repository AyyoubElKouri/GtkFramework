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

                                
                                <!-- Start Scrolled Windows window -->
                                <scrolled_window id = "scrolled_windows_window" horizontal = FALSE vertical = TRUE>

                                    <!-- Start Windows box -->
                                    <box id = "Windows_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>

                                        <!-- Start widnows button -->
                                        <button id = "Windows" label = "Windows">
            
                                        </button add_to_box(Windows_box, Windows, START, TRUE, TRUE, 0, 7, 0, 0, 0)>
                                        <!-- End Widnows button -->

                                        <!-- Start Windows button -->
                                        <button id = "Windows2" label = "Windows">

                                        </button add_to_box(Windows_box, Windows2, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                        <!-- End Windows button -->

                                        <!-- Start Windows button -->
                                        <button id = "Windows3" label = "Windows">

                                        </button add_to_box(Windows_box, Windows3, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                        <!-- End Windows button -->

                                        <!-- Start Windows button -->
                                        <button id = "Windows4" label = "Windows">

                                        </button add_to_box(Windows_box, Windows4, START, TRUE, TRUE, 0, 0, 0, 0, 0)>
                                        <!-- End Windows button -->

                                    </box add_to_scrolled_window(scrolled_windows_window, Windows_box)>
                                    <!-- End Windows box -->

                                </scrolled_window add_to_stack(stack_catalog, scrolled_windows_window, "Windows")>
                                <!-- End Scrolled Windows window -->


                                <!-- Start Scrolled Containers window -->
                                <scrolled_window id = "scrolled_containers_window" horizontal = FALSE vertical = TRUE>

                                    <!-- Start Containers box -->
                                    <box id = "Containers_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>

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
                                    <box id = "Widgets_box" orientation = GTK_ORIENTATION_VERTICAL align = -1 spacing = 0>

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