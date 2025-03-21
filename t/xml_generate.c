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
        fprintf(xml_file, "\n");
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
        } else if (strcmp(node_data->widget_name, "stack") == 0){
            write_stack(((stackInfos *)(node_data->widget_data)), xml_file);
        } else if (strcmp(node_data->widget_name, "switcher") == 0){
            write_switcher(((switcherInfos *)(node_data->widget_data)), xml_file);
        } else if (strcmp(node_data->widget_name, "scrolled_window") == 0){
            write_scrolled_window(((scrolledWindowInfos *)(node_data->widget_data)), xml_file);
        } else if (strcmp(node_data->widget_name, "button") == 0){
            write_button(((buttonInfos *)(node_data->widget_data)), xml_file);
        } else if (strcmp(node_data->widget_name, "check_button") == 0){
            write_check_button(((checkButtonInfos *)(node_data->widget_data)), xml_file);
        } else if (strcmp(node_data->widget_name, "color_button") == 0){
            write_color_button(((colorButtonInfos *)(node_data->widget_data)), xml_file);
        } else if (strcmp(node_data->widget_name, "entry") == 0){
            write_entry(((entryInfos *)(node_data->widget_data)), xml_file);
        } else if (strcmp(node_data->widget_name, "font_button") == 0){
            write_font_button(((fontButtonInfos *)(node_data->widget_data)), xml_file);
        } else if (strcmp(node_data->widget_name, "image") == 0){
            write_image(((imageInfos *)(node_data->widget_data)), xml_file);
        } else if (strcmp(node_data->widget_name, "label") == 0){
            write_label(((labelInfos *)(node_data->widget_data)), xml_file);
        } else if (strcmp(node_data->widget_name, "level_bar") == 0){
            write_level_bar(((levelBarInfos *)(node_data->widget_data)), xml_file);
        } else if (strcmp(node_data->widget_name, "link_button") == 0){
            write_link_button(((linkButtonInfos *)(node_data->widget_data)), xml_file);
        } else if (strcmp(node_data->widget_name, "menu_button") == 0){
            write_menu_button(((menuButtonInfos *)(node_data->widget_data)), xml_file); 
        } else if (strcmp(node_data->widget_name, "menu") == 0){
            write_menu(((menuInfos *)(node_data->widget_data)), xml_file);
        } else if (strcmp(node_data->widget_name, "menu_item") == 0){
            write_menu_item(((menuItemInfos *)(node_data->widget_data)), xml_file);
        } else if (strcmp(node_data->widget_name, "radio_button") == 0){
            write_radio_button(((radioButtonInfos *)(node_data->widget_data)), xml_file);
        }
        fprintf(xml_file, ">");
    } else {
        // Traitement de la balise fermée (utilise le closing_tag si disponible)
        fprintf(xml_file, "\n");
        const char *closing_tag = node_data->closing_tag ? node_data->closing_tag : node_data->information;
        fprintf(xml_file, "%s", closing_tag);
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
    generate_xml(global_tree, "XML/test.x");
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

    fprintf(file, "type = GTK_WINDOW_TOPLEVEL ");

    if(windowInformations->background_color)
        fprintf(file, "color = \"%s\" ", windowInformations->background_color);
    
    if(windowInformations->background_image)
        fprintf(file, "image = \"../%s\" ", windowInformations->background_image);
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
        fprintf(file, "icon_path = \"../%s\" ", headerBarInformations->icon_path);
    fprintf(file, "settings = %s", (headerBarInformations->settings == TRUE) ? "TRUE" : "FALSE");
}

void write_frame(frameInfos *frameInformations, FILE *file){
    setlocale(LC_NUMERIC, "C");
    fprintf(file, "title = \"%s\" ", frameInformations->title);

    fprintf(file, "horizontal_placement = %.1f ",frameInformations->horizontal_placement);

    fprintf(file, "vertical_placement = %.1f", frameInformations->vertical_placement);
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

void write_stack(stackInfos *stackInformations, FILE *file){

    
    fprintf(file, "switcher = %s ", stackInformations->id_switcher);

    if(stackInformations->transition_type == GTK_STACK_TRANSITION_TYPE_CROSSFADE){
        fprintf(file, "transition_type = %s ", "GTK_STACK_TRANSITION_TYPE_CROSSFADE");
    } else if(stackInformations->transition_type == GTK_STACK_TRANSITION_TYPE_NONE){
        fprintf(file, "transition_type = %s ", "GTK_STACK_TRANSITION_TYPE_NONE");
    } else if (stackInformations->transition_type ==GTK_STACK_TRANSITION_TYPE_SLIDE_LEFT){
        fprintf(file, "transition_type = %s ", "GTK_STACK_TRANSITION_TYPE_SLIDE_LEFT");
    } else {
        fprintf(file, "transition_type = %s ", "GTK_STACK_TRANSITION_TYPE_SLIDE_RIGHT");
    }

    fprintf(file, "transition_duration = %d", stackInformations->transition_duration);
}

void write_switcher(switcherInfos *switcherInformations, FILE *file){
    fprintf(file, "spacing = %d ", switcherInformations->spacing);

    fprintf(file, "buttons_same_size = %s", (switcherInformations->buttons_same_size == TRUE) ? "TRUE" : "FALSE");
}

void write_scrolled_window(scrolledWindowInfos *scrolledWindowInforamtions, FILE *file){

    fprintf(file, "horizontal = %s ", (scrolledWindowInforamtions->horizontal == TRUE) ? "TRUE" : "FALSE");

    fprintf(file, "vertical = %s", (scrolledWindowInforamtions->vertical == TRUE) ? "TRUE" : "FALSE");
}

void write_button(buttonInfos *buttonInformations, FILE *file){

    fprintf(file, "label = \"%s\" ", (buttonInformations->label) ? buttonInformations->label : "Default label");

    fprintf(file, "relief = %s ", (buttonInformations->relief == GTK_RELIEF_NONE) ? "GTK_RELIEF_NONE" : "GTK_RELIEF_NORMAL");

    fprintf(file, "use_underline = %s ", (buttonInformations->use_underline == TRUE) ? "TRUE" : "FALSE");

    if(buttonInformations->path_to_image)
        fprintf(file, "path_to_image = \"%s\" ", buttonInformations->path_to_image);

    if(buttonInformations->callback_name)
        fprintf(file, "callback = G_CALLBACK(%s) ", buttonInformations->callback_name);

    if(buttonInformations->data_name)
        fprintf(file, "data = \"%s\"", buttonInformations->data_name);
}   

void write_check_button(checkButtonInfos *checkButtonInformation, FILE *file){

    fprintf(file, "label = \"%s\" ", checkButtonInformation->label);
    fprintf(file, "active = %s ", (checkButtonInformation->active) ? "TRUE" : "FALSE");
    fprintf(file, "use_underline = %s ", (checkButtonInformation->use_underline) ? "TRUE" : "FALSE");

    if(checkButtonInformation->callback_name)
        fprintf(file, "callback = G_CALLBACK(%s) ", checkButtonInformation->callback_name);

    if(checkButtonInformation->data_name)
        fprintf(file, "data = \"%s\"", checkButtonInformation->data_name);
}

void write_color_button(colorButtonInfos *colorButtonInformation, FILE *file){
    fprintf(file, "default_color = \"%s\" ", colorButtonInformation->default_color);

    if(!colorButtonInformation->title)
        fprintf(file, "title = \"%s\" ", colorButtonInformation->title);

    fprintf(file, "use_alpha = %s", (colorButtonInformation->use_alpha) ? "TRUE" : "FALSE");
}

void write_entry(entryInfos *entryInformations, FILE *file){

    setlocale(LC_NUMERIC, "C");

    if(entryInformations->default_text)
        fprintf(file, "default_text = \"%s\" ", entryInformations->default_text);

    if(entryInformations->indicator_text)
        fprintf(file, "indicator_text = \"%s\" ",entryInformations->indicator_text);

    fprintf(file, "visible = %s ",(entryInformations->visible) ? "TRUE" : "FALSE");

    fprintf(file, "editable = %s ",(entryInformations->editable) ? "TRUE" : "FALSE");

    fprintf(file, "max_length = %d ",entryInformations->max_length);

    fprintf(file, "alignment = %.1f",entryInformations->alignment);

}

void write_font_button(fontButtonInfos *fontButtonInformations, FILE *file){
    
    if(fontButtonInformations->title){
        fprintf(file, "title = \"%s\" ", fontButtonInformations->title);
    }
    if(fontButtonInformations->default_font_name)
        fprintf(file, "default_font_name = \"%s\" ", fontButtonInformations->default_font_name);

    fprintf(file, "show_size = %s ", (fontButtonInformations->show_size) ? "TRUE" : "FALSE");

    fprintf(file, "show_style = %s ", (fontButtonInformations->show_style) ? "TRUE" : "FALSE");

    fprintf(file, "use_size = %s ", (fontButtonInformations->use_size) ? "TRUE" : "FALSE");

    fprintf(file, "use_font = %s", (fontButtonInformations->use_font) ? "TRUE" : "FALSE");
    
}

void write_image(imageInfos *imageInformations, FILE *file){
    if(imageInformations->path){
        fprintf(file, "path = \"../%s\"", imageInformations->path);
    }
}

void write_label(labelInfos *labelInformations, FILE *file){

    if(labelInformations->text)
        fprintf(file, "text = \"%s\" ", labelInformations->text);
    
    fprintf(file, "size = %d ", labelInformations->size);

    fprintf(file, "font = \"%s\" ", labelInformations->font);

    fprintf(file, "color = \"%s\" ", labelInformations->color);

    fprintf(file, "background = \"%s\" ", labelInformations->background);

    fprintf(file, "justify = %d ", (labelInformations->justify == GTK_JUSTIFY_CENTER) ? 2 : ((labelInformations->justify == GTK_JUSTIFY_LEFT) ? 0 : 1));

    fprintf(file, "underline = %s ", (labelInformations->underline) ? "TRUE" : "FALSE");

    fprintf(file, "weight = %d ", (labelInformations->weight == PANGO_WEIGHT_NORMAL) ? 400 :  700);

    fprintf(file, "style = %d ",(labelInformations->style == PANGO_STYLE_NORMAL) ? 0 : 2);

    fprintf(file, "wrap = %s",(labelInformations->wrap) ? "TRUE" : "FALSE");

}

void write_level_bar(levelBarInfos *levelBarInformations, FILE *file){

    setlocale(LC_NUMERIC, "C");

    fprintf(file, "inverted = %s ", (levelBarInformations->inverted) ? "TRUE" : "FALSE");

    fprintf(file, "min_value = %.f ", levelBarInformations->min_value);

    fprintf(file, "max_value = %.f ", levelBarInformations->max_value);

    fprintf(file, "default_value = %.f ", levelBarInformations->default_value);

    fprintf(file, "mode = %d", levelBarInformations->mode);

}

void write_link_button(linkButtonInfos *linkButtonInformations, FILE *file){

    if(linkButtonInformations->label){
        fprintf(file, "label = \"%s\" ", linkButtonInformations->label);
    }

    if(linkButtonInformations->url){
        fprintf(file, "uri = \"%s\" ", linkButtonInformations->url);
    }
}

void write_menu_button(menuButtonInfos *menuButtonInformations, FILE *file){

    if(menuButtonInformations->label){
        fprintf(file, "label = \"%s\" ", menuButtonInformations->label);
    }

    if(menuButtonInformations->path_to_image){
        fprintf(file, "image = \"%s\" ", menuButtonInformations->path_to_image);
    }

    if(menuButtonInformations->arrow_type == GTK_ARROW_DOWN){
        fprintf(file, "arrow_type = %s", "GTK_ARROW_DOWN");
    } else if (menuButtonInformations->arrow_type == GTK_ARROW_UP){
        fprintf(file, "arrow_type = %s", "GTK_ARROW_UP");
    } else if (menuButtonInformations->arrow_type == GTK_ARROW_LEFT){
        fprintf(file, "arrow_type = %s", "GTK_ARROW_LEFT");
    } else {
        fprintf(file, "arrow_type = %s", "GTK_ARROW_RIGHT");
    }
}

void write_menu(menuInfos *menuInformations, FILE *file){

    fprintf(file, "is_primary = %s ", (menuInformations->is_primary) ? "TRUE" : "FALSE");

    if(menuInformations->label){
        fprintf(file, "label = \"%s\"", menuInformations->label);
    }
}

void write_menu_item(menuItemInfos *menuItemInformations, FILE *file){
    
    if(menuItemInformations->label)
        fprintf(file, "label = \"%s\" ", menuItemInformations->label);

    fprintf(file, "type = \"%s\" ", menuItemInformations->type);

    if(menuItemInformations->callback_name && strcmp(menuItemInformations->callback_name, "") != 0)
        fprintf(file, "callback = G_CALLBACK(%s) ", menuItemInformations->callback_name);

    if(menuItemInformations->data_name && strcmp(menuItemInformations->data_name, "") != 0)
        fprintf(file, "data = \"%s\"", menuItemInformations->data_name);
    
}

void write_radio_button(radioButtonInfos *radioButtonInformations, FILE *file){

    if(radioButtonInformations->label && strcmp(radioButtonInformations->label, "") != 0){
        fprintf(file, "label = \"%s\" ", radioButtonInformations->label);
    }

    if(radioButtonInformations->path_to_image && strcmp(radioButtonInformations->path_to_image, "") != 0){
        fprintf(file, "path_to_image = \"%s\" ", radioButtonInformations->path_to_image);
    }

    if(radioButtonInformations->radio_group_member_name && strcmp(radioButtonInformations->radio_group_member_name, "") != 0){
        fprintf(file, "id_radio_group_member = \"%s\" ", radioButtonInformations->radio_group_member_name);
    }

    fprintf(file, "default_state = %s", (radioButtonInformations->default_state) ? "TRUE" : "FALSE");

}