/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 09:25:12 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/02/03 08:12:44 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	char	*cursor;
	char	*adevolver;
	char	abuscar;

	adevolver = NULL;
	cursor = (char *) s;
	abuscar = (char) c;
	while ((*cursor != '\0') && (*cursor != abuscar))
	{
		cursor++;
	}
	if (*cursor == abuscar)
	{
		adevolver = cursor;
	}
	return (adevolver);
}
