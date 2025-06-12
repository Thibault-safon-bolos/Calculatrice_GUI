#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

GtkWidget *window;
GtkCssProvider *provider;
GdkScreen *screen;


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
        gtk_window_set_resizable(GTK_WINDOW(window), TRUE);

        gtk_window_set_icon_from_file(GTK_WINDOW(window), "logo.png", NULL);

        //Fermeture de la fentre propre
        g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

        //Création de l'application du css
        provider = gtk_css_provider_new();

        //Chemin du Css qui vient d'un fichier
        gtk_css_provider_load_from_path(provider,"style.css", NULL);

        //Set de l'écran
        screen = gdk_screen_get_default();

        //Application du CSS
        gtk_style_context_add_provider_for_screen(screen, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);



        //Montre les elements
        gtk_widget_show_all(window);
        
        //Maintien la fenetre ouverte
        gtk_main();    
        return 0;
    }