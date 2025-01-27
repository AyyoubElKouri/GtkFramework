/*****************************************************************************************************************************
 * 
 * @file spin_button.h
 * @brief the implementation of the functions in spin_button.h
 * 
 * 
 * @author Ayyoub el kouri
 * @date 27/01/2025
 * @version 1.0 (last update 27/01/2025)
 * 
 ****************************************************************************************************************************/

#include "../../include/widgets/spin_button.h"

GtkWidget *create_spin_button(gdouble min, gdouble max, gdouble step, gdouble value, guint digits, gboolean wrap, gboolean numeric)
{
    spinButtonInfos *spinButtonInformations = (spinButtonInfos *)malloc(sizeof(spinButtonInfos));
    if(!spinButtonInformations) return NULL;

    spinButtonInformations->min = min;
    spinButtonInformations->max = max;
    spinButtonInformations->step = step;
    spinButtonInformations->value = value;
    spinButtonInformations->digits = digits;
    spinButtonInformations->wrap = wrap;
    spinButtonInformations->numeric = numeric;

    GtkWidget *spinButton = set_properties_spin_button(spinButtonInformations);
    free(spinButtonInformations);

    return spinButton;
}

GtkWidget *set_properties_spin_button(spinButtonInfos *spinButtonInformation)
{
    // create the spin button with the properties
    GtkWidget *spinButton = gtk_spin_button_new_with_range(spinButtonInformation->min, spinButtonInformation->max, spinButtonInformation->step);

    // set the value
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinButton), spinButtonInformation->value);

    // set the digits
    gtk_spin_button_set_digits(GTK_SPIN_BUTTON(spinButton), spinButtonInformation->digits);

    // set the wrap
    gtk_spin_button_set_wrap(GTK_SPIN_BUTTON(spinButton), spinButtonInformation->wrap);

    // set the numeric
    gtk_spin_button_set_numeric(GTK_SPIN_BUTTON(spinButton), spinButtonInformation->numeric);

    return spinButton;
}

spinButtonInfos *get_properties_spin_button(GtkWidget *spinButton)
{
    spinButtonInfos *spinButtonInformation = (spinButtonInfos *)malloc(sizeof(spinButtonInfos));
    if(!spinButtonInformation) return NULL;

    gtk_spin_button_get_range(GTK_SPIN_BUTTON(spinButton), &spinButtonInformation->min, &spinButtonInformation->max);

    gtk_spin_button_get_increments(GTK_SPIN_BUTTON(spinButton), &spinButtonInformation->step, NULL);

    spinButtonInformation->value = gtk_spin_button_get_value(GTK_SPIN_BUTTON(spinButton));

    spinButtonInformation->digits = gtk_spin_button_get_digits(GTK_SPIN_BUTTON(spinButton));

    spinButtonInformation->wrap = gtk_spin_button_get_wrap(GTK_SPIN_BUTTON(spinButton));

    spinButtonInformation->numeric = gtk_spin_button_get_numeric(GTK_SPIN_BUTTON(spinButton));

    return spinButtonInformation;
}