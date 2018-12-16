#include <rbtree_header.h>

/*
 * This function allocates memory for the requested node
 * Parameters = 0
 * Return value:
 * 		Address of allocated node - on success
 * 		NULL - on failure
 */

NODE *getnode( void )
{
	NODE *newnode = NULL;
	newnode = (NODE *)malloc( sizeof(struct node) );
	if( newnode == NULL )
		return NULL;
	return newnode;
}	
