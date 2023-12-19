/*
	18.12.2023
aesh.c by Tarık Çelik

This software is relased under bsd-3 clause
license.

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {

bool exit = false;
char command[50];
char dir[50];
char file[50];
char exc[50];

printf("\nAetherShell 0.1 by Tarık Çelik \n");
printf("Write 'help' for help \n");

while (exit == false) {

	printf("* ");
	scanf("%s", command);

	if (strcmp(command, "clear") == 0) {
	printf("\e[1;1H\e[2J");
		}

	if (strcmp(command, "exit") == 0) {
	exit = true;
		}

	if (strcmp(command, "cd") == 0) {
	scanf("%s", dir);
	chdir(dir);
	}

	if (strcmp(command, "ls") == 0) {
	 DIR *dir;
	 struct dirent *entry;
	 dir = opendir(".");
	 while ((entry = readdir(dir)) != NULL) {
         printf("%s\n", entry->d_name);
	}
	 closedir(dir);
	}

	if (strcmp(command, "mkdir") == 0) {
	scanf("%s",dir);
	mkdir(dir, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	}

	if (strcmp(command, "rmdir") == 0) {
		scanf("%s", dir);
		rmdir(dir);
	}

	if (strcmp(command, "touch") == 0) {
		scanf("%s", file);
		FILE* File = fopen(file, "w");
		fclose(File);
	}

	if (strcmp(command, "rm") == 0) {
                scanf("%s", file);
                remove(file);
	}

	if (strcmp(command, "exec") == 0) {
		fgets(exc, sizeof(exc), stdin);
		system(exc);
	}
	if (strcmp(command, "help") == 0) {

		printf("\nAetherShell 0.1 by Tarık Çelik");
		printf("\n * help for that menu");
		printf("\n * clear for clearing the screen");
		printf("\n * exit for exiting");
		printf("\n * cd <path>for entering to a directory");
		printf("\n * ls for listing contents of current directory");
		printf("\n * mkdir <dirname> for creating a directory");
		printf("\n * rmdir <dirname> for removing a directory");
		printf("\n * touch <filename> for creating files");
		printf("\n * rm <filename> for removing a file");
		printf("\n * exec <command> for executing a command");
                printf("\n \n"); // we need that line for proper output
		}
	}
}
