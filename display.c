#include "display.h"

#define BUFSIZE (1024)

void display_menu()
{
	char buf[1024] = {0};
	FILE* fptr = fopen("./interfaces/menu", "r");
	while(fgets(buf, BUFSIZE, fptr))
	{
		printf("%s", buf);
	}
	fclose(fptr);
}
