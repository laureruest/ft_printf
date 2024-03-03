/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:40:31 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/02/08 10:42:06 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static void	domov(unsigned char *d, unsigned char *o, size_t n, short int desp)
{
	while (n != 0)
	{
		*d = *o;
		d = d + desp;
		o = o + desp;
		n = n - 1;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ptrdestino;
	unsigned char	*ptrorigen;
	short int		dstdestorg;
	short int		semaforo;

	if ((dst == NULL) && (src == NULL))
		return (NULL);
	semaforo = 1;
	ptrdestino = (unsigned char *) dst;
	ptrorigen = (unsigned char *) src;
	dstdestorg = ptrdestino - ptrorigen;
	if (len > 0)
	{
		if (dstdestorg > 0)
		{
			ptrorigen = ptrorigen + len - 1;
			ptrdestino = ptrdestino + len - 1;
			semaforo = -1;
		}
		domov(ptrdestino, ptrorigen, len, semaforo);
	}
	return (dst);
}
