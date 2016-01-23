/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <cchameyr@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:42:20 by cchameyr          #+#    #+#             */
/*   Updated: 2016/01/12 15:57:28 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *t;

	t = (unsigned char *)b;
	while (len > 0)
	{
		len--;
		t[len] = (unsigned char)c;
	}
	b = (void *)t;
	return (b);
}
