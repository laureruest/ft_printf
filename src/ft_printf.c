/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 08:01:02 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/03/24 09:42:52 by lruiz-es         ###   ########.fr       */
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
	char			*str;
	int				num;
	unsigned int	unum;

	if ((*f == 'i') || (*f == 'd') || (*f == 'c'))
	{
		num = va_arg(l_args, int);
		lr_print(f, num, count);
	}
	if ((*f == 'u') || (*f == 'x') || (*f == 'X'))
	{
		unum = va_arg(l_args, unsigned int);
		lr_pruint(f, unum, count);
	}
	if (*f == 's')
	{
		str = va_arg(l_args, char *);
		lr_prstr(str, count);
	}
	if (*f == 'p')
		lr_prptr(l_args, count);
}

int	ft_printf(const char *s_format, ...)
{
	va_list	ptr;
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
			ac_prn(&s[f_idx++], ptr, &count);
	}
	va_end(ptr);
	return (count);
}
