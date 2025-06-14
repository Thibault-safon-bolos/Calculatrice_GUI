
#include <gtk/gtk.h>
#include "widget.h"

//édition entry 
void addValue(GtkWidget *widget, gpointer data){
    gint pos = -1;
    const gchar *text = gtk_button_get_label(GTK_BUTTON(widget));
    gtk_editable_insert_text(GTK_EDITABLE(Champs), text, -1, &pos);
}


//Reset
void reset(GtkWidget *widget, gpointer data){
    gtk_entry_set_text(GTK_ENTRY(Champs), "");
}
