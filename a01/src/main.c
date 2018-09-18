/**
 *
 * The main file for this simple data storage application.
 *
 */
#include <sys/stat.h>
#include <sys/types.h>
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datastorer.h"

extern int errno;

/**
 * Prints out help text for using the program.
 */
void print_help()
{
    printf("Usage: kasza_a01 [DIR]\n");
}

/**
 * Method to initialize the directory where the
 * files are stored.
 * If the directory doesn't exist, it will be created.
 * If the path is not a directory or if the directory
 * is inaccessible, the method will exit with a status of 0.
 * Otherwise, a success will return 1.
 */
int init_dir(const char *path)
{
    int e;
    struct stat path_stat;
    e = stat(path, &path_stat);
    if (e == 0)
    {
        if (S_ISDIR(path_stat.st_mode))
        {
            return 1;
        }
        else
        {
            printf("%s is not a directory.\n", path);
            print_help();
            return 0;
        }
    }
    else
    {
        if (errno = ENOENT)
        {
            e = mkdir(path, S_IRWXU);
            if (e != 0)
            {
                printf("unable to create %s; errno=%d\n", path, errno);
                return 0;
            }
            else
            {
                return 1;
            }
        }
        else
        {
            printf("unable to read %s; errno=%d\n", path, errno);
            return 0;
        }
    }
}

/**
 * Displays the user prompt.
 * Parses the user's input.
 * Hands off user's request to proper function.
 */
void prompt_loop(const char *path)
{
    char command[255], cmd_type[25];
    // (char*)malloc(255 * sizeof(char));

    while (1)
    {
        printf("> ");

        // scanf("%s", command);
        fgets(command, 255, stdin);

        if ((strlen(command) > 0) && (command[strlen(command) - 1] == '\n'))
            command[strlen(command) - 1] = '\0';

        for (int i = 0; command[i]; i++)
        {
            if (command[i] == ' ')
                break;
            cmd_type[i] = tolower(command[i]);
        }

        if (strcmp(cmd_type, "add") == 0)
        {
            // printf("gonna add things\n");
            ds_add(command, path);
        }
        else if (strcmp(cmd_type, "show") == 0)
        {
            printf("gonna show things\n");
            // show(command, path);
        }
        else if (strcmp(cmd_type, "delete") == 0)
        {
            printf("gonna delete things\n");
            // delete(command, path);
        }
        else if (strcmp(cmd_type, "set") == 0)
        {
            printf("gonna set things\n");
            // set(command, path);
        }
        else if (strcmp(cmd_type, "quit") == 0)
        {
            return;
        }
        else
        {
            printf("\"%s\" is not a recognized command.\n", cmd_type);
            printf("Valid commands are ADD, SHOW, DELETE, SET, and QUIT.\n");
        }

        memset(cmd_type, 0, sizeof(cmd_type));
        memset(command, 0, sizeof(command));
    }
}

/**
 * main
 */
int main(int argc, char *argv[])
{
    int e;
    char dir[255]; // directory where files are stored

    // set dir if provided
    // otherwise, use /tmp/kasza_a1
    if (argc > 1)
    {
        strcpy(dir, argv[1]);
    }
    else
    {
        strcpy(dir, "/tmp/kasza_a1");
    }

    if (init_dir(dir) == 0)
    {
        return EXIT_FAILURE;
    }

    prompt_loop(dir);

    return EXIT_SUCCESS;
}