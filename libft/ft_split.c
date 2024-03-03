/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 17:00:01 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/02/10 13:14:17 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

// Prep new ptrs, biggest than old, copyng, return orig ptr to new reserv. mem
static char	**prepare(char **oldptr, size_t size)
{
	size_t	s;
	char	**nwptr;

	s = 0;
	nwptr = ft_calloc(size, sizeof(size_t));
	if (nwptr != NULL)
	{
		while (oldptr[s] != NULL)
		{
			nwptr[s] = ft_strdup((const char *) oldptr[s]);
			free(oldptr[s]);
			s++;
		}
	}
	free(oldptr);
	nwptr[s] = NULL;
	return (nwptr);
}

// Secuenciality stracts strings & resize ptr
static char	**ins_newstr(char **ptr, char *beg_str, char *end_str, size_t s)
{
	size_t	nw_str_long;
	char	*aux;

	ptr = prepare(ptr, s + 1);
	if (ptr != NULL)
	{
		if (end_str != NULL)
		{
			nw_str_long = (size_t)(end_str - beg_str);
			ptr[s - 1] = ft_substr((char const *)beg_str, 0, nw_str_long);
		}
		if (end_str == NULL)
		{
			aux = ft_strdup((const char *)beg_str);
			if (*aux != '\0')
				ptr[s - 1] = aux;
			else if (1)
				return (ptr);
		}
		s++;
	}
	return (ptr);
}

// function trivial case when there is not char c to split
static char	**trivial(char const *s)
{
	char	**newptr;

	if (*s != '\0')
	{
		newptr = ft_calloc(2, sizeof(size_t));
		if (newptr)
		{
			newptr[0] = ft_strdup(s);
			newptr[1] = NULL;
		}
	}
	if (*s == '\0')
	{
		newptr = ft_calloc(1, sizeof(size_t));
		if (newptr)
			newptr[0] = NULL;
	}
	return (newptr);
}

// Non-trivial function when is necessary splitting using c
static char	**notriv(char *cursor_1, char *cursor_2, char c)
{
	char	**nwptr;
	size_t	size;

	size = 1;
	nwptr = ft_calloc(size, sizeof(size_t));
	if (nwptr)
	{
		nwptr[0] = NULL;
		while ((cursor_2 != NULL) && (nwptr != NULL))
		{
			while (*cursor_1 == c)
				cursor_1++;
			if (*cursor_1 == '\0')
				return (nwptr);
			cursor_2 = ft_strchr(cursor_1, c);
			nwptr = ins_newstr(nwptr, cursor_1, cursor_2, size);
			cursor_1 = cursor_2;
			size++;
		}
	}
	return (nwptr);
}

// Library API
char	**ft_split(char const *s, char c)
{
	char	*cursor_1;
	char	*cursor_2;
	char	**toret;

	cursor_1 = (char *) s;
	cursor_2 = ft_strchr(cursor_1, c);
	if ((!cursor_2) || (c == '\0'))
		toret = (trivial(s));
	if ((cursor_2) && (c != '\0'))
		toret = notriv(cursor_1, cursor_2, c);
	return (toret);
}
