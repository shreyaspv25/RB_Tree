#include <rbtree_header.h>

/*
 * This function displays the inorder traversal 
 * sequence using recursion.
 * Parameters = 1
 * 		1 - Address of root node
 * Return value:
 * 		Nothing
 */

void display_inorder( NODE **root )
{
	if( (*root) == NULL )
		return;
	/* Recursively traverse the left child */
	display_inorder( &( (*root) -> left_child ) );
	/* Check if node color is RED or BLACK */
	if( ( (*root) -> color ) == RED )
	/* Prints the RED nodes */
		printf( "%s%d%s ", COLOR_RED, (*root) -> data, COLOR_BLACK );
	else
	/* Prints the BLACK nodes */
		printf( "%d ", (*root) -> data );
	/* Recursively traverse the right child */
	display_inorder( &( (*root) -> right_child ) );
}
