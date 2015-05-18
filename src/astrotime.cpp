// AstroTime - https://github.com/larsnaesbye/astrotime
//
// Copyright (c) 2015, Lars Næsbye Christensen
// All rights reserved. Refer to the GPL 3 document for details.
// 

#include <stdlib.h>
#include <gtk/gtk.h>

#include "Constants.h" // only version number for now

static void AstroTime (GtkWidget *wid, GtkWidget *win)
{
  GtkWidget *dialog = NULL;

  dialog = gtk_message_dialog_new (GTK_WINDOW (win), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, "AstroTime");
  gtk_window_set_position (GTK_WINDOW (dialog), GTK_WIN_POS_CENTER);
  gtk_dialog_run (GTK_DIALOG (dialog));
  gtk_widget_destroy (dialog);
}

int main (int argc, char *argv[])
{
  GtkWidget *button = NULL;
  GtkWidget *vbox = NULL;
  GtkWidget *win = NULL;

  GtkWidget *menubar = NULL;
  GtkWidget *filemenu = NULL;
  GtkWidget *helpmenu = NULL;

  GtkWidget *file = NULL;
  GtkWidget *quit = NULL;
  GtkWidget *about = NULL;

  /* Initialize GTK+ */
  g_log_set_handler ("Gtk", G_LOG_LEVEL_WARNING, (GLogFunc) gtk_false, NULL);
  gtk_init (&argc, &argv);
  g_log_set_handler ("Gtk", G_LOG_LEVEL_WARNING, g_log_default_handler, NULL);

  /* Create the main window */
  win = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size(GTK_WINDOW (win), 500, 200);
  gtk_container_set_border_width (GTK_CONTAINER (win), 5);
  gtk_window_set_title (GTK_WINDOW (win), "AstroTime "+ATversion);
  gtk_window_set_position (GTK_WINDOW (win), GTK_WIN_POS_CENTER);
  gtk_widget_realize (win);
 
  /* Create a menu bar */

  menubar = gtk_menu_bar_new();
  filemenu = gtk_menu_new();
  helpmenu = gtk_menu_new();

  file = gtk_menu_item_new_with_label("File");
  quit = gtk_menu_item_new_with_label("Quit");
  about = gtk_menu_item_new_with_label("About...");


  gtk_menu_item_set_submenu(GTK_MENU_ITEM(file), filemenu);
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(about), helpmenu);

  gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), quit);
  gtk_menu_shell_append(GTK_MENU_SHELL(menubar), file);
  gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help);

  gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 3);

 g_signal_connect (win, "destroy", gtk_main_quit, NULL);

  /* Create a vertical box with buttons */
  vbox = gtk_vbox_new (TRUE, 5);
  gtk_container_add (GTK_CONTAINER (win), vbox);

  button = gtk_button_new_from_stock (GTK_STOCK_DIALOG_INFO);

  g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (AstroTime), (gpointer) win);
  gtk_box_pack_start (GTK_BOX (vbox), button, TRUE, TRUE, 0);

  button = gtk_button_new_from_stock (GTK_STOCK_CLOSE);

  g_signal_connect (button, "clicked", gtk_main_quit, NULL);
  gtk_box_pack_start (GTK_BOX (vbox), button, TRUE, TRUE, 0);

  /* Enter the main loop */
  gtk_widget_show_all (win);
  gtk_main ();
  return 0;
}
