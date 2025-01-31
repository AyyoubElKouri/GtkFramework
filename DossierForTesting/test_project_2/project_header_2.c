/*****************************************************************************************************************************
 * 
 * @project: Information about all widgets in the static library
 * @file project_header.c
 * @brief the implementation file of the widgets project
 * 
 * 
 * @test testWidgets N°: 1.2.0
 * 
 * @author Ayyoub el Kouri
 * @date 28/01/2025
 * @version 1.0 (last update 28/01/2025)
 * 
 ******************************************************************************************************************************/

#include "project_header_2.h"

static void start_spinner_callback(GtkWidget *widget, gpointer data)
{
    start_spinner(data);
}

static void stop_spinner_callback(GtkWidget *widget, gpointer data)
{
    stop_spinner(data);
}


void project2(GtkApplication *app)
{
    /*---Start Window---*/
    GtkWidget *window = create_window(app, GTK_WINDOW_TOPLEVEL, "Widgets", 1100, 600, TRUE, GTK_WIN_POS_CENTER, TRUE, NULL, 1.0, FALSE);

        /*---Start Header Bar---*/
        GtkWidget *header_bar = create_header_bar("Widgets", "Project 2", "assets/Application_icon/apple.png", TRUE);
            
        /*---Start Menu Button---*/
            GtkWidget *menu_button = create_menu_button("Menu",NULL, GTK_ARROW_DOWN);

                /*---Start Menu---*/
                GtkWidget *menu = create_menu(TRUE, "Menu");
                
                    /*---Start Menu Item---*/
                    GtkWidget *menu_item = create_menu_item("Test1", "normal", NULL, NULL, NULL);
                    add_to_menu(menu, menu_item);
                    /*---End Menu Item---*/

                    /*---Start Menu Item---*/
                    GtkWidget *menu_item2 = create_menu_item("Test2", "normal", NULL, NULL, NULL);
                    add_to_menu(menu, menu_item2);
                    /*---End Menu Item---*/

                    /*---Start Menu Item---*/
                    GtkWidget *menu_item3 = create_menu_item("Test3", "normal", NULL, NULL, NULL);
                    add_to_menu(menu, menu_item3);
                    /*---End Menu Item---*/
                
                add_to_menu_button(menu_button, menu);
                /*---End Menu---*/
            
            add_to_header_bar(header_bar, menu_button, LEFT);
            /*---End Menu Button---*/

        add_header_bar_to_window(window, header_bar);
        /*---End Header Bar---*/
    
        /*---Start Scrolled Window---*/
        GtkWidget *scrolled_window = create_scrolled_window(FALSE, TRUE);
        
            /*---Start Main Box---*/
            GtkWidget *main_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

                /*---Start Main Stack---*/
                GtkWidget *main_stack = create_stack(GTK_STACK_TRANSITION_TYPE_SLIDE_LEFT_RIGHT, 500);

                    /*---Start Stack box 1---*/
                    GtkWidget *stack_box1 = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

                        /*---Start Line1 box---*/
                        GtkWidget *line1_box = create_box(GTK_ORIENTATION_HORIZONTAL, -1, 0);

                            /*---Start Frame button Box---*/
                            GtkWidget *frame_button_box = create_frame("Normal Button", 0.5, 1);

                                /*---Start Button Box---*/
                                GtkWidget *button_box = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_CENTER, 10);
                                    
                                    /*---Start Button 1---*/
                                    GtkWidget *button1 = create_button(GTK_RELIEF_NORMAL, "Button 1", FALSE, NULL, NULL, NULL);
                                    add_to_box(button_box, button1, START, FALSE, FALSE, 0, 0, 0, 0, 0);
                                    /*---End Button 1---*/

                                    /*---Start Button 2---*/
                                    GtkWidget *button2 = create_button(GTK_RELIEF_NORMAL, "Button 2", FALSE, NULL, NULL, NULL);
                                    add_to_box(button_box, button2, START, FALSE, FALSE, 0, 0, 0, 0, 0);
                                    /*---End Button 2---*/

                                    /*---Start Button 3---*/
                                    GtkWidget *button3 = create_button(GTK_RELIEF_NORMAL, "Button 3", FALSE, NULL, NULL, NULL);
                                    add_to_box(button_box, button3, START, FALSE, FALSE, 0, 0, 0, 0, 0);
                                    /*---End Button 3---*/

                                add_to_frame(frame_button_box, button_box, 10, 10, 20, 20);
                                /*---End Button Box---*/

                            add_to_box(line1_box, frame_button_box, START, TRUE, FALSE, 0, 0, 0, 0, 0);
                            /*---End Frame button Box---*/

                            /*---Start Frame check button Box---*/
                            GtkWidget *frame_check_button_box = create_frame("Check Button", 0.5, 1);

                                /*---Start Check button Box---*/
                                GtkWidget *check_button_box = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_CENTER, 0);

                                    /*---Start Check button 1---*/  
                                    GtkWidget *check_button1 = create_check_button("Check button 1", FALSE, FALSE, NULL, NULL);
                                    add_to_box(check_button_box, check_button1, START, FALSE, FALSE, 0, 0, 0, 0, 0);
                                    /*---End Check button 1---*/

                                    /*---Start Check button 2---*/
                                    GtkWidget *check_button2 = create_check_button("Check button 2", FALSE, FALSE, NULL, NULL);
                                    add_to_box(check_button_box, check_button2, START, FALSE, FALSE, 0, 0, 0, 0, 0);
                                    /*---End Check button 2---*/

                                    /*---Start Check button 3---*/
                                    GtkWidget *check_button3 = create_check_button("Check button 3", FALSE, FALSE, NULL, NULL);
                                    add_to_box(check_button_box, check_button3, START, FALSE, FALSE, 0, 0, 0, 0, 0);
                                    /*---End Check button 3---*/

                                add_to_frame(frame_check_button_box, check_button_box, 10, 10, 20, 20);
                                /*---End Check button Box---*/
                            
                            add_to_box(line1_box, frame_check_button_box, START, TRUE, FALSE, 0, 0, 0, 0, 0);
                            /*---End Frame check button Box---*/

                            /*---Start Frame color button Box---*/
                            GtkWidget *frame_color_button_box = create_frame("Color Button", 0.5, 1);

                                /*---Start color button Box---*/
                                GtkWidget *color_button_box = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_CENTER, 0);

                                    /*---Start Color button---*/
                                    GtkWidget *color_button = create_color_button("#000000", "Color Button", TRUE);

                                    add_to_box(color_button_box, color_button, START, FALSE, FALSE, 0, 0, 0, 0, 0);
                                    /*---End Color button---*/

                                add_to_frame(frame_color_button_box, color_button_box, 10, 10, 20, 20);
                                /*---End Color button Box---*/
                            
                            add_to_box(line1_box, frame_color_button_box, START, TRUE, FALSE, 0, 0, 0, 0, 0);
                            /*---End Frame Color button Box---*/

                            /*---Start Frame Switch button Box---*/
                            GtkWidget *frame_switch_button_box = create_frame("Switch Button", 0.5, 1);

                                /*---Start Switch Button Box---*/
                                GtkWidget *switch_button_box = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_CENTER, 0);

                                    /*---Start Switch Button---*/
                                    GtkWidget *switch_button = create_switch_button(FALSE, NULL, NULL);
                                    add_to_box(switch_button_box, switch_button, START, FALSE, FALSE, 0, 0, 0, 0, 0);
                                    /*---End Switch Button---*/

                                add_to_frame(frame_switch_button_box, switch_button_box, 10, 10, 20, 20);
                                /*---End Switch Button Box---*/
                            
                            add_to_box(line1_box, frame_switch_button_box, START, TRUE, FALSE, 0, 0, 0, 0, 0);
                            /*---End Frame Switch button Box---*/

                        add_to_box(stack_box1, line1_box, START, TRUE, FALSE, 0, 0, 30, 0, 0);
                        /*---End Line1 box---*/


                        /*---Start Line2 box---*/
                        GtkWidget *line2_box = create_box(GTK_ORIENTATION_HORIZONTAL, -1, 0);

                            /*---Start frame entry Box---*/
                            GtkWidget *frame_entry_box = create_frame("Entry", 0.5, 1);

                                /*---Start Entry Box---*/
                                GtkWidget *entry_box = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_CENTER, 0);

                                    /*---Start Username Entry---*/
                                    GtkWidget *username_entry = create_entry(NULL, "Username", TRUE, TRUE, 15, 0.5);
                                    add_to_box(entry_box, username_entry, START, FALSE, FALSE, 0, 0, 10, 0, 0);
                                    /*---End Username Entry---*/

                                    /*---Start Password Entry---*/
                                    GtkWidget *password_entry = create_entry(NULL, "Password", FALSE, TRUE, 15, 0.5);
                                    add_to_box(entry_box, password_entry, START, FALSE, FALSE, 0, 0, 10, 0, 0);
                                    /*---End Password Entry---*/

                                add_to_frame(frame_entry_box, entry_box, 10, 10, 20, 20);
                                /*---End Entry Box---*/
                            
                            add_to_box(line2_box, frame_entry_box, START, TRUE, FALSE, 0, 0, 0, 0, 0);
                            /*---End Frame entry Box---*/

                            /*---Start frame font Box---*/
                            GtkWidget *frame_font_box = create_frame("Font", 0.5, 1);

                                /*---Start Font Box---*/
                                GtkWidget *font_box = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_CENTER, 0);

                                    /*---Start Font button---*/
                                    GtkWidget *font_button = create_font_button("consolas", "Fonts", TRUE, TRUE, TRUE, TRUE);
                                    add_to_box(font_box, font_button, START, FALSE, FALSE, 0, 0, 10, 0, 0);
                                    /*---End Font button---*/

                                add_to_frame(frame_font_box, font_box, 10, 10, 20, 20);
                                /*---End Font Box---*/
                            
                            add_to_box(line2_box, frame_font_box, START, TRUE, FALSE, 0, 0, 0, 0, 0);
                            /*---End Frame font Box---*/

                            /*---Start frame image Box---*/
                            GtkWidget *frame_image_box = create_frame("Image", 0.5, 1);

                                /*---Start Image Box---*/
                                GtkWidget *image_box = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_CENTER, 0);

                                    /*---Start Image---*/
                                    GtkWidget *image = create_image("assets/w160/ma.png");
                                    add_to_box(image_box, image, START, FALSE, FALSE, 0, 0, 10, 0, 0);
                                    /*---End Image---*/

                                add_to_frame(frame_image_box, image_box, 10, 10, 20, 20);
                                /*---End Image Box---*/
                            
                            add_to_box(line2_box, frame_image_box, START, TRUE, FALSE, 0, 0, 0, 0, 0);
                            /*---End Frame image Box---*/

                            /*---Start frame label Box---*/
                            GtkWidget *frame_label_box = create_frame("Label", 0.5, 1);

                                /*---Start Label Box---*/
                                GtkWidget *label_box = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_CENTER, 0);

                                    /*---Start Label---*/
                                    GtkWidget *label = create_label("Label test", 16, "consolas", "#FF3233", "#0033EE", GTK_JUSTIFY_CENTER, TRUE, PANGO_WEIGHT_BOLD, PANGO_STYLE_ITALIC, TRUE);
                                    add_to_box(label_box, label, START, FALSE, FALSE, 0, 0, 10, 0, 0);
                                    /*---End Label---*/

                                add_to_frame(frame_label_box, label_box, 10, 10, 20, 20);
                                /*---End Label Box---*/
                            
                            add_to_box(line2_box, frame_label_box, START, TRUE, FALSE, 0, 0, 0, 0, 0);
                            /*---End Frame label Box---*/

                        add_to_box(stack_box1, line2_box, START, TRUE, FALSE, 0, 0, 10, 0, 0);
                        /*---End Line2 box---*/


                        /*---Start Line3 box---*/
                        GtkWidget *line3_box = create_box(GTK_ORIENTATION_HORIZONTAL, -1, 0);

                            /*---Start frame level bar Box---*/
                            GtkWidget *frame_level_bar_box = create_frame("Level Bar", 0.5, 1);

                                /*---Start Level Bar Box---*/
                                GtkWidget *level_bar_box = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_CENTER, 0);

                                    /*---Start Level Bar---*/
                                    GtkWidget *level_bar = create_level_bar(0, 10, 50, GTK_LEVEL_BAR_MODE_CONTINUOUS, FALSE);
                                    add_to_box(level_bar_box, level_bar, START, TRUE, TRUE, 0, 0, 0, 0, 0);
                                    /*---End Level Bar---*/

                                add_to_frame(frame_level_bar_box, level_bar_box, 10, 10, 20, 20);
                                /*---End Level Bar Box---*/
                            
                            add_to_box(line3_box, frame_level_bar_box, START, TRUE, FALSE, 0, 10, 0, 0, 0);
                            /*---End Frame level bar Box---*/

                            /*---Start frame progress bar Box---*/
                            GtkWidget *frame_progress_bar_box = create_frame("Progress Bar", 0.5, 1);

                                /*---Start Progress Bar Box---*/
                                GtkWidget *progress_bar_box = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_CENTER, 0);

                                    /*---Start Progress Bar---*/
                                    GtkWidget *progress_bar = create_progress_bar("test", 0.5, TRUE, FALSE, FALSE);
                                    add_to_box(progress_bar_box, progress_bar, START, FALSE, FALSE, 0, 0, 0, 0, 0);
                                    /*---End Progress Bar---*/

                                add_to_frame(frame_progress_bar_box, progress_bar_box, 10, 10, 20, 20);
                                /*---End Progress Bar Box---*/
                            
                            add_to_box(line3_box, frame_progress_bar_box, START, TRUE, FALSE, 0, 10, 0, 0, 0);
                            /*---End Frame progress bar Box---*/

                            /*---Start frame link button Box---*/
                            GtkWidget *frame_link_button_box = create_frame("Link Button", 0.5, 1);

                                /*---Start Link Button Box---*/
                                GtkWidget *link_button_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

                                    /*---Start Link Button---*/
                                    GtkWidget *link_button = create_link_button("https://google.com", "Google");
                                    add_to_box(link_button_box, link_button, START, TRUE, TRUE, 0, 0, 0, 0, 0);
                                    /*---End Link Button---*/

                                add_to_frame(frame_link_button_box, link_button_box, 10, 10, 20, 20);
                                /*---End Link Button Box---*/
                            
                            add_to_box(line3_box, frame_link_button_box, START, TRUE, FALSE, 0, 10, 0, 0, 0);
                            /*---End Frame link button Box---*/

                            /*---Start frame radio button Box---*/
                            GtkWidget *frame_radio_button_box = create_frame("Radio Button", 0.5, 1);

                                /*---Start Radio Button Box---*/
                                GtkWidget *radio_button_box = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_CENTER, 0);

                                    /*---Start Radio Button 1---*/
                                    GtkWidget *radio_button_1 = create_radio_button("Radio Button 1", NULL, NULL, TRUE);
                                    add_to_box(radio_button_box, radio_button_1, START, FALSE, FALSE, 0, 0, 10, 0, 0);
                                    /*---End Radio Button 1---*/

                                    /*---Start Radio Button 2---*/
                                    GtkWidget *radio_button_2 = create_radio_button("Radio Button 2", NULL, radio_button_1, FALSE);
                                    add_to_box(radio_button_box, radio_button_2, START, FALSE, FALSE, 0, 0, 10, 0, 0);
                                    /*---End Radio Button 2---*/

                                    /*---Start Radio Button 3---*/
                                    GtkWidget *radio_button_3 = create_radio_button("Radio Button 3", NULL, radio_button_2, FALSE);
                                    add_to_box(radio_button_box, radio_button_3, START, FALSE, FALSE, 0, 0, 10, 0, 0);
                                    /*---End Radio Button 3---*/

                                add_to_frame(frame_radio_button_box, radio_button_box, 10, 10, 20, 20);
                                /*---End Radio Button Box---*/
                            
                            add_to_box(line3_box, frame_radio_button_box, START, TRUE, FALSE, 0, 10, 0, 0, 0);
                            /*---End Frame radio button Box---*/

                        add_to_box(stack_box1, line3_box, START, TRUE, FALSE, 0, 0, 10, 0, 0);
                        /*---End Line3 box---*/

                        /*---Start Line4 box---*/
                        GtkWidget *line4_box = create_box(GTK_ORIENTATION_HORIZONTAL, -1, 0);

                            /*---Start frame scale Box---*/
                            GtkWidget *frame_scale_box = create_frame("Scale", 0.5, 1);

                                /*---Start Scale Box---*/
                                GtkWidget *scale_box = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_CENTER, 0);

                                    /*---Start Scale---*/
                                    GtkWidget *scale = create_scale(GTK_ORIENTATION_HORIZONTAL, 0, 100, 1, 50, GTK_POS_TOP, "HELLO", 0, GTK_POS_TOP);
                                    add_to_box(scale_box, scale, START, FALSE, FALSE, 0, 0, 0, 0, 0);
                                    /*---End Scale---*/

                                add_to_frame(frame_scale_box, scale_box, 10, 10, 20, 20);
                                /*---End Scale Box---*/
                            
                            add_to_box(line4_box, frame_scale_box, START, TRUE, FALSE, 0, 10, 0, 0, 0);
                            /*---End Frame scale Box---*/

                            /*---Start frame separator Box---*/
                            GtkWidget *frame_separator_box = create_frame("Separator", 0.5, 1);

                                /*---Start Separator Box---*/
                                GtkWidget *separator_box = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_CENTER, 0);

                                    /*---Start button 1 Separator---*/
                                    GtkWidget *button_1_separator = create_button(GTK_RELIEF_NORMAL, "Button 1", FALSE, NULL, NULL, NULL);
                                    add_to_box(separator_box, button_1_separator, START, FALSE, FALSE, 0, 0, 10, 0, 0);
                                    /*---End button 1 Separator---*/

                                    /*---Start Separator---*/
                                    GtkWidget *separator = create_separator(GTK_ORIENTATION_HORIZONTAL);
                                    add_to_box(separator_box, separator, START, FALSE, FALSE, 0, 0, 10, 0, 0);
                                    /*---End Separator---*/

                                    /*---Start button 2 Separator---*/
                                    GtkWidget *button_2_separator = create_button(GTK_RELIEF_NORMAL, "Button 2", FALSE, NULL, NULL, NULL);
                                    add_to_box(separator_box, button_2_separator, START, FALSE, FALSE, 0, 0, 10, 0, 0);
                                    /*---End button 2 Separator---*/

                                add_to_frame(frame_separator_box, separator_box, 10, 10, 20, 20);
                                /*---End Separator Box---*/
                            
                            add_to_box(line4_box, frame_separator_box, START, TRUE, FALSE, 0, 10, 0, 0, 0);
                            /*---End Frame separator Box---*/

                            /*---Start frame spinner Box---*/
                            GtkWidget *frame_spinner_box = create_frame("Spinner", 0.5, 1);

                                /*---Start Spinner Box---*/
                                GtkWidget *spinner_box = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_CENTER, 0);

                                    /*---Start spinner---*/
                                    GtkWidget *spinner = create_spinner(FALSE);
                                    add_to_box(spinner_box, spinner, START, FALSE, FALSE, 0, 0, 10, 0, 0);
                                    /*---End spinner---*/

                                    /*---Start Start-button Spinner---*/
                                    GtkWidget *start_button_spinner = create_button(GTK_RELIEF_NORMAL, "Start", FALSE, NULL,G_CALLBACK(start_spinner_callback), spinner);
                                    add_to_box(spinner_box, start_button_spinner, START, FALSE, FALSE, 0, 0, 10, 0, 0);
                                    /*---End Start-button Spinner---*/

                                    /*---Start Stop-button Spinner---*/
                                    GtkWidget *stop_button_spinner = create_button(GTK_RELIEF_NORMAL, "Stop", FALSE, NULL, G_CALLBACK(stop_spinner_callback), spinner);
                                    add_to_box(spinner_box, stop_button_spinner, START, FALSE, FALSE, 0, 0, 10, 0, 0);
                                    /*---End Stop-button Spinner---*/

                                add_to_frame(frame_spinner_box, spinner_box, 10, 10, 20, 20);
                                /*---End Spinner Box---*/
                            
                            add_to_box(line4_box, frame_spinner_box, START, TRUE, FALSE, 0, 10, 0, 0, 0);
                            /*---End Frame spinner Box---*/

                            /*---Start frame spin button Box---*/
                            GtkWidget *frame_spin_button_box = create_frame("Spin Button", 0.5, 1);

                                /*---Start Spin Button Box---*/
                                GtkWidget *spin_button_box = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_CENTER, 0);

                                    /*---Start spin button---*/
                                    GtkWidget *spin_button = create_spin_button(0, 10, 1, 5, 0, FALSE, TRUE);
                                    add_to_box(spin_button_box, spin_button, START, FALSE, FALSE, 0, 0, 10, 0, 0);
                                    /*---End spin button---*/

                                add_to_frame(frame_spin_button_box, spin_button_box, 10, 10, 20, 20);
                                /*---End Spin Button Box---*/
                            
                            add_to_box(line4_box, frame_spin_button_box, START, TRUE, FALSE, 0, 10, 0, 0, 0);
                            /*---End Frame spin button Box---*/

                            /*---Start frame text view Box---*/
                            GtkWidget *frame_text_view_box = create_frame("Write something (-.-) hh", 0.5, 1);

                                /*---Start Text View Box---*/
                                GtkWidget *text_view_box = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_CENTER, 0);

                                    /*---Start text view---*/
                                    GtkWidget *text_view = create_text_view("hello", 12, "consolas", "#000000", "#FFFFFF", GTK_JUSTIFY_CENTER, PANGO_WEIGHT_NORMAL, PANGO_STYLE_NORMAL, TRUE, TRUE, TRUE);
                                    add_to_box(text_view_box, text_view, START, FALSE, FALSE, 0, 0, 10, 0, 0);
                                    /*---End text view---*/

                                add_to_frame(frame_text_view_box, text_view_box, 10, 10, 20, 20);
                                /*---End Text View Box---*/
                            
                            add_to_box(line4_box, frame_text_view_box, START, TRUE, FALSE, 0, 10, 0, 0, 0);
                            /*---End Frame text view Box---*/


                        add_to_box(stack_box1, line4_box, START, TRUE, FALSE, 0, 0, 10, 0, 0);
                        /*---End Line4 box---*/

                            
                    add_to_stack(main_stack, stack_box1, "Widgets Page 1");
                    /*---End Stack box 1---*/

                    /*---Start Stack box 2---*/
                    GtkWidget *stack_box2 = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_CENTER, 0);

                        GtkWidget *login_box = create_box(GTK_ORIENTATION_HORIZONTAL, GTK_ALIGN_CENTER, 0);

                            /*---Start login grid---*/
                            GtkWidget *login_grid = create_grid(10, 0, TRUE, TRUE);

                                /*---Start login label---*/
                                GtkWidget *login_label = create_label("Login", 12, "MonoLisa Nerd Font Mono Bold 10", "#000000", "#F6F5F4", GTK_JUSTIFY_CENTER, FALSE, PANGO_WEIGHT_BOLD, PANGO_STYLE_NORMAL, TRUE);
                                add_to_grid(login_grid, login_label, 0, 0, 1, 1);
                                /*---End login label---*/
                                
                                /*---Start username entry---*/
                                GtkWidget *username_entry_entry = create_entry(NULL, "Username", TRUE, TRUE, 20, 0.5);
                                add_to_grid(login_grid, username_entry_entry, 1, 0, 1, 1);
                                /*---End username entry---*/

                                /*---Start password entry---*/
                                GtkWidget *password_entry_entry = create_entry(NULL, "Password", FALSE, TRUE, 20, 0.5);
                                add_to_grid(login_grid, password_entry_entry, 2, 0, 1, 1);
                                /*---End password entry---*/

                                /*---Start login button---*/
                                GtkWidget *login_button = create_button(GTK_RELIEF_NORMAL, "Login", FALSE, NULL, NULL, NULL);
                                add_to_grid(login_grid, login_button, 3, 0, 1, 1);
                                /*---End login button---*/

                            add_to_box(login_box, login_grid, START, FALSE, FALSE, 0, 0, 10, 0, 0);
                            /*---End login grid---*/

                            gtk_widget_set_size_request(login_grid, 300, 1);

                        add_to_box(stack_box2, login_box, START, TRUE, FALSE, 0, 0, 10, 0, 0);
                        /*---End login box---*/

                    add_to_stack(main_stack, stack_box2, "Widgets Page 2");
                    /*---End Stack box 2---*/


                add_to_box(main_box, main_stack, START, FALSE, FALSE, 0, 0, 0, 0, 0);
                /*---End Main Stack---*/

                /*---Start Switcher---*/
                GtkWidget *switcher = create_switcher(5, TRUE);
                add_to_switcher(switcher, main_stack);
                add_to_box(main_box, switcher, START, FALSE, FALSE, 0, 0, 10, 0, 0);
                /*---End Switcher---*/
            
            add_to_scrolled_window(scrolled_window, main_box);
            /*---End Main Box---*/
        
        add_to_container(window, scrolled_window);
        /*---End Scrolled Window---*/

    show_widget(window);
    /*---End Window---*/
}