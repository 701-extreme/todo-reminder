#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "status.h"
#include "response_handle.h"

/* return the final state dependent on the current state and the user response */
Status response_handle(Status user_viewing, char* response)
{
	unsigned int response_num = (unsigned int)strtol(response, NULL, 10);
	switch(user_viewing){
	case WELCOME:
		return handle_welcome(response_num);
	case MENU:
		return handle_menu(response_num);
	case SETUP:
		return handle_setup(response_num);
	default:
		return user_viewing;
	}
}

Status handle_welcome(unsigned int response)
{
	printf("handling response to welcome page\n");
	switch(response){
		case 1:
			return handle_setup(response);
		case 2:
			/* allow user to enter the file name in the schedule/ directory to import */
			break;
		case 3:
			exit(0);
		default:
			return WELCOME;
	}
	return WELCOME;
}

Status handle_menu(unsigned int response)
{
	printf("handling response to menu page\n");
	return MENU;
}

Status handle_setup(unsigned int response)
{
	printf("handling reponse to setup page\n");
	return SETUP;
}
