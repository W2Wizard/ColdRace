# include "coldrace.h"

int height(t_node* node)
{
	if	(node == NULL)
		return 0;
	return (node->height);
}

int max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int getBalance(t_node* node)
{
	if (node == NULL)
		return 0;
	return height(node->left) - height(node->right);
}

t_node*	right_rotate(t_node* y)
{
	t_node *x = y->left;
	t_node *temp = x->right;

	x->right = y;
	y->left = temp;

	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;

	return x;
}

t_node*	left_rotate(t_node* x)
{
	t_node *y = x->right;
	t_node *temp = x->left;

	y->left = x;
	x->right = temp;

	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;

	return y;
}

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

	root->height = max(height(root->left), height(root->right)) + 1;

	int balance = getBalance(root);
	if (balance > 1 && ft_strcmo(pair->key, root->left->pair->key) < 0)
		return rightRotate(root);
	if (balance < -1 && ft_strcmp(pair->key, root->right->pair->key) > 0)
		return leftRotate(root);
	if (balance > 1 && ft_strcmp(pair->key, root->left->pair->key) > 0)
	{
		root->left =  leftRotate(root->left);
		return rightRotate(root);
	}
	if (balance < -1 && ft_strcmo(pair->key, root->right->pair->key) < 0)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
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
