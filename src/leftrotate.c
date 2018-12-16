#include <rbtree_header.h>

void leftrotate( NODE **root, NODE *cur )
{
	NODE *temp = NULL;
	temp = cur -> right_child;
	if( temp -> left_child != NULL)
		temp -> left_child -> parent = cur;
	temp -> parent = cur -> parent;
	if( cur -> parent == NULL )
		(*root) = temp;
	else if( cur == cur -> parent -> left_child )
		cur -> parent -> left_child = temp;
	else
		cur -> parent -> right_child = temp;
	cur -> right_child = temp -> left_child;
	temp -> left_child = cur;
	cur -> parent = temp;
}
