/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:18:38 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/03/30 12:50:26 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ullitop(char *f, unsigned long long int n);

int	itop(int n)
{
	int						toret;
	int						aux;
	unsigned long long int	lnum;

	toret = 0;
	if (n < 0)
	{
		toret = write(1, "-", 1);
		lnum = (unsigned long long int) (-num);
	}
	if (n >=0)
		lnum = (unsigned long long int) num;
	if (toret < 0)
		return (toret);
	aux = ullitop("u", lnum);
	if (aux < 0)
		return (aux);
	toret += aux;
	return (toret);
}
