/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   coldrace.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 14:22:47 by lde-la-h      #+#    #+#                 */
/*   Updated: 2021/12/14 15:24:50 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLDRACE_H
# define COLDRACE_H
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# define SHUT(x) (void)x

//= Types =//

typedef struct		s_pair
{
	char*			key;
	char*			value;
}					t_pair;

typedef struct		s_node
{
	t_pair*			pair;
	struct s_node*	left;
	struct s_node*	right;
}					t_node;

//= Functions =//

t_pair*	new_pair(char* key, char* value);
t_node*	new_node(t_pair* pair);
t_node*	insert_node(t_node* root, t_pair* pair);

#endif