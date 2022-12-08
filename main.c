#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>

/*==Global var==*/

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

//BMI var
GtkWidget *height_input;
GtkWidget *weight_input;
GtkWidget *result_bmi;
GtkWidget *bmi;

//Break var
GtkWidget *totalB_input;
GtkWidget *costB_input;
GtkWidget *priceB_input;
GtkWidget *unit_result;
GtkWidget *sale_result;

//Windows var
GtkBuilder *builder;
GtkWidget *window;
GtkWidget *windowTip;
GtkWidget *bmi_window;
GtkWidget *break_window;


void discount_calculate(){

    char *price;
    char *discount;
    char result[20];

    price = gtk_entry_get_text(price_input);
    discount = gtk_entry_get_text(discount_input);

    //operation:
    float dif = (strtof(discount,NULL)/100) * strtof(price,NULL);

    gcvt(strtof(price,NULL)-dif,6,result);

    gtk_label_set_text(GTK_LABEL(result_label),result);


    printf("Button is clicked\n");
    printf("%s\n",price);
    printf("%s\n",discount);
    printf("%s\n",result);

}

void tipCalculator(){

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

void bmiCalculator(){

    char *height;
    char *weight;
    char result[20];
    char bmi_ch[20];

    height = gtk_entry_get_text(height_input);
    weight = gtk_entry_get_text(weight_input);
    float w = strtof(weight,NULL);
    float h = strtof(height,NULL);
    float b = w / (h*h);

    //Operation
    gcvt(b,6,result);

    if(b < 18.5){
        printf("Underweight");
        strcpy(bmi_ch,"Underweight");
    }else if('s'>18.5 && b<24.9){
        printf("Normal");
        strcpy(bmi_ch,"Normal");
    }else if('tr'>25.0 && b<29.9){
        printf("Overweight");
        strcpy(bmi_ch,"Overweight");
    }else{
        printf("Obese");
        strcpy(bmi_ch,"Obese");
    }

    gtk_label_set_text(GTK_LABEL(bmi),bmi_ch);
    gtk_label_set_text(GTK_LABEL(result_bmi),result);


}

void breakCalculator(){

       char *totalB;
       char *costB;
       char *priceB;
       char u_result[20];
       char s_result[20];

    totalB = gtk_entry_get_text(totalB_input);
    costB = gtk_entry_get_text(costB_input);
    priceB = gtk_entry_get_text(priceB_input);
    //Operation
    float t = strtof(totalB,NULL);
    float c = strtof(costB,NULL);
    float p = strtof(priceB,NULL);
    float sale = t / (p-c) * p;
    float unit = t /(p-c);
    gcvt(sale,6,s_result);
    gcvt(unit,6,u_result);

    printf("%s: ",s_result);
    printf("\n%s: ",u_result);
    gtk_label_set_text(GTK_LABEL(unit_result),u_result);
    gtk_label_set_text(GTK_LABEL(sale_result),s_result);
}

//open discount_app:
void open_discount_app(){


    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "app1UI.glade", NULL);
    window = GTK_WIDGET(gtk_builder_get_object(builder, "discount_window"));
    gtk_builder_connect_signals(builder, NULL);


    /*Event Handler on Button*/
    GtkWidget *g_btn_submit;
    g_btn_submit = GTK_WIDGET(gtk_builder_get_object(builder, "calculate_btn"));

    price_input = GTK_WIDGET(gtk_builder_get_object(builder, "price_input"));
    discount_input = GTK_WIDGET(gtk_builder_get_object(builder, "discount_input"));
    result_label = GTK_WIDGET(gtk_builder_get_object(builder, "result_label"));

    g_signal_connect(G_OBJECT(g_btn_submit), "clicked", G_CALLBACK(discount_calculate), NULL);

    gtk_widget_show_all (window);
    gtk_main ();
}

//open Tip
void open_tip_app(){


    builder = gtk_builder_new();

    gtk_builder_add_from_file(builder, "tipUI.glade", NULL);
    windowTip = GTK_WIDGET(gtk_builder_get_object(builder, "tip_window"));
    gtk_builder_connect_signals(builder, NULL);

     /*Event Handler on Button*/
    GtkWidget *g_btn_cal_tip;

    g_btn_cal_tip = GTK_WIDGET(gtk_builder_get_object(builder, "cal_tip_btn"));
    bill_input = GTK_WIDGET(gtk_builder_get_object(builder, "bill_input"));
    tax_input = GTK_WIDGET(gtk_builder_get_object(builder, "tax_input"));
    tip_input = GTK_WIDGET(gtk_builder_get_object(builder, "tip_input"));
    split_input = GTK_WIDGET(gtk_builder_get_object(builder, "split_input"));
    result_tip = GTK_WIDGET(gtk_builder_get_object(builder, "result_tip"));

    g_signal_connect(G_OBJECT(g_btn_cal_tip), "clicked", G_CALLBACK(tipCalculator), NULL);

    gtk_widget_show_all (windowTip);
    gtk_main ();
}

//open BMI:
void open_bmi_app(){

    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "bmiUI.glade", NULL);
    bmi_window = GTK_WIDGET(gtk_builder_get_object(builder, "bmi_window"));
    gtk_builder_connect_signals(builder, NULL);

    /*Event Handler on Button*/
    GtkWidget *g_btn_cal_bmi;
    g_btn_cal_bmi = GTK_WIDGET(gtk_builder_get_object(builder, "cal_bmi_btn"));
    height_input = GTK_WIDGET(gtk_builder_get_object(builder, "height_input"));
    weight_input = GTK_WIDGET(gtk_builder_get_object(builder, "weight_input"));
    result_bmi = GTK_WIDGET(gtk_builder_get_object(builder, "result_bmi"));
    bmi = GTK_WIDGET(gtk_builder_get_object(builder, "bmi"));

    g_signal_connect(G_OBJECT(g_btn_cal_bmi), "clicked", G_CALLBACK(bmiCalculator), NULL);



    gtk_widget_show_all (bmi_window);
    gtk_main ();

}

//open Break
void open_break_app(){
    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "breakEvenUI.glade", NULL);
    break_window = GTK_WIDGET(gtk_builder_get_object(builder, "break_window"));
    gtk_builder_connect_signals(builder, NULL);

     /*Event Handler on Button*/
    GtkWidget *g_btn_cal_break;
    g_btn_cal_break = GTK_WIDGET(gtk_builder_get_object(builder, "cal_break_btn"));
    totalB_input = GTK_WIDGET(gtk_builder_get_object(builder, "totalB_input"));
    costB_input = GTK_WIDGET(gtk_builder_get_object(builder, "costB_input"));
    priceB_input = GTK_WIDGET(gtk_builder_get_object(builder, "priceB_input"));
    unit_result = GTK_WIDGET(gtk_builder_get_object(builder, "unit_result"));
    sale_result = GTK_WIDGET(gtk_builder_get_object(builder, "sale_result"));


    g_signal_connect(G_OBJECT(g_btn_cal_break), "clicked", G_CALLBACK(breakCalculator), NULL);

    gtk_widget_show_all (break_window);
    gtk_main ();
}

int main (int argc, char *argv[])
{

  /* Initialize GTK+ */
  g_log_set_handler ("Gtk", G_LOG_LEVEL_WARNING, (GLogFunc) gtk_false, NULL);
  gtk_init (&argc, &argv);
  g_log_set_handler ("Gtk", G_LOG_LEVEL_WARNING, g_log_default_handler, NULL);

  /* Link between glade Home page and CodeBlocks */
  builder = gtk_builder_new();
  gtk_builder_add_from_file(builder, "homeUI.glade", NULL);
  window = GTK_WIDGET(gtk_builder_get_object(builder, "home"));
  gtk_builder_connect_signals(builder, NULL);

  /*Open Discount App btn*/
  GtkWidget *g_btn_app1;
  g_btn_app1 = GTK_WIDGET(gtk_builder_get_object(builder, "btn_discount"));
  g_signal_connect(G_OBJECT(g_btn_app1), "clicked", G_CALLBACK(open_discount_app), NULL);


  /*Open Tip App btn*/
  GtkWidget *g_btn_tip;
  g_btn_tip = GTK_WIDGET(gtk_builder_get_object(builder, "btn_tip"));
  g_signal_connect(G_OBJECT(g_btn_tip), "clicked", G_CALLBACK(open_tip_app), NULL);


  /*Open BMI App btn*/
  GtkWidget *g_btn_bmi;
  g_btn_bmi = GTK_WIDGET(gtk_builder_get_object(builder, "btn_bmi"));
  g_signal_connect(G_OBJECT(g_btn_bmi), "clicked", G_CALLBACK(open_bmi_app), NULL);


  /*Open BMI App btn*/
  GtkWidget *g_btn_break;
  g_btn_break = GTK_WIDGET(gtk_builder_get_object(builder, "btn_break"));
  g_signal_connect(G_OBJECT(g_btn_break), "clicked", G_CALLBACK(open_break_app), NULL);

  /* Enter the main loop */
  gtk_widget_show_all (window);
  gtk_main ();
  return 0;
}
