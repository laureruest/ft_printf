/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:46:19 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/01/28 13:01:21 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				diferencia;
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char *) s1;
	c2 = (unsigned char *) s2;
	diferencia = 0;
	if (n > 0)
	{
		while ((n > 1) && (*c1 == *c2))
		{
			c1++;
			c2++;
			n--;
		}
		diferencia = (int)(*c1 - *c2);
	}
	return (diferencia);
}
