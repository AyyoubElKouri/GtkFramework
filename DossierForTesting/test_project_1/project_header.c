/*****************************************************************************************************************************
 * 
 * @project: Information about countries
 * @file project_header.c
 * @brief the implementation file of the Countries project
 * 
 * 
 * @test testCountries N°: 1.1.0
 * 
 * @author Ayyoub el Kouri
 * @date 28/01/2025
 * @version 1.0 (last update 28/01/2025)
 * 
 ******************************************************************************************************************************/

#include "project_header.h"


void project1(GtkApplication *app)
{
    /*---Start Window---*/
    GtkWidget *window = create_window(app, GTK_WINDOW_TOPLEVEL, "Countries", 900, 600, TRUE, GTK_WIN_POS_CENTER, TRUE, NULL, 1, FALSE);

        /*--- Start Header Bar---*/
        GtkWidget *header_bar = create_header_bar("Countries", "Project 1", "assets/Application_icon/apple.png", TRUE);
        add_header_bar_to_window(window, header_bar);
        /*---End Header Bar---*/

        /*---Start Scrolled Window---*/
        GtkWidget *scrolled_window = create_scrolled_window(FALSE, TRUE);

            /*---Start Main Box---*/
            GtkWidget *main_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 10);
                
                /*---Start Line 1 box---*/
                GtkWidget *line1_box = create_box(GTK_ORIENTATION_HORIZONTAL, -1, 0);
                    
                    /*---Start Morroco Grid---*/
                    GtkWidget *morroco_grid = create_grid(12, 0, FALSE, FALSE);

                        /*---Start Morroco image---*/
                        GtkWidget *morroco_image = create_image("assets/w160/ma.png");
                        add_to_grid(morroco_grid,morroco_image, 0, 0, 1, 1);
                        /*---End Morroco image---*/

                        /*---Start Morroco Label*/
                        GtkWidget *morroco_label = create_label("Morroco", 12, "consolas", "#000000", "#FFFFFF", GTK_JUSTIFY_CENTER, FALSE, PANGO_WEIGHT_BOLD, PANGO_STYLE_NORMAL, TRUE);
                        add_to_grid(morroco_grid, morroco_label, 1, 0, 1, 1);
                        /*---End Morroco Label---*/

                        /*---Start Morroco Button*/
                        GtkWidget *morroco_button = create_button(GTK_RELIEF_NORMAL, "Morroco Informations", FALSE, NULL, G_CALLBACK(marocInfos), NULL);
                        add_to_grid(morroco_grid, morroco_button, 2, 0, 1, 1);
                        /*---End Morroco Button---*/

                    add_to_box(line1_box, morroco_grid, START, TRUE, FALSE, 0, 0, 0, 0, 0);
                    /*---End Morroco Grid---*/
                    

                    /*---Start France Grid---*/
                    GtkWidget *france_grid = create_grid(12, 0, FALSE, FALSE);

                        /*---Start France mage---*/
                        GtkWidget *france_image = create_image("assets/w160/fr.png");
                        add_to_grid(france_grid, france_image, 0, 0, 1, 1);
                        /*---End France image---*/

                        /*---Start france Label*/
                        GtkWidget *france_label = create_label("France", 12, "consolas", "#000000", "#FFFFFF", GTK_JUSTIFY_CENTER, FALSE, PANGO_WEIGHT_BOLD, PANGO_STYLE_NORMAL, TRUE);
                        add_to_grid(france_grid, france_label, 1, 0, 1, 1);
                        /*---End france Label---*/

                        /*---Start france Button*/
                        GtkWidget *france_button = create_button(GTK_RELIEF_NORMAL, "France Informations", FALSE, NULL, G_CALLBACK(franceInfos), NULL);
                        add_to_grid(france_grid, france_button, 2, 0, 1, 1);
                        /*---End france Button---*/

                    add_to_box(line1_box, france_grid, START, TRUE, FALSE, 0, 0, 0, 0, 0);
                    /*---End France Grid---*/


                    /*---Start Italy Grid---*/
                    GtkWidget *italy_grid = create_grid(12, 0, FALSE, FALSE);

                        /*---Start Italy Image---*/
                        GtkWidget *italy_image = create_image("assets/w160/it.png");
                        add_to_grid(italy_grid, italy_image, 0, 0, 1, 1);
                        /*---End Italy Grid---*/

                        /*---Start Italy Label*/
                        GtkWidget *italy_label = create_label("Italy", 12, "consolas", "#000000", "#FFFFFF", GTK_JUSTIFY_CENTER, FALSE, PANGO_WEIGHT_BOLD, PANGO_STYLE_NORMAL, TRUE);
                        add_to_grid(italy_grid, italy_label, 1, 0, 1, 1);
                        /*---End Italy Label---*/

                        /*---Start Italy Button*/
                        GtkWidget *italy_button = create_button(GTK_RELIEF_NORMAL, "Italy Informations", FALSE, NULL, G_CALLBACK(italieInfos), NULL);
                        add_to_grid(italy_grid, italy_button, 2, 0, 1, 1);
                        /*---End Italy Button---*/

                    add_to_box(line1_box, italy_grid, START, TRUE, FALSE, 0, 0, 0, 0, 0);
                    /*---End Italy Grid---*/

                add_to_box(main_box, line1_box, START, TRUE, FALSE, 0, 0, 0, 0, 0);
                /*---End Line 1 Box---*/


                /*---Start Line 2 box---*/
                GtkWidget *line2_box = create_box(GTK_ORIENTATION_HORIZONTAL, -1, 0);
                    
                    /*---Start Algerie Grid---*/
                    GtkWidget *algerie_grid = create_grid(12, 0, FALSE, FALSE);

                        /*---Start Algerie image---*/
                        GtkWidget *algerie_image = create_image("assets/w160/dz.png");
                        add_to_grid(algerie_grid,algerie_image, 0, 0, 1, 1);
                        /*---End Algerie image---*/

                        /*---Start Algerie Label*/
                        GtkWidget *algerie_label = create_label("Algerie", 12, "consolas", "#000000", "#FFFFFF", GTK_JUSTIFY_CENTER, FALSE, PANGO_WEIGHT_BOLD, PANGO_STYLE_NORMAL, TRUE);
                        add_to_grid(algerie_grid, algerie_label, 1, 0, 1, 1);
                        /*---End Algerie Label---*/

                        /*---Start Algerie Button*/
                        GtkWidget *algerie_button = create_button(GTK_RELIEF_NORMAL, "Algerie Informations", FALSE, NULL, G_CALLBACK(algerieInfos), NULL);
                        add_to_grid(algerie_grid, algerie_button, 2, 0, 1, 1);
                        /*---End Algerie Button---*/

                    add_to_box(line2_box, algerie_grid, START, TRUE, FALSE, 0, 0, 0, 0, 0);
                    /*---End Algerie Grid---*/
                    

                    /*---Start Saudi Arabia Grid---*/
                    GtkWidget *saudi_arabia_grid = create_grid(12, 0, FALSE, FALSE);

                        /*---Start Saudi Arabia image---*/
                        GtkWidget *saudi_arabia_image = create_image("assets/w160/sa.png");
                        add_to_grid(saudi_arabia_grid, saudi_arabia_image, 0, 0, 1, 1);
                        /*---End Saudi Arabia image---*/

                        /*---Start Saudi Arabia Label*/
                        GtkWidget *saudi_arabia_label = create_label("Saudi Arabia", 12, "consolas", "#000000", "#FFFFFF", GTK_JUSTIFY_CENTER, FALSE, PANGO_WEIGHT_BOLD, PANGO_STYLE_NORMAL, TRUE);
                        add_to_grid(saudi_arabia_grid, saudi_arabia_label, 1, 0, 1, 1);
                        /*---End Sauudi Arabia Label---*/

                        /*---Start Saudi Arabia Button*/
                        GtkWidget *saudi_arabia_button = create_button(GTK_RELIEF_NORMAL, "Saudi Arabia Informations", FALSE, NULL, G_CALLBACK(saudiArabieInfos), NULL);
                        add_to_grid(saudi_arabia_grid, saudi_arabia_button, 2, 0, 1, 1);
                        /*---End Saudi Arabia Button---*/

                    add_to_box(line2_box, saudi_arabia_grid, START, TRUE, FALSE, 0, 0, 0, 0, 0);
                    /*---End Saudi Arabia Grid---*/


                    /*---Start Argentina Grid---*/
                    GtkWidget *argentina_grid = create_grid(12, 0, FALSE, FALSE);

                        /*---Start Argentina Image---*/
                        GtkWidget *argentina_image = create_image("assets/w160/ar.png");
                        add_to_grid(argentina_grid, argentina_image, 0, 0, 1, 1);
                        /*---End Argentina Image---*/

                        /*---Start Argentina Label*/
                        GtkWidget *argentina_label = create_label("Argentina", 12, "consolas", "#000000", "#FFFFFF", GTK_JUSTIFY_CENTER, FALSE, PANGO_WEIGHT_BOLD, PANGO_STYLE_NORMAL, TRUE);
                        add_to_grid(argentina_grid, argentina_label, 1, 0, 1, 1);
                        /*---End Argentina Label---*/

                        /*---Start Argentina Button*/
                        GtkWidget *argentina_button = create_button(GTK_RELIEF_NORMAL, "Italy Informations", FALSE, NULL, G_CALLBACK(argentinaInfos), NULL);
                        add_to_grid(argentina_grid, argentina_button, 2, 0, 1, 1);
                        /*---End Argentina Button---*/

                    add_to_box(line2_box, argentina_grid, START, TRUE, FALSE, 0, 0, 0, 0, 0);
                    /*---End Argentina Grid---*/

                add_to_box(main_box, line2_box, START, TRUE, FALSE, 0, 0, 0, 0, 0);
                /*---End Line 2 Box---*/

            add_to_container(scrolled_window, main_box);
            /*---End the Main Box---*/

        add_to_container(window, scrolled_window);
        /*---End Scrolled Window---*/

    show_widget(window);
    /*---End Window---*/
}

