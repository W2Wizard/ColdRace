# include "coldrace.h"
#define DEBUG printf("%*s:%i, %s\n", 20, __FILE__, __LINE__, __FUNCTION__);
int height(t_node* node)
{
	if (node == NULL)
		return (0);
	return (node->height);
}

int avl_max(int a, int b)
{
	return (a * (a >= b) + b * (b > a));
}

int avl_get_balance(t_node* node)
{
	if (node == NULL)
		return (0);
	return height(node->left) - height(node->right);
}

t_node*	avl_right_rotate(t_node* y)
{
	t_node *x = y->left;
	t_node *temp = x->right;

	x->right = y;
	y->left = temp;

	y->height = avl_max(height(y->left), height(y->right)) + 1;
	x->height = avl_max(height(x->left), height(x->right)) + 1;

	return (x);
}

t_node*	avl_left_rotate(t_node* x)
{
	t_node *y = x->right;
	t_node *temp = y->left;

	y->left = x;
	x->right = temp;

	x->height = avl_max(height(x->left), height(x->right)) + 1;
	y->height = avl_max(height(y->left), height(y->right)) + 1;

	return (y);
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
		root->right = insert_node(root->right, pair);
	else
	{
		free_pair(pair);
		return (root);
	}

	root->height = avl_max(height(root->left), height(root->right)) + 1;

	int balance = avl_get_balance(root);
	
	if (balance > 1) {
		if (ft_strcmp(pair->key, root->left->pair->key) < 0) {
			return avl_right_rotate(root);
		} else {
			root->left =  avl_left_rotate(root->left);
			return avl_right_rotate(root);
		}
	}
	else if (balance < -1) {
		if (ft_strcmp(pair->key, root->right->pair->key) > 0) {
			return avl_left_rotate(root);
		} else {
			root->right = avl_right_rotate(root->right);
			return avl_left_rotate(root);
		}
	}
	return (root);
}

t_pair*	find_node(t_node* root, char *key)
{
	int32_t	res_strcmp;

	if (root == NULL)
		return (NULL);
	res_strcmp = ft_strcmp(key, root->pair->key);
	if (res_strcmp == 0)
		return(root->pair);
	else if (res_strcmp > 0)
		return (find_node(root->right, key));
	else
		return(find_node(root->left, key));
}

void preOrder(t_node* root)
{
	if(root != NULL)
	{
		printf("%s, ", root->pair->key);
		preOrder(root->left);
		preOrder(root->right);
	}
}