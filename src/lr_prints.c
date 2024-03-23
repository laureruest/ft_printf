/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lr_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:16:24 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/03/23 10:56:29 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

void	lr_print(char *f, int num, int *count)
{
	char	*str;

	if (*f == 'c')
	{
		*count += 1;
		ft_putchar_fd(num, 1);
	}
	else if ((*f == 'd') || (*f == 'i') || (*f == 'u'))
	{
		str = ft_itoa(num);
		ft_putstr_fd(str, 1);
		*count += ft_strlen(str);
		free(str);
	}
}

void	lr_pruint(char *f, int num, int *count)
{
	char					*str;
	int						idx;

	if (*f == 'u')
	{
		lr_print(f, num, count);
		return ;
	}
	str = ft_ullitohex(num);
	if (*f == 'X')
	{
		idx = 0;
		while (str[idx] != '\0')
		{
			str[idx] = ft_toupper(str[idx]);
			idx++;
		}
	}
	*count += ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
}

void	lr_prstr(char *s, int *count)
{
	*count += ft_strlen(s);
	ft_putstr_fd(s, 1);
}

void	lr_prptr(va_list args, int *count)
{
	unsigned long long int	lnum;
	char					*str;

	lnum = (unsigned long long int) va_arg(args, void *);
	str = ft_ullitohex(lnum);
	*count += ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
}
