/*****************************************************************************************************************************
 * 
 * @file grid.h
 * @brief the header file of the grid container
 * 
 * this file contains all the functions declarations and structures used in the grid container
 * 
 * @author Ayyoub el Kouri
 * @date 28/01/2025
 * @version 1.1 (last update 28/01/2025)
 * 
 ******************************************************************************************************************************/

#ifndef GRID_H
#define GRID_H

#include <gtk/gtk.h>

/**
 * @struct gridInfos
 * @brief the grid properties
 */

typedef struct
{
    guint rows_spacing;
    guint columns_spacing;
    gboolean rows_homogeneous;
    gboolean columns_homogeneous;
}gridInfos;

/**
 * @brief creates a grid container
 * 
 * @param rows_spacing the spacing between rows
 * @param columns_spacing the spacing between columns
 * @param rows_homogeneous if the rows are homogeneous
 * @param columns_homogeneous if the columns are homogeneous
 * 
 * @return GtkWidget* the grid
*/

GtkWidget *create_grid(guint rows_spacing, guint columns_spacing, gboolean rows_homogeneous, gboolean columns_homogeneous);

/**
 * @brief sets the properties of the grid
 * 
 * @param gridInformations the grid properties
 * 
 * @return GtkWidget* the grid
*/

GtkWidget *set_properties_grid(gridInfos *gridInformations);

/**
 * @brief gets the properties of the grid
 * 
 * @param grid the grid
 * 
 * @return gridInfos* the grid properties
 */

gridInfos *get_properties_grid(GtkWidget *grid);


void add_to_grid(GtkWidget *grid, GtkWidget *child, guint row, guint column, guint row_span, guint column_span);

#endif