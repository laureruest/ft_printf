/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 11:29:16 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/01/28 12:30:44 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	car;
	unsigned char	*carac;

	car = (unsigned char) c;
	carac = b;
	while (len > 0)
	{
		*carac = car;
		carac++;
		len--;
	}
	return (b);
}
