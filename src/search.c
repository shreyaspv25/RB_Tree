#include <rbtree_header.h>

/*
 * This function searches the tree to find
 * the specified key recursively.
 * Parameters = 2
 * 		1 - Address of root node
 * 		2 - Key to search
 * Return value:
 * 		Address of node where key is found - Success
 *		NULL - If key is not found (Failure)
 */

NODE* search( NODE **root, int key )
{
	NODE *ret = NULL;
	/* NULL Leaf found */
	if( (*root) == NULL )
		return NULL;
	/* Non-NULL Leaf with key found */
	if( (*root) -> data == key )
		return (*root);
	else if( key > ( (*root) -> data ) )
	/* Recursively search the right subtree */
		ret = search( &( (*root) -> right_child ), key );
	else
	/* Recursively search the left subtree */
		ret = search( &( (*root) -> left_child ), key );
	return ret;
}
