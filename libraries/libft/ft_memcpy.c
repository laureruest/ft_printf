/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:45:36 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/02/08 10:38:33 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptrdestino;
	unsigned char	*ptrorigen;

	ptrdestino = (unsigned char *) dst;
	ptrorigen = (unsigned char *) src;
	if ((ptrorigen == NULL) && (ptrdestino == NULL))
		return (NULL);
	while (n != 0)
	{
		*ptrdestino = *ptrorigen;
		ptrdestino++;
		ptrorigen++;
		n--;
	}
	return (dst);
}
