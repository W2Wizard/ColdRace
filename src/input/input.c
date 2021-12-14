/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 15:01:47 by lde-la-h      #+#    #+#                 */
/*   Updated: 2021/12/14 19:30:17 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "coldrace.h"

// char*	ft_getline(char* readstr, char** remainder)
// {
// 	size_t	len;
// 	char*	out;
// 	char*	rem;

// 	len = ft_strclen(readstr, '\n') + 1;
// 	if (!readstr[len - 1])
// 		len--;
// 	out = ft_substr(readstr, 0, len);
// 	rem = ft_strdup(readstr + len);
// 	free(readstr);
// 	if (!*rem)
// 	{
// 		free(rem);
// 		*remainder = NULL;
// 	}
// 	else
// 		*remainder = rem;
// 	return (out);
// }

char*	ft_getline(char* readstr, char** remainder)
{
	size_t	middle = ft_strclen(readstr, '\n');
	char* front = malloc_check(ft_substr(readstr, 0, middle));
	char *rem = malloc_check(ft_strdup(readstr + middle + 1));
	free(readstr);
	if (rem[0] == '\0')
	{
		free(rem);
		*remainder = NULL;
	}
	else
		*remainder = rem;
	return (front);
}

char*	ft_readline(int32_t fd)
{
	static char*	remainder;
	ssize_t			bread = 0;
	char*			readstr = NULL;
	char			BUFF[BUFFER_SIZE + 1];

	if (remainder && ft_strchr(remainder, '\n') != NULL)
		return (ft_getline(remainder, &remainder));
	readstr = remainder;
	while ((bread = read(fd, BUFF, BUFFER_SIZE)))
	{
		BUFF[bread] = '\0';
		readstr = ft_append(readstr, BUFF);
		if (ft_strchr(readstr, '\n'))
			return(ft_getline(readstr, &remainder));
	}
	return (readstr);
}
