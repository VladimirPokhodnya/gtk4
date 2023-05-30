#include<gtk/gtk.h>
void quit_app(GtkWidget *widget, gpointer data) {
  gboolean *done = data;
  *done = TRUE;
  g_main_context_wakeup(NULL);
}
int main() {
  gtk_init();
  gboolean done = FALSE;
  GtkWidget *window;
  GtkWidget *label;
  window = gtk_window_new();
  gtk_window_set_title(GTK_WINDOW(window), "test GTK4 + C");
  gtk_window_set_default_size(GTK_WINDOW(window), 400, 400);
  g_signal_connect(window, "destroy", G_CALLBACK(quit_app), &done);
  label = gtk_label_new("hello, world");
  gtk_label_set_xalign(GTK_LABEL(label), 0);
  gtk_label_set_yalign(GTK_LABEL(label), 0);
  gtk_window_set_child(GTK_WINDOW(window), label);
  gtk_widget_show(window);
  while(!done) {
    g_main_context_iteration(NULL, TRUE);
  }
  return 0;
}