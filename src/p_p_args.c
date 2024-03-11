/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_p_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:16:24 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/03/11 20:01:23 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

void	p_p_args(char *f, va_list l_args, int *count)
{
	char	*str;
	char	ch;

	if ((*f == 'd') || (*f == 'i'))
		lr_prnb(l_args, count);
	else if (*f == 'u')
		lr_uprnb(l_args, count);
	else if (*f == 'x')
		lr_lhex(l_args, count);
	else if (*f == 'X')
		lr_uhex(l_args, count);
	else if (*f == 'c')
	{
		ch = va_arg(l_args, unsigned int);
		ft_putchar_fd(ch, 1);
		*count++;
	}
	else if (*f == 's')
	{
		str = va_arg(l_args, char*);
		ft_putstr_fd(str, 1);
		*count += ft_strlen(str);
	}
	else if (*f == 'p')
		lr_prptr(l_args, count);
}
