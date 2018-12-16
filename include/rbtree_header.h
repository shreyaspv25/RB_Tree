#ifndef RBTREE_HEADER_H
#define RBTREE_HEADER_H

#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 		256
#define COLOR_RED 		"\x1B[31m"
#define COLOR_GREEN 	"\x1B[32m"
#define COLOR_YELLOW 	"\x1B[33m"
#define COLOR_BLACK 	"\x1B[0m"

enum nodecolor { BLACK, RED, DOUBLE_BLACK };
typedef enum nodecolor NODE_COLOR;

/* Structure template for RB_TREE Node */
struct node
{
	int data;
	struct node *left_child;
	struct node *right_child;
	struct node *parent;
	NODE_COLOR color;
};

/* Structure Template for QUEUE_LIST */
struct queue_list
{
	struct node *node_ptr;
	struct queue_list *next;
};

typedef struct queue_list QUEUE_NODE;
typedef struct node NODE;

/*	FUNCTION PROTOTYPES	*/

extern NODE *getnode( void );
extern NODE *initnode( int );
extern int insert( NODE **, int );
extern int insert_into_tree( NODE **, NODE * );
extern void display_inorder( NODE ** );
extern int display_levelorder( NODE ** );
extern void leftrotate( NODE **, NODE * );
extern void rightrotate( NODE **, NODE * );
extern NODE* search( NODE **, int );
extern int delete( NODE **, int );
extern void reform_tree( NODE **, NODE * );
extern NODE* find_successor( NODE * );
extern int push_back( QUEUE_NODE **, NODE * );
extern NODE* pop_front( QUEUE_NODE ** );
extern int get_size( QUEUE_NODE * );
extern NODE_COLOR getcolor( NODE * );
extern void setcolor( NODE *, NODE_COLOR );

#endif /* RBTREE_HEADER_H */
