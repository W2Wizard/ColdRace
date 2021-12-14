/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 14:50:45 by avan-ber      #+#    #+#                 */
/*   Updated: 2021/12/14 15:28:13 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "coldrace.h"

size_t	ft_strcmp(const char* str1, const char* str2)
{
	size_t i = 0;
	while (str1[i] != '\0')
	{
		if (str1[i] != str2[i])
			break ;
		i++;
	}
	return (str1[i] - str2[i]);
}

size_t	ft_strlen(const char* str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

void	print_error_message(char *message)
{
	write(2, message, ft_strlen(message));
}

void*	malloc_check(void* obj)
{
	if (obj == NULL)
	{
		print_error_message("Malloc failed\n");
		exit(EXIT_FAILURE);
	}
	return (obj);
}

void	free_pair(t_pair *pair)
{
	free(pair->key);
	free(pair->value);
	free(pair);
}