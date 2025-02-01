/*****************************************************************************************************************************
 * 
 * @file xml_style.h
 * @brief the header file of the engine of the xml style
 * 
 * 
 * @author Ayyoub el Kouri
 * @date 26/01/2025
 * @version 2.0 (last update 01/02/2025)
 * 
 ****************************************************************************************************************************/



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