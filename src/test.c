/*
 *
 * AstroTime
 *
 * Copyright 2015 Lars Næsbye Christensen, All Rights Reserved
 *
 * This code is distributed without warranty. You are free to use this
 * code for any purpose, however, if this code is republished or
 * redistributed in its original form, as hardcopy or electronically,
 * then you must include this copyright notice along with the code.
 *
 * Questions or comments regarding this code or any bugs it contains can
 * be directed to the author via e-mail at lars@naesbye.dk
 *
*/

//#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {

time_t timer;
char buffer[26];
struct tm* tm_info;

time(&timer);
tm_info = localtime(&timer)

strftime(buffer, 26, "%Y:%m:%d %H:%M:%S.000", tm_info);
puts(buffer);

return 0;

}

/*
Establish basic application loop
Make the 5 menus and submenus
Display time 
*/
