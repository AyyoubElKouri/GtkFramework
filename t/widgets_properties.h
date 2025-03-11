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


 char * box_container_properties(char *parent_id, GtkWidget *obj);
 void box_widget_properties();

 char * header_bar_container_properties(char *parent_id, GtkWidget *obj);
 void header_bar_widget_properties();

 char * fixed_container_properties(char *parent_id, GtkWidget *obj);
 void fixed_widget_properties();

 char * frame_container_properties(char *parent_id, GtkWidget *obj);
 void frame_widget_properties();

 char * grid_container_properties(char *parent_id, GtkWidget *obj);
 void grid_widget_properties();

 char * paned_container_properties(char *parent_id, GtkWidget *obj);
 void paned_widget_properties();

 char * stack_container_properties(char *parent_id, GtkWidget *obj);
 void stack_widget_properties();

 char * switcher_container_properties(char *parent_id, GtkWidget *obj);
 void switcher_widget_properties();


 #endif // WIDGETS_PROPERTIES_H