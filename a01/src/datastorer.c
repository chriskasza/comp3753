/**
 * Handles adding data provided by the user.
 *
 * Format: ADD <name>; <email>; <year>; <country>
 */

#include <stdio.h>

struct row
{
    char name[1000], email[1000], country[1000];
    int year;
};

/**
 * function to add a new record.
 *
 */
int ds_add(char *command, char *path)
{
    FILE *ptr_datafile;
    struct row new_row;

    sscanf(command, "%s %s; %s; %d; %s", new_row.name, new_row.email, new_row.year, new_row.country);

    // printf("name = %s; email = %s; year = %d; country = %s\n", new_row.name, new_row.email, new_row.year, new_row.country );

    ptr_datafile = fopen("pseudodb.bin", "wb");

    if (!ptr_datafile)
    {
        printf("Unable to open file!");
        return 1;
    }
    fwrite(&new_row, sizeof(struct row), 1, ptr_datafile);
    fclose(ptr_datafile);
    return 0;
}

/**
 * function to delete a record
 */
int ds_delete(char *command, char *path) {

}