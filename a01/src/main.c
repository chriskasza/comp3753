/**
 *
 * The main file for this simple data storage application.
 *
 */
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

extern int errno;

/**
 * Prints out help text for using the program.
 */
void print_help()
{
    print('Usage: kasza_a01 [DIR]\n');
}

/**
 * Method to initialize the directory where the
 * files are stored.
 * If the directory doesn't exist, it will be created.
 * If the path is not a directory or if the directory
 * is inaccessible, the method will kill the program.
 */
void init_dir(const char *path)
{
    int e;
    struct stat path_stat;
    e = stat(path, &path_stat);
    if (e == 0)
    {
        if (S_ISDIR(path_stat.st_mode))
        {
            return;
        }
        else
        {
            printf("%s is not directory.\n", path);
            print_help();
            EXIT_FAILURE;
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
                EXIT_FAILURE;
            }
            else
            {
                return;
            }
        }
        else
        {
            printf("unable to read %s; errno=%d\n", path, errno);
            EXIT_FAILURE;
        }
    }
}

/**
 * Displays the user prompt.
 * Parses the user's input.
 * Hands off user's request to proper function.
 */
void prompt_loop() {
    printf('> ');

}

/**
 * main
 */
int main(int argc, char *argv[])
{
    int e;
    char *dir; // directory where files are stored

    // set dir if provided
    // otherwise, use /tmp/kasza_a1
    if (argc > 1)
    {
        dir = argv[1];
    }
    else
    {
        dir = '/tmp/kasza_a1';
    }

    init_dir(dir);

    EXIT_SUCCESS;
}