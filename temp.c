#include <gtk/gtk.h>
#include "include/GtkFramework/GtkFramework.h"
static void activate(GtkApplication *app, gpointer data){
GtkWidget *window = create_window(app, GTK_WINDOW_TOPLEVEL, "Default title", 800, 200, TRUE, GTK_WIN_POS_CENTER, TRUE, NULL, 1.0, FALSE);
GtkWidget *header_bar = create_header_bar("Block", "block of computer science", "assets/data-science.png", TRUE);
add_header_bar_to_window(window, header_bar);
GtkWidget *main_box = create_box(GTK_ORIENTATION_HORIZONTAL, -1, 10);
GtkWidget *box1 = create_box(GTK_ORIENTATION_VERTICAL, -1, 10);
GtkWidget *maroc_scrolled_window = create_scrolled_window(FALSE, TRUE);
GtkWidget *maroc_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 10);
GtkWidget *maroc_image = create_image("assets/w160/ma.png");
add_to_box(maroc_box, maroc_image, START, TRUE, FALSE, 0, 0, 0, 0, 0);
GtkWidget *maroc_label = create_label("Maroc", 10, "Arial", "#FFFFFF", "#000000", GTK_JUSTIFY_CENTER, FALSE, 0, 0, TRUE);
add_to_box(maroc_box, maroc_label, START, TRUE, FALSE, 0, 0, 0, 0, 0);
GtkWidget *maroc_information = create_label("Hello", 18, "consolas", "#FF33FF", "#000000", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);
add_to_box(maroc_box, maroc_information, START, TRUE, FALSE, 0, 0, 0, 5, 0);
add_to_scrolled_window(maroc_scrolled_window, maroc_box);
add_to_box(box1, maroc_scrolled_window, START, TRUE, TRUE, 0, 0, 0, 0, 0);
add_to_box(main_box, box1, START, TRUE, TRUE, 0, 0, 0, 5, 0);
GtkWidget *box2 = create_box(GTK_ORIENTATION_VERTICAL, -1, 10);
GtkWidget *maroc_scrolled_window2 = create_scrolled_window(FALSE, TRUE);
GtkWidget *maroc_box2 = create_box(GTK_ORIENTATION_VERTICAL, -1, 10);
GtkWidget *maroc_image2 = create_image("assets/w160/ma.png");
add_to_box(maroc_box2, maroc_image2, START, TRUE, FALSE, 0, 0, 0, 0, 0);
GtkWidget *maroc_label2 = create_label("Maroc", 10, "Arial", "#FFFFFF", "#000000", GTK_JUSTIFY_CENTER, FALSE, 0, 0, TRUE);
add_to_box(maroc_box2, maroc_label2, START, TRUE, FALSE, 0, 0, 0, 0, 0);
GtkWidget *maroc_information2 = create_label("Morocco,[d] officially the Kingdom of Morocco,[e] is a country in the Maghreb region of North Africa. It overlooks the Mediterranean Sea to the north and the Atlantic Ocean to the west, and has land borders with Algeria to the east, and the disputed territory of Western Sahara to the south. Morocco also claims the Spanish exclaves of Ceuta, Melilla and Peñón de Vélez de la Gomera, and several small Spanish-controlled islands off its coast.[17] It has a population of approximately 37 million. Islam is both the official and predominant religion, while Arabic and Berber are the official languages. Additionally, French and the Moroccan dialect of Arabic are widely spoken. The culture of Morocco is a mix of Arab, Berber, African and European cultures. Its capital is Rabat, while its largest city is Casablanca.[18]Morocco,[d] officially the Kingdom of Morocco,[e] is a country in the Maghreb region of North Africa. It overlooks the Mediterranean Sea to the north and the Atlantic Ocean to the west, and has land borders with Algeria to the east, and the disputed territory of Western Sahara to the south. Morocco also claims the Spanish exclaves of Ceuta, Melilla and Peñón de Vélez de la Gomera, and several small Spanish-controlled islands off its coast.[17] It has a population of approximately 37 million. Islam is both the official and predominant religion, while Arabic and Berber are the official languages. Additionally, French and the Moroccan dialect of Arabic are widely spoken. The culture of Morocco is a mix of Arab, Berber, African and European cultures. Its capital is Rabat, while its largest city is Casablanca.[18]", 10, "Arial", "#FFFFFF", "#000000", GTK_JUSTIFY_CENTER, FALSE, 0, 0, TRUE);
add_to_box(maroc_box2, maroc_information2, START, TRUE, FALSE, 0, 0, 0, 5, 0);
add_to_scrolled_window(maroc_scrolled_window2, maroc_box2);
add_to_box(box2, maroc_scrolled_window2, START, TRUE, TRUE, 0, 0, 0, 0, 0);
add_to_box(main_box, box2, START, TRUE, TRUE, 0, 0, 0, 5, 0);
add_to_container(window, main_box);
show_widget(window);
}
int main(int argc, char *argv[]){
    GtkApplication *app = gtk_application_new("org.example.app", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}
