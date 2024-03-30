/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 09:00:00 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/03/30 10:53:54 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>

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

// put sing, count the size of work (calculatin wg, weight of digit more sig)
// and starts
char	*ft_itoa(int n)
{
	unsigned short int	wg;
	char				*tor;
	size_t				l;

	wg = c_wg(n, 0);
	l = ((size_t) wg) + 2;
	if (n < 0)
		l++;
	tor = malloc(l);
	if (tor != NULL)
	{
		l = 0;
		ins(tor, n, l, wg);
	}
	return (tor);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullitohex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:18:18 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/03/23 12:07:48 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static unsigned long long int	my_pow(unsigned long long int b, int exp)
{
	if (exp == 0)
		return (1);
	if (exp == 1)
		return (b);
	exp--;
	return (b * my_pow(b, exp));
}

static char	conv_dig(unsigned long long int n, int wg)
{
	unsigned long long int	dig;

	dig = n / (my_pow(16, wg));
	if (dig < 10)
		dig += '0' - '\0';
	else if (dig > 9)
		dig += 'a' - '\0' - 10;
	return (dig);
}

// redim ptr data size & fill string
static void	ins(char *ptr, unsigned long long int n, size_t cursor, int exp)
{
	ptr[cursor] = conv_dig(n, exp);
	cursor++;
	if (exp == 0)
	{
		ptr[cursor] = '\0';
		return ;
	}
	n %= my_pow(16, exp);
	exp--;
	ins(ptr, n, cursor, exp);
}

// compute the more significave's exponent for base_10 of ABS(n)
static int	c_wg(unsigned long long int n, int exp)
{
	if (n < 16)
		return (exp);
	exp++;
	return (c_wg(n / 16, exp));
}

// put sing, count the size of work (calculatin wg, weight of digit more sig)
// and starts
char	*ft_ullitohex(unsigned long long int n)
{
	int		wg;
	char	*tor;
	size_t	l;

	wg = c_wg(n, 0);
	l = ((size_t) wg) + 4;
	tor = malloc(l);
	if (tor != NULL)
	{
		tor[0] = '0';
		tor[1] = 'x';
		l = 2;
		ins(tor, n, l, wg);
	}
	return (tor);
}
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uitohex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:04:25 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/03/23 14:05:35 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static unsigned long long int	my_pow(unsigned long long int b, int exp)
{
	if (exp == 0)
		return (1);
	if (exp == 1)
		return (b);
	exp--;
	return (b * my_pow(b, exp));
}

static char	conv_dig(unsigned long long int n, int wg)
{
	unsigned long long int	dig;

	dig = n / (my_pow(16, wg));
	if (dig < 10)
		dig += '0' - '\0';
	else if (dig > 9)
		dig += 'a' - '\0' - 10;
	return (dig);
}

// redim ptr data size & fill string
static int	pr(unsigned long long int n, int exp)
{
	char	toprn;
	int		toret;

   	toprn = conv_dig(n, exp);
	if (exp == 0)
	{
		return ;
	}
	n %= my_pow(16, exp);
	exp--;
	ins(ptr, n, cursor, exp);
}

static int	c_wg(unsigned long long int n, int exp)
{
	if (n < 16)
		return (exp);
	exp++;
	return (c_wg(n / 16, exp));
}

int	ullitohexp(char *f, unsigned long long int n)
{
	int	toret;
	int	aux;

	toret = 0;
	aux = 0;
	if (*f == 'p')
		aux = write(1, "0x", 2);
	if (aux < 0)
		return (aux);
	toret += aux;

	return (toret);
}
