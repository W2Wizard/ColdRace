/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 14:21:58 by lde-la-h      #+#    #+#                 */
/*   Updated: 2021/12/14 19:00:24 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "coldrace.h"

int32_t main(void)
{
	const int32_t fd = open("big.txt", O_RDONLY);

	char*   key = NULL;
	t_node* tree = NULL;
	// Part 1, enter
	while ((key = ft_readline(fd)))
	{
		if (*key == '\0')
			break;
		char* value = ft_readline(fd);
		tree = insert_node(tree, new_pair(key, value));
	}
	// Part 2, searching
	while ((key = ft_readline(fd)))
	{
		if (*key == '\0')
			break;
		t_pair* pair = find_node(tree, key);
		if (pair == NULL)
		{
			printf("%s: Not found.\n", key);
			// write(STDERR_FILENO, key, ft_strclen(key, '\n'));
			// write(STDERR_FILENO, ": Not found.\n", 13);
		}
		else
		{
			printf("%s\n", pair->value);
			// write(STDOUT_FILENO, pair->value, ft_strclen(pair->value, '\n'));
			// write(STDOUT_FILENO, "\n", 1);
		}
	}
	exit(EXIT_SUCCESS);
}

