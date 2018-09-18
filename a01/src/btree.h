/**
 * Header file for the btree data structure.
 *
 * Code guidance from http://www.cs.yale.edu/homes/aspnes/pinewiki/BTrees.html
 */

typedef struct btNode *btree;

bTree reate(void);

void bt_destroy(bTree t);

/* return nonzero if key is present in tree */
int btSearch(bTree t, int key);

/* insert a new element into a tree */
void btInsert(bTree t, int key);

/* print all keys of the tree in order */
void btPrintKeys(bTree t);