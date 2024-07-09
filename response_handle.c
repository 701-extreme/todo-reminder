#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "status.h"

/* return the final state dependent on the current state and the user response */
Status response_handle(Status user_viewing, char* response)
{
	case WELCOME:
		return handle_welcome(response);
	case MENU:
		return handle_menu(response);
	case SETUP:
		return handle_setup(response);
	default:
		return user_viewing;
}

Status handle_welcome(char* response)
{
	printf("handling response to welcome page\n");
	return WELCOME;
}

Status handle_menu(char* response)
{
	printf("handling response to menu page\n");
	return MENU;
}

Status handle_setup(char* response)
{
	printf("handling reponse to setup page\n");
	return SETUP;
}
