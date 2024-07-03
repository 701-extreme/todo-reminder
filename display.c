#include "display.h"

#define BUFSIZE (1024)

void display(Status user_viewing)
{
	switch(user_viewing)
	{
		case WELCOME:
			display_interface("./interfaces/welcome");
			break;
		case MENU:
			display_interface("./interfaces/menu");
			break;
		default:
			break;
	}
}

void display_interface(char* path)
{
	char buf[1024] = {0};
	FILE* fptr = fopen(path, "r");
	while(fgets(buf, BUFSIZE, fptr))
	{
		printf("%s", buf);
	}
	fclose(fptr);
}
