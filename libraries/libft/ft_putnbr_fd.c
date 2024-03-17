/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:01:48 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/02/09 13:13:15 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

static int	my_pow(int b, unsigned short int exp)
{
	if (exp == 0)
		return (1);
	if (exp == 1)
		return (b);
	exp--;
	return (b * my_pow(b, exp));
}

static char	conv_dig(int n, unsigned short int wg)
{
	int	dig;

	dig = n / (my_pow(10, wg));
	if (dig < 0)
		dig *= -1;
	return (((unsigned char) dig) + '0' - '\0');
}

// redim ptr data size & fill string
static void	ins(char *ptr, int n, size_t cursor, unsigned short int exp)
{
	if ((n < 0) && (cursor == 0))
	{
		ptr[cursor] = '-';
		cursor ++;
	}
	ptr[cursor] = conv_dig(n, exp);
		cursor++;
	if (exp == 0)
	{
		ptr[cursor] = '\0';
		return ;
	}
	n %= my_pow(10, exp);
	exp--;
	ins(ptr, n, cursor, exp);
}

// compute the more significave's exponent for base_10 of ABS(n)
static unsigned short int	c_wg(int n, unsigned short int exp)
{
	if ((n > -10) && (n < 10))
		return (exp);
	exp++;
	return (c_wg(n / 10, exp));
}

void	ft_putnbr_fd(int n, int fd)
{
	char				buf[13];
	unsigned short int	wg;
	size_t				l;

	l = 0;
	wg = c_wg(n, 0);
	ins(buf, n, l, wg);
	write(fd, buf, ft_strlen(buf));
}
