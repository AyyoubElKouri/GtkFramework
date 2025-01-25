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
#include "widgets_includes.h"
#include "data_structres_includes.h"

static void hello(GtkWidget *widget, gpointer data)
{
    char *chaine = (char *)data;
    g_print("Hello, World = %s\n", chaine ? chaine : "NULL");
}

static void changer(GtkWidget *widget, gpointer data)
{
    g_print("changer! = %s\n", (char *)data);
}

static void clicker(GtkWidget *widget, gpointer data)
{
    g_print("clicker! = %s\n", (char *)data);
}



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
    GtkWidget *separator;
    GtkWidget *button;
    GtkWidget *checkButton;
    GtkWidget *linkButton;
    GtkWidget *menuItem;

    window = create_window(app, GTK_WINDOW_TOPLEVEL, "hello", 900, 660, TRUE, GTK_WIN_POS_CENTER, TRUE, NULL, 1, FALSE);
    dialog = create_dialog("hhhhhhh", window, GTK_DIALOG_MODAL, 70, 70, 1, "BUTTON", GTK_RESPONSE_OK, "hello", GTK_RESPONSE_CANCEL, "NULL", GTK_RESPONSE_OK);
    label = create_label("is meee", 16, "consolas", "#80a30d", "#ff1100", GTK_JUSTIFY_CENTER, TRUE, PANGO_WEIGHT_BOLD, PANGO_STYLE_ITALIC, FALSE);
    image = create_image("/home/ayyoub/Téléchargements/hie.png");
    spinner = create_spinner(TRUE);
    textView = create_text_view("Bonjour mes amis icihhhhh kkkkkkkk kkkkkkkkkkk kkkkkkkkkkkk khhhhhhh hhhhhh h hhhhh hhhhhhh hhhhhh hhhhhhh hhhh hhhhhhh hhhhhh hhhh hhh hh hhhhhh hy hhhhhhhh hhhhhhhhh hhhhhhhhh h hksjdql dkj", 12, "consolas", "#000100", "#FFFFFF", GTK_JUSTIFY_CENTER, PANGO_WEIGHT_NORMAL, PANGO_STYLE_ITALIC, TRUE, FALSE, TRUE);
    levelBar = create_level_bar(0, 5, 5, GTK_LEVEL_BAR_MODE_DISCRETE, TRUE);
    progressBar = create_progress_bar("hello is me", 0.9, TRUE, FALSE, TRUE);
    scale = create_scale(GTK_ORIENTATION_VERTICAL, 0, 60, 2, 0, GTK_POS_LEFT, "hello is me", 0, GTK_POS_RIGHT);
    separator = create_separator(GTK_ORIENTATION_VERTICAL);
    button = create_button(GTK_RELIEF_NONE, "hello is me", TRUE, NULL, G_CALLBACK(hello), "hello");
    checkButton = create_check_button("_hello is me", TRUE, TRUE, G_CALLBACK(clicker), "NULddL");
    linkButton = create_link_button("https://www.google.com", "google");
    menuItem = create_menu_item("hello is me", "normal", NULL, G_CALLBACK(changer), "NULddL");
    
    


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

    separatorInfos *separatorInformation = get_properties_separator(separator);
    printf("orientation: %d\n", separatorInformation->orientation);

    buttonInfos *buttonInformation = get_properties_button(button);
    printf("relief: %d\nlabel: %s\nuse_underline: %d\npath_to_image: %s\ncallback: %p\ndata: %s\n", buttonInformation->relief, buttonInformation->label, buttonInformation->use_underline, buttonInformation->path_to_image, buttonInformation->callback, (char *)buttonInformation->data);

    checkButtonInfos *checkButtonInformation = get_properties_check_button(checkButton);
    printf("label: %s\nactive: %d\nuse_underline: %d\ncallback: %p\ndata: %s\n", checkButtonInformation->label, checkButtonInformation->active, checkButtonInformation->use_underline, checkButtonInformation->callback, (char *)checkButtonInformation->data);

    linkButtonInfos *linkButtonInformation = get_properties_link_button(linkButton);
    printf("uri: %s\nlabel: %s\n", linkButtonInformation->uri, linkButtonInformation->label);

    menuItemInfos *menuItemInformation = get_properties_menuItem(menuItem);
    printf("label: %s\type: %s\n submenu: %d\ncallback: %p\ndata: %s\n", menuItemInformation->label, menuItemInformation->type,menuItemInformation->submenu, menuItemInformation->callback, menuItemInformation->data);



    

    GtkWidget *submenu_item1 = create_menu_item("Sous-Option 1", "normal", NULL, NULL, NULL);
    GtkWidget *submenu_item2 = create_menu_item("Sous-Option 2", "normal", NULL, NULL, NULL);

    LinkedList *submenuL = create_linked_list();
    insert_at_beginning(submenuL, submenu_item1);
    insert_at_beginning(submenuL, submenu_item2);

    GtkWidget *submenu = create_menu(FALSE, "sous-menu", submenuL);

    GtkWidget *submenu2_item1 = create_menu_item("hello bro", "radio", NULL, G_CALLBACK(hello), NULL);
    GtkWidget *submenu2_item2 = create_menu_item("hello world", "radio", NULL, NULL, NULL);

    LinkedList *submenu2L = create_linked_list();
    insert_at_beginning(submenu2L, submenu2_item1);
    insert_at_beginning(submenu2L, submenu2_item2);

    GtkWidget *submenu2 = create_menu(FALSE, "sous-menu2", submenu2L);


    GtkWidget *item1 = create_menu_item("Item 1", "normal", submenu2, NULL, NULL);
    GtkWidget *item2 = create_menu_item("Item 2", "separator", NULL, NULL, NULL);
    GtkWidget *item3 = create_menu_item("Item 3", "check", NULL, NULL, NULL);
    GtkWidget *item4 = create_menu_item("Item 4", "radio", NULL, NULL, NULL);
    GtkWidget *item5 = create_menu_item("Item 5", "normal", submenu, NULL, NULL);


    LinkedList *menuL = create_linked_list();
    insert_at_beginning(menuL, item1);
    insert_at_beginning(menuL, item2);
    insert_at_beginning(menuL, item3);
    insert_at_beginning(menuL, item4);
    insert_at_beginning(menuL, item5);

    GtkWidget *menu = create_menu(TRUE, "Menu", menuL);

    menuInfos *menuInformation = get_properties_menu(menu);
    printf("is_primary: %d\nlabel: %s\nitems: %p\n", menuInformation->is_primary, menuInformation->label, menuInformation->items);


    gtk_container_add(GTK_CONTAINER(window), menu);


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

