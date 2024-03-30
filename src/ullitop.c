/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ullitop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:15:14 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/03/30 12:56:02 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static unsigned long long int	my_pow(unsigned long long int b, int exp)
{
	if (exp == 0)
		return (1);
	if (exp == 1)
		return (b);
	exp--;
	return (b * my_pow(b, exp));
}

static int	pr_dig(char *f, unsigned long long int n, int wg)
{
	unsigned long long int	dig;
	int						prtd;
	int						base;

	if (*f == 'u')
		base = 10;
	else
		base = 16;
	dig = n / (my_pow(base, wg));
	if (dig < 10)
		dig += '0' - '\0';
	else if (dig > 9)
	{
		dig += 'a' - '\0' - 10;
		if (*f == 'X')
			dig -= 'a' - 'A';
	}
	prtd = write (1, (char *) &dig, 1);
	return (prtd);
}

static int	pr(char *f, unsigned long long int n, int exp, int acum)
{
   	int	aux;
	
	aux = pr_dig(f, n, exp);
	if (aux < 0)
		return (aux);
	else
		acum += aux;
	if (exp == 0)
		return (acum);
	n %= my_pow(16, exp);
	exp--;
	return (pr(f, n, exp, acum));
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
	toret  = pr(f, n, c_wg(n, 0), toret);
	return (toret);
}
