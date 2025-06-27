
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

void traitement(GtkWidget *widget, gpointer data){

    const char *input = gtk_entry_get_text(GTK_ENTRY(Champs));

    //Vérification si le champs est null
    if (input == NULL || strlen(input) == 0) {
        gtk_entry_set_text(GTK_ENTRY(Champs),"Merci de mettre une opération de calcul");
        return;
    }


    // détection d'un opérateur
    int op_pos = -1;
    char operateur = '\0';
    for (int i = 0; input[i] != '\0'; ++i) {
        if (input[i] == '+' || input[i] == '-' ||input[i] == '*' || input[i] == '/') {
            op_pos = i;
            operateur = input[i];
            break;
        }
    }

    if (op_pos < 0) {
        gtk_entry_set_text(GTK_ENTRY(Champs),"Opérateur manquant (+, -, *, /)");
        return;
    }

    //Récupération des  nombres
    char buf1[64], buf2[64];

    strncpy(buf1, input, op_pos);
    buf1[op_pos] = '\0';

    strcpy(buf2, input + op_pos + 1);

    //Vérification si le buffer sont null
    if (strlen(buf1) == 0 || strlen(buf2) == 0) {
        gtk_entry_set_text(GTK_ENTRY(Champs), "Veuillez saisir deux nombres autour de l’opérateur");
        return;
    }

    //Convertie les chaine de caractère en nombre
    char *endptr;
    double nombre1 = strtod(buf1, &endptr);
    if (*endptr != '\0') {
        gtk_entry_set_text(GTK_ENTRY(Champs),"Format invalide pour le premier nombre");
        return;
    }
    double nombre2 = strtod(buf2, &endptr);
    if (*endptr != '\0') {
        gtk_entry_set_text(GTK_ENTRY(Champs),"Format invalide pour le second nombre");
        return;
    }

    //Division par 0
    if (operateur == '/' && nombre2 == 0.0) {
        gtk_entry_set_text(GTK_ENTRY(Champs), "Erreur : division par zéro");
        return;
    }

    //Calcule
    double resultat = 0.0;
    switch (operateur) {
        case '+':
            resultat = nombre1 + nombre2;
            break;
        case '-':
            resultat = nombre1 - nombre2;
            break;
        case '*':
            resultat = nombre1 * nombre2;
            break;
        case '/':
            resultat = nombre1 / nombre2;
            break;
        default:
            // ne devrait pas arriver
            gtk_entry_set_text(GTK_ENTRY(Champs),"Opérateur non pris en charge");
            return;
    }

    //convertie le resultat et l'affiche
    char result_str[128];
    snprintf(result_str, sizeof(result_str), "%g", resultat);
    gtk_entry_set_text(GTK_ENTRY(Champs), result_str);

}