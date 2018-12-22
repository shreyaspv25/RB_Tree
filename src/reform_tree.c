#include <rbtree_header.h>

/*
 * This function restructures the tree by rotations or recoloring.
 * Parameters = 2
 * 		1 - Address of root node
 *		2 - Address of child node of deleted node
 * Return value:
 * 		Nothing
 */

void reform_tree( NODE **root, NODE *node )
{
	NODE *siblingnode = NULL;
	NODE *parentnode = NULL;
	NODE *curnode = node;
	
	/* Set color of the child of the deleted node as DOUBLE BLACK */
	setcolor( curnode, DOUBLE_BLACK );
	
	/* Check whether the child of the deleted node is DOUBLE BLACK
 	 * and is not a ROOT node
	 * Child of the deleted node is "curnode"
	 */
	while( curnode != (*root) && getcolor( curnode ) == DOUBLE_BLACK )
	{
		/* Identify the parent node */
		parentnode = curnode -> parent;
		/* Check whether the curnode is a left child */
		if( curnode == parentnode -> left_child )
		{
			/* Retrieve the sibling of the curnode */
			siblingnode = parentnode -> right_child;
			/* Check the color of the sibling node */
			if( getcolor( siblingnode ) == RED )
			{
				/* If siblingnode color is RED */
				/* Recolor the sibling BLACK */
				setcolor( siblingnode, BLACK );
				/* Recolor the parent RED */
				setcolor( parentnode, RED );
				/* Left rotate about parent */
				leftrotate( root, parentnode );
			}
			else
			{
				/* If sibling color is BLACK check for sibling's left child and sibling's right child color as BLACK */
				if( getcolor( siblingnode -> left_child ) == BLACK && getcolor( siblingnode -> right_child ) == BLACK )
				{
					/* Recolor the sibling RED */
					setcolor( siblingnode, RED );
					/* Check whether parent color is RED */
					if( getcolor( parentnode ) == RED )
					/* Recolor the parent BLACK */
						setcolor( parentnode, BLACK );
					else
					/* Recolor the parent DOUBLE BLACK */
						setcolor( parentnode, DOUBLE_BLACK );
					/* Set curnode as parentnode to check above */
					curnode = parentnode;
				}
				else
				{
					/* Check if sibling's right child is BLACK */
					if( getcolor( siblingnode -> right_child ) == BLACK )
					{
						/* Recolor the near nephew BLACK */
						setcolor( siblingnode -> left_child, BLACK );
						/* Recolor the sibling RED */
						setcolor( siblingnode, RED );
						/* Right rotate about sibling node */
						rightrotate( root, siblingnode );
						/* Assign new sibling as parent's right child */
						siblingnode = parentnode -> right_child; 
					}
					/* Recolor sibling to parent's color */
					setcolor( siblingnode, getcolor( parentnode ) );
					/* Recolor the parent BLACK */
					setcolor( parentnode, BLACK );
					/* Recolor the far nephew BLACK */
					setcolor( siblingnode -> right_child, BLACK );
					/* Left rotate about parent */
					leftrotate( root, parentnode );
					break;
				}
			}
		}
		else
		{
			/* Retrieve the sibling of the curnode */
			siblingnode = parentnode -> left_child;
			/* Check the color of the sibling node */
			if( getcolor( siblingnode ) == RED )
			{
				/* If siblingnode color is RED */
				/* Recolor the sibling BLACK */
				setcolor( siblingnode, BLACK );
				/* Recolor the parent RED */
				setcolor( parentnode, RED );
				/* Right rotate about parent */
				rightrotate( root, parentnode );
			}
			else
			{
				/* If sibling color is BLACK check for sibling's left child and sibling's right child color as BLACK */
				if( getcolor( siblingnode -> left_child ) == BLACK && getcolor( siblingnode -> right_child ) == BLACK )
				{
					/* Recolor the sibling RED */
					setcolor( siblingnode, RED );
					/* Check whether parent color is RED */
					if( getcolor( parentnode ) == RED )
					/* Recolor the parent BLACK */
						setcolor( parentnode, BLACK );
					else
					/* Recolor the parent DOUBLE BLACK */
						setcolor( parentnode, DOUBLE_BLACK );
					/* Set curnode as parentnode to check above */
					curnode = parentnode;
				}
				else
				{
					/* Check if sibling's left child is BLACK */
					if( getcolor( siblingnode -> left_child ) == BLACK )
					{
						/* Recolor the near nephew BLACK */
						setcolor( siblingnode -> right_child, BLACK );
						/* Recolor the sibling RED */
						setcolor( siblingnode, RED );
						/* Left rotate about sibling node */
						leftrotate( root, siblingnode );
						/* Assign new sibling as parent's left child */
						siblingnode = parentnode -> left_child; 
					}
					/* Recolor sibling to parent's color */
					setcolor( siblingnode, getcolor( parentnode ) );
					/* Recolor the parent BLACK */
					setcolor( parentnode, BLACK );
					/* Recolor the far nephew BLACK */
					setcolor( siblingnode -> left_child, BLACK );
					/* Right rotate about parent */
					rightrotate( root, parentnode );
					break;
				}
			}
		}
	}//end of while
	
	/* Check if the node to be deleted is a left child or right child */
	if( node == node -> parent -> left_child )
	/* Remove the left link to that node */
		node -> parent -> left_child = NULL;
	else
	/* Remove the right link to that node */
		node -> parent -> right_child = NULL;
	/* Deallocating memory */
	free( node );
	node = NULL;

	/* Recoloring would have made the ROOT node
	 * either RED or DOUBLE BLACK, so recolor
	 * the ROOT node to BLACK
	 */
	setcolor( (*root), BLACK );
}
