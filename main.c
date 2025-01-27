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
#include "include/GtkFramework/GtkFramework.h"

static void marocInfos(GtkWidget *widget, gpointer data)
{
    GtkWidget *window = create_window(NULL, GTK_WINDOW_TOPLEVEL, "Morocco", 700, 460, FALSE, GTK_WIN_POS_CENTER, TRUE, NULL, 1, FALSE);
    GtkWidget *title = create_label("1 - this window is for Morocco", 27, "consolas", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, TRUE, PANGO_WEIGHT_BOLD, PANGO_STYLE_NORMAL, FALSE);
    GtkWidget *subtitle1 = create_label("1 - 1 : Morroco history", 20, "consolas", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, TRUE, PANGO_WEIGHT_BOLD, PANGO_STYLE_NORMAL, TRUE);
    GtkWidget *paragraph1 = create_label("Le Maroc, situé au carrefour de l'Afrique, de l'Europe et du monde arabe, possède une riche histoire. Les premiers habitants, les Berbères, s’y sont installés il y a plus de 3000 ans. Les Phéniciens, suivis des Romains, ont laissé leur empreinte dans la région. À partir du VIIe siècle, l'islam a été introduit par les Arabes, marquant un tournant majeur dans la culture et l'organisation politique. Sous les dynasties almoravide, almohade, mérinide et saadienne, le Maroc a connu des périodes de prospérité et d'influence. En 1912, le pays est devenu un protectorat franco-espagnol, avant de recouvrer son indépendance en 1956 sous Mohammed V. Depuis, le Maroc s'est modernisé tout en préservant ses traditions, sous la gouvernance actuelle de Mohammed VI.",
    12, "consolas", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, PANGO_WEIGHT_NORMAL, PANGO_STYLE_NORMAL, TRUE);


    GtkWidget *subtitle2 = create_label("1 - 2 : Morroco culture", 20, "consolas", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, TRUE, PANGO_WEIGHT_BOLD, PANGO_STYLE_NORMAL, TRUE);
    GtkWidget *paragraph2 = create_label("La culture marocaine est riche et diversifiée, influencée par les Berbères, les Arabes, les Africains subsahariens et les cultures andalouse et européenne. La langue arabe et le berbère (amazigh) sont les langues officielles, avec une grande variété de dialectes. L'islam joue un rôle central dans les traditions et la vie quotidienne. La cuisine marocaine, réputée dans le monde entier, inclut des plats emblématiques comme le couscous, le tajine et les pastillas. L'artisanat marocain, avec ses tapis, poteries, babouches et zellige, reflète un savoir-faire ancestral. Les fêtes religieuses comme l’Aïd et des célébrations culturelles comme le Moussem de Tan-Tan témoignent de l'attachement aux traditions. La musique, notamment le gnawa, le chaâbi et l’andalou, est un pilier culturel. Enfin, le Maroc est connu pour son hospitalité chaleureuse et ses souks animés qui reflètent l’âme de ses villes.",
    12, "consolas", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, PANGO_WEIGHT_NORMAL, PANGO_STYLE_NORMAL, TRUE);

    GtkWidget *main_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 20);

    GtkWidget *box_for_title = create_box(GTK_ORIENTATION_HORIZONTAL, GTK_ALIGN_START, 0);
    add_box(box_for_title, title, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    GtkWidget *box_for_subtitle1 = create_box(GTK_ORIENTATION_HORIZONTAL, GTK_ALIGN_START, 0);
    add_box(box_for_subtitle1, subtitle1, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    GtkWidget *box_for_subtitle2 = create_box(GTK_ORIENTATION_HORIZONTAL, GTK_ALIGN_START, 0);
    add_box(box_for_subtitle2, subtitle2, START, FALSE, FALSE, 0, 0, 0, 0, 0);
    


    add_box(main_box, box_for_title, START, FALSE, FALSE, 0, 90, 0, 0, 0);
    add_box(main_box, box_for_subtitle1, START, FALSE, FALSE, 0, 30, 0, 0, 0);
    add_box(main_box, paragraph1, START, FALSE, FALSE, 0, 4, 0, 10, 0);
    add_box(main_box, box_for_subtitle2, START, FALSE, FALSE, 0, 30, 0, 0, 0);
    add_box(main_box, paragraph2, START, FALSE, FALSE, 0, 4, 0, 10, 0);

    GtkWidget *scrolled_window = create_scrolled_window();
    add_to_scrolled_window(scrolled_window, main_box);

    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window), GTK_POLICY_NEVER, GTK_POLICY_ALWAYS);

    gtk_container_add(GTK_CONTAINER(window), scrolled_window);

    gtk_widget_show_all(window);
}


static void franceInfos(GtkWidget *widget, gpointer data)
{
    GtkWidget *window = create_window(NULL, GTK_WINDOW_TOPLEVEL, "France", 700, 460, FALSE, GTK_WIN_POS_CENTER, TRUE, NULL, 1, FALSE);
    GtkWidget *title = create_label("2 - this window is for France", 27, "consolas", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, TRUE, PANGO_WEIGHT_BOLD, PANGO_STYLE_NORMAL, FALSE);
    GtkWidget *subtitle1 = create_label("2 - 1 : France history", 20, "consolas", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, TRUE, PANGO_WEIGHT_BOLD, PANGO_STYLE_NORMAL, TRUE);
    GtkWidget *paragraph1 = create_label("La France, située en Europe de l'Ouest, possède une histoire riche et complexe. Les Gaulois, peuple celte, étaient les premiers habitants avant la conquête romaine par Jules César en 52 av. J.-C. Au Moyen Âge, la France est devenue une puissance majeure sous les dynasties mérovingienne, carolingienne et capétienne. La Révolution française de 1789 a marqué un tournant décisif, abolissant la monarchie et établissant la République. Napoléon Bonaparte a ensuite étendu l'influence française à travers l'Europe au début du XIXe siècle. Après deux guerres mondiales dévastatrices, la France est devenue l'une des principales puissances mondiales, membre fondateur de l'Union européenne et acteur clé sur la scène internationale.",
    12, "consolas", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, PANGO_WEIGHT_NORMAL, PANGO_STYLE_NORMAL, TRUE);

    GtkWidget *subtitle2 = create_label("2 - 2 : France culture", 20, "consolas", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, TRUE, PANGO_WEIGHT_BOLD, PANGO_STYLE_NORMAL, TRUE);
    GtkWidget *paragraph2 = create_label("La culture française est l'une des plus influentes au monde. La langue française, parlée par des millions de personnes, est un pilier de cette culture. La France est célèbre pour sa littérature, avec des auteurs comme Victor Hugo, Marcel Proust et Albert Camus. La cuisine française, inscrite au patrimoine mondial de l'UNESCO, est réputée pour ses plats raffinés comme la baguette, le fromage et le vin. L'art français, de la Renaissance à l'impressionnisme, a marqué l'histoire de l'art. La France est également connue pour sa mode, son cinéma et sa musique. Les traditions comme la Fête nationale du 14 juillet et les marchés de Noël reflètent l'âme du pays.",
    12, "consolas", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, PANGO_WEIGHT_NORMAL, PANGO_STYLE_NORMAL, TRUE);

    GtkWidget *main_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 20);

    GtkWidget *box_for_title = create_box(GTK_ORIENTATION_HORIZONTAL, GTK_ALIGN_START, 0);
    add_box(box_for_title, title, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    GtkWidget *box_for_subtitle1 = create_box(GTK_ORIENTATION_HORIZONTAL, GTK_ALIGN_START, 0);
    add_box(box_for_subtitle1, subtitle1, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    GtkWidget *box_for_subtitle2 = create_box(GTK_ORIENTATION_HORIZONTAL, GTK_ALIGN_START, 0);
    add_box(box_for_subtitle2, subtitle2, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    add_box(main_box, box_for_title, START, FALSE, FALSE, 0, 90, 0, 0, 0);
    add_box(main_box, box_for_subtitle1, START, FALSE, FALSE, 0, 30, 0, 0, 0);
    add_box(main_box, paragraph1, START, FALSE, FALSE, 0, 4, 0, 10, 0);
    add_box(main_box, box_for_subtitle2, START, FALSE, FALSE, 0, 30, 0, 0, 0);
    add_box(main_box, paragraph2, START, FALSE, FALSE, 0, 4, 0, 10, 0);

    GtkWidget *scrolled_window = create_scrolled_window();
    add_to_scrolled_window(scrolled_window, main_box);

    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window), GTK_POLICY_NEVER, GTK_POLICY_ALWAYS);

    gtk_container_add(GTK_CONTAINER(window), scrolled_window);

    gtk_widget_show_all(window);
}

static void argentinaInfos(GtkWidget *widget, gpointer data)
{
    GtkWidget *window = create_window(NULL, GTK_WINDOW_TOPLEVEL, "Argentina", 700, 460, FALSE, GTK_WIN_POS_CENTER, TRUE, NULL, 1, FALSE);
    GtkWidget *title = create_label("3 - this window is for Argentina", 27, "consolas", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, TRUE, PANGO_WEIGHT_BOLD, PANGO_STYLE_NORMAL, FALSE);
    GtkWidget *subtitle1 = create_label("3 - 1 : Argentina history", 20, "consolas", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, TRUE, PANGO_WEIGHT_BOLD, PANGO_STYLE_NORMAL, TRUE);
    GtkWidget *paragraph1 = create_label("L'Argentine, située en Amérique du Sud, a une histoire marquée par les peuples indigènes, la colonisation espagnole et l'indépendance. Les Espagnols ont colonisé la région au XVIe siècle, et l'Argentine a déclaré son indépendance en 1816. Le XIXe siècle a été marqué par des conflits internes et une forte immigration européenne, notamment d'Italiens et d'Espagnols. Le XXe siècle a vu l'émergence de figures politiques comme Juan Perón, dont l'idéologie a profondément influencé le pays. Malgré des périodes de dictature et de crise économique, l'Argentine reste une nation dynamique et culturellement riche.",
    12, "consolas", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, PANGO_WEIGHT_NORMAL, PANGO_STYLE_NORMAL, TRUE);

    GtkWidget *subtitle2 = create_label("3 - 2 : Argentina culture", 20, "consolas", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, TRUE, PANGO_WEIGHT_BOLD, PANGO_STYLE_NORMAL, TRUE);
    GtkWidget *paragraph2 = create_label("La culture argentine est un mélange unique d'influences européennes et indigènes. Le tango, né à Buenos Aires, est l'une des danses les plus célèbres au monde. La littérature argentine est marquée par des auteurs comme Jorge Luis Borges et Julio Cortázar. La cuisine argentine est réputée pour ses viandes grillées (asado) et ses vins, notamment ceux de la région de Mendoza. Le football est une passion nationale, avec des joueurs légendaires comme Diego Maradona et Lionel Messi. Les festivals traditionnels, comme le Carnaval, reflètent la diversité culturelle du pays.",
    12, "consolas", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, PANGO_WEIGHT_NORMAL, PANGO_STYLE_NORMAL, TRUE);

    GtkWidget *main_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 20);

    GtkWidget *box_for_title = create_box(GTK_ORIENTATION_HORIZONTAL, GTK_ALIGN_START, 0);
    add_box(box_for_title, title, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    GtkWidget *box_for_subtitle1 = create_box(GTK_ORIENTATION_HORIZONTAL, GTK_ALIGN_START, 0);
    add_box(box_for_subtitle1, subtitle1, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    GtkWidget *box_for_subtitle2 = create_box(GTK_ORIENTATION_HORIZONTAL, GTK_ALIGN_START, 0);
    add_box(box_for_subtitle2, subtitle2, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    add_box(main_box, box_for_title, START, FALSE, FALSE, 0, 90, 0, 0, 0);
    add_box(main_box, box_for_subtitle1, START, FALSE, FALSE, 0, 30, 0, 0, 0);
    add_box(main_box, paragraph1, START, FALSE, FALSE, 0, 4, 0, 10, 0);
    add_box(main_box, box_for_subtitle2, START, FALSE, FALSE, 0, 30, 0, 0, 0);
    add_box(main_box, paragraph2, START, FALSE, FALSE, 0, 4, 0, 10, 0);

    GtkWidget *scrolled_window = create_scrolled_window();
    add_to_scrolled_window(scrolled_window, main_box);

    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window), GTK_POLICY_NEVER, GTK_POLICY_ALWAYS);

    gtk_container_add(GTK_CONTAINER(window), scrolled_window);

    gtk_widget_show_all(window);
}

static void algerieInfos(GtkWidget *widget, gpointer data)
{
    GtkWidget *window = create_window(NULL, GTK_WINDOW_TOPLEVEL, "Algérie", 700, 460, FALSE, GTK_WIN_POS_CENTER, TRUE, NULL, 1, FALSE);
    GtkWidget *title = create_label("4 - this window is for Algérie", 27, "consolas", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, TRUE, PANGO_WEIGHT_BOLD, PANGO_STYLE_NORMAL, FALSE);
    GtkWidget *subtitle1 = create_label("4 - 1 : Algérie history", 20, "consolas", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, TRUE, PANGO_WEIGHT_BOLD, PANGO_STYLE_NORMAL, TRUE);
    GtkWidget *paragraph1 = create_label("L'Algérie, située en Afrique du Nord, a une histoire riche et variée. Les Berbères, premiers habitants, ont été influencés par les Phéniciens, les Romains et les Arabes. La conquête arabe au VIIe siècle a introduit l'islam et la langue arabe. La colonisation française en 1830 a profondément marqué le pays, menant à une guerre d'indépendance sanglante entre 1954 et 1962. Depuis son indépendance, l'Algérie s'est construite en tant que nation souveraine, avec des défis politiques et économiques, mais aussi une forte identité culturelle.",
    12, "consolas", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, PANGO_WEIGHT_NORMAL, PANGO_STYLE_NORMAL, TRUE);

    GtkWidget *subtitle2 = create_label("4 - 2 : Algérie culture", 20, "consolas", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, TRUE, PANGO_WEIGHT_BOLD, PANGO_STYLE_NORMAL, TRUE);
    GtkWidget *paragraph2 = create_label("La culture algérienne est un mélange d'influences berbères, arabes et méditerranéennes. La musique traditionnelle, comme le chaâbi et le raï, est très populaire. La cuisine algérienne, avec des plats comme le couscous et la chorba, est riche et variée. L'artisanat, notamment les tapis et les poteries, reflète un savoir-faire ancestral. Les fêtes religieuses, comme l'Aïd, et les célébrations culturelles, comme Yennayer (le Nouvel An berbère), sont des moments importants de la vie sociale. La littérature algérienne, avec des auteurs comme Kateb Yacine et Assia Djebar, est reconnue internationalement.",
    12, "consolas", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, PANGO_WEIGHT_NORMAL, PANGO_STYLE_NORMAL, TRUE);

    GtkWidget *main_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 20);

    GtkWidget *box_for_title = create_box(GTK_ORIENTATION_HORIZONTAL, GTK_ALIGN_START, 0);
    add_box(box_for_title, title, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    GtkWidget *box_for_subtitle1 = create_box(GTK_ORIENTATION_HORIZONTAL, GTK_ALIGN_START, 0);
    add_box(box_for_subtitle1, subtitle1, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    GtkWidget *box_for_subtitle2 = create_box(GTK_ORIENTATION_HORIZONTAL, GTK_ALIGN_START, 0);
    add_box(box_for_subtitle2, subtitle2, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    add_box(main_box, box_for_title, START, FALSE, FALSE, 0, 90, 0, 0, 0);
    add_box(main_box, box_for_subtitle1, START, FALSE, FALSE, 0, 30, 0, 0, 0);
    add_box(main_box, paragraph1, START, FALSE, FALSE, 0, 4, 0, 10, 0);
    add_box(main_box, box_for_subtitle2, START, FALSE, FALSE, 0, 30, 0, 0, 0);
    add_box(main_box, paragraph2, START, FALSE, FALSE, 0, 4, 0, 10, 0);

    GtkWidget *scrolled_window = create_scrolled_window();
    add_to_scrolled_window(scrolled_window, main_box);

    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window), GTK_POLICY_NEVER, GTK_POLICY_ALWAYS);

    gtk_container_add(GTK_CONTAINER(window), scrolled_window);

    gtk_widget_show_all(window);
}

static void italieInfos(GtkWidget *widget, gpointer data)
{
    GtkWidget *window = create_window(NULL, GTK_WINDOW_TOPLEVEL, "Italie", 700, 460, FALSE, GTK_WIN_POS_CENTER, TRUE, NULL, 1, FALSE);
    GtkWidget *title = create_label("5 - this window is for Italie", 27, "consolas", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, TRUE, PANGO_WEIGHT_BOLD, PANGO_STYLE_NORMAL, FALSE);
    GtkWidget *subtitle1 = create_label("5 - 1 : Italie history", 20, "consolas", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, TRUE, PANGO_WEIGHT_BOLD, PANGO_STYLE_NORMAL, TRUE);
    GtkWidget *paragraph1 = create_label("L'Italie, berceau de la civilisation romaine, a une histoire riche et influente. La Rome antique a dominé une grande partie de l'Europe, de l'Afrique du Nord et du Moyen-Orient. Après la chute de l'Empire romain, l'Italie est devenue une mosaïque de cités-États et de royaumes. La Renaissance, née en Italie au XIVe siècle, a marqué un âge d'or pour l'art, la science et la culture. L'unification de l'Italie en 1861 a créé un État-nation moderne. Au XXe siècle, l'Italie a traversé des périodes de fascisme et de guerre, avant de devenir une république démocratique et un membre fondateur de l'Union européenne.",
    12, "consolas", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, PANGO_WEIGHT_NORMAL, PANGO_STYLE_NORMAL, TRUE);

    GtkWidget *subtitle2 = create_label("5 - 2 : Italie culture", 20, "consolas", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, TRUE, PANGO_WEIGHT_BOLD, PANGO_STYLE_NORMAL, TRUE);
    GtkWidget *paragraph2 = create_label("La culture italienne est l'une des plus riches et des plus influentes au monde. L'art italien, de la Renaissance à l'époque moderne, a produit des génies comme Léonard de Vinci, Michel-Ange et Botticelli. La musique italienne, avec l'opéra et des compositeurs comme Verdi et Puccini, est célèbre dans le monde entier. La cuisine italienne, avec ses pâtes, pizzas et glaces, est appréciée internationalement. Les traditions, comme le Carnaval de Venise et la Fête de la République, reflètent l'identité italienne. L'Italie est également connue pour son architecture, ses villes historiques et son mode de vie.",
    12, "consolas", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, PANGO_WEIGHT_NORMAL, PANGO_STYLE_NORMAL, TRUE);

    GtkWidget *main_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 20);

    GtkWidget *box_for_title = create_box(GTK_ORIENTATION_HORIZONTAL, GTK_ALIGN_START, 0);
    add_box(box_for_title, title, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    GtkWidget *box_for_subtitle1 = create_box(GTK_ORIENTATION_HORIZONTAL, GTK_ALIGN_START, 0);
    add_box(box_for_subtitle1, subtitle1, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    GtkWidget *box_for_subtitle2 = create_box(GTK_ORIENTATION_HORIZONTAL, GTK_ALIGN_START, 0);
    add_box(box_for_subtitle2, subtitle2, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    add_box(main_box, box_for_title, START, FALSE, FALSE, 0, 90, 0, 0, 0);
    add_box(main_box, box_for_subtitle1, START, FALSE, FALSE, 0, 30, 0, 0, 0);
    add_box(main_box, paragraph1, START, FALSE, FALSE, 0, 4, 0, 10, 0);
    add_box(main_box, box_for_subtitle2, START, FALSE, FALSE, 0, 30, 0, 0, 0);
    add_box(main_box, paragraph2, START, FALSE, FALSE, 0, 4, 0, 10, 0);

    GtkWidget *scrolled_window = create_scrolled_window();
    add_to_scrolled_window(scrolled_window, main_box);

    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window), GTK_POLICY_NEVER, GTK_POLICY_ALWAYS);

    gtk_container_add(GTK_CONTAINER(window), scrolled_window);

    gtk_widget_show_all(window);
}

static void saudiArabieInfos(GtkWidget *widget, gpointer data)
{
    GtkWidget *window = create_window(NULL, GTK_WINDOW_TOPLEVEL, "Arabie Saoudite", 700, 460, FALSE, GTK_WIN_POS_CENTER, TRUE, NULL, 1, FALSE);
    GtkWidget *title = create_label("6 - this window is for Arabie Saoudite", 27, "consolas", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, TRUE, PANGO_WEIGHT_BOLD, PANGO_STYLE_NORMAL, FALSE);
    GtkWidget *subtitle1 = create_label("6 - 1 : Arabie Saoudite history", 20, "consolas", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, TRUE, PANGO_WEIGHT_BOLD, PANGO_STYLE_NORMAL, TRUE);
    GtkWidget *paragraph1 = create_label("L'Arabie Saoudite, située dans la péninsule arabique, est le berceau de l'islam. Les tribus arabes ont dominé la région pendant des siècles, avec La Mecque et Médine comme centres religieux. En 1932, le royaume d'Arabie Saoudite a été fondé par Abdulaziz Al Saoud. La découverte de pétrole dans les années 1930 a transformé le pays en une puissance économique mondiale. Aujourd'hui, l'Arabie Saoudite est un acteur clé dans le monde arabe et musulman, tout en cherchant à moderniser son économie et sa société grâce à des initiatives comme Vision 2030.",
    12, "consolas", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, PANGO_WEIGHT_NORMAL, PANGO_STYLE_NORMAL, TRUE);

    GtkWidget *subtitle2 = create_label("6 - 2 : Arabie Saoudite culture", 20, "consolas", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, TRUE, PANGO_WEIGHT_BOLD, PANGO_STYLE_NORMAL, TRUE);
    GtkWidget *paragraph2 = create_label("La culture saoudienne est profondément enracinée dans les traditions islamiques et arabes. La langue arabe et l'islam jouent un rôle central dans la vie quotidienne. Les vêtements traditionnels, comme la thobe pour les hommes et l'abaya pour les femmes, reflètent l'identité culturelle. La cuisine saoudienne, avec des plats comme le kabsa et le mandi, est riche en saveurs. Les arts traditionnels, comme la calligraphie arabe et la danse du sabre, sont très appréciés. Les festivals religieux, comme le Hajj et l'Aïd, sont des moments importants de la vie sociale.",
    12, "consolas", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, PANGO_WEIGHT_NORMAL, PANGO_STYLE_NORMAL, TRUE);

    GtkWidget *main_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 20);

    GtkWidget *box_for_title = create_box(GTK_ORIENTATION_HORIZONTAL, GTK_ALIGN_START, 0);
    add_box(box_for_title, title, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    GtkWidget *box_for_subtitle1 = create_box(GTK_ORIENTATION_HORIZONTAL, GTK_ALIGN_START, 0);
    add_box(box_for_subtitle1, subtitle1, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    GtkWidget *box_for_subtitle2 = create_box(GTK_ORIENTATION_HORIZONTAL, GTK_ALIGN_START, 0);
    add_box(box_for_subtitle2, subtitle2, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    add_box(main_box, box_for_title, START, FALSE, FALSE, 0, 90, 0, 0, 0);
    add_box(main_box, box_for_subtitle1, START, FALSE, FALSE, 0, 30, 0, 0, 0);
    add_box(main_box, paragraph1, START, FALSE, FALSE, 0, 4, 0, 10, 0);
    add_box(main_box, box_for_subtitle2, START, FALSE, FALSE, 0, 30, 0, 0, 0);
    add_box(main_box, paragraph2, START, FALSE, FALSE, 0, 4, 0, 10, 0);

    GtkWidget *scrolled_window = create_scrolled_window();
    add_to_scrolled_window(scrolled_window, main_box);

    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window), GTK_POLICY_NEVER, GTK_POLICY_ALWAYS);

    gtk_container_add(GTK_CONTAINER(window), scrolled_window);

    gtk_widget_show_all(window);
}

static void start(GtkWidget *spinner, gpointer data)
{
    start_spinner(GTK_WIDGET(data));
}

static void stop(GtkWidget *spinner, gpointer data)
{
    stop_spinner(GTK_WIDGET(data));
}

static void activate(GtkApplication *app, gpointer data)
{
    // GtkWidget *window;
    // GtkWidget *dialog;
    // GtkWidget *label;
    // GtkWidget *image;
    // GtkWidget *spinner;
    // GtkWidget *textView;
    // GtkWidget *levelBar;
    // GtkWidget *progressBar;
    // GtkWidget *scale;
    // GtkWidget *separator;
    // GtkWidget *button;
    // GtkWidget *checkButton;
    // GtkWidget *linkButton;
    // GtkWidget *menuItem;

    GtkWidget *window;
    GtkWidget *header_bar;
    GtkWidget *dialog;
    GtkWidget *item1 = create_menu_item("item1", "normal", NULL, NULL, NULL);
    GtkWidget *item2 = create_menu_item("item1", "normal", NULL, NULL, NULL);

    LinkedList *maliste = create_linked_list();
    insert_at_beginning(maliste, item1);
    insert_at_beginning(maliste, item2);

    GtkWidget *liste = create_menu(TRUE,"list", maliste);
    GtkWidget *listeB = create_menu_button("menu", NULL, liste, GTK_ARROW_DOWN);

    GtkWidget *buttonA = create_button(GTK_RELIEF_NORMAL, NULL, FALSE, "assets/home.png", G_CALLBACK(marocInfos), NULL);
    GtkWidget *buttonB = create_button(GTK_RELIEF_NORMAL, "clickme", FALSE, NULL, NULL, NULL);

    LinkedList *list = create_linked_list();

    insert_at_end(list, listeB);
    insert_at_end(list, buttonB);

    window = create_window(app, GTK_WINDOW_TOPLEVEL, "Contry", 900, 660, TRUE, GTK_WIN_POS_CENTER, TRUE, NULL, 1, FALSE);
    header_bar = create_header_bar(window, "Contry", "This is a subtitle", "assets/smallHome.png", TRUE, NULL, list);
    
    headerBarInfos *headerBarInformations = get_properties_header_bar(header_bar);
    printf("Title: %s\nSubtitle: %s\nIcon path : %s\nSettings: %d\n", headerBarInformations->title, headerBarInformations->subtitle, headerBarInformations->icon_path, headerBarInformations->settings);

    if(headerBarInformations->window == window)
        g_print("Oui\n");
    else
        g_print("Non\n");

    if(headerBarInformations->start_widgets_liste == NULL)
        g_print("Oui\n");
    else
        g_print("Non\n");
    
    if(headerBarInformations->end_widgets_liste == list)
        g_print("Oui\n");
    else
        g_print("Non\n");
    

    // Morocco
    GtkWidget *maroc_image = create_image("assets/w160/ma.png");
    GtkWidget *maroc_label = create_label("       Maroc       ", 18, "Arial Rounded MT Bold", "#000000", "#eda49f", GTK_JUSTIFY_CENTER, TRUE, PANGO_WEIGHT_BOLD, PANGO_STYLE_NORMAL, TRUE);
    GtkWidget *button = create_button(GTK_RELIEF_NORMAL, "click maroc", FALSE, NULL, G_CALLBACK(marocInfos), NULL);

    GtkWidget *box_maroc = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_CENTER, 5);
    add_box(box_maroc, maroc_image, START, FALSE, FALSE, 2, 0, 0, 0, 0);
    add_box(box_maroc, maroc_label, START, FALSE, FALSE, 2, 0, 0, 0, 0);
    add_box(box_maroc, button, START, FALSE, FALSE, 2, 0, 0, 0, 0);

    // France
    GtkWidget *french_image = create_image("assets/w160/fr.png");
    GtkWidget *french_label = create_label("      French      ", 18, "Arial Rounded MT Bold", "#000000", "#eda49f", GTK_JUSTIFY_CENTER, TRUE, PANGO_WEIGHT_BOLD, PANGO_STYLE_NORMAL, TRUE);
    GtkWidget *button2 = create_button(GTK_RELIEF_NORMAL, "click french", FALSE, NULL, G_CALLBACK(franceInfos), NULL);

    GtkWidget *box_france = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_CENTER, 5);
    add_box(box_france, french_image, START, FALSE, FALSE, 2, 0, 0, 0, 0);
    add_box(box_france, french_label, START, FALSE, FALSE, 2, 0, 0, 0, 0);
    add_box(box_france, button2, START, FALSE, FALSE, 2, 0, 0, 0, 0);


    // argentina
    GtkWidget *argentina_image = create_image("assets/w160/ar.png");
    GtkWidget *argentina_label = create_label("    Argentina    ", 18, "Arial Rounded MT Bold", "#000000", "#eda49f", GTK_JUSTIFY_CENTER, TRUE, PANGO_WEIGHT_BOLD, PANGO_STYLE_NORMAL, TRUE);
    GtkWidget *button3 = create_button(GTK_RELIEF_NORMAL, "click argentina", FALSE, NULL, G_CALLBACK(argentinaInfos), NULL);

    GtkWidget *box_argentina = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_CENTER, 5);
    add_box(box_argentina, argentina_image, START, FALSE, FALSE, 2, 0, 0, 0, 0);
    add_box(box_argentina, argentina_label, START, FALSE, FALSE, 2, 0, 0, 0, 0);
    add_box(box_argentina, button3, START, FALSE, FALSE, 2, 0, 0, 0, 0);

    // algeria
    // GtkWidget *algeria_image = create_image("assets/w160/dz.png");
    // GtkWidget *algeria_label = create_label("      Algeria      ", 18, "Arial Rounded MT Bold", "#000000", "#eda49f", GTK_JUSTIFY_CENTER, TRUE, PANGO_WEIGHT_BOLD, PANGO_STYLE_NORMAL, TRUE);
    // GtkWidget *button4 = create_button(GTK_RELIEF_NORMAL, "click algeria", FALSE, NULL, G_CALLBACK(algerieInfos), NULL);
    GtkWidget *spinner = create_spinner(FALSE);
    GtkWidget *startButtom = create_button(GTK_RELIEF_NORMAL, "Start", FALSE, NULL, G_CALLBACK(start), spinner);
    GtkWidget *stopButtom = create_button(GTK_RELIEF_NORMAL, "Stop", FALSE, NULL, G_CALLBACK(stop), spinner);


    GtkWidget *box_algeria = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_CENTER, 5);
    // add_box(box_algeria, algeria_image, START, FALSE, FALSE, 2, 0, 0, 0, 0);
    // add_box(box_algeria, algeria_label, START, FALSE, FALSE, 2, 0, 0, 0, 0);
    // add_box(box_algeria, button4, START, FALSE, FALSE, 2, 0, 0, 0, 0);

    GtkWidget *boxSpinner = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_CENTER, 0);
    GtkWidget *boxButton = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_CENTER, 6);

    

    add_box(boxSpinner, spinner, START, FALSE, FALSE, 2, 0, 0, 0, 0);
    add_box(boxButton, startButtom, START, FALSE, FALSE, 2, 0, 0, 0, 0);
    add_box(boxButton, stopButtom, START, FALSE, FALSE, 2, 0, 0, 0, 0);

    add_box(box_algeria, boxSpinner, START, FALSE, FALSE, 2, 0, 0, 0, 0);
    add_box(box_algeria, boxButton, START, FALSE, FALSE, 2, 0, 0, 0, 0);

    // italy
    GtkWidget *italy_image = create_image("assets/w160/it.png");
    GtkWidget *italy_label = create_label("        Italy         ", 18, "Arial Rounded MT Bold", "#000000", "#eda49f", GTK_JUSTIFY_CENTER, TRUE, PANGO_WEIGHT_BOLD, PANGO_STYLE_NORMAL, TRUE);
    GtkWidget *button5 = create_button(GTK_RELIEF_NORMAL, "click italy", FALSE, NULL, G_CALLBACK(italieInfos), NULL);

    GtkWidget *box_italy = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_CENTER, 5);
    add_box(box_italy, italy_image, START, FALSE, FALSE, 2, 0, 0, 0, 0);
    add_box(box_italy, italy_label, START, FALSE, FALSE, 2, 0, 0, 0, 0);
    add_box(box_italy, button5, START, FALSE, FALSE, 2, 0, 0, 0, 0);

    // saudi arabia
    // GtkWidget *saudi_image = create_image("assets/w160/sa.png");
    // GtkWidget *saudi_label = create_label("    Saudi Arabia    ", 18, "Arial Rounded MT Bold", "#000000", "#eda49f", GTK_JUSTIFY_CENTER, TRUE, PANGO_WEIGHT_BOLD, PANGO_STYLE_NORMAL, TRUE);
    // GtkWidget *button6 = create_button(GTK_RELIEF_NORMAL, "click saudi arabia", FALSE, NULL, G_CALLBACK(saudiArabieInfos), NULL);
    GtkWidget *propress = create_progress_bar("progress bar : ", 0.5, TRUE, FALSE, FALSE);

    GtkWidget *box_saudi = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_CENTER, 5);
    // add_box(box_saudi, saudi_image, START, FALSE, FALSE, 2, 0, 0, 0, 0);
    // add_box(box_saudi, saudi_label, START, FALSE, FALSE, 2, 0, 0, 0, 0);
    // add_box(box_saudi, button6, START, FALSE, FALSE, 2, 0, 0, 0, 0);
    add_box(box_saudi, propress, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    // the line 1 container of morocco, france and argentina
    GtkWidget *boxLine1 = create_box(GTK_ORIENTATION_HORIZONTAL, -1, 10);

    add_box(boxLine1, box_maroc, START, TRUE, FALSE, 0, 0, 0, 0, 0);
    add_box(boxLine1, box_france, START, TRUE, FALSE, 0, 0, 0, 0, 0);
    add_box(boxLine1, box_argentina, START, TRUE, FALSE, 0, 0, 0, 0, 0);

    // the line 2 container of algeria, italy and saudi arabia
    GtkWidget *boxLine2 = create_box(GTK_ORIENTATION_HORIZONTAL, -1, 10);

    add_box(boxLine2, box_algeria, START, TRUE, FALSE, 0, 0, 0, 0, 0);
    add_box(boxLine2, box_italy, START, TRUE, FALSE, 0, 0, 0, 0, 0);
    add_box(boxLine2, box_saudi, START, TRUE, FALSE, 0, 0, 0, 0, 0);

    // the main container
    GtkWidget *box_main = create_box(GTK_ORIENTATION_VERTICAL, -1, 10);

    add_box(box_main, boxLine1, START, TRUE, FALSE, 0, 0, 0, 0, 0);
    add_box(box_main, boxLine2, START, TRUE, FALSE, 0, 0, 0, 0, 0);

    GtkWidget *boxDialog = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_START, 0);
    GtkWidget *label = gtk_label_new("hello is me");
    add_box(boxDialog, label, START, TRUE, FALSE, 10, 0, 0, 0, 0);

    dialog = create_dialog("Confirmer votre choix hhh , juste pour rir, bien sûr que vous voulez entre", window, GTK_DIALOG_MODAL, 800, 70, 1, boxDialog, "Entrer", GTK_RESPONSE_OK, "Quitter", GTK_RESPONSE_CANCEL, "NULL", GTK_RESPONSE_CANCEL);
    
    dialogInfos *dialogInformations = get_properties_dialog(dialog);
    printf("titre : %s\nflags : %d\nwidth : %d\nheight : %d\nopacity : %f\ntitre1 : %s\ntitre2 : %s\ntitre3 : %s\nreponse1 : %d\nreponse2 : %d\nreponse3 : %d\n", dialogInformations->title, dialogInformations->flags, dialogInformations->width, dialogInformations->height, dialogInformations->opacily, dialogInformations->title1, dialogInformations->title2, dialogInformations->title3, dialogInformations->answer1, dialogInformations->answer2, dialogInformations->answer3);
    if(dialogInformations->parent == window)
        g_print("Oui\n");
    else
        g_print("Non");
    
    if(dialogInformations->box_content_area == boxDialog)
        g_print("Oui\n");
    else
        g_print("Non\n");
    
    gtk_container_add(GTK_CONTAINER(window), box_main);

    int reponse = gtk_dialog_run(GTK_DIALOG(dialog));
    if(reponse == GTK_RESPONSE_CANCEL)
    {
        g_application_quit(G_APPLICATION(app));
    }

    gtk_widget_destroy(dialog);
        
    gtk_widget_show_all(window);
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

