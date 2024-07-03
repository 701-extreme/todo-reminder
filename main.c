#include "display.h"
#include <dirent.h>
#include <errno.h>
#include <ctype.h>
#include <sys/stat.h>

#define INPUT_MAX (1024)

typedef enum status
{
	WELCOME,
	MENU,
	SETUP,
	IMPORT,
	ADD,
	REMOVE
}Status;

int invalid_input(char* input, int len, Status user_viewing)
{
	switch(user_viewing)
	{
		case WELCOME:
			if(atoi(input)<1||atoi(input)>3)
				return 1;
		case MENU:
			if(atoi(input)<1||atoi(input)>6)
				return 1;
		default:
			return 0;
	}
}

int choose_files(struct dirent** filelist);
static int ext_filter(const struct dirent* file); 
void free_filelist(struct dirent** filelist, int len);

int main(int argc, char** argv)
{
	// Determine the starting interface
	Status user_viewing = 0;
	struct dirent** filelist = 0;
	int nfiles = 0;
	DIR* schedules = opendir("schedules");
	if(schedules)
	{
		printf("Directory exists\n");
		user_viewing = MENU;
		nfiles = choose_files(filelist);
		closedir(schedules);
	}
	else if (errno==ENOENT) // Directory does not exist
	{
		printf("Directory does not exist, creating one\n");
		user_viewing=WELCOME;
		mkdir("schedules", 0755);
	}
	else
	{
		printf("Failed to operate opendir()\n");
		exit(1);
	}
	
	// Loop to read user commands
	char input[INPUT_MAX] = {0};
	char* line;
	int len = 0;
	while(1)
	{
		display_menu();
		// handle user input
		printf("Enter your option: ");
		line = fgets(input, INPUT_MAX, stdin);
		len = strlen(input)-1;
		input[len]=0;
		printf("You have entered: %s\n", line);
		while(invalid_input(input, len, user_viewing))
		{
			printf("%s is an invalid command, Please try again: ", input);
			line = fgets(input, INPUT_MAX, stdin);
			len = strlen(input)-1;
			input[len]=0;
		}
	}
	free_filelist(filelist, nfiles);
	return 0;
}

/* Only file returned true in this condition will be passed */
static int ext_filter(const struct dirent* dir)
{
     if(!dir)
       return 0;

     if(dir->d_type == DT_REG) { /* only deal with regular file */
         const char *ext = strrchr(dir->d_name,'.');
         if((!ext) || (ext == dir->d_name))
           	return 0;
         else {
           	if(strcmp(ext, ".reminder") == 0)
             	return 1;
        	}
	}

     	return 0;
}

/* Choose the file with .reminder extension, return the number of files matched */
int choose_files(struct dirent** filelist)
{
	int n = scandir(".", &filelist, ext_filter, alphasort);
	return n;
}

void free_filelist(struct dirent** filelist, int n)
{
	while(n--)
		free(filelist[n]);
	free(filelist);
}
