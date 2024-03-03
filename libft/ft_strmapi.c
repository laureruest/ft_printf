/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 17:16:46 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/02/07 13:17:52 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*tor;
	char			*c_in;
	char			*c_out;
	unsigned int	l;

	l = ft_strlen(s);
	tor = malloc(l + 1);
	if (tor != NULL)
	{
		l = 0;
		c_in = (char *) s;
		c_out = tor;
		while (*c_in != '\0')
		{
			*c_out = f(l, *c_in);
			c_out++;
			l++;
			c_in++;
		}
		*c_out = '\0';
	}
	return (tor);
}
