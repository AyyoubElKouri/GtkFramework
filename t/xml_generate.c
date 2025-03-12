/*****************************************************************************************************************************
 * 
 * @file xml_generate.c
 * @brief the implementation of the functions in xml_generate.h
 * 
 * 
 * @author Ayyoub el Kouri
 * @date 07/03/2025
 * @version 1.0 (last update 07/03/2025)
 * 
 ****************************************************************************************************************************/

#include "xml_generate.h"

extern GtkWidget *global_tree;

// Callback pour générer le XML
static void xml_generation_callback(GtkTreeIter *iter, gpointer user_data, gboolean is_open_tag) {
    FILE *xml_file = (FILE *)user_data; // Récupérer le fichier XML
    GtkTreeModel *model = gtk_tree_view_get_model(GTK_TREE_VIEW(global_tree)); // À adapter

    TreeNodeData *node_data = tree_node_get_data(model, iter);

    if (is_open_tag) {
        fprintf(xml_file, "<%s id=\"%s\" ", node_data->widget_name, node_data->information);
        if(strcmp(node_data->widget_name, "window") == 0)
            write_window(((windowInfos *)(node_data->widget_data)), xml_file);
        else if (strcmp(node_data->widget_name, "box") == 0){
            write_box(((boxInfos *)(node_data->widget_data)), xml_file);
        } else if (strcmp(node_data->widget_name, "header_bar") == 0){
            write_header_bar(((headerBarInfos *)(node_data->widget_data)), xml_file);
        } else if (strcmp(node_data->widget_name, "frame") == 0){
            write_frame(((frameInfos *)(node_data->widget_data)), xml_file);
        } else if(strcmp(node_data->widget_name, "grid") == 0){
            write_grid(((gridInfos *)(node_data->widget_data)), xml_file);
        } else if (strcmp(node_data->widget_name, "paned") == 0){
            write_paned(((panedInfos *)(node_data->widget_data)), xml_file);
        }
        fprintf(xml_file, ">\n");
    } else {
        // Traitement de la balise fermée (utilise le closing_tag si disponible)
        const char *closing_tag = node_data->closing_tag ? node_data->closing_tag : node_data->information;
        fprintf(xml_file, "%s\n", closing_tag);
    }

    // Libérer la mémoire allouée par tree_node_get_data()
    g_free(node_data->information);
    g_free(node_data->closing_tag);
    g_free(node_data);
}

void generate_xml(GtkWidget *tree_view, const char *output_filename) {
    // Ouvrir le fichier de sortie
    FILE *xml_file = fopen(output_filename, "w");
    if (!xml_file) {
        g_printerr("Erreur lors de l'ouverture du fichier %s\n", output_filename);
        return;
    }

    // Lancer le parcours récursif avec le callback
    tree_recursive_traverse(tree_view, xml_generation_callback, xml_file);

    // Fermer le fichier
    fclose(xml_file);
}


void start_generate(GtkWidget *widget, gpointer data){
    generate_xml(global_tree, "test.x");
}

void write_window(windowInfos *windowInformations, FILE *file){
    if(windowInformations->app){
        fprintf(file, "app = \"app\" ");
    }

    fprintf(file, "title = \"%s\" ", windowInformations->title);

    fprintf(file, "width = %d ", windowInformations->width);

    fprintf(file, "height = %d ", windowInformations->height);

    fprintf(file, "decorate = %s ", (windowInformations->decorate == TRUE) ? "TRUE" : "FALSE");

    fprintf(file, "resizable = %s ", (windowInformations->resizable == TRUE) ? "TRUE" : "FALSE");

    fprintf(file, "fullscreen = %s ", (windowInformations->fullscreen == TRUE) ? "TRUE" : "FALSE");

    setlocale(LC_NUMERIC, "C");
    fprintf(file, "opacity = %.1f ", windowInformations->opacity);

    if(windowInformations->position == GTK_WIN_POS_CENTER){
        fprintf(file, "position = %s ", "GTK_WIN_POS_CENTER");
    } else if (windowInformations->position == GTK_WIN_POS_CENTER_ON_PARENT){
        fprintf(file, "position = %s ", "GTK_WIN_POS_CENTER_ON_PARENT");
    } else {
        fprintf(file, "position = %s ", "GTK_WIN_POS_MOUSE");
    }

    fprintf(file, "type = GTK_WINDOW_TOPLEVEL");
}

void write_box(boxInfos *boxInformations, FILE *file){
    if(boxInformations->orientation == GTK_ORIENTATION_VERTICAL){
        fprintf(file, "orientation = GTK_ORIENTATION_VERTICAL ");
    } else {
        fprintf(file, "orientation = GTK_ORIENTATION_HORIZONTAL ");
    }

    if(boxInformations->align == GTK_ALIGN_CENTER){
        fprintf(file, "align = GTK_ALIGN_CENTER ");
    } else if (boxInformations->align == GTK_ALIGN_START){
        fprintf(file, "align = GTK_ALIGN_START ");
    } else if (boxInformations->align == GTK_ALIGN_END){
        fprintf(file, "align = GTK_ALIGN_END ");
    } else 
        fprintf(file, "align = -1 ");


    fprintf(file, "spacing = %d", boxInformations->spacing);
}

void write_header_bar(headerBarInfos *headerBarInformations, FILE *file){
    fprintf(file, "title = \"%s\" ", headerBarInformations->title);
    fprintf(file, "subtitle = \"%s\" ", headerBarInformations->subtitle);
    if(headerBarInformations->icon_path)
        fprintf(file, "icon_path = \"%s\" ", headerBarInformations->icon_path);
    fprintf(file, "settings = %s", (headerBarInformations->settings == TRUE) ? "TRUE" : "FALSE");
}

void write_frame(frameInfos *frameInformations, FILE *file){
    
    fprintf(file, "title = \"%s\" ", frameInformations->title);

    fprintf(file, "horizontal_placement = %.0f ",frameInformations->horizontal_placement);

    fprintf(file, "vertical_placement = %.0f", frameInformations->vertical_placement);
}

 void write_grid(gridInfos *gridInformations, FILE *file){

    fprintf(file, "rows_spacing = %d ", gridInformations->rows_spacing);

    fprintf(file, "columns_spacing = %d ", gridInformations->columns_spacing);

    fprintf(file, "rows_homogeneous = %s ", (gridInformations->rows_homogeneous == TRUE) ? "TRUE" : "FALSE");

    fprintf(file, "columns_homogeneous = %s", (gridInformations->columns_homogeneous == TRUE) ? "TRUE" : "FALSE");
}

void write_paned(panedInfos *panedInformations, FILE *file){

    fprintf(file, "orientation = %s ", (panedInformations->orientation == GTK_ORIENTATION_HORIZONTAL) ? "GTK_ORIENTATION_HORIZONTAL" : "GTK_ORIENTATION_VERTICAL");

    fprintf(file, "default_position = %d ", panedInformations->default_position);

    fprintf(file, "show_handle = %s", (panedInformations->show_handle) ? "TRUE" : "FALSE");
}