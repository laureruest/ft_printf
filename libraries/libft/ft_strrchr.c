/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 09:25:26 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/02/11 08:26:08 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*cursor;
	char	*adevolver;
	char	abuscar;

	adevolver = NULL;
	cursor = (char *) s;
	abuscar = (char) c;
	while (*cursor != '\0')
	{
		cursor++;
	}
	while ((cursor >= s) && (*cursor != abuscar))
	{
		cursor--;
		if (cursor < s)
			return (adevolver);
	}
	if (*cursor == abuscar)
	{
		adevolver = cursor;
	}
	return (adevolver);
}
