#include "coldrace.h"

/**
 * Compares two strings.
 * 
 * @param str1 The first string.
 * @param str2 The second string.
 * @return size_t Look at the manpage :P
 */
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

/**
 * Gets the length of the string until a given char or until null.
 * 
 * @param str The string.
 * @param c The char until which to count to.
 * @return size_t The length of the string until c or \0.
 */
size_t	ft_strclen(const char* str, char c)
{
	int i = 0;

	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

/**
 * Returns the length of the string.
 * 
 * @param str The string.
 * @return size_t The length.
 */
size_t	ft_strlen(const char* str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

/**
 * Duplicates a given string, will call exit on malloc fail.
 * 
 * @param s1 The string to duplicate.
 * @return char* The newly allocated string thats identical in terms of content to s1.
 */
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

/**
 * Allocates a new string by appending str2 to str1, freeing str1 in the process.
 * 
 * @param str1 The first string.
 * @param str2 The second string.
 * @return char* The new string.
 */
char*   ft_append(char* str1, char* str2)
{
    char    *out;
    size_t    len1;
    size_t    len2;

    if (!str1)
        return (ft_strdup(str2));
    len1 = ft_strlen(str1);
    len2 = ft_strlen(str2);
    out = (char *)malloc_check(malloc(len1 + len2 + 1));
    ft_memmove(out, str1, len1);
    ft_memmove(out + len1, str2, len2);
    free((char *)str1);
	out[len1 + len2] = '\0';
    return (out);
}

/**
 * Retrieves a subset of the given string.
 * 
 * @param s The string.
 * @param start The starting position.
 * @param len How many characters long.
 * @return char* 
 */
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

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (0);
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