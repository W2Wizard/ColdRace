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
# define BUFFER_SIZE 255
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
	size_t			height;
}					t_node;

//= Functions =//

int32_t	ft_strcmp(const char* str1, const char* str2);
size_t	ft_strclen(const char* str, char c);
size_t	ft_strlen(const char* str);
char*	ft_readline(int32_t fd);
char*	ft_strdup(const char *s1);
char	*ft_substr(char const* s, size_t start, size_t len);
size_t	ft_strclen(const char* str, char c);
char*   ft_append(char* str1, char* str2);
void*	ft_memmove(void *dst, const void *src, size_t len);
char*	ft_strchr(const char *s, int32_t c);
void	print_error_message(char *message);
void*	malloc_check(void* obj);
void	free_pair(t_pair *pair);

//= Algo =//

t_pair*	new_pair(char* key, char* value);
t_node*	new_node(t_pair* pair);
t_node*	insert_node(t_node* root, t_pair* pair);
t_pair*	find_node(t_node* root, char *key);

#endif