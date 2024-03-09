/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:26:10 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/02/05 18:35:12 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// alocates and return (type void) ptr to count objects of s bytes everyone
// return a ptr = 0 on errors
void	*ft_calloc(size_t count, size_t size)
{
	size_t			mem_size;
	unsigned char	*obj;
	void			*ptrtoret;
	size_t			i;

	i = 0;
	mem_size = count * size;
	obj = malloc(mem_size);
	ptrtoret = (void *)obj;
	if (obj != NULL)
	{
		while (i < mem_size)
		{
			obj[i] = '\0';
			i++;
		}
	}
	return (ptrtoret);
}
