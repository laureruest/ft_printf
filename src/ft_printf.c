/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 08:01:02 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/03/31 09:30:53 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int	lr_print(char *f, int num, int count);
int	lr_pruint(char *f, int num, int count);
int	lr_prstr(char *s, int count);
int	lr_prptr(void *ptr, int count);

static int	lr_ppc(int count, size_t *idx)
{
	int	rflag;

	rflag = write(1, "%", 1);
	*idx += 2;
	if (rflag < 0)
		return (rflag);
	else
		return (count + rflag);
}

static int	lr_putchar(char *toprn, int count)
{
	int	toret;

	toret = write(1, toprn, 1);
	if (toret >= 0)
		return (count + toret);
	else
		return (toret);
}

static int	ac_prn(char *f, va_list l_args, int count)
{
	char			*str;
	int				num;
	unsigned int	unum;

	if ((*f == 'i') || (*f == 'd') || (*f == 'c'))
	{
		num = va_arg(l_args, int);
		return (lr_print(f, num, count));
	}
	if ((*f == 'u') || (*f == 'x') || (*f == 'X'))
	{
		unum = va_arg(l_args, unsigned int);
		return (lr_pruint(f, unum, count));
	}
	if (*f == 's')
	{
		str = va_arg(l_args, char *);
		return (lr_prstr(str, count));
	}
	if (*f == 'p')
		return (lr_prptr(l_args, count));
	return (0);
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
	while ((s[f_idx] != '\0') && (count >= 0))
	{
		if (s[f_idx] != '%')
			count = lr_putchar(&s[f_idx++], count);
		else if ((s[f_idx] == '%') && (s[f_idx + 1] == '%'))
			count = lr_ppc(count, &f_idx);
		else if (s[f_idx++] == '%')
			count = ac_prn(&s[f_idx++], ptr, count);
	}
	va_end(ptr);
	return (count);
}
