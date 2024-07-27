#ifndef RESP_H
#define RESP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "status.h"

Status response_handle(Status user_viewing, char* response);
Status handle_welcome(unsigned int response);
Status handle_menu(unsigned int response);
Status handle_setup(unsigned int response);

#endif
