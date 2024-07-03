#ifndef DISP_H
#define DISP_H

#include <stdio.h>
#include "status.h"

/* Choose which interface to display */
void display(Status user_viewing);

/* Display the corresponding interface */
void display_interface(char* path);

#endif
