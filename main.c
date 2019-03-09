#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

struct labelMod{
    GtkLabel* lbl;
    int i;
};

static gboolean delete_event(GtkWidget *widget, GdkEvent *event, gpointer data ){
    g_print ("delete event occurred\n");
    return FALSE;
}

static void destroy(GtkWidget *widget, GdkEvent *event, gpointer data){
    gtk_main_quit ();
}

gboolean button_clicked (GtkWidget *widget, gpointer user_data){
    printf("Button clicked");
    g_print("\n");
    //g_print("Butt pressed");
    //gtk_label_set_text("shitfuck");
    struct labelMod* mod = user_data;
    mod->i += 1;
    printf("NUM: %d", mod->i);
    g_print("\n");
    char str[10];
    sprintf(str, "%d", mod->i);
    gtk_label_set_text(mod->lbl, str);
}

int main(int argc, char* argv[]){
    struct labelMod combo;
    combo.i = 5;

    GtkBuilder *gtkBuilder;
    GtkWidget *window;
    GtkWidget *button;
    GtkLabel *label;

    gtk_init(&argc, &argv);
    gtkBuilder = gtk_builder_new();
    gtk_builder_add_from_file(gtkBuilder, "GladeTest.glade", NULL);
    //gtk_builder_add_from_string();
    window = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "window1"));
    button = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "why"));
    label = GTK_LABEL(gtk_builder_get_object(gtkBuilder, "label"));
    combo.lbl = label;
    //g_signal_connect (G_OBJECT (button), "key_press_event", G_CALLBACK (on_key_press), NULL);

    g_signal_connect (button, "clicked", G_CALLBACK (button_clicked), &combo);

    //g_object_unref(G_OBJECT(gtkBuilder));
    //gtk_widget_show(window);
    g_signal_connect (window, "delete-event", G_CALLBACK (delete_event), NULL);
    g_signal_connect (window, "destroy", G_CALLBACK (destroy), NULL);


    gtk_widget_show_all(window);
    gtk_main();
    printf("Hello World\n");
    return 0;
}

