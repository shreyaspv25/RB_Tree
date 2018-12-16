#include <rbtree_header.h>

void reform_tree( NODE **root, NODE *node )
{
	NODE *siblingnode = NULL;
	NODE *parentnode = NULL;
	NODE *curnode = node;
	setcolor( curnode, DOUBLE_BLACK );
	while( curnode != (*root) && getcolor( curnode ) == DOUBLE_BLACK )
	{
		parentnode = curnode -> parent;
		if( curnode == parentnode -> left_child )
		{
			//left child handling
			siblingnode = parentnode -> right_child;
			if( getcolor( siblingnode ) == RED )
			{
				setcolor( siblingnode, BLACK );//recoloring the sibling black
				setcolor( parentnode, RED ); //recoloring the parent red
				leftrotate( root, parentnode ); //left rotate about the parent
			}
			else
			{
				if( getcolor( siblingnode -> left_child ) == BLACK && getcolor( siblingnode -> right_child ) == BLACK )
				{
				/*	if both child nodes of sibling are black then color the sibling 
					i.e parent of child node as RED	*/
					setcolor( siblingnode, RED );
					if( getcolor( parentnode ) == RED )
						setcolor( parentnode, BLACK );
					else
						setcolor( parentnode, DOUBLE_BLACK );
					curnode = parentnode;
				}
				else
				{
					if( getcolor( siblingnode -> right_child ) == BLACK )
					{
						//recoloring the near nephew black
						setcolor( siblingnode -> left_child, BLACK );
						//recolor the sibling red
						setcolor( siblingnode, RED );
						rightrotate( root, siblingnode ); //right rotate about the sibling
						//sibling is given color of parent
						siblingnode = parentnode -> right_child; 
					}
					setcolor( siblingnode, getcolor( parentnode ) );
					//recolor the parent BLACK
					setcolor( parentnode, BLACK );
					//recolor the far nephew BLACK
					setcolor( siblingnode -> right_child, BLACK );
					//left rotate about the parent
					leftrotate( root, parentnode );
					break;
				}
			}
		}
		else
		{
			//right child handling
			siblingnode = parentnode -> left_child;
			if( getcolor( siblingnode ) == RED )
			{
				setcolor( siblingnode, BLACK ); //recoloring the sibling black
				setcolor( parentnode, RED ); //recoloring the parent red
				rightrotate( root, parentnode ); //right rotate about the parent
			}
			else
			{
				if( getcolor( siblingnode -> left_child ) == BLACK && getcolor( siblingnode -> right_child ) == BLACK )
				{
				/*	if both child nodes of sibling are black then color the sibling 
					i.e parent of child node as RED	*/
					setcolor( siblingnode, RED );
					if( getcolor( parentnode ) == RED )
						setcolor( parentnode, BLACK );
					else
						setcolor( parentnode, DOUBLE_BLACK );
					curnode = parentnode;
				}
				else
				{
					if( getcolor( siblingnode -> left_child ) == BLACK )
					{
						//recoloring the near nephew black
						setcolor( siblingnode -> right_child, BLACK );
						//recolor the sibling red
						setcolor( siblingnode, RED );
						leftrotate( root, siblingnode ); //left rotate about the sibling
						//sibling is given color of parent
						siblingnode = parentnode -> left_child; 
					}
					setcolor( siblingnode, getcolor( parentnode ) );
					//recolor the parent BLACK
					setcolor( parentnode, BLACK );
					//recolor the far nephew BLACK
					setcolor( siblingnode -> left_child, BLACK );
					//left rotate about the parent
					rightrotate( root, parentnode );
					break;
				}
			}
		}
	}//end of while

	if( node == node -> parent -> left_child )
		node -> parent -> left_child = NULL;
	else
		node -> parent -> right_child = NULL;
	free( node );
	node = NULL;
	setcolor( (*root), BLACK );
}
