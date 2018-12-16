#include <rbtree_header.h>

/*
 * This function inserts the given value into the tree
 * Parameters = 2
 * 		1 - Address of root node
 * 		2 - Value to insert into tree
 * Return value:
 * 		0 - on successful insertion
 * 		1 - on failure
 */

int insert( NODE **root, int value )
{
	NODE *newnode = NULL;
	NODE *curnode = NULL;
	
	/* Parent's sibling node */
	NODE *unclenode = NULL;
	int ret = -1;
	
	/* Initializes the newnode with the given value */
	newnode = initnode( value );
	if( newnode == NULL )
		return EXIT_FAILURE;
	
	/* If inserting the first node into the tree
	 * then that node should be the root node
	 */
	if( (*root) == NULL )
	{
		setcolor( newnode, BLACK );
		(*root) = newnode;
		return EXIT_SUCCESS;
	}
	
	/* If not the first node then insert_into_tree() inserts the
	 * newnode into the tree at required position as in a binary
	 * search tree without restructuring the tree
	 */
	ret = insert_into_tree( root, newnode );
	if( ret )
		return EXIT_FAILURE;
	
	curnode = newnode;
	/* Double RED Problem resolution */
	while( curnode -> parent != NULL && getcolor( curnode -> parent ) == RED )
	{
		/* Check whether the node's parent is the left child or right child */
		if( curnode -> parent == curnode -> parent -> parent -> left_child )
		{
			/* Left child handling */
			/* Extract unclenode i.e parent's siblingnode */
			unclenode = curnode -> parent -> parent -> right_child;
			/* Check whether unclenode is RED or BLACK */
			if( unclenode != NULL && getcolor( unclenode ) == RED )
			{
				/* If unclenode is RED, recoloring is done */
				/* Color the parentnode BLACK */
				setcolor( curnode -> parent, BLACK );
				/* Color the unclenode BLACK */
				setcolor( unclenode, BLACK );
				/* Color the grandparentnode RED */
				setcolor( unclenode -> parent, RED );
				/* Change curnode to grandparent to check for recoloring */
				curnode = curnode -> parent -> parent;
			}
			else
			{
				/* If unclenode is not RED, rotation is done then recoloring */
				/* Check whether curnode is right child or not */
				if( curnode == curnode -> parent -> right_child )
				{
					/* If curnode is right child
					 * rotation is performed about the parent
					 * Case : L2A 
					 */
					curnode = curnode -> parent;
					/* Left rotate about parent */
					leftrotate( root, curnode );
				}
				/* Case : L2B */
				/* Recoloring and Right rotation is performed */
				/* Color the parentnode BLACK */
				setcolor( curnode -> parent, BLACK );
				/* Color the grandparentnode RED */
				setcolor( curnode -> parent -> parent, RED );
				/* Right rotate about the grandparent */
				rightrotate( root, curnode -> parent -> parent );
			}
		}
		else
		{
			/* Extract unclenode i.e parent's siblingnode */
			unclenode = curnode -> parent -> parent -> left_child;
			/* Check whether unclenode is RED or BLACK */
			if( unclenode != NULL && getcolor( unclenode ) == RED )
			{
				/* If unclenode is RED, recoloring is done */
				/* Color the parentnode BLACK */
				setcolor( curnode -> parent, BLACK );
				/* Color the unclenode BLACK */
				setcolor( unclenode, BLACK );
				/* Color the grandparentnode RED */
				setcolor( unclenode -> parent, RED );
				/* Change curnode to grandparent to check for recoloring */
				curnode = curnode -> parent -> parent;
			}
			else
			{
				/* If unclenode is not RED, rotation is done then recoloring */
				/* Check whether curnode is left child or not */
				if( curnode == curnode -> parent -> left_child )
				{
					/* If curnode is left child
					 * rotation is performed about the parent
					 * Case : R2A
					 */
					curnode = curnode -> parent;
					/* Right rotate about parent */
					rightrotate( root, curnode );
				}
				/* Case : R2B */
				/* Recoloring and Left rotation is performed */
				/* Color the parentnode BLACK */
				setcolor( curnode -> parent, BLACK );
				/* Color the grandparentnode RED */
				setcolor( curnode -> parent -> parent, RED );
				/* Left rotate about the grandparent */
				leftrotate( root, curnode -> parent -> parent );
			}
		}
	}// end while
	
	/* After rotation and recoloring root color
	 * might have changed to RED
	 * So recolor it to BLACK
	 */
	setcolor( (*root), BLACK );
	return EXIT_SUCCESS;
}
