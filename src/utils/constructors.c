#include "coldrace.h"

/**
 * Creates a new pair.
 * 
 * @param key The key, identifier.
 * @param value The value associated with the key.
 * @return t_pair* The pair.
 */
t_pair* new_pair(char* key, char* value)
{
	t_pair* output = malloc_check(malloc(sizeof(t_pair)));
	output->key = key;
	output->value = value;
	return (output);
}

/**
 * Creates a new node.
 * 
 * @param pair The pair to add to the node.
 * @return t_node* The node.
 */
t_node* new_node(t_pair* pair)
{
	t_node* output = malloc_check(malloc(sizeof(t_node)));
	output->pair = pair;
	output->left = NULL;
	output->right = NULL;
	output->height = 1;
	return (output);
}