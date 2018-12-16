#include <rbtree_header.h>

/*
 * This function inserts the newly initialized node
 * into the tree as in BST without restructuring.
 * Parameters = 2
 * 		1 - Address of ROOT node
 *		2 - Address of newly initialized node
 * Return value:
 * 		0 - on success
 * 		1 - on failure
 */

int insert_into_tree( NODE **root, NODE *node )
{
	NODE *temp = NULL;
	NODE *prev = NULL;
	if( (*root) == NULL )
		return EXIT_FAILURE;
	temp = *root;
	/* Traverse the tree to find exact position */
	while( temp != NULL )
	{
		prev = temp;
		if( node -> data < temp -> data )
		/* Traverse the left subtree */
			temp = temp -> left_child;
		else if( node -> data >= temp -> data )
		/* Traverse the right subtree */
			temp = temp -> right_child;
		else
			break;
	}
	temp = prev;
	if( node -> data < temp -> data )
	/* Attach as left child */
		temp -> left_child = node;
	else if( node -> data >= temp -> data )
	/* Attach as right child */
		temp -> right_child = node;
	/* Update parent node value */
	node -> parent = temp;
	return EXIT_SUCCESS;
}
