#include <rbtree_header.h>

/*
 * This function deletes a given node value from the tree.
 * Parameters = 2
 * 		1 - Address of root node
 *		2 - Value to be deleted
 * Return value:
 * 		0 - Success
 * 		1 - Failure
 */

int delete( NODE **root, int value )
{
	NODE *delnode = NULL;
	NODE *tempnode = NULL;
	NODE *curnode = NULL;

	/* Search the address of the node to be deleted */
	delnode = search( root, value );
	if( delnode == NULL )
		return EXIT_FAILURE;
	
	/* Check whether node to be deleted has child nodes */
	if( delnode -> left_child == NULL && delnode -> right_child == NULL )
		tempnode = delnode;
	else
	{
		/* If child nodes exist, then find the successor of the node */
		tempnode = find_successor( delnode );
		/* Copy the successor node data */
		delnode -> data = tempnode -> data;
	}
	
	/* Check whether node to be deleted is a root node */
	if( tempnode == (*root) )
	{
		/* Delete root node */
		(*root) = NULL;
		/* Deallocate memory */
		free( tempnode );
		return EXIT_SUCCESS;
	}
	/* Check whether the color of the node to be deleted is RED and has either
	 * left child colored RED or right child colored RED
	 */
	if( getcolor( tempnode ) == RED || getcolor( tempnode -> left_child ) == RED 
								|| getcolor( tempnode -> right_child ) == RED )
	{
		/* Identify the child node of the node to be deleted */
		if( tempnode -> left_child != NULL )
			curnode = tempnode -> left_child;
		else
			curnode = tempnode -> right_child;

		/* Check whether the node to be deleted is left child or right child */
		if( tempnode == tempnode -> parent -> left_child )
		{
			/* Assign the child of deleted node to its place */
			tempnode -> parent -> left_child = curnode;
			if( curnode != NULL )
			{
				/* If child exists, update the parent */
				curnode -> parent = tempnode -> parent;
				/* Re-color it to BLACK */
				setcolor( curnode, BLACK );
			}
			/* Deallocate memory */
			free( tempnode );
			tempnode = NULL;
		}
		else
		{
			/* Assign the child of deleted node to its place */
			tempnode -> parent -> right_child = curnode;
			if( curnode != NULL )
			{
				/* If child exists, update the parent */
				curnode -> parent = tempnode -> parent;
				/* Re-color it to BLACK */
				setcolor( curnode, BLACK );
			}
			/* Deallocate memory */
			free( tempnode );
			tempnode = NULL;
		}
	}
	else
	/* If the node to be deleted is a BLACK node the re-structure the tree */
		reform_tree( root, tempnode );
	return EXIT_SUCCESS;
}
