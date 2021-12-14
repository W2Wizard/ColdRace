#include "coldrace.h"

/**
 * Creates a new pair.
 * 
 * @param key 
 * @param value 
 * @return t_pair* 
 */
t_pair* new_pair(char* key, char* value)
{
	t_pair* output = malloc(sizeof(t_pair));
	output->key = key;
	output->value = value;
	return (output);
}

/**
 * Creates a new node.
 * 
 * @param pair 
 * @param left 
 * @param right 
 * @return t_node* 
 */
t_node* new_node(t_pair* pair)
{
	t_node* output = malloc(sizeof(t_node));
	output->pair = pair;
	output->left = NULL;
	output->right = NULL;
	return (output);
}