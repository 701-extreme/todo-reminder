#ifndef RESP_H
#define RESP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "status.h"

Status response_handle(Status user_viewing, char* response);
Status handle_welcome(char* response);
Status handle_menu(char* response);
Status handle_setup(char* response);

#endif
