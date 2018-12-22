#include <rbtree_header.h>

/*
 * This function identifies and returns the 
 * successor node of the requesting node.
 * Parameters = 1
 * 		1 - Address of requesting node
 * Return value:
 * 		Address of successor node
 */

NODE *find_successor( NODE *current )
{
	NODE *successor = NULL;
	/* Check whether left child exists */
	if( current -> left_child != NULL )
	{
		/* Retrieve the maximum element from left subtree */
		successor = current -> left_child;
		/* Maximum element can be found at the rightmost side */
		while( successor -> right_child != NULL )
			successor = successor -> right_child;
	}
	else
	{
		/* Retrieve the minimum element from right subtree */
		successor = current -> right_child;
		/* Minimum element can be found at the leftmost side */
		while( successor -> left_child != NULL )
			successor = successor -> left_child;
	}
	return successor;
}
