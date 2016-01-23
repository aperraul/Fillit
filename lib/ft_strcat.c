/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <cchameyr@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:00:40 by cchameyr          #+#    #+#             */
/*   Updated: 2016/01/12 15:56:35 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, char *s2)
{
	int		size;
	int		cpt;

	cpt = 0;
	size = ft_strlen(s1);
	while (s2[cpt])
		s1[size++] = s2[cpt++];
	s1[size] = '\0';
	return (s1);
}
