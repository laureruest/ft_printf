/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:14:53 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/02/09 12:32:55 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

//return non-zero is there is coincidence
static int	bool_str_in_whis(char *is_here, char *tosearch, size_t len)
{
	int	toreturn;
	int	len_t_s;
	int	ilen;

	ilen = (int) len;
	len_t_s = ft_strlen(tosearch);
	toreturn = 1;
	if (ilen < len_t_s)
		return (0);
	while ((len_t_s > 0) && (toreturn == 1))
	{
		if (*is_here != *tosearch)
			toreturn = 0;
		tosearch++;
		is_here++;
		len_t_s--;
	}
	return (toreturn);
}

//b_coin is bool_coincidence (true if there is coincidence)
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		b_coin;
	int		i;
	char	*wheresearch;
	char	*whatosrch;
	char	*toret;

	toret = NULL;
	wheresearch = (char *) haystack;
	whatosrch = (char *) needle;
	if (len > ft_strlen(wheresearch))
		len = ft_strlen(wheresearch);
	if (*whatosrch == '\0')
		return (wheresearch);
	b_coin = 0;
	i = *wheresearch;
	i = 0;
	while ((len > 0) && (b_coin == 0))
	{
		b_coin = bool_str_in_whis(&wheresearch[i], whatosrch, len);
		i++;
		len--;
	}
	if (b_coin != 0)
		toret = &wheresearch[i - 1];
	return (toret);
}
