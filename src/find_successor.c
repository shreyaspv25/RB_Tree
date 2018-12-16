#include <rbtree_header.h>

NODE *find_successor( NODE *current )
{
	NODE *successor = NULL;
	if( current -> left_child != NULL )
	{
		successor = current -> left_child;
		while( successor -> right_child != NULL )
			successor = successor -> right_child;
	}
	else
	{
		successor = current -> right_child;
		while( successor -> left_child != NULL )
			successor = successor -> left_child;
	}
	return successor;
}
