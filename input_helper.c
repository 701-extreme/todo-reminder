#include "input_helper.h"

int invalid_input(char* input, int len, Status user_viewing)
{
	int numbercmd = (int)strtol(input, NULL, 10);
	char str[INPUT_MAX]={0};
	sprintf(str, "%d", numbercmd);
	int is_num = 0;
	if(strcmp(str, input)==0)
		is_num = 1;	
	switch(user_viewing)
	{
		case WELCOME:
			if((numbercmd<1||numbercmd>3) || !is_num)
				return 1;
		case MENU:
			if((numbercmd<1||numbercmd>5) || !is_num)
				return 1;
		default:
			return 0;
	}
}

void get_command(char* line, Status user_viewing)
{
	char input[INPUT_MAX] = {0};
	int len=0;
	printf("COMMAND > ");
	if(!fgets(input, INPUT_MAX, stdin))
	{
		printf("fgets error!\n");
		exit(1);
	}
	len = strlen(input)-1;
	input[len] = 0;
	while(invalid_input(input, len, user_viewing))
	{
		printf("%s is an invalid command, Please try again\nCOMMAND > ", input);
			if(!fgets(input, INPUT_MAX, stdin))
			{
				printf("fgets error!\n");
				exit(1);
			}
			len = strlen(input)-1;
			input[len]=0;
			printf("You have entered: %s\n", input);
	}
	strcpy(line, input);
}
