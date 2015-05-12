#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# DONE:
# Keep window on top
# About... Dialog
#
# TODO: (0.1 - august)
# use the Astropy libs
# Make the clock update every 0.5 secs
# Close dialog actually closes
# Resize font upon window resize
# TODO: (0.2)
# Menu shortcuts
# Accelerators
# Set Location Dialog
# TODO: (0.5)
# Chimes on the hour - none, once every hour, number every hour
# Keep on top must be optional, but default
# TODO: (0.9)
# Settings load/save
# SVG icon
# Documentation

import datetime
import gtk

from astropy import time

class AstroTime(gtk.Window):



    def __init__(self):
        super(AstroTime, self).__init__()

        self.set_title("AstroTime")
        self.set_position(gtk.WIN_POS_CENTER)
        self.set_keep_above(True)
        #self.set_decorated(False)
        mb = gtk.MenuBar()

        filemenu = gtk.Menu()
        locmenu = gtk.Menu()
        timemenu = gtk.Menu()
        chimesmenu = gtk.Menu()
        helpmenu = gtk.Menu()


        filem = gtk.MenuItem("File")
        locm = gtk.MenuItem("Location")
        timem = gtk.MenuItem("Time")
        chimesm = gtk.MenuItem("Chimes")
        helpm = gtk.MenuItem("Help")

        filem.set_submenu(filemenu)
        locm.set_submenu(locmenu)
        timem.set_submenu(timemenu)
        chimesm.set_submenu(chimesmenu)
        helpm.set_submenu(helpmenu)
       
        exit = gtk.MenuItem("Exit")
        exit.connect("activate", gtk.main_quit)
        filemenu.append(exit)
        
        setlocation = gtk.MenuItem("Set Location...")
        setlocation.connect("activate", self.location_dialog)
        locmenu.append(setlocation)

        lmt12 = gtk.MenuItem("Local Mean Time (12 hr format)")
        lmt12.connect("activate", gtk.main_quit)
        timemenu.append(lmt12)

        lmt24 = gtk.MenuItem("Local Mean Time (24 hr format)")
        lmt24.connect("activate", gtk.main_quit)
        timemenu.append(lmt24)

        univtime = gtk.MenuItem("Universal Time")
        univtime.connect("activate", gtk.main_quit)
        timemenu.append(univtime)

        sepitem = gtk.SeparatorMenuItem()
        timemenu.append(sepitem)

        lst = gtk.MenuItem("Local Sidereal Time")
        lst.connect("activate", gtk.main_quit)
        timemenu.append(lst)

        gst = gtk.MenuItem("Greenwich Sidereal Time")
        gst.connect("activate", gtk.main_quit)
        timemenu.append(gst)

        none = gtk.MenuItem("None")
        none.connect("activate", gtk.main_quit)
        chimesmenu.append(none)

        single = gtk.MenuItem("Single")
        single.connect("activate", gtk.main_quit)
        chimesmenu.append(single)

        multiple = gtk.MenuItem("Multiple")
        multiple.connect("activate", gtk.main_quit)
        chimesmenu.append(multiple)

        about = gtk.MenuItem("About AstroTime...")
        about.connect("activate", self.about_dialog)
        helpmenu.append(about)

        mb.append(filem)
        mb.append(locm)
        mb.append(timem)
        mb.append(chimesm)
        mb.append(helpm)

    	displayTime = str(datetime.datetime.now())
    	timeLabel = gtk.Label("Time")
        timeLabel.set_use_markup(gtk.TRUE)
        fontsize = 24
    	timeLabel.set_markup('<span font_desc="DejaVu Sans Mono '+str(fontsize)+'">'+displayTime+'</span>')

        vbox = gtk.VBox(False,2)
        hbox = gtk.HBox(False,2)
        vbox.pack_start(mb, False, False, 0)
        hbox.add(timeLabel)
        vbox.add(hbox)

        self.add(vbox)


        timeLabel.show()

        self.connect("destroy", gtk.main_quit)
        self.show_all()

    def about_dialog(self, widget):
        dialog = gtk.MessageDialog(None,gtk.DIALOG_DESTROY_WITH_PARENT,gtk.MESSAGE_INFO,gtk.BUTTONS_CLOSE,"AstroTime 0.1\nDistro Astro - Linux for Astronomers\n\nby Lars Næsbye Christensen")
        response = dialog.run()

    def location_dialog(self, widget):
        dialog = gtk.MessageDialog(None,gtk.DIALOG_DESTROY_WITH_PARENT,gtk.MESSAGE_INFO,gtk.BUTTONS_CLOSE," Set Location coming up")
        response = dialog.run()
AstroTime()
gtk.main()
