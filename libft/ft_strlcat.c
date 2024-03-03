/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:33:09 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/02/08 08:57:27 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	originalsizedst;
	size_t	tostart;

	originalsizedst = ft_strlen(dst);
	if (dstsize == 0)
		return (ft_strlen(src));
	if (dstsize > originalsizedst)
	{
		i = 0;
		tostart = originalsizedst;
		while ((src[i] != '\0') && (tostart < dstsize - 1))
		{
			dst[tostart] = src[i];
			i++;
			tostart++;
		}
		dst[tostart] = '\0';
	}
	if (dstsize < originalsizedst)
		originalsizedst = dstsize;
	return (ft_strlen(src) + originalsizedst);
}
