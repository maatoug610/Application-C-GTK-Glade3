#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>

//Global var

//Discount var
GtkWidget *price_input;
GtkWidget *discount_input;
GtkWidget *result_label;

//Tip var
GtkWidget *bill_input;
GtkWidget *tax_input;
GtkWidget *tip_input;
GtkWidget *split_input;
GtkWidget *result_tip;

GtkBuilder *builder;
GtkWidget *window;
GtkWidget *windowTip;


void discount_calculate(){


    char *price;
    char *discount;
    char result[20];

    price = gtk_entry_get_text(price_input);
    discount = gtk_entry_get_text(discount_input);

    //operation:
    float dif= (strtof(discount,NULL)/100) * strtof(price,NULL);

    gcvt(strtof(price,NULL)-dif,6,result);

    gtk_label_set_text(GTK_LABEL(result_label),result);


    printf("Button is clicked\n");
    printf("%s\n",price);
    printf("%s\n",discount);
    printf("%s\n",result);

}

void tipCalculator(){

printf("Tip");
    char *bill;
    char *tax;
    char *tip;
    char *split;
    char result[20];

    bill = gtk_entry_get_text(bill_input);
    tax = gtk_entry_get_text(tax_input);
    tip = gtk_entry_get_text(tip_input);
    split = gtk_entry_get_text(split_input);

    float b = strtof(bill,NULL);
    float ta = strtof(tax,NULL);
    float ti = strtof(tip,NULL);
    float s = strtof(split,NULL);
    //operation:


    gcvt((b + b*ta/100 + b*ti/100) / s,6,result);

    gtk_label_set_text(GTK_LABEL(result_tip),result);


    printf("%s",result);

}

//open App1:
void open_app1(){


    builder = gtk_builder_new();

    gtk_builder_add_from_file(builder, "app1UI.glade", NULL);
    window = GTK_WIDGET(gtk_builder_get_object(builder, "app1"));
    gtk_builder_connect_signals(builder, NULL);



    /*Event Handler on Button*/
    GtkWidget *g_btn_submit;
    g_btn_submit = GTK_WIDGET(gtk_builder_get_object(builder, "calculate_btn"));

    price_input = GTK_WIDGET(gtk_builder_get_object(builder, "price_input"));
    discount_input = GTK_WIDGET(gtk_builder_get_object(builder, "discount_input"));
    result_label = GTK_WIDGET(gtk_builder_get_object(builder, "result_label"));
    /*
    input = GTK_WIDGET(gtk_builder_get_object(builder, "input_name"));
    input2 = GTK_WIDGET(gtk_builder_get_object(builder, "input_name2"));
    label = GTK_WIDGET(gtk_builder_get_object(builder, "label1"));*/

    g_signal_connect(G_OBJECT(g_btn_submit), "clicked", G_CALLBACK(discount_calculate), NULL);

    gtk_widget_show_all (window);
    gtk_main ();
}

//open Tip
void open_btn(){


    builder = gtk_builder_new();

    gtk_builder_add_from_file(builder, "tipUI.glade", NULL);
    windowTip = GTK_WIDGET(gtk_builder_get_object(builder, "tip_window"));
    gtk_builder_connect_signals(builder, NULL);

     /*Event Handler on Button*/
    GtkWidget *g_btn_cal_tip;
    g_btn_cal_tip = GTK_WIDGET(gtk_builder_get_object(builder, "btn_tip"));


    bill_input = GTK_WIDGET(gtk_builder_get_object(builder, "bill_input"));
    tax_input = GTK_WIDGET(gtk_builder_get_object(builder, "tax_input"));
    tip_input = GTK_WIDGET(gtk_builder_get_object(builder, "tip_input"));
    split_input = GTK_WIDGET(gtk_builder_get_object(builder, "split_input"));
    result_tip = GTK_WIDGET(gtk_builder_get_object(builder, "result_tip"));

    g_signal_connect(G_OBJECT(g_btn_cal_tip), "clicked", G_CALLBACK(tipCalculator), NULL);

    gtk_widget_show_all (windowTip);
    gtk_main ();
}

int main (int argc, char *argv[])
{

  /* Initialize GTK+ */
  g_log_set_handler ("Gtk", G_LOG_LEVEL_WARNING, (GLogFunc) gtk_false, NULL);
  gtk_init (&argc, &argv);
  g_log_set_handler ("Gtk", G_LOG_LEVEL_WARNING, g_log_default_handler, NULL);

  /* Link between glade and CodeBlocks */


  builder = gtk_builder_new();

  gtk_builder_add_from_file(builder, "homeUI.glade", NULL);

  window = GTK_WIDGET(gtk_builder_get_object(builder, "home"));
  gtk_builder_connect_signals(builder, NULL);

  /*Open Discount App btn*/
  GtkWidget *g_btn_app1;
  g_btn_app1 = GTK_WIDGET(gtk_builder_get_object(builder, "btn_app1"));
  g_signal_connect(G_OBJECT(g_btn_app1), "clicked", G_CALLBACK(open_app1), NULL);



  /*Open Tip App btn*/
  GtkWidget *g_btn_tip;
  g_btn_tip = GTK_WIDGET(gtk_builder_get_object(builder, "btn_tip"));
  g_signal_connect(G_OBJECT(g_btn_tip), "clicked", G_CALLBACK(open_btn), NULL);


  /* Enter the main loop */
  gtk_widget_show_all (window);
  gtk_main ();
  return 0;
}
