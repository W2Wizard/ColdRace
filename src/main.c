/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 14:21:58 by lde-la-h      #+#    #+#                 */
/*   Updated: 2021/12/14 15:58:25 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "coldrace.h"

int32_t main(void)
{
    t_node  *tree = NULL;
    // Part 1
    while (true)
    {
        char* key = ft_readline(STDIN_FILENO);
        if (*key == '\n')
            break;
        char* value = ft_readline(STDIN_FILENO);
        insert_node(tree, new_pair(key, value));
    }
    // Part 2, searching
    while (true)
    {
        char *key = ft_readline(STDIN_FILENO);
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
