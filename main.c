#include <sys/stat.h>
#include <errno.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

#include "display.h"
#include "input_helper.h"

#define INPUT_MAX (1024)

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
		nfiles = choose_files(filelist);
		if(nfiles<1)
			user_viewing = WELCOME;
		else
			user_viewing = MENU;
		closedir(schedules);
	}
	else if (errno==ENOENT) // Directory does not exist
	{
		printf("Directory does not exist, creating one\n");
		user_viewing = WELCOME;
		mkdir("schedules", 0755);
	}
	else
	{
		printf("Failed to operate opendir()\n");
		exit(1);
	}
	
	char* input = (char*)malloc(sizeof(char)*INPUT_MAX);
	// Loop to read user commands
	display(user_viewing);
	while(1)
	{
		get_command(input, user_viewing);
		printf("your input is: %s\n", input);
	}
	free(input);
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
	int n = scandir("./schedules", &filelist, ext_filter, alphasort);
	return n;
}

void free_filelist(struct dirent** filelist, int n)
{
	while(n--)
		free(filelist[n]);
	free(filelist);
}
