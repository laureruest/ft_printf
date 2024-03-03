/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:38:22 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/01/19 18:35:17 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int	isupper(int carac)
{
	return ((carac >= 'A') && (carac <= 'Z'));
}

static	int	islower(int carac)
{
	return ((carac >= 'a') && (carac <= 'z'));
}

int	ft_isalpha(int c)
{
	int	toret;

	toret = (isupper(c) || islower(c));
	return (toret);
}
