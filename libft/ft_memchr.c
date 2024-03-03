/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:39:44 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/02/08 09:05:03 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	abuscar;
	unsigned char	*cursor;
	void			*adevolver;

	cursor = (unsigned char *) s;
	abuscar = (unsigned char) c;
	adevolver = NULL;
	if (n > 0)
	{
		n--;
		while ((n > 0) && (*cursor != abuscar))
		{
			cursor++;
			n--;
		}
		if (*cursor == abuscar)
		{
			adevolver = (void *)cursor;
		}
	}
	return (adevolver);
}
