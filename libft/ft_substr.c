/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 08:08:09 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/02/11 18:50:14 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*prepare(char *dest, char *src, unsigned int len)
{
	size_t	i;

	i = 0;
	while ((i < len) && (src[i] != '\0'))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// copies from string s, starts in index start, to new *char string (maxlen len)
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*src_cursor;
	char	*obj_str;
	size_t	i;

	src_cursor = ((char *) s);
	i = ft_strlen(src_cursor);
	if (i >= start)
		i -= start;
	if (i > len)
		i = len;
	obj_str = malloc(i + 1);
	if (obj_str != NULL)
	{
		if (((ft_strlen(src_cursor) + 2) <= (start + 2)) || (len == 0))
			obj_str[0] = '\0';
		else if (((unsigned int)(ft_strlen(src_cursor)) <= start))
			obj_str[0] = '\0';
		else if (1)
			obj_str = prepare(obj_str, &src_cursor[start], len);
	}
	return (obj_str);
}
