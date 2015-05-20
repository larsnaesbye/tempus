// AstroTime - https://github.com/larsnaesbye/astrotime
//
// Copyright (c) 2015, Lars Næsbye Christensen
//
// All rights reserved. Refer to the accompanying GPL3 document for details.
// 

#include <stdlib.h>
#include <gtk/gtk.h>

static void AboutDialog (GtkWidget *wid, GtkWidget *win)
{
  GtkWidget *dialog = NULL;

  dialog = gtk_message_dialog_new (GTK_WINDOW (win), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, "AstroTime 0.1\n\nby Lars Næsbye Christensen");
  gtk_window_set_position (GTK_WINDOW (dialog), GTK_WIN_POS_CENTER);
  gtk_dialog_run (GTK_DIALOG (dialog));
  gtk_widget_destroy (dialog);
}

static void SetLocation (GtkWidget *wid, GtkWidget *win)
{
  GtkWidget *dialog = NULL;

  dialog = gtk_message_dialog_new (GTK_WINDOW (win), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, "Set Location dialog not ready yet!");
  gtk_window_set_position (GTK_WINDOW (dialog), GTK_WIN_POS_CENTER);
  gtk_dialog_run (GTK_DIALOG (dialog));
  gtk_widget_destroy (dialog);
}

int main (int argc, char *argv[])
{

  GtkWidget *win = NULL;
  GtkWidget *button = NULL;
  GtkWidget *vbox = NULL;

  GtkWidget *menubar = NULL;
  
  GtkWidget *filemenu = NULL;
  GtkWidget *locationmenu = NULL;
  GtkWidget *timemenu = NULL;
  GtkWidget *chimesmenu = NULL;
  GtkWidget *helpmenu = NULL;

  GtkWidget *file = NULL;
  GtkWidget *exit = NULL;

  GtkWidget *location = NULL;
  GtkWidget *setlocation = NULL;  
  
  GtkWidget *time = NULL;
  GtkWidget *lmt12 = NULL;
  GtkWidget *lmt24 = NULL;
  GtkWidget *univ = NULL;
  GtkWidget *sep = NULL;
  GtkWidget *lst = NULL;
  GtkWidget *gst = NULL;

  GtkWidget *chimes = NULL;
  GtkWidget *none = NULL;
  GtkWidget *single = NULL;
  GtkWidget *multiple = NULL;
  
  GtkWidget *help = NULL;
  GtkWidget *about = NULL;
  
  GtkWidget *timelabel = NULL;

  /* Initialize GTK+ */
  //g_log_set_handler ("Gtk", G_LOG_LEVEL_WARNING, (GLogFunc) gtk_false, NULL);
  gtk_init (&argc, &argv);
  //g_log_set_handler ("Gtk", G_LOG_LEVEL_WARNING, g_log_default_handler, NULL);

  /* Create our main window */
  win = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size(GTK_WINDOW (win), 500, 400);
  gtk_container_set_border_width (GTK_CONTAINER (win), 6);
  gtk_window_set_title (GTK_WINDOW (win), "AstroTime 0.1");
  gtk_window_set_decorated (GTK_WINDOW (win), TRUE);
  gtk_window_set_position (GTK_WINDOW (win), GTK_WIN_POS_CENTER);
  gtk_window_set_keep_above (GTK_WINDOW (win), TRUE);
  gtk_widget_realize (win);
 
  /* Create our menu bar */
  menubar = gtk_menu_bar_new();
    
  /* Build our menus with menu items */

  filemenu = gtk_menu_new();
  file = gtk_menu_item_new_with_mnemonic("_File");
  exit = gtk_menu_item_new_with_mnemonic("E_xit");
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(file), filemenu);
  gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), exit);
  g_signal_connect (G_OBJECT (exit), "activate", gtk_main_quit, (gpointer)  win); gtk_menu_bar_append(GTK_MENU_BAR(menubar), filemenu);

  locationmenu = gtk_menu_new();
  location = gtk_menu_item_new_with_mnemonic("_Location");
  setlocation = gtk_menu_item_new_with_mnemonic("_Set Location...");
  g_signal_connect (G_OBJECT (setlocation), "activate", G_CALLBACK (SetLocation), (gpointer) win);
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(location), locationmenu);
  gtk_menu_shell_append(GTK_MENU_SHELL(locationmenu), setlocation);
  gtk_menu_bar_append(GTK_MENU_BAR(menubar), locationmenu);

  timemenu = gtk_menu_new();
  time = gtk_menu_item_new_with_mnemonic("_Time");
  lmt12 = gtk_menu_item_new_with_mnemonic("_Local Mean Time (12 hr format)");
  lmt24 = gtk_menu_item_new_with_mnemonic("Local _Mean Time (24 hr format)");
  univ = gtk_menu_item_new_with_mnemonic("_Universal Time");
  sep = gtk_separator_menu_item_new();
  lst = gtk_menu_item_new_with_mnemonic("Local _Sidereal Time");
  gst = gtk_menu_item_new_with_mnemonic("_Greenwich Sidereal Time");
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(time), timemenu);
  gtk_menu_shell_append(GTK_MENU_SHELL(timemenu), lmt12);
  gtk_menu_shell_append(GTK_MENU_SHELL(timemenu), lmt24);
  gtk_menu_shell_append(GTK_MENU_SHELL(timemenu), univ);
  gtk_menu_shell_append(GTK_MENU_SHELL(timemenu), sep);
  gtk_menu_shell_append(GTK_MENU_SHELL(timemenu), lst);
  gtk_menu_shell_append(GTK_MENU_SHELL(timemenu), gst);


  chimesmenu = gtk_menu_new();
  chimes = gtk_menu_item_new_with_mnemonic("_Chimes");
  none = gtk_menu_item_new_with_mnemonic("_None");
  single = gtk_menu_item_new_with_mnemonic("_Single");
  multiple = gtk_menu_item_new_with_mnemonic("_Multiple");
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(chimes), chimesmenu);
  /* TODO: These three need to be a radio group */
  gtk_menu_shell_append(GTK_MENU_SHELL(chimesmenu), none);
  gtk_menu_shell_append(GTK_MENU_SHELL(chimesmenu), single);
  gtk_menu_shell_append(GTK_MENU_SHELL(chimesmenu), multiple);

  helpmenu = gtk_menu_new();
  help = gtk_menu_item_new_with_mnemonic("_Help");
  about = gtk_menu_item_new_with_mnemonic("_About AstroTime...");
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), helpmenu);
  gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), about);
  g_signal_connect (G_OBJECT (about), "activate", G_CALLBACK (AboutDialog), (gpointer) win);
  
  /* Add the menus to our menubar */
  gtk_menu_shell_append(GTK_MENU_SHELL(menubar), file);
  gtk_menu_shell_append(GTK_MENU_SHELL(menubar), location);
  gtk_menu_shell_append(GTK_MENU_SHELL(menubar), time);
  gtk_menu_shell_append(GTK_MENU_SHELL(menubar), chimes);  
  gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help);

  gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 3);

  g_signal_connect (win, "destroy", gtk_main_quit, NULL);

  /* Create our vertical layout box for menubar plus label */
  vbox = gtk_vbox_new (FALSE, 0);
  timelabel = gtk_label_new("Label!!!");

  gtk_container_add (GTK_CONTAINER (win), vbox);
  //gtk_container_add (GTK_CONTAINER (vbox), timelabel);

  gtk_box_pack_start (GTK_BOX (vbox), menubar, FALSE, FALSE, 3);


  gtk_widget_show_all (win);

  /* Enter the main event loop */
  gtk_main ();
  return 0;
}
