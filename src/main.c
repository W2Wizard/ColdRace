/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 14:21:58 by lde-la-h      #+#    #+#                 */
/*   Updated: 2021/12/15 11:00:14 by jowytrzy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "coldrace.h"
// #define BUFFER_SIZE 500

// static void	print_buffer(char *buffer, int *buff_i)
// {
// 	write(1, buffer, *buff_i);
// 	ft_bzero(buffer, BUFFER_SIZE);
// 	*buff_i = 0;
// }

// int			add_print_buffer(const char *str, int length)
// {
// 	static char	buffer[BUFFER_SIZE];
// 	static int	buff_i;
// 	static int	count;
// 	int			i;

// 	i = 0;
// 	if (length < 0)
// 	{
// 		print_buffer(buffer, &buff_i);
// 		i = count;
// 		count = 0;
// 		return (i);
// 	}
// 	while (i < length)
// 	{
// 		buffer[buff_i] = str[i];
// 		buff_i++;
// 		i++;
// 		count++;
// 		if (buff_i == BUFFER_SIZE)
// 			print_buffer(buffer, &buff_i);
// 	}
// 	return (count);
// }

int32_t main(void)
{
	const int32_t fd = open("big.txt", O_RDONLY);
	static t_node* trees[256];

	char*   key = NULL;
	// t_node* tree = NULL;
	// Part 1, enter
	// printf("P: %p\n", trees[5]);
	while ((key = ft_readline(fd)))
	{
		if (*key == '\0')
			break;
		char* value = ft_readline(fd);
		trees[(int)key[0]] = insert_node(trees[(int)key[0]], new_pair(key, value));
		// tree = insert_node(tree, new_pair(key, value));
	}
	// Part 2, searching
	while ((key = ft_readline(fd)))
	{
		if (*key == '\0')
			break;
		// t_pair* pair = find_node(tree, key);
		t_pair* pair = find_node(trees[(int)key[0]], key);
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

