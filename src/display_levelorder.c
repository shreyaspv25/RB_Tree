#include <rbtree_header.h>

/*
 * This function displays the level traversal 
 * sequence using queue list.
 * Parameters = 1
 * 		1 - Address of root node
 * Return value:
 * 		0 - Success
 *		1 - Failure
 */

int display_levelorder( NODE **root )
{
	/* Head pointer for queue list */
	QUEUE_NODE *head = NULL;
	NODE *curnode = NULL;
	int ret = -1;
	int curlevelnc = 0; /* Current level node count */
	int level = 0; /* Level number */
	
	curnode = (*root);
	/* Push the root node to queue */
	ret = push_back( &head, curnode );
	/* Until queue list becomes empty iterate */
	while( head != NULL )
	{
		/* Get the current queue list size */
		curlevelnc = get_size( head );
		/* Print level number */
		printf( "%sL(%d): %s", COLOR_YELLOW, level, COLOR_BLACK );

		/* Iterate until all nodes in current level are visited */
		while( curlevelnc != 0 )
		{
			/* Pop the node from queue */
			curnode = pop_front( &head );
			/* Print the node's content */
			if( curnode -> color == RED )
				printf( "%s%d%s ", COLOR_RED, curnode -> data, COLOR_BLACK );
			else
				printf( "%d ", curnode -> data );
			if( curnode -> left_child != NULL )
			{
				/* Push the node's left child to queue */
				ret = push_back( &head, curnode -> left_child );
				if( ret )
					return EXIT_FAILURE;
			}
			if( curnode -> right_child != NULL )
			{
				/* Push the node's right child to queue */
				ret = push_back( &head, curnode -> right_child );
				if( ret )
					return EXIT_FAILURE;
			}
			curlevelnc--;
		}
		printf( "\n" );
		level++;
	}
	return EXIT_SUCCESS;
}
