/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 14:21:58 by lde-la-h      #+#    #+#                 */
/*   Updated: 2021/12/15 10:31:28 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "coldrace.h"

int32_t main(void)
{
	char*   key = NULL;
	t_node* tree = NULL;

	// Part 1, enter
	while ((key = ft_readline(STDIN_FILENO)))
	{
		if (*key == '\0')
			break;
		char* value = ft_readline(STDIN_FILENO);
		tree = insert_node(tree, new_pair(key, value));
	}

	// Part 2, searching
	while ((key = ft_readline(STDIN_FILENO)))
	{
		if (*key == '\0')
			break;
		t_pair* pair = find_node(tree, key);
		if (pair == NULL)
			printf("%s: Not found.\n", key);
		else
			printf("%s\n", pair->value);
	}
	exit(EXIT_SUCCESS);
}
