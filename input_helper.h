#ifndef HLP_H
#define HLP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "status.h"

#define INPUT_MAX (1024)

/* Check for invalid input */
int invalid_input(char* input, int len, Status user_viewing);

/* Get user commands */
void get_command(char* line, Status user_viewing);

#endif
