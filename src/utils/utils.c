/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 14:50:45 by avan-ber      #+#    #+#                 */
/*   Updated: 2021/12/14 15:24:49 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "coldrace.h"

size_t	ft_strclen(const char* str, char c)
{
	int i = 0;

	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}


size_t	ft_strlen(const char* str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

char*	ft_strdup(const char* s1)
{
	char    *str;
	size_t    ln;

	ln = ft_strlen(s1);
	str = malloc_check(malloc(ln * sizeof(char) + 1));
	ft_memmove(str, s1, ln);
	str[ln] = '\0';
	return (str);
}

char*   ft_append(char* str1, char* str2)
{
	size_t	len1 = 0;
	size_t	len2 = 0;
	char*	out = NULL;

	if (!str1)
		return(ft_strdup(str2));
	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	out = malloc_check(malloc((len1 + len2 + 1) * sizeof(char)));
	ft_memmove(out, str1, len1);
	ft_memmove(out + len1, str2, len1);
	out[len1 + len2] = '\0';
	return (out);
}

char	*ft_substr(char const* s, size_t start, size_t len)
{
	char*	sub;
	size_t	strln;

	strln = ft_strlen(s);
	if (start > strln)
		return (ft_strdup(""));
	if (len > strln - start)
		return (ft_strdup(s + start));
	sub = malloc_check(malloc((len + 1) * sizeof(char)));
	ft_memmove(sub, &s[start], len);
	sub[len] = '\0';
	return (sub);
}

void*	ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst || !src)
		return (NULL);
	i = 0;
	if (src < dst)
	{
		while (len-- > 0)
			((uint8_t *)dst)[len] = ((uint8_t *)src)[len];
	}
	else
	{
		while (i < len)
		{
			((uint8_t *)dst)[i] = ((uint8_t *)src)[i];
			i++;
		}
	}
	return (dst);
}

char*	ft_strchr(const char* s, int32_t c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	if (c == '\0')
		return ((char *)&s[len]);
	while (i < len - 1)
	{
		if (s[i] == (uint8_t)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
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