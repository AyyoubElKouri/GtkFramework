/****************************************************************************************************************************
 * 
 * @file widgets_properties.h
 * 
 * @author Ayyoub el kouri
 * @date 09/03/2025
 * @version 1.1 (last update 09/03/2025)
 * 
 ****************************************************************************************************************************/

 #ifndef WIDGETS_PROPERTIES_H
 #define WIDGETS_PROPERTIES_H

 #include "../include/GtkFramework/GtkFramework.h"
 #include "../XML/xscEngine/widgets_structures.h"
 #include "widget_callbacks.h"


 char * box_container_properties            (char *parent_id, GtkWidget *obj);
 void box_widget_properties();

 char * header_bar_container_properties     (char *parent_id, GtkWidget *obj);
 void header_bar_widget_properties();

 char * fixed_container_properties          (char *parent_id, GtkWidget *obj);
 void fixed_widget_properties();

 char * frame_container_properties          (char *parent_id, GtkWidget *obj);
 void frame_widget_properties();

 char * grid_container_properties           (char *parent_id, GtkWidget *obj);
 void grid_widget_properties();

 char * paned_container_properties          (char *parent_id, GtkWidget *obj);
 void paned_widget_properties();

 char * stack_container_properties          (char *parent_id, GtkWidget *obj);
 void stack_widget_properties();

 char * switcher_container_properties       (char *parent_id, GtkWidget *obj);
 void switcher_widget_properties();

 char * scrolled_window_container_properties(char *parent_id, GtkWidget *obj);
 void scrolled_window_widget_properties();

 char *button_container_properties          (char *parent_id, GtkWidget *obj);
 void button_widget_properties();

 char *check_button_container_properties    (char *parent_id, GtkWidget *obj);
 void check_button_widget_properties(); 

 char *color_button_container_properties    (char *parent_id, GtkWidget *obj);
 void color_button_widget_properties(); 

 char *combo_box_container_properties       (char *parent_id, GtkWidget *obj);
 void combo_box_widget_properties(); 

 char *entry_container_properties           (char *parent_id, GtkWidget *obj);
 void entry_widget_properties(); 


 char *font_button_container_properties     (char *parent_id, GtkWidget *obj);
 void font_button_widget_properties(); 

 char *image_container_properties           (char *parent_id, GtkWidget *obj);
 void image_widget_properties(); 

 char *label_container_properties           (char *parent_id, GtkWidget *obj);
 void label_widget_properties(); 

 char *level_bar_container_properties       (char *parent_id, GtkWidget *obj);
 void level_bar_widget_properties(); 

 char *link_button_container_properties     (char *parent_id, GtkWidget *obj);
 void link_button_widget_properties();

 char *menu_button_container_properties     (char *parent_id, GtkWidget *obj);
 void menu_button_widget_properties         ();

 char *menu_container_properties            (char *parent_id, GtkWidget *obj);
 void menu_widget_properties                ();

 char *menu_item_container_properties       (char *parent_id, GtkWidget *obj);
 void menu_item_widget_properties           ();

 char *radio_button_container_properties    (char *parent_id, GtkWidget *obj);
 void radio_button_widget_properties        ();
 
 #endif // WIDGETS_PROPERTIES_H