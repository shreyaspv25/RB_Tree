#include <rbtree_header.h>

/*
 * This function retrieves the color of the requested node.
 * Parameters = 1
 * 		1 - Address of node
 * Return value:
 * 		Returns the color either RED or BLACK
 */

NODE_COLOR getcolor( NODE *node )
{
	/* If a NULL Leaf node return BLACK */
	if( node == NULL )
		return BLACK;
	/* Non-NULL Leaf node */
	return node -> color;
}

/*
 * This function sets the color of the specified node
 * Parameters = 2
 * 		1 - Address of node
 *		2 - Color value
 * Return value:
		Nothing
 */

void setcolor( NODE *node, NODE_COLOR color )
{
	/* If NULL Leaf node */
	if( node == NULL )
		return;
	/* Non-NULL Leaf Node */
	node -> color = color;
}
