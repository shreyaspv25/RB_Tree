#include <rbtree_header.h>

/*
 * This function inserts the node to queue.
 * Parameters = 2
 * 		1 - Address of queue's head
 *		2 - Address of node to push
 * Return value:
 * 		0 - Success
 *		1 - Failure
 */

int push_back( QUEUE_NODE **head, NODE *node )
{
	QUEUE_NODE *newnode = NULL;
	QUEUE_NODE *traverse = NULL;
	
	/* Allocating memory for new node */
	newnode = (QUEUE_NODE *)malloc( sizeof(struct queue_list) );
	if( newnode == NULL )
		return EXIT_FAILURE;
	
	/* Initializing the new node of queue */
	newnode -> node_ptr = node;
	newnode -> next = NULL;
	
	/* Inserting node into the queue at rear */
	if( (*head) == NULL )
	{
		(*head) = newnode;
		return EXIT_SUCCESS;
	}
	/* Traverse till rear and insert */
	traverse = (*head);
	while( traverse -> next != NULL )
		traverse = traverse -> next;
	traverse -> next = newnode;
	return EXIT_SUCCESS;
}

/*
 * This function removes the node from queue.
 * Parameters = 1
 * 		1 - Address of queue's head
 * Return value:
 * 		Content of removed node - On success
 *		NULL - On failure
 */

NODE *pop_front( QUEUE_NODE **head )
{
	QUEUE_NODE *delnode = NULL;
	NODE *delnode_data = NULL;
	
	if( (*head) == NULL )
		return NULL;
	/* removing node from front of queue */
	delnode = (*head);
	(*head) = (*head) -> next; /* Succeed queue's head */
	delnode_data = delnode -> node_ptr; /* Backup node's content */
	delnode -> next = NULL;
	free( delnode ); /* Deallocate memory */
	delnode = NULL;
	return delnode_data; /* Return backed up content */
}

/*
 * This function returns the size of the queue list.
 * Parameters = 1
 * 		1 - Address of queue's head
 * Return value:
 * 		Queue size
 */

int get_size( QUEUE_NODE *head )
{
	int count = 0;
	/* Compute queue size by iterating the queue list */
	while( head != NULL )
	{
		count++;
		head = head -> next;
	}
	return count;
}
