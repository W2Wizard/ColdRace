/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 15:01:47 by lde-la-h      #+#    #+#                 */
/*   Updated: 2021/12/14 23:59:17 by jowytrzy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "coldrace.h"

char*    ft_getline(char* readstr, char** remainder)
{
    size_t  len = ft_strclen(readstr, '\n');
    char*   out = ft_substr(readstr, 0, len);
    
    if (readstr[len] == '\n')
        len++;
    if (readstr[len] == '\0')
        *remainder = NULL;
    else
        *remainder= ft_strdup(readstr + len);
    free(readstr);
    return (out);
}

char*    ft_readline(int32_t fd)
{
    static char*	remainder;
    ssize_t			bread = 0;
    char*           readstr = NULL;
    char            BUFF[BUFFER_SIZE + 1];

    if (remainder && strchr(remainder, '\n'))
        return (ft_getline(remainder, &remainder));
    while ((bread = read(fd, BUFF, BUFFER_SIZE)))
    {
        BUFF[bread] = '\0';
        readstr = ft_append(readstr, BUFF);
        if (remainder)
        {
            char* temp = ft_append(remainder, readstr);
            free(readstr);
            readstr = temp;
            remainder = NULL;
        }
        if (strchr(readstr, '\n'))
            return (ft_getline(readstr, &remainder));
    }
    return (readstr);
}
