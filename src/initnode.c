#include <rbtree_header.h>

/*
 * This function initializes the newly created node
 * with the specified value.
 * Parameters = 1
 * 		1 - Value to initialize
 * Return value:
 * 		Address of initialized node - on success
 * 		NULL - on failure
 */

NODE *initnode( int value )
{
	NODE *newnode = NULL;
	/* Requests memory for newnode */
	newnode = getnode();
	if( newnode == NULL )
		return NULL;
	/* Initialize value and pointers */
	newnode -> data = value;
	newnode -> left_child = NULL;
	newnode -> right_child = NULL;
	newnode -> parent = NULL;
	/* Initialize newnode's color to RED */
	newnode -> color = RED;
	return newnode;
}	
