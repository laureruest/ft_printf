/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 08:01:02 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/03/20 18:52:26 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include <stdlib.h>

void	lr_print(char *f, int num, int *count);
void	lr_pruint(char *f, int num, int *count);
void	lr_prstr(char *s, int *count);
void	lr_prptr(void *ptr, int *count);

static void	lr_ppc(int *count, size_t *idx)
{
	ft_putchar_fd('%', 1);
	*count += 1;
	*idx += 2;
}

static void	lr_putchar(char toprn, int *count)
{
	ft_putchar_fd(toprn, 1);
	*count += 1;
}

static void	ac_prn(char *f, va_list l_args, int *count)
{
	char	*str;
	int		num;

	if ((*f == 'i') || (*f == 'd') || (*f == 'c'))
	{
		num = va_arg(l_args, int);
		lr_print(f, num, count);
	}
	if ((*f == 'u') || (*f == 'x') || (*f == 'X'))
	{
		num = va_arg(l_args, unsigned int);
		lr_pruint(f, num, count);
	}
	if (*f == 's')
	{
		str = va_arg(l_args, char *);
		lr_prstr(str, count);
		free(str);
	}
	if (*f == 'p')
		lr_prptr(l_args, count);
	va_end(l_args);
}

int	ft_printf(const char *s_format, ...)
{
	va_list	ptr;
	va_list	l_arg_snding;
	int		count;
	size_t	f_idx;
	char	*s;

	s = (char *) s_format;
	count = 0;
	f_idx = 0;
	va_start(ptr, s_format);
	while (s[f_idx] != '\0')
	{
		if (s[f_idx] != '%')
			lr_putchar(s[f_idx++], &count);
		else if ((s[f_idx] == '%') && (s[f_idx + 1] == '%'))
			lr_ppc(&count, &f_idx);
		else if (s[f_idx++] == '%')
		{
			va_copy(l_arg_snding, ptr);
			ac_prn(&s[f_idx++], l_arg_snding, &count);
			*s = va_arg(ptr, int);
		}
	}
	va_end(ptr);
	return (count);
}
