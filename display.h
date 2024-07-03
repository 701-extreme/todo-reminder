#ifndef DISP_H
#define DISP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum status
{
        WELCOME,
        MENU,
        SETUP,
        IMPORT,
        ADD,
        REMOVE
}Status;

void display(Status user_viewing);
void display_interface(char* path);

#endif
