/******************************************************************************************************************************
 * 
 * @project: GTK3 project
 * @file main.c
 * @brief the main file of the project
 * 
 * This file contains the main function of the project.
 * 
 * @author Ayyoub el kouri
 * @date 20/01/2025
 * @version 1.0 (last update 24/01/2025)
 * 
 *****************************************************************************************************************************/


#include <gtk/gtk.h>
#include "includes.h"

static void activate(GtkApplication *app, gpointer data)
{
    GtkWidget *window;
    GtkWidget *dialog;
    GtkWidget *label;
    GtkWidget *image;
    GtkWidget *spinner;
    GtkWidget *textView;
    GtkWidget *levelBar;
    GtkWidget *progressBar;
    GtkWidget *scale;

    window = create_window(app, GTK_WINDOW_TOPLEVEL, "hello", 900, 660, TRUE, GTK_WIN_POS_CENTER, TRUE, NULL, 1, FALSE);
    dialog = create_dialog("hhhhhhh", window, GTK_DIALOG_MODAL, 70, 70, 1, "BUTTON", GTK_RESPONSE_OK, "hello", GTK_RESPONSE_CANCEL, "NULL", GTK_RESPONSE_OK);
    label = create_label("is meee", 16, "consolas", "#80a30d", "#ff1100", GTK_JUSTIFY_CENTER, TRUE, PANGO_WEIGHT_BOLD, PANGO_STYLE_ITALIC, FALSE);
    image = create_image("/home/ayyoub/Téléchargements/hie.png");
    spinner = create_spinner(TRUE);
    textView = create_text_view("Bonjour mes amis icihhhhh kkkkkkkk kkkkkkkkkkk kkkkkkkkkkkk khhhhhhh hhhhhh h hhhhh hhhhhhh hhhhhh hhhhhhh hhhh hhhhhhh hhhhhh hhhh hhh hh hhhhhh hy hhhhhhhh hhhhhhhhh hhhhhhhhh h hksjdql dkj", 12, "consolas", "#000100", "#FFFFFF", GTK_JUSTIFY_CENTER, PANGO_WEIGHT_NORMAL, PANGO_STYLE_ITALIC, TRUE, FALSE, TRUE);
    levelBar = create_level_bar(0, 5, 5, GTK_LEVEL_BAR_MODE_DISCRETE, TRUE);
    progressBar = create_progress_bar("hello is me", 0.9, TRUE, FALSE, TRUE);
    scale = create_scale(GTK_ORIENTATION_VERTICAL, 0, 60, 2, 8, GTK_POS_LEFT, "hello is me", 0, GTK_POS_RIGHT);


    

    labelInfos *labelInformation = get_properties_label(label);
    printf("text: %s\nsize: %d\nfont: %s\ncolor: %s\nbackground: %s\njustify: %d\nunderline: %d\nweight: %d\nstyle: %d\nwrap: %d\n", labelInformation->text, labelInformation->size, labelInformation->font, labelInformation->color, labelInformation->background, labelInformation->justify, labelInformation->underline, labelInformation->weight, labelInformation->style, labelInformation->wrap);

    
    imageInfos *imageInformation = get_properties_image(image);
    printf("path: %s\n", imageInformation->path);

    spinnerInfos *spinnerInformation = get_properties_spinner(spinner);
    printf("active: %d\n", spinnerInformation->active);

    textViewInfos *textViewInformation = get_properties_text_view(textView);
    printf("text: %s\nsize: %d\nfont: %s\ncolor: %s\nbackground: %s\njustify: %d\nweight: %d\nstyle: %d\nwrap: %d\ncursor_visible: %d\neditable: %d\n", textViewInformation->text, textViewInformation->size, textViewInformation->font, textViewInformation->color, textViewInformation->background, textViewInformation->justify, textViewInformation->weight, textViewInformation->style, textViewInformation->wrap, textViewInformation->cursor_visible, textViewInformation->editable);

    levelBarInfos *levelBarInformation = get_properties_level_bar(levelBar);
    printf("min_value: %f\nmax_value: %f\ndefault_value: %f\nmode: %d\ninverted: %d\n", levelBarInformation->min_value, levelBarInformation->max_value, levelBarInformation->default_value, levelBarInformation->mode, levelBarInformation->inverted);

    progressBarInfos *progressBarInformation = get_properties_progress_bar(progressBar);
    printf("text: %s\nfraction: %f\nshow_text: %d\npulse: %d\ninverted: %d\n", progressBarInformation->text, progressBarInformation->fraction, progressBarInformation->show_text, progressBarInformation->pulse, progressBarInformation->inverted);

    scaleInfos *scaleInformation = get_properties_scale(scale);
    printf("orientation: %d\nmin_value: %f\nmax_value: %f\nstep: %f\nmark_value: %f\nmark_position: %d\ntext: %s\ndigits: %d\nvalue_pos: %d\n", scaleInformation->orientation, scaleInformation->min_value, scaleInformation->max_value, scaleInformation->step, scaleInformation->mark_value, scaleInformation->mark_position, scaleInformation->text, scaleInformation->digits, scaleInformation->value_pos);

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_container_add(GTK_CONTAINER(window), box);

    gtk_box_pack_start(GTK_BOX(box), scale, TRUE, FALSE, 0);

    gtk_widget_show_all(window);
    // gtk_widget_show_all(dialog);
}


int main(int argc, char **argv)
{
    GtkApplication *app = gtk_application_new("id.gtk", G_APPLICATION_DEFAULT_FLAGS);
    int status = 0;
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}

