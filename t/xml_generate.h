/****************************************************************************************************************************
 * 
 * @file xml_generate.h
 * 
 * @author Ayyoub el kouri
 * @date 07/03/2025
 * @version 1.1 (last update 07/03/2025)
 * 
 ****************************************************************************************************************************/

 #ifndef XML_GENERATE_H
 #define XML_GENERATE_H

 #include <stdio.h>
 #include <locale.h>
 #include "../include/GtkFramework/GtkFramework.h"

 
 static void xml_generation_callback(GtkTreeIter *iter, gpointer user_data, gboolean is_open_tag);

 void generate_xml(GtkWidget *tree_view, const char *output_filename);

 void start_generate(GtkWidget *widget, gpointer data);

 void write_window(windowInfos *windowInformations, FILE *file);

 void write_box(boxInfos *boxInformations, FILE *file);

 void write_header_bar(headerBarInfos *headerBarInformations, FILE *file);

 void write_frame(frameInfos *frameInformations, FILE *file);

 void write_grid(gridInfos *gridInformations, FILE *file);

 void write_paned(panedInfos *panedInformations, FILE *file);


 #endif // XML_GENERATE_H