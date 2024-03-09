/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:53:05 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/02/05 17:17:41 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*univ_cursor;
	char	*obj_cursor;
	char	*obj;

	obj = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (obj != NULL)
	{
		obj_cursor = obj;
		univ_cursor = (char *) s1;
		while (*univ_cursor != '\0')
		{
			*obj_cursor = *univ_cursor;
			obj_cursor++;
			univ_cursor++;
		}
		univ_cursor = (char *) s2;
		while (*univ_cursor != '\0')
		{
			*obj_cursor = *univ_cursor;
			obj_cursor++;
			univ_cursor++;
		}
		*obj_cursor = '\0';
	}
	return (obj);
}
