


#ifndef XML_STYLE_H
#define XML_STYLE_H

#include "../include/GtkFramework/GtkFramework.h"
#include "widgets_data_bases.h"

typedef struct
{
    int argc;
    char **argv;
}arg;


void use_xml_style_file(GtkApplication *app, arg *myarg);


#endif