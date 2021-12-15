/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 14:21:58 by lde-la-h      #+#    #+#                 */
/*   Updated: 2021/12/15 11:49:09 by jowytrzy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "coldrace.h"
#define BUFFER_SIZE_PRINT 2048


static void	print_buffer(char *buffer, int *buff_i)
{
	write(1, buffer, *buff_i);
	ft_bzero(buffer, BUFFER_SIZE_PRINT);
	*buff_i = 0;
}

void	add_print_buffer(const char *str, int flush, int nl)
{
	static char	buffer[BUFFER_SIZE_PRINT];
	static int	buff_i;

	if (flush)
	{
		print_buffer(buffer, &buff_i);
		return ;
	}
	while (*str)
	{
		buffer[buff_i] = *str;
		buff_i++;
		str++;
		if (buff_i == BUFFER_SIZE)
			print_buffer(buffer, &buff_i);
	}
	if (nl) {
		buffer[buff_i] = '\n';
		buff_i++;
		if (buff_i == BUFFER_SIZE)
			print_buffer(buffer, &buff_i);
	}
	return ;
}

int32_t main(void)
{
	// const int32_t fd = open("big.txt", O_RDONLY);
	const int fd = STDIN_FILENO;

	static t_node* trees[256];
	// t_node* tree = NULL;
	char*   key = NULL;

	// Part 1, enter
	while ((key = ft_readline(fd)))
	{
		if (*key == '\0')
			break;
		char* value = ft_readline(fd);
		unsigned int index = (unsigned int)key[0];
		trees[index] = insert_node(trees[index], new_pair(key, value));
		// tree = insert_node(tree, new_pair(key, value));
	}
	free(key);
	//Part 2, searching
	while ((key = ft_readline(fd)))
	{
		if (*key == '\0')
			break;
		// t_pair* pair = find_node(tree, key);
		t_pair* pair = find_node(trees[(unsigned int)key[0]], key);
		if (pair == NULL) {
			add_print_buffer(key, 0, 0);
			add_print_buffer(": Not found.", 0, 1);
			// printf("%s: Not found.\n", key);
		}
		else {
			add_print_buffer(pair->value, 0, 1);
			// printf("%s\n", pair->value);
		}
		free(key);
	}
	free(key);
	add_print_buffer("",1,0);
	exit(EXIT_SUCCESS);
}
