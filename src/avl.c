# include "coldrace.h"

t_node*	insert_node(t_node* root, t_pair* pair)
{
	int	res_strcmp;

	if (root == NULL)
		return (new_node(pair));
	res_strcmp = ft_strcmp(pair->key, root->pair->key);
	if (res_strcmp < 0)
		root->left = insert_node(root->left, pair);
	else if (res_strcmp > 0)
		root->left = insert_node(root->right, pair);
	else
	{
		free_pair(pair);
		return (root);
	}
	return (root);
}

t_pair*	find_node(t_node* root, char *key)
{
	int	res_strcmp;

	if (root == NULL)
		return (NULL);
	res_strcmp = ft_strcmp(key, root->pair->key);
	if (res_strcmp == 0)
		return(root->pair);
	else if (res_strcmp > 0)
		return (find_node(root->left, key));
	else
		return(find_node(root->left, key));
}
