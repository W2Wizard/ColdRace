/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 14:21:58 by lde-la-h      #+#    #+#                 */
/*   Updated: 2021/12/14 17:53:16 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "coldrace.h"

int32_t main(void)
{
    int32_t fd = open("big.txt", O_RDONLY);
    t_node  *tree = NULL;
    // Part 1
    while (true)
    {
        char* key = ft_readline(fd);
        if (*key == '\n')
            break;
        char* value = ft_readline(fd);
        tree = insert_node(tree, new_pair(key, value));
    }
    // Part 2, searching
    while (true)
    {
        char *key = ft_readline(fd);
        if (*key == '\n')
            break;
        t_pair* pair = find_node(tree, key);
        if (pair == NULL)
            printf("%s: Not found.\n", key);
        else
            printf("%s\n", pair->value);
    }
    exit(EXIT_SUCCESS);
}
