# Tempus

Tempus is a Free and Open Source utility for displaying the current time in various time systems, mainly for astronomical purposes.

It was written for the Distro Astro Linux distribution in C++ using the Qt user interface toolkit for maximum compatibility in case someone wishes to port it to other platforms. It also serves as my first excursion into programming with the Qt framework.

It is intended to be small and unobtrusive, unless you want it to be.
Tempus is c 2016-2018 by Lars Næsbye Christensen and its usage is covered under the GNU Public License (GPL) version 3 or any later version.

You'll be needing Qt 5 or newer for Tempus to work. It has been tested with 5.12.

## Usage

This section explains some of the ways you can use Tempus to view time.
Tempus runs as an ordinary desktop application, using familiar menus,
windows, and controls.

It has one window, displaying the time in a scalable view as the central information in big monospace type that resizes with the main window.

You run Tempus as you would any other program, by double-clicking its icon or running it from a command line interface.

The location obviously affects some time calculations, so Tempus needs to know your location in order to calculate sidereal times and other things. You can set your location in the Location menu.

## Formats and standards

The time formats supported are:

* Local Mean Time
* Universal Time, Coordinated
* Julian Day
* Julian Day, modified
* Local Sidereal Time
* Greenwich Sidereal Time

City coordinates are of course points within an urban area, and therefore not more precise than so many other points. The current values are taken from the dateandtime.info web site. Currently, only the time zone values are of use for the display of local time, since a particular longitude isn’t a
guarantee for a matching local time.

Tempus aims to adhere to the following scientific standards:

* World Geodetic System (WGS84, EPSG:4326) - in the locations.xml file, for example

## Troubleshooting

If Tempus does not run, check the following:

* That the execute bit is set on the application
* That Qt framework version 5 is installed properly

## Building

If you wish to build Tempus from scratch, you need to obtain the C++ source code and related files, which can be obtained by cloning:

`git clone https://github.com/larsnaesbye/tempus.git`

For this, you will need Qt version 5 or later (5.5 or later greatly preferred) installed for compilation to work.
You need to run the qmake tool (part of Qt) to be able to compile the
application properly. In addition you may want to install Qt Creator to
edit the base project and forms.

You might want to ensure that ’Shadow Build’ is disabled in Projects
Mode or else icons and other things might not build right.
