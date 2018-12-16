#include <rbtree_header.h>

int main( void )
{
	char *input_buf = NULL;
	char choice = 0;
	int value = 0;
	int ret = -1;
	NODE *root = NULL;
	NODE *res = NULL;
	input_buf = (char *)malloc( sizeof(char) * BUF_SIZE );
	if( input_buf == NULL )
	{
		fprintf( stderr, "%sMemory Allocation failed%s\n", COLOR_RED, COLOR_BLACK );
		return EXIT_FAILURE;
	}
	while( 1 )
	{
		printf( "--------------------------------\n" );
		printf( "1.Insert\n2.Display\n3.Search\n4.Delete\nEnter choice: " );
		if( fgets( input_buf, BUF_SIZE, stdin ) == NULL )
		{
			fprintf( stderr, "%sInput error%s\n", COLOR_RED, COLOR_BLACK );
			return EXIT_FAILURE;
		}
		choice = atoi( input_buf );
		switch( choice )
		{
			case 0 :
					free( input_buf );
					return EXIT_SUCCESS;
			case 1 :
					printf( "Enter value to insert: " );
					if( fgets( input_buf, BUF_SIZE, stdin ) == NULL )
					{
						fprintf( stderr, "%sInput error%s\n", COLOR_RED, COLOR_BLACK );
						return EXIT_FAILURE;
					}
					value = atoi( input_buf );
					ret = insert( &root, value );
					if( ret )
						fprintf( stdout, "%sNode insertion failed%s\n", COLOR_RED, COLOR_BLACK );
					else
						fprintf( stdout, "%sNode inserted successfully%s\n", COLOR_GREEN, COLOR_BLACK );
					break;

			case 2 :
					if( root != NULL )
					{
						printf( "Tree elements are -\n" );
						printf( "Inorder display\n" );
						display_inorder( &root );
						printf( "\nLevel-order display\n" );
						ret = display_levelorder( &root );
						if( ret )
							fprintf( stderr, "%sLevel-order displaying failed%s\n", COLOR_RED, COLOR_BLACK );
					}
					else
						fprintf( stdout, "%sNo nodes in the tree%s\n", COLOR_YELLOW, COLOR_BLACK );
					break;
			
			case 3 :
					if( root != NULL)
					{
						printf( "Enter key value to search: " );
						if( fgets( input_buf, BUF_SIZE, stdin ) == NULL )
						{
							fprintf( stderr, "%sInput error%s\n", COLOR_RED, COLOR_BLACK );
							return EXIT_FAILURE;
						}
						value = atoi( input_buf );
						res = search( &root, value );
						if( res == NULL )
							fprintf( stdout, "%sKey %d not found%s\n", COLOR_RED, value, COLOR_BLACK );
						else
							fprintf( stdout, "%sKey %d found at %p%s\n", COLOR_GREEN, value, res, COLOR_BLACK );
					}
					else
						fprintf( stdout, "%sNo nodes in the tree%s\n", COLOR_YELLOW, COLOR_BLACK );
					break;
			
			case 4 :
					if( root != NULL)
					{
						printf( "Enter key to delete: " );
						if( fgets( input_buf, BUF_SIZE, stdin ) == NULL )
						{
							fprintf( stderr, "%sInput error%s\n", COLOR_RED, COLOR_BLACK );
							return EXIT_FAILURE;
						}
						value = atoi( input_buf );
						ret = delete( &root, value );
						if( ret )
							fprintf( stdout, "%sKey %d not found in tree%s\n", COLOR_RED, value, COLOR_BLACK );
						else
							fprintf( stdout, "%sKey %d deleted successfully%s\n", COLOR_GREEN, value, COLOR_BLACK );
					}
					else
						fprintf( stdout, "%sNo nodes in the tree%s\n", COLOR_YELLOW, COLOR_BLACK );
					break;

			default:
					fprintf( stderr, "%sInvalid choice entered%s\n", COLOR_RED, COLOR_BLACK );			
		}
	}
}
