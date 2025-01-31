/*****************************************************************************************************************************
 * 
 * @file Countries.c
 * @brief the source file of the Countries
 * 
 * this file contains all implementations for the Courntries functions
 * 
 * @test testContry N°: 1.1.0
 * 
 * @author Ayyoub el Kouri
 * @date 28/01/2025
 * @version 1.0 (last update 28/01/2025)
 * 
 ******************************************************************************************************************************/

#include "Countries.h"

void marocInfos(GtkWidget *widget, gpointer data)
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
    add_to_box(box_for_title, title, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    GtkWidget *box_for_subtitle1 = create_box(GTK_ORIENTATION_HORIZONTAL, GTK_ALIGN_START, 0);
    add_to_box(box_for_subtitle1, subtitle1, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    GtkWidget *box_for_subtitle2 = create_box(GTK_ORIENTATION_HORIZONTAL, GTK_ALIGN_START, 0);
    add_to_box(box_for_subtitle2, subtitle2, START, FALSE, FALSE, 0, 0, 0, 0, 0);
    


    add_to_box(main_box, box_for_title, START, FALSE, FALSE, 0, 90, 0, 0, 0);
    add_to_box(main_box, box_for_subtitle1, START, FALSE, FALSE, 0, 30, 0, 0, 0);
    add_to_box(main_box, paragraph1, START, FALSE, FALSE, 0, 4, 0, 10, 0);
    add_to_box(main_box, box_for_subtitle2, START, FALSE, FALSE, 0, 30, 0, 0, 0);
    add_to_box(main_box, paragraph2, START, FALSE, FALSE, 0, 4, 0, 10, 0);

    GtkWidget *scrolled_window = create_scrolled_window(TRUE, TRUE);
    add_to_scrolled_window(scrolled_window, main_box);

    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window), GTK_POLICY_NEVER, GTK_POLICY_ALWAYS);

    gtk_container_add(GTK_CONTAINER(window), scrolled_window);

    gtk_widget_show_all(window);
}


void franceInfos(GtkWidget *widget, gpointer data)
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
    add_to_box(box_for_title, title, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    GtkWidget *box_for_subtitle1 = create_box(GTK_ORIENTATION_HORIZONTAL, GTK_ALIGN_START, 0);
    add_to_box(box_for_subtitle1, subtitle1, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    GtkWidget *box_for_subtitle2 = create_box(GTK_ORIENTATION_HORIZONTAL, GTK_ALIGN_START, 0);
    add_to_box(box_for_subtitle2, subtitle2, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    add_to_box(main_box, box_for_title, START, FALSE, FALSE, 0, 90, 0, 0, 0);
    add_to_box(main_box, box_for_subtitle1, START, FALSE, FALSE, 0, 30, 0, 0, 0);
    add_to_box(main_box, paragraph1, START, FALSE, FALSE, 0, 4, 0, 10, 0);
    add_to_box(main_box, box_for_subtitle2, START, FALSE, FALSE, 0, 30, 0, 0, 0);
    add_to_box(main_box, paragraph2, START, FALSE, FALSE, 0, 4, 0, 10, 0);

    GtkWidget *scrolled_window = create_scrolled_window(TRUE, TRUE);
    add_to_scrolled_window(scrolled_window, main_box);

    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window), GTK_POLICY_NEVER, GTK_POLICY_ALWAYS);

    gtk_container_add(GTK_CONTAINER(window), scrolled_window);

    gtk_widget_show_all(window);
}

void argentinaInfos(GtkWidget *widget, gpointer data)
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
    add_to_box(box_for_title, title, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    GtkWidget *box_for_subtitle1 = create_box(GTK_ORIENTATION_HORIZONTAL, GTK_ALIGN_START, 0);
    add_to_box(box_for_subtitle1, subtitle1, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    GtkWidget *box_for_subtitle2 = create_box(GTK_ORIENTATION_HORIZONTAL, GTK_ALIGN_START, 0);
    add_to_box(box_for_subtitle2, subtitle2, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    add_to_box(main_box, box_for_title, START, FALSE, FALSE, 0, 90, 0, 0, 0);
    add_to_box(main_box, box_for_subtitle1, START, FALSE, FALSE, 0, 30, 0, 0, 0);
    add_to_box(main_box, paragraph1, START, FALSE, FALSE, 0, 4, 0, 10, 0);
    add_to_box(main_box, box_for_subtitle2, START, FALSE, FALSE, 0, 30, 0, 0, 0);
    add_to_box(main_box, paragraph2, START, FALSE, FALSE, 0, 4, 0, 10, 0);

    GtkWidget *scrolled_window = create_scrolled_window(TRUE, TRUE);
    add_to_scrolled_window(scrolled_window, main_box);

    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window), GTK_POLICY_NEVER, GTK_POLICY_ALWAYS);

    gtk_container_add(GTK_CONTAINER(window), scrolled_window);

    gtk_widget_show_all(window);
}

void algerieInfos(GtkWidget *widget, gpointer data)
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
    add_to_box(box_for_title, title, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    GtkWidget *box_for_subtitle1 = create_box(GTK_ORIENTATION_HORIZONTAL, GTK_ALIGN_START, 0);
    add_to_box(box_for_subtitle1, subtitle1, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    GtkWidget *box_for_subtitle2 = create_box(GTK_ORIENTATION_HORIZONTAL, GTK_ALIGN_START, 0);
    add_to_box(box_for_subtitle2, subtitle2, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    add_to_box(main_box, box_for_title, START, FALSE, FALSE, 0, 90, 0, 0, 0);
    add_to_box(main_box, box_for_subtitle1, START, FALSE, FALSE, 0, 30, 0, 0, 0);
    add_to_box(main_box, paragraph1, START, FALSE, FALSE, 0, 4, 0, 10, 0);
    add_to_box(main_box, box_for_subtitle2, START, FALSE, FALSE, 0, 30, 0, 0, 0);
    add_to_box(main_box, paragraph2, START, FALSE, FALSE, 0, 4, 0, 10, 0);

    GtkWidget *scrolled_window = create_scrolled_window(TRUE, TRUE);
    add_to_scrolled_window(scrolled_window, main_box);

    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window), GTK_POLICY_NEVER, GTK_POLICY_ALWAYS);

    gtk_container_add(GTK_CONTAINER(window), scrolled_window);

    gtk_widget_show_all(window);
}

void italieInfos(GtkWidget *widget, gpointer data)
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
    add_to_box(box_for_title, title, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    GtkWidget *box_for_subtitle1 = create_box(GTK_ORIENTATION_HORIZONTAL, GTK_ALIGN_START, 0);
    add_to_box(box_for_subtitle1, subtitle1, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    GtkWidget *box_for_subtitle2 = create_box(GTK_ORIENTATION_HORIZONTAL, GTK_ALIGN_START, 0);
    add_to_box(box_for_subtitle2, subtitle2, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    add_to_box(main_box, box_for_title, START, FALSE, FALSE, 0, 90, 0, 0, 0);
    add_to_box(main_box, box_for_subtitle1, START, FALSE, FALSE, 0, 30, 0, 0, 0);
    add_to_box(main_box, paragraph1, START, FALSE, FALSE, 0, 4, 0, 10, 0);
    add_to_box(main_box, box_for_subtitle2, START, FALSE, FALSE, 0, 30, 0, 0, 0);
    add_to_box(main_box, paragraph2, START, FALSE, FALSE, 0, 4, 0, 10, 0);

    GtkWidget *scrolled_window = create_scrolled_window(TRUE, TRUE);
    add_to_scrolled_window(scrolled_window, main_box);

    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window), GTK_POLICY_NEVER, GTK_POLICY_ALWAYS);

    gtk_container_add(GTK_CONTAINER(window), scrolled_window);

    gtk_widget_show_all(window);
}

void saudiArabieInfos(GtkWidget *widget, gpointer data)
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
    add_to_box(box_for_title, title, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    GtkWidget *box_for_subtitle1 = create_box(GTK_ORIENTATION_HORIZONTAL, GTK_ALIGN_START, 0);
    add_to_box(box_for_subtitle1, subtitle1, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    GtkWidget *box_for_subtitle2 = create_box(GTK_ORIENTATION_HORIZONTAL, GTK_ALIGN_START, 0);
    add_to_box(box_for_subtitle2, subtitle2, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    add_to_box(main_box, box_for_title, START, FALSE, FALSE, 0, 90, 0, 0, 0);
    add_to_box(main_box, box_for_subtitle1, START, FALSE, FALSE, 0, 30, 0, 0, 0);
    add_to_box(main_box, paragraph1, START, FALSE, FALSE, 0, 4, 0, 10, 0);
    add_to_box(main_box, box_for_subtitle2, START, FALSE, FALSE, 0, 30, 0, 0, 0);
    add_to_box(main_box, paragraph2, START, FALSE, FALSE, 0, 4, 0, 10, 0);

    GtkWidget *scrolled_window = create_scrolled_window(TRUE, TRUE);
    add_to_scrolled_window(scrolled_window, main_box);

    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window), GTK_POLICY_NEVER, GTK_POLICY_ALWAYS);

    gtk_container_add(GTK_CONTAINER(window), scrolled_window);

    gtk_widget_show_all(window);
}