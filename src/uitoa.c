/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uitoa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:03:28 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/03/23 15:51:55 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static unsigned long long int	my_pow(unsigned int b, unsigned short int exp)
{
	if (exp == 0)
		return (1);
	if (exp == 1)
		return (b);
	exp--;
	return (b * my_pow(b, exp));
}

static char	conv_dig(unsigned long long int n, unsigned short int wg)
{
	unsigned long long int	dig;

	dig = n / (my_pow(10, wg));
	dig += '0' - '\0';
	return (dig);
}

// redim ptr data size & fill string
static void	ins(char *p, unsigned int n, size_t cur, unsigned short int exp)
{
	p[cur] = conv_dig(n, exp);
	cur++;
	if (exp == 0)
	{
		p[cur] = '\0';
		return ;
	}
	n %= my_pow(10, exp);
	exp--;
	ins(p, n, cur, exp);
}

// compute the more significave's exponent for base_10 of ABS(n)
static unsigned int	c_wg(unsigned int n, unsigned short int exp)
{
	if (n < 10)
		return (exp);
	exp++;
	return (c_wg(n / 10, exp));
}

// put sing, count the size of work (calculatin wg, weight of digit more sig)
// and starts
char	*uitoa(unsigned int n)
{
	unsigned short int	wg;
	char				*tor;
	size_t				l;

	wg = c_wg(n, 0);
	l = ((size_t) wg) + 2;
	tor = malloc(l);
	if (tor != NULL)
	{
		l = 0;
		ins(tor, n, l, wg);
	}
	return (tor);
}
