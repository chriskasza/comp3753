typedef struct row *record;

/* add a record */
int ds_add(char *command, char *path);

/* delete a record */
int ds_delete(char *command, char *path);

/* show records that match */
int ds_show(char *command, char *path);

/* update records that match */
int ds_set(char *command, char *path);