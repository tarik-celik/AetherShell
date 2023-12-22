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

bool *exit = (bool *) malloc (sizeof(bool));
*exit = false;
char *command = (char *) malloc (10);
char *dir = (char *) malloc (500);
char *file = (char *) malloc (500);
char *exc = (char *) malloc (500);
char *cwd = (char *) malloc (500);

printf("\nAetherShell 0.3 by Tarık Çelik \n");
printf("Write 'help' for help \n");

while (*exit == false) {

	printf("* ");
	scanf("%s", command);

	if (strcmp(command, "clear") == 0) {
	printf("\e[1;1H\e[2J");
		}

	if (strcmp(command, "exit") == 0) {
	*exit = true;
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
		scanf(" %[^\n]", exc);
		system(exc);
	}

	if (strcmp(command, "mv") == 0) {
		scanf("%s", file);
		scanf("%s", dir);
		rename(file, dir);
	}

	if (strcmp(command, "pwd") == 0) {
		getcwd(cwd, 500);
		printf("%s\n", cwd);

	}

	if (strcmp(command, "cp") == 0) {
            char *sourcefile = (char *)malloc(100);
            char *destinationfile = (char *)malloc(100);
            scanf("%s %s", sourcefile, destinationfile);
	    FILE *sourceFile = fopen(sourcefile, "rb");
            FILE *destFile = fopen(destinationfile, "wb");
	    if (sourceFile == NULL || destFile == NULL) {
                printf("Error: Unable to open files for copying.\n");
            } else {
                char *buffer = (char *)malloc(1024);
                size_t bytesRead;

                while ((bytesRead = fread(buffer, 1, sizeof(buffer), sourceFile)) > 0) {
                    fwrite(buffer, 1, bytesRead, destFile);
                }

                free(buffer);
                fclose(sourceFile);
                fclose(destFile);
            }

            free(sourcefile);
            free(destinationfile);
        }
	if (strcmp(command, "calc") == 0) {
		float *num1 = (float *) malloc (sizeof(float));
		float *num2 = (float *) malloc (sizeof(float));
		float *num3 = (float *) malloc (sizeof(float));
		char *op = (char *) malloc (1);
		scanf("%f %c %f", num1, op, num2);
		if (*op == *"+") {
		*num3 = *num1 + *num2;
			}
		if (*op == *"-") {
		*num3 = *num1 - *num2;
			}
		if (*op == *"/" || *op == *":") {
		*num3 = *num1 / *num2;
			}
		if (*op == *"x" || *op == *"*") {
		*num3 = *num1 * *num2;
		}
		printf("%.3f", *num3);
		printf("\n");
		free(num1);
		free(num2);
		free(num3);
		free(op);
	}
	if (strcmp(command, "help") == 0) {

		printf("\nAetherShell 0.3 by Tarık Çelik");
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
		printf("\n * mv <filename> <location > for moving a file");
		printf("\n * cp <filename> <newfile> for moving a file");
		printf("\n * calc <operation> for calculating");
		printf("\n * pwd for seeing current directory");
                printf("\n \n"); // we need that line for proper output
		}
	}

free(exit);
free(command);
free(dir);
free(exc);
free(file);
free(cwd);
}
