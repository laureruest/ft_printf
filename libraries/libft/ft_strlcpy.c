/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 08:38:07 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/01/28 12:48:51 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char	*source;

	if (dstsize > 0)
	{
		source = (char *) src;
		while ((*source != '\0') && (dstsize > 1))
		{
			*dst = *source;
			source++;
			dst++;
			dstsize--;
		}
		*dst = '\0';
	}
	return (ft_strlen(src));
}
