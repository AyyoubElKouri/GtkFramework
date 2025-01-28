/*****************************************************************************************************************************
 * 
 * @file grid.c
 * @brief the implementation of the functions in grid.h
 * 
 * 
 * @author Ayyoub el kouri
 * @date 28/01/2025
 * @version 1.1 (last update 28/01/2025)
 * 
 ****************************************************************************************************************************/

#include "../../include/containers/grid.h"

GtkWidget *create_grid(guint rows_spacing, guint columns_spacing, gboolean rows_homogeneous, gboolean columns_homogeneous)
{
    gridInfos *gridInformations = (gridInfos *)malloc(sizeof(gridInfos));
    if(!gridInformations) return NULL;

    gridInformations->rows_spacing = rows_spacing;
    gridInformations->columns_spacing = columns_spacing;
    gridInformations->rows_homogeneous = rows_homogeneous;
    gridInformations->columns_homogeneous = columns_homogeneous;

    GtkWidget *grid = set_properties_grid(gridInformations);

    return grid;
}

GtkWidget *set_properties_grid(gridInfos *gridInformations)
{
    GtkWidget *grid = gtk_grid_new();
    // set the row spacing
    gtk_grid_set_row_spacing(GTK_GRID(grid), gridInformations->rows_spacing);

    // set the column spacing
    gtk_grid_set_column_spacing(GTK_GRID(grid), gridInformations->columns_spacing);

    // set the row homogeneous
    gtk_grid_set_row_homogeneous(GTK_GRID(grid), gridInformations->rows_homogeneous);

    // set the column homogeneous
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), gridInformations->columns_homogeneous);

    return grid;
}

gridInfos *get_properties_grid(GtkWidget *grid)
{
    gridInfos *gridInformations = (gridInfos *)malloc(sizeof(gridInfos));
    if(!gridInformations) return NULL;

    // get the row spacing
    gridInformations->rows_spacing = gtk_grid_get_row_spacing(GTK_GRID(grid));

    // get the column spacing
    gridInformations->columns_spacing = gtk_grid_get_column_spacing(GTK_GRID(grid));

    // get the row homogeneous
    gridInformations->rows_homogeneous = gtk_grid_get_row_homogeneous(GTK_GRID(grid));

    // get the column homogeneous
    gridInformations->columns_homogeneous = gtk_grid_get_column_homogeneous(GTK_GRID(grid));

    return gridInformations;
}

void add_to_grid(GtkWidget *grid, GtkWidget *child, guint row, guint column, guint row_span, guint column_span)
{
    gtk_grid_attach(GTK_GRID(grid), child, column, row, row_span, column_span);
}