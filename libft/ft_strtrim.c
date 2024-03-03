/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:55:52 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/02/11 10:27:49 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

// func rets  non-Z,if the character pointed is inside the string to_search
static int	let_to_del(char *ptr, const char *to_search)
{
	int		toret;
	char	*cursor;
	char	*limit;

	toret = 0;
	cursor = (char *) to_search;
	limit = cursor + ft_strlen(to_search);
	while (cursor < limit)
	{
		if (*ptr == *cursor)
		{
			toret = 1;
		}
		cursor++;
	}
	return (toret);
}

//while letter is in set, go moving ptr to right
static char	*go_t_right(char *ptr, const char *set)
{
	while ((let_to_del(ptr, set)) && (*ptr != '\0'))
	{
		ptr++;
	}
	return (ptr);
}

//if letter than is pointed, is in set, (let to del) return that ptr to left
// stops if arrives to limit
static char	*go_t_left(char *ptr, char *limit, const char *set)
{
	while ((let_to_del(ptr, set)) && (ptr >= limit))
	{
		ptr--;
	}
	return (ptr);
}

// put inside ptr the final string trimmed and returns where write '\0'
static char	*do_data(char *ptr, char *left, char *right)
{
	while (left <= right)
	{
		*ptr = *left;
		ptr++;
		left++;
	}
	return (ptr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr_right;
	char	*ptr_left;
	char	*ptrtoret;
	char	*to_put_null;
	size_t	size;

	size = 0;
	ptr_left = (char *) s1;
	ptr_right = ptr_left;
	if (*s1 != '\0')
		ptr_right = ptr_left + ft_strlen(s1) - 1;
	ptr_right = go_t_left(ptr_right, ptr_left, set);
	ptr_left = go_t_right(ptr_left, set);
	if (ptr_right >= ptr_left)
		size = 1 + ptr_right - ptr_left;
	ptrtoret = malloc(size + 1);
	if (ptrtoret != NULL)
	{
		to_put_null = do_data(ptrtoret, ptr_left, ptr_right);
		*to_put_null = '\0';
	}
	return (ptrtoret);
}
