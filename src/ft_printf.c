/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 08:01:02 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/03/10 16:21:11 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include <stdlib.h>

static void	lr_ppc(int *count, size_t *idx)
{
	ft_putchar('%', 1);
	*count++;
	*idx += 2;
}

static void	lr_putchar(char toprn, int *count)
{
	ft_putchar(toprn, 1);
	*count++;
}

int	ft_printf(const char *s_format, ...)
{
	va_list	ptr;
	va_list l_arg_snding;
	int		count;
	size_t	f_idx;

	count = 0;
	f_idx = 0;
	va_start(ptr, s_format);
	while (s_format[f_idx] != '\0')
	{
		if (s_format[f_idx] != '%')
			lr_putchar(s_format[f_idx++], count);
		else if ((s_format[f_idx] == '%') && (s_format[f_idx + 1] == '%'))
			lr_ppc(count, f_idx);
		else if (s_format[f_idx++] == '%')
		{
			va_copy(l_arg_snding, ptr);
			p_p_args(s_format[f_idx++], l_arg_snding, count);
			va_arg(ptr, void);
		}
	}
	va_end(ptr);
	return (count);
}
