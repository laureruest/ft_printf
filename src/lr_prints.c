/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lr_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:16:24 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/03/30 10:54:00 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int	ullitohexp(char *f, unsigned long long int n);
int	itop(int num);
int	uitop(unsigned int num);

int	strlen(char *s)
{
	int	idx;
	int	toret;

	idx = 0;
	toret = 0;
	while (s[idx++] != '\0')
		toret++;
	return (toret);
}

int	lr_print(char *f, int num, int count)
{
	char	*str;
	int		toret;

	if (*f == 'c')
	{
		str = (char *) &num;
		toret = write(1, str, 1);
	}
	else
		toret = itop(num);
	if (toret < 0)
		return (toret);
	else
		return (toret + count);
}

int	lr_pruint(char *f, unsigned int num, int count)
{
	int	toret;

	if (*f == 'u')
		toret = uitop(num);
	else
		toret = ullitohexp(f, num);
	if (toret < 0)
		return (toret);
	else
		return (toret + count);
}

int	lr_prstr(char *s, int count)
{
	int	toret;

	if (s)
		toret = write(1, s, strlen(s));
	else
		toret = write(1, "(null)", 6);
	if (toret < 0)
		return (toret);
	else
		return (toret + count);
}

int	lr_prptr(va_list args, int count)
{
	unsigned long long int	lnum;
	int	toret;

	lnum = (unsigned long long int) va_arg(args, void *);
	toret = ullitohexp("p", lnum);
	if (toret < 0)
		return (toret);
	else
		return (toret + count);
}
