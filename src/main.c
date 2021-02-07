#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "functions.h"

int iter = 0;
int first_num = 0;
int second_num = 0;
int result = 0;
char *expr = "+";

GtkWidget *window;
GtkWidget *expression;
GtkWidget *column0, *column1, *column2, *column3, *column4;
GtkWidget *all_box, *oth_box;
GtkWidget *entry;
GtkWidget *button1, *button2, *button3, *button4, *button5, *button6;
GtkWidget *button7, *button8, *button9, *button0, *button_p, *button_m;
GtkWidget *button_mult, *button_share, *button_cl, *button_ex;

int main(int argc, char **argv) 
{
    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    expression = gtk_label_new("");
    entry = gtk_entry_new();
    column0 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 1);
    column1 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 1);
    column2 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 1);
    column3 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 1);
    column4 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 1);

    button1 = gtk_button_new_with_label("1");
    button2 = gtk_button_new_with_label("2");
    button3 = gtk_button_new_with_label("3");
    button4 = gtk_button_new_with_label("4");
    button5 = gtk_button_new_with_label("5");
    button6 = gtk_button_new_with_label("6");
    button7 = gtk_button_new_with_label("7");
    button8 = gtk_button_new_with_label("8");
    button9 = gtk_button_new_with_label("9");
    button0 = gtk_button_new_with_label("0");
    button_p = gtk_button_new_with_label("+");
    button_m = gtk_button_new_with_label("-");
    button_mult = gtk_button_new_with_label("*");
    button_share = gtk_button_new_with_label("/");
    button_cl = gtk_button_new_with_label("C");
    button_ex = gtk_button_new_with_label("=");

    all_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 1);
    oth_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 1);

    gtk_window_set_title(GTK_WINDOW(window), "Калькулятор");
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 250, 300);
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
    gtk_window_set_icon_from_file(GTK_WINDOW(window), "icon.jpg", NULL);

    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(destroy), NULL);
    g_signal_connect(G_OBJECT(button_p), "clicked", G_CALLBACK(plus_hand), entry);
    g_signal_connect(G_OBJECT(button_m), "clicked", G_CALLBACK(minus_hand), entry);
    g_signal_connect(G_OBJECT(button_share), "clicked", G_CALLBACK(share_hand), entry);
    g_signal_connect(G_OBJECT(button_mult), "clicked", G_CALLBACK(multiply_hand), entry);
    g_signal_connect(G_OBJECT(button_ex), "clicked", G_CALLBACK(outmore), entry);
    g_signal_connect(G_OBJECT(button1), "clicked", G_CALLBACK(putnumber), "1");
    g_signal_connect(G_OBJECT(button2), "clicked", G_CALLBACK(putnumber), "2");
    g_signal_connect(G_OBJECT(button3), "clicked", G_CALLBACK(putnumber), "3");
    g_signal_connect(G_OBJECT(button4), "clicked", G_CALLBACK(putnumber), "4"); 
    g_signal_connect(G_OBJECT(button5), "clicked", G_CALLBACK(putnumber), "5");
    g_signal_connect(G_OBJECT(button6), "clicked", G_CALLBACK(putnumber), "6");
    g_signal_connect(G_OBJECT(button7), "clicked", G_CALLBACK(putnumber), "7");
    g_signal_connect(G_OBJECT(button8), "clicked", G_CALLBACK(putnumber), "8");
    g_signal_connect(G_OBJECT(button9), "clicked", G_CALLBACK(putnumber), "9");
    g_signal_connect(G_OBJECT(button0), "clicked", G_CALLBACK(putnumber), "0");
	g_signal_connect(G_OBJECT(button_cl), "clicked", G_CALLBACK(cleardata), entry);

    gtk_box_pack_start(GTK_BOX(column1), button1, TRUE, FALSE, 1);
    gtk_box_pack_start(GTK_BOX(column1), button4, TRUE, FALSE, 1);
    gtk_box_pack_start(GTK_BOX(column1), button7, TRUE, FALSE, 1);
    gtk_box_pack_start(GTK_BOX(column4), button_p, TRUE, FALSE, 1);
    gtk_box_pack_start(GTK_BOX(column4), button_share, TRUE, FALSE, 1);

    gtk_box_pack_start(GTK_BOX(column2), button2, TRUE, FALSE, 1);
    gtk_box_pack_start(GTK_BOX(column2), button5, TRUE, FALSE, 1);
    gtk_box_pack_start(GTK_BOX(column2), button8, TRUE, FALSE, 1);
    gtk_box_pack_start(GTK_BOX(column4), button_m, TRUE, FALSE, 1);


    gtk_box_pack_start(GTK_BOX(column3), button3, TRUE, FALSE, 1);
    gtk_box_pack_start(GTK_BOX(column3), button6, TRUE, FALSE, 1);
    gtk_box_pack_start(GTK_BOX(column3), button9, TRUE, FALSE, 1);
    gtk_box_pack_start(GTK_BOX(column4), button_mult, TRUE, FALSE, 1);
    gtk_box_pack_start(GTK_BOX(column4), button_cl, TRUE, FALSE, 1);

    gtk_box_pack_start(GTK_BOX(all_box), column1, TRUE, FALSE, 1);
    gtk_box_pack_start(GTK_BOX(all_box), column2, TRUE, FALSE, 1);
    gtk_box_pack_start(GTK_BOX(all_box), column3, TRUE, FALSE, 1);
    gtk_box_pack_start(GTK_BOX(all_box), column4, TRUE, FALSE, 1);

    gtk_box_pack_start(GTK_BOX(oth_box), expression, TRUE, FALSE, 1);
    gtk_box_pack_start(GTK_BOX(oth_box), entry, TRUE, FALSE, 1);
    gtk_box_pack_start(GTK_BOX(oth_box), all_box, TRUE, FALSE, 1);
    gtk_box_pack_start(GTK_BOX(oth_box), button0, TRUE, FALSE, 1);
    gtk_box_pack_start(GTK_BOX(oth_box), button_ex, TRUE, FALSE, 1);

    gtk_container_add(GTK_CONTAINER(window), oth_box);

    gtk_widget_show_all(window);

    gtk_main();
    
    return 0;
}

void destroy(GtkWidget *window, gpointer data) 
{
    gtk_main_quit();
}

void plus_hand(GtkWidget *button, gpointer data) 
{
    const char *text = gtk_entry_get_text(GTK_ENTRY((GtkWidget *)data));
    const char *textexp = gtk_label_get_text(GTK_LABEL(expression));
    char newtext[200];

    if (first_num == 0) {
        first_num = atoi(text);
	sprintf(newtext, "%s %i", textexp, first_num);
	gtk_entry_set_text(GTK_ENTRY((GtkWidget *)data), "");
	gtk_label_set_text(GTK_LABEL(expression), newtext);
    } else if (first_num != 0 && iter == 0) {
       second_num = atoi(text);
       sprintf(newtext, "%s + %i", textexp, second_num);
       gtk_label_set_text(GTK_LABEL(expression), newtext);
       iter = 1;
    }
    
    expr = "+";

    printf("%i\n%i\n\n", first_num, second_num);
}

void minus_hand(GtkWidget *button, gpointer data) 
{
    const char *text = gtk_entry_get_text(GTK_ENTRY((GtkWidget *)data));
    const char *textexp = gtk_label_get_text(GTK_LABEL(expression));
    char newtext[200];

    if (first_num == 0) {
        first_num = atoi(text);
	sprintf(newtext, "%s %i", textexp, first_num);
        gtk_entry_set_text(GTK_ENTRY((GtkWidget *)data), "");
	gtk_label_set_text(GTK_LABEL(expression), newtext);
    } else if (first_num != 0 && iter == 0) {
       second_num = atoi(text);
       sprintf(newtext, "%s - %i", textexp, second_num);
       gtk_label_set_text(GTK_LABEL(expression), newtext);
       iter = 1;
    }
    
    expr = "-";

    printf("%i\n%i\n\n", first_num, second_num);
}

void share_hand(GtkWidget *button, gpointer data) 
{
    const char *text = gtk_entry_get_text(GTK_ENTRY((GtkWidget *)data));
    const char *textexp = gtk_label_get_text(GTK_LABEL(expression));
    char newtext[200];

    if (first_num == 0) {
        first_num = atoi(text);
	sprintf(newtext, "%s %i", textexp, first_num);
	gtk_entry_set_text(GTK_ENTRY((GtkWidget *)data), "");
	gtk_label_set_text(GTK_LABEL(expression), newtext);
    } else if (first_num != 0 && iter == 0) {
       second_num = atoi(text);
       sprintf(newtext, "%s / %i", textexp, second_num);
       gtk_label_set_text(GTK_LABEL(expression), newtext);
       iter = 1;
    }
    
    expr = "/";

    printf("%i\n%i\n\n", first_num, second_num);
}

void multiply_hand(GtkWidget *button, gpointer data) 
{
    const char *text = gtk_entry_get_text(GTK_ENTRY((GtkWidget *)data));
    const char *textexp = gtk_label_get_text(GTK_LABEL(expression));
    char newtext[200];

    if (first_num == 0) {
        first_num = atoi(text);
	sprintf(newtext, "%s %i", textexp, first_num);
	gtk_entry_set_text(GTK_ENTRY((GtkWidget *)data), "");
	gtk_label_set_text(GTK_LABEL(expression), newtext);
    } else if (first_num != 0 && iter == 0) {
       second_num = atoi(text);
       sprintf(newtext, "%s * %i", textexp, second_num);
       gtk_label_set_text(GTK_LABEL(expression), newtext);
       iter = 1;
    }
    
    expr = "*";

    printf("%i\n%i\n\n", first_num, second_num);
}

void outmore(GtkWidget *button, gpointer data) 
{
   const char *text = gtk_entry_get_text(GTK_ENTRY((GtkWidget *)data));
   if (expr == "+") {
       result = first_num + second_num;
   } else if (expr == "-") {
       result = first_num - second_num;
   } else if (expr == "*") {
       result = first_num * second_num;
   } else if (expr == "/") {
       result = first_num / second_num;
   }
   char outres[200];
   sprintf(outres, "%i", result);
   gtk_label_set_text(GTK_LABEL(expression), outres);
   first_num = result;
   iter = 0;
   printf("%i\n", result);
}

void putnumber(GtkWidget *button, gpointer data) 
{
    const char *text = gtk_entry_get_text(GTK_ENTRY(entry));
    char *num = data;
    char newtext[200];
    sprintf(newtext, "%s%s", text, num);
    gtk_entry_set_text(GTK_ENTRY(entry), newtext);
    printf("%s\n", newtext);
    
}

void cleardata(GtkWidget *button, gpointer data) 
{
    gtk_entry_set_text(GTK_ENTRY((GtkWidget *) data), "");
    gtk_label_set_text(GTK_LABEL(expression), "");
    result = 0;
    iter = 0;
    first_num = 0;
    second_num = 0;
}
