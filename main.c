#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

GtkWidget *window;
GtkCssProvider *provider;
GdkScreen *screen;

GtkWidget *boxmain;
GtkWidget *Champs;

GtkWidget *boxselect;

GtkWidget *boxcol1;
GtkWidget *buttonC;
GtkWidget *button7;
GtkWidget *button4;
GtkWidget *button1;

GtkWidget *boxcol2;
GtkWidget *buttondiv;
GtkWidget *button8;
GtkWidget *button5;
GtkWidget *button2;

GtkWidget *boxcol3;
GtkWidget *buttonmultiple;
GtkWidget *button9;
GtkWidget *button6;
GtkWidget *button3;

GtkWidget *boxcol4;
GtkWidget *buttonmoins;
GtkWidget *buttonplus;
GtkWidget *buttonresult;

int main(int argc, char *argv[]){
    //initialisation GTK
    gtk_init(&argc, &argv);

    //Creation d'une nouvelle fenetre
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    //Set d'un ID pour CSS
    gtk_widget_set_name(window, "main_window");

    //Titre de la fenetre
    gtk_window_set_title(GTK_WINDOW(window), "Shifumi");

    //Set taille
    gtk_window_set_default_size(GTK_WINDOW(window), 500, 300);
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);

    gtk_window_set_icon_from_file(GTK_WINDOW(window), "logo.png", NULL);

    //Fermeture de la fentre propre
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    //Création de l'application du css
    provider = gtk_css_provider_new();

    //Chemin du Css qui vient d'un fichier
    gtk_css_provider_load_from_path(provider,"styles.css", NULL);

    //Set de l'écran
    screen = gdk_screen_get_default();

    //Application du CSS
    gtk_style_context_add_provider_for_screen(screen, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    //Couche 1
    boxmain = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(window), boxmain);
    Champs = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(boxmain), Champs, FALSE, FALSE, 10);

    boxselect = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_box_pack_start(GTK_BOX(boxmain), boxselect, FALSE, FALSE, 2);

    boxcol1 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_box_pack_start(GTK_BOX(boxselect), boxcol1, FALSE, FALSE, 2);
    buttonC = gtk_button_new_with_label("C");
    button7 = gtk_button_new_with_label("7");
    button4 = gtk_button_new_with_label("4");
    button1 = gtk_button_new_with_label("1");
    gtk_box_pack_start(GTK_BOX(boxcol1), buttonC, FALSE, FALSE, 2);
    gtk_box_pack_start(GTK_BOX(boxcol1), button7, FALSE, FALSE, 2);
    gtk_box_pack_start(GTK_BOX(boxcol1), button4, FALSE, FALSE, 2);
    gtk_box_pack_start(GTK_BOX(boxcol1), button1, FALSE, FALSE, 2);

    boxcol2 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_box_pack_start(GTK_BOX(boxselect), boxcol2, FALSE, FALSE, 2);
    buttondiv = gtk_button_new_with_label("/");
    button8 = gtk_button_new_with_label("8");
    button5 = gtk_button_new_with_label("5");
    button2 = gtk_button_new_with_label("2");
    gtk_box_pack_start(GTK_BOX(boxcol2), buttondiv, FALSE, FALSE, 2);
    gtk_box_pack_start(GTK_BOX(boxcol2), button8, FALSE, FALSE, 2);
    gtk_box_pack_start(GTK_BOX(boxcol2), button5, FALSE, FALSE, 2);
    gtk_box_pack_start(GTK_BOX(boxcol2), button2, FALSE, FALSE, 2);

    boxcol3 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_box_pack_start(GTK_BOX(boxselect), boxcol3, FALSE, FALSE, 2);
    buttonmultiple = gtk_button_new_with_label("/");
    button9 = gtk_button_new_with_label("8");
    button6 = gtk_button_new_with_label("5");
    button3 = gtk_button_new_with_label("2");
    gtk_box_pack_start(GTK_BOX(boxcol3), buttonmultiple, FALSE, FALSE, 2);
    gtk_box_pack_start(GTK_BOX(boxcol3), button9, FALSE, FALSE, 2);
    gtk_box_pack_start(GTK_BOX(boxcol3), button6, FALSE, FALSE, 2);
    gtk_box_pack_start(GTK_BOX(boxcol3), button3, FALSE, FALSE, 2);

    boxcol4 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_box_pack_start(GTK_BOX(boxselect), boxcol4, FALSE, FALSE, 2);
    buttonmoins = gtk_button_new_with_label("-");
    buttonplus = gtk_button_new_with_label("+");
    buttonresult = gtk_button_new_with_label("=");
    gtk_box_pack_start(GTK_BOX(boxcol4), buttonmoins, TRUE, TRUE, 2);
    gtk_box_pack_start(GTK_BOX(boxcol4), buttonplus, TRUE, TRUE, 2);
    gtk_box_pack_start(GTK_BOX(boxcol4), buttonresult, TRUE, TRUE, 2);

    //Montre les elements
    gtk_widget_show_all(window);

    //Maintien la fenetre ouverte
    gtk_main();    
    return 0;
    }