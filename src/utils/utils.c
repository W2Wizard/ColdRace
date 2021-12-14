/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 14:50:45 by avan-ber      #+#    #+#                 */
/*   Updated: 2021/12/14 15:02:29 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "coldrace.h"

size_t	ft_strlen(const char* str)
{
	int i = 0;

	while (str[i])
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