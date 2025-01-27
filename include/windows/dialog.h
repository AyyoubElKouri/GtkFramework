/*****************************************************************************************************************************
 * 
 * @file dialog.h
 * @brief header file for creating dialog for a window with its properties
 * 
 * This header file contains all function declarations for
 * creating a GTK dialog with its properties.
 * 
 * @author Ayyoub el Kouri
 * @date 20/01/2025
 * @version 1.0 (last update 20/01/2025)
 * 
 ****************************************************************************************************************************/

#ifndef DIALOG_H
#define DIALOG_H

#include <gtk/gtk.h>

/**
 * @struct dialogInfos
 * @brief the dialog properties
 */

typedef struct
{
    const gchar *title;
    GtkWidget *parent;
    GtkDialogFlags flags;
    gint width;
    gint height;
    gdouble opacily;
    GtkWidget *box_content_area;
    const gchar *title1;
    gint answer1;
    const gchar *title2;
    gint answer2;
    const char *title3;
    gint answer3;
} dialogInfos;

/**
 * @brief This function sets the information in one structure and creates a dialog with this information.
 * 
 * @param title The title of the dialog.
 * @param flags This is responsible for whether the dialog is fixed with the parent or not.
 * @param width The default width of the dialog.
 * @param height The default height of the dialog.
 * @param opacity The default opacity of the dialog.
 * @param title1 The title of the first button in the dialog.
 * @param answer1 The answer associated with the first button.
 * @param title2 The title of the second button in the dialog.
 * @param answer2 The answer associated with the second button.
 * @param title3 The title of the third button in the dialog.
 * @param answer3 The answer associated with the third button.
 * 
 * @note By default, 3 buttons are provided. If you need fewer buttons, you can pass "NULL" as the title to
 *       indicate that there is no button here.
 * 
 * @return GtkWidget* A pointer to the created dialog.
 */

GtkWidget *create_dialog(const gchar *title, GtkWidget *parent, GtkDialogFlags flags, gint width, gint height, double opacity, GtkWidget *box_content_area, const gchar *title1, gint answer1, const gchar *title2, gint answer2, const char *title3, gint answer3);

/**
 * @brief This function creates the dialog and sets its properties.
 * 
 * @param dialogInformations The properties of the dialog
 * @return GtkWidget pointer to the dialog
 */

GtkWidget *set_properties_dialog(dialogInfos *dialogInformations);

/**
 * @brief This function return the properties of the dialog;
 * 
 * @param dialog The dialog 
 * @return dialogInfos pointer to the structre of the dialog in parameter
 */

dialogInfos *get_properties_dialog(GtkWidget *dialog);



#endif // DIALOG_H