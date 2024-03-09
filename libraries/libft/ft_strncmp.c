/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 11:41:43 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/01/28 12:56:52 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*uc1;
	unsigned char	*uc2;
	int				adevolver;

	adevolver = 0;
	uc1 = (unsigned char *) s1;
	uc2 = (unsigned char *) s2;
	if (n > 0)
	{
		while ((n > 1) && (*uc1 == *uc2) && (*uc1 != '\0') && (*uc2 != '\0'))
		{
			n--;
			uc1++;
			uc2++;
		}
		adevolver = (int)(*uc1 - *uc2);
	}
	return (adevolver);
}
