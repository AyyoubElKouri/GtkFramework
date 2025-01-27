/*****************************************************************************************************************************
 * 
 * @file text_view.c
 * @brief the implementation of the functions in text_view.h
 * 
 * 
 * @author Ayyoub el kouri
 * @date 23/01/2025
 * @version 1.0 (last update 23/01/2025)
 * 
 ****************************************************************************************************************************/

#include "../../include/widgets/text_view.h"
#define max 100

char *colorG;
char *backgroundG;
int styleG;

GtkWidget *create_text_view(const gchar *text, gint size, const gchar *font, const gchar *color, const gchar *background, GtkJustification justify, PangoWeight weight, PangoStyle style, gboolean wrap, gboolean cursor_visible, gboolean editable)
{
    textViewInfos *textViewInformation = (textViewInfos *)malloc(sizeof(textViewInfos));
    if(!textViewInformation) return NULL;

    textViewInformation->text = g_strdup(text);
    if(!textViewInformation->text)
    {
        free(textViewInformation);
        return NULL;
    }

    textViewInformation->size = size;
    textViewInformation->font = g_strdup(font);
    if(!textViewInformation->font)
    {
        free(textViewInformation);
        return NULL;
    }

    textViewInformation->color = g_strdup(color);
    colorG = g_strdup(color);
    if(!textViewInformation->color)
    {
        free(textViewInformation);
        return NULL;
    }

    textViewInformation->background = g_strdup(background);
    backgroundG = g_strdup(background);
    if(!textViewInformation->background)
    {
        free(textViewInformation);
        return NULL;
    }

    textViewInformation->justify = justify;
    textViewInformation->weight = weight;
    textViewInformation->style = style;
    styleG = style;
    textViewInformation->wrap = wrap;
    textViewInformation->cursor_visible = cursor_visible;
    textViewInformation->editable = editable;

    GtkWidget *textView = set_properties_text_view(textViewInformation);
    free(textViewInformation);

    return textView;
}


GtkWidget *set_properties_text_view(textViewInfos *textViewInformation)
{
    GtkWidget *textView = gtk_text_view_new();

    // Récupérer le buffer existant
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textView));

    // Définir le texte
    gtk_text_buffer_set_text(buffer, textViewInformation->text, -1);
    
    GtkTextIter start, end;
    gtk_text_buffer_get_start_iter(buffer, &start);
    gtk_text_buffer_get_end_iter(buffer, &end);

    // set the size 
    GtkTextTag *size_tag = gtk_text_buffer_create_tag(buffer, "size_tag", "size", textViewInformation->size * PANGO_SCALE, NULL);


    gtk_text_buffer_apply_tag(buffer, size_tag, &start, &end);

    // set the font
    GtkTextTag *font_tag = gtk_text_buffer_create_tag(buffer, "font_tag", "font", textViewInformation->font, NULL);
    gtk_text_buffer_apply_tag(buffer, font_tag, &start, &end);

    // set the color 
    GtkTextTag *color = gtk_text_buffer_create_tag(buffer, "color", "foreground", textViewInformation->color, NULL);
    gtk_text_buffer_apply_tag(buffer, color, &start, &end);

    // set the background
    GtkTextTag *background_tag = gtk_text_buffer_create_tag(buffer, "background_tag", "background", textViewInformation->background, NULL);
    gtk_text_buffer_apply_tag(buffer, background_tag, &start, &end);

    // set the justification
    gtk_text_view_set_justification(GTK_TEXT_VIEW(textView), textViewInformation->justify);

    // set the weight
    GtkTextTag *weight_tag = gtk_text_buffer_create_tag(buffer, "weight_tag", "weight", textViewInformation->weight, NULL);
    gtk_text_buffer_apply_tag(buffer, weight_tag, &start, &end);

    // set the style
    GtkTextTag *style_tag = gtk_text_buffer_create_tag(buffer, "style_tag", "style", textViewInformation->style, NULL);
    gtk_text_buffer_apply_tag(buffer, style_tag, &start, &end);
    
    // set the wrap
    if(textViewInformation->wrap)
        gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(textView), GTK_WRAP_WORD);

    // set the cursor visibility
    if(!textViewInformation->cursor_visible)
        gtk_text_view_set_cursor_visible(GTK_TEXT_VIEW(textView), FALSE);
    
    // set the editability
    if(!textViewInformation->editable)
        gtk_text_view_set_editable(GTK_TEXT_VIEW(textView), FALSE);
    
    return textView;
}

textViewInfos *get_properties_text_view(GtkWidget *textView)
{
    textViewInfos *textViewInformation = (textViewInfos *)malloc(sizeof(textViewInfos));
    if(!textViewInformation) return NULL;

    // get the text from the buffer
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textView));
    GtkTextIter start, end;
    gtk_text_buffer_get_start_iter(buffer, &start);
    gtk_text_buffer_get_end_iter(buffer, &end);
    textViewInformation->text = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);

    // get the size
    GtkTextTagTable *tag_table = gtk_text_buffer_get_tag_table(buffer);
    if (!tag_table)
        textViewInformation->size = 12;
    else
    {
        GtkTextTag *size_tag = gtk_text_tag_table_lookup(tag_table, "size_tag");

        if (size_tag) {
            gint size = 0;

            g_object_get(size_tag, "size-points", &size, NULL);
            if (size == 0) {
                g_object_get(size_tag, "size", &size, NULL);
                if (size > 0) {
                    size = size / PANGO_SCALE;
                }
            }

            textViewInformation->size = (size > 0) ? size : 12;
        }
        else
            textViewInformation->size = 12;
    }

    // get font
    GtkTextTag *font_tag = gtk_text_tag_table_lookup(tag_table, "font_tag");

    if (font_tag)
    {
        gchar *font = NULL;
        g_object_get(font_tag, "font", &font, NULL);
        textViewInformation->font = g_strdup(font);
        g_free(font);
    } else
        textViewInformation->font = g_strdup("Sans 12");

    
    // get color
    textViewInformation->color = g_strdup(colorG);
    
    // get background color
    textViewInformation->background = g_strdup(backgroundG);

    // get justification
    textViewInformation->justify = gtk_text_view_get_justification(GTK_TEXT_VIEW(textView));

    // get weight and style
    GtkTextView *textView2 = GTK_TEXT_VIEW(textView);

    PangoContext *context = gtk_widget_get_pango_context(GTK_WIDGET(textView2));
    PangoFontDescription *font_desc = pango_context_get_font_description(context);

    if (font_desc)
    {
        textViewInformation->weight = pango_font_description_get_weight(font_desc);
        textViewInformation->style = styleG;
    }

    // get wrap
    textViewInformation->wrap = gtk_text_view_get_wrap_mode(GTK_TEXT_VIEW(textView)) != GTK_WRAP_NONE;
    
    // get cursor visibility
    textViewInformation->cursor_visible = gtk_text_view_get_cursor_visible(GTK_TEXT_VIEW(textView));

    // get editability
    textViewInformation->editable = gtk_text_view_get_editable(GTK_TEXT_VIEW(textView));

    return textViewInformation;
}