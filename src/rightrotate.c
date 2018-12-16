#include <rbtree_header.h>

void rightrotate( NODE **root, NODE *cur )
{
	NODE *temp = NULL;
	temp = cur -> left_child;
	if( temp -> right_child != NULL)
		temp -> right_child -> parent = cur;
	temp -> parent = cur -> parent;
	if( cur -> parent == NULL )
		(*root) = temp;
	else if( cur == cur -> parent -> right_child )
		cur -> parent -> right_child = temp;
	else
		cur -> parent -> left_child = temp;
	cur -> left_child = temp -> right_child;
	temp -> right_child = cur;
	cur -> parent = temp;
}
