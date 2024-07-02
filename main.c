#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE (1024)

int main(int argc, char** argv)
{
	char buf[BUFSIZE] = {0};
	FILE* fptr=fopen("interfaces/menu", "r");
	while(fgets(buf, BUFSIZE, fptr))
	{
		printf("%s", buf);
	}
	fclose(fptr);
	return 0;
}
