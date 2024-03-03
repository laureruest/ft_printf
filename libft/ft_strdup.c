/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:58:00 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/02/09 16:50:01 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

// alloc mem and copy inside the str s1 & return pointer to mem_allocated
char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*org_cursor;
	char	*dest_cursor;
	char	*toreturn;

	size = ft_strlen(s1);
	toreturn = malloc(size + 1);
	if (toreturn != NULL)
	{
		org_cursor = (char *) s1;
		dest_cursor = toreturn;
		while (size > 0)
		{
			*dest_cursor = *org_cursor;
			dest_cursor++;
			org_cursor++;
			size--;
		}
		*dest_cursor = '\0';
	}
	return (toreturn);
}
