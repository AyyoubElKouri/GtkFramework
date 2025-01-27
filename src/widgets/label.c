/*****************************************************************************************************************************
 * 
 * @file label.c
 * @brief the implementation of the functions in label.h
 * 
 * 
 * @author Ayyoub el kouri
 * @date 21/01/2025
 * @version 1.0 (last update 22/01/2025)
 * 
 ****************************************************************************************************************************/

#include <stdlib.h>
#include <string.h>
#include "../../include/widgets/label.h"

GtkWidget *create_label(const gchar *text, gint size, const gchar *font, const gchar *color, const gchar *background, GtkJustification justify, gboolean underline, PangoWeight weight, PangoStyle style, gboolean wrap)
{
    labelInfos *labelInformation = (labelInfos *)malloc(sizeof(labelInfos));
    if(!labelInformation) return NULL;

    labelInformation->text = g_strdup(text);
    if(!labelInformation->text)
    {
        free(labelInformation);
        return NULL;
    }

    labelInformation->size = size;
    labelInformation->font = g_strdup(font);
    if(!labelInformation->font)
    {
        free(labelInformation);
        return NULL;
    }

    labelInformation->color = g_strdup(color);
    if(!labelInformation->color)
    {
        free(labelInformation);
        return NULL;
    }

    labelInformation->background = g_strdup(background);
    if(!labelInformation->background)
    {
        free(labelInformation);
        return NULL;
    }

    labelInformation->justify = justify;

    labelInformation->underline = underline;
    labelInformation->weight = weight;
    labelInformation->style = style;
    labelInformation->wrap = wrap;

    GtkWidget *label = set_properties_label(labelInformation);
    free(labelInformation);

    return label;
}

GtkWidget *set_properties_label(labelInfos *labelInformations)
{
    // create a label
    GtkWidget *label = gtk_label_new(labelInformations->text);
    
    // create list attributes
    PangoAttrList *attrList = pango_attr_list_new();

    // set the size
    PangoAttribute *size = pango_attr_size_new(labelInformations->size * PANGO_SCALE);
    pango_attr_list_insert(attrList, size);

    // set the font
    PangoAttribute *font = pango_attr_family_new(labelInformations->font);
    pango_attr_list_insert(attrList, font);

    // set the color
    // extract the color
    int red, green, blue;

    // Vérifier que la chaîne commence par '#' et a une longueur de 7 caractères
    if (labelInformations->color[0] != '#' || strlen(labelInformations->color) != 7) {
        perror("Format de couleur invalide. Utilisez le format '#RRGGBB'.\n");
        exit(EXIT_FAILURE);
    }

    // Convertir les composantes rouge, verte et bleue
    char temp[3];

    temp[0] = labelInformations->color[1];
    temp[1] = labelInformations->color[2];
    temp[2] = '\0';
    red = (int)strtol(temp, NULL, 16);

    temp[0] = labelInformations->color[3];
    temp[1] = labelInformations->color[4];
    temp[2] = '\0';
    green = (int)strtol(temp, NULL, 16);

    temp[0] = labelInformations->color[5];
    temp[1] = labelInformations->color[6];
    temp[2] = '\0';
    blue = (int)strtol(temp, NULL, 16);
    
    PangoAttribute *color = pango_attr_foreground_new(red * 256, green * 256, blue * 256);
    pango_attr_list_insert(attrList, color);




    // set the background
    // extract the background
    // Vérifier que la chaîne commence par '#' et a une longueur de 7 caractères
    if (labelInformations->background[0] != '#' || strlen(labelInformations->background) != 7) {
        perror("Format de couleur invalide. Utilisez le format '#RRGGBB'.\n");
        exit(EXIT_FAILURE);
    }

    // Convertir les composantes rouge, verte et bleue
    temp[0] = labelInformations->background[1];
    temp[1] = labelInformations->background[2];
    temp[2] = '\0';
    red = (int)strtol(temp, NULL, 16);

    temp[0] = labelInformations->background[3];
    temp[1] = labelInformations->background[4];
    temp[2] = '\0';
    green = (int)strtol(temp, NULL, 16);

    temp[0] = labelInformations->background[5];
    temp[1] = labelInformations->background[6];
    temp[2] = '\0';
    blue = (int)strtol(temp, NULL, 16);

    PangoAttribute *background = pango_attr_background_new(red * 256, green * 256, blue * 256);
    pango_attr_list_insert(attrList, background);
    



    // set the alignment
    gtk_label_set_justify(GTK_LABEL(label), labelInformations->justify);

    // set the underline
    if(labelInformations->underline)
    {
        PangoAttribute *underline = pango_attr_underline_new(PANGO_UNDERLINE_SINGLE);
        pango_attr_list_insert(attrList, underline);
    }

    // set the weight
    PangoAttribute *weight = pango_attr_weight_new(labelInformations->weight);
    pango_attr_list_insert(attrList, weight);

    // set the style
    PangoAttribute *style = pango_attr_style_new(labelInformations->style);
    pango_attr_list_insert(attrList, style);


    // set the attributes
    gtk_label_set_attributes(GTK_LABEL(label), attrList);

    // set the wrap of the text
    gtk_label_set_line_wrap(GTK_LABEL(label), labelInformations->wrap);

    return label;
}

labelInfos *get_properties_label(GtkWidget *label)
{
    labelInfos *labelInformation = (labelInfos *)malloc(sizeof(labelInfos));
    if(!labelInformation) return NULL;

    // get the text
    labelInformation->text = gtk_label_get_text(GTK_LABEL(label));

    labelInformation->wrap  = gtk_label_get_line_wrap(GTK_LABEL(label));

        // Lire les attributs du label
    PangoAttrList *labelAttrList = gtk_label_get_attributes(GTK_LABEL(label));
    if (labelAttrList)
    {
        PangoAttrIterator *iter = pango_attr_list_get_iterator(labelAttrList);

        // Parcourir les attributs
        do {
            PangoAttribute *attr;

            // Taille de la police
            attr = pango_attr_iterator_get(iter, PANGO_ATTR_SIZE);
            if (attr) 
                labelInformation->size = ((PangoAttrInt *)attr)->value / PANGO_SCALE;

            // Famille de police
            attr = pango_attr_iterator_get(iter, PANGO_ATTR_FAMILY);
            if (attr)
                labelInformation->font = g_strdup(((PangoAttrString *)attr)->value);

            // Couleur du texte
            attr = pango_attr_iterator_get(iter, PANGO_ATTR_FOREGROUND);
            if (attr)
            {
                PangoColor color = ((PangoAttrColor *)attr)->color;
                int red = color.red / 256;
                int green = color.green / 256;
                int blue = color.blue / 256;
                char colorHex[8];
                sprintf(colorHex, "#%02X%02X%02X", red, green, blue);
                labelInformation->color = g_strdup(colorHex);
            }

            // Couleur de background
            attr = pango_attr_iterator_get(iter, PANGO_ATTR_BACKGROUND);
            if (attr)
            {
                PangoColor color = ((PangoAttrColor *)attr)->color;
                int red = color.red / 256;
                int green = color.green / 256;
                int blue = color.blue / 256;
                char colorHex[8];
                sprintf(colorHex, "#%02X%02X%02X", red, green, blue);
                labelInformation->background = g_strdup(colorHex);
            }

            // Soulignement
            attr = pango_attr_iterator_get(iter, PANGO_ATTR_UNDERLINE);
            if (attr)
                labelInformation->underline = TRUE;

            // Poids de la police
            attr = pango_attr_iterator_get(iter, PANGO_ATTR_WEIGHT);
            if (attr)
                labelInformation->weight = ((PangoAttrInt *)attr)->value;

            // Style de la police
            attr = pango_attr_iterator_get(iter, PANGO_ATTR_STYLE);
            if (attr)
                labelInformation->style = ((PangoAttrInt *)attr)->value;

        } while (pango_attr_iterator_next(iter));

        pango_attr_iterator_destroy(iter);
    }

    return labelInformation;
}