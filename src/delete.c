#include <rbtree_header.h>

int delete( NODE **root, int value )
{
	NODE *delnode = NULL;
	NODE *tempnode = NULL;
	NODE *curnode = NULL;

	/* search the address of the node to be deleted */
	delnode = search( root, value );
	if( delnode == NULL )
		return EXIT_FAILURE;
	
	
	if( delnode -> left_child == NULL && delnode -> right_child == NULL )
		tempnode = delnode;
	else
	{
		tempnode = find_successor( delnode );
		delnode -> data = tempnode -> data;
	}

	if( tempnode == (*root) )
	{
		(*root) = NULL;
		free( tempnode );
		return EXIT_SUCCESS;
	}
	
	if( getcolor( tempnode ) == RED || getcolor( tempnode -> left_child ) == RED 
								|| getcolor( tempnode -> right_child ) == RED )
	{
		if( tempnode -> left_child != NULL )
			curnode = tempnode -> left_child;
		else
			curnode = tempnode -> right_child;

		if( tempnode == tempnode -> parent -> left_child )
		{
			tempnode -> parent -> left_child = curnode;
			if( curnode != NULL )
			{
				curnode -> parent = tempnode -> parent;
				setcolor( curnode, BLACK );
			}
			free( tempnode );
			tempnode = NULL;
		}
		else
		{
			tempnode -> parent -> right_child = curnode;
			if( curnode != NULL )
			{
				curnode -> parent = tempnode -> parent;
				setcolor( curnode, BLACK );
			}
			free( tempnode );
			tempnode = NULL;
		}
	}
	else
		reform_tree( root, tempnode );
	return EXIT_SUCCESS;
}
