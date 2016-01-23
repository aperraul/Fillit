/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 15:20:46 by cchameyr          #+#    #+#             */
/*   Updated: 2015/12/14 16:04:31 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int			ft_cptform(t_form *form)
{
	t_form *list;

	if (!form)
		return (0);
	list = form;
	while (list->next)
		list = list->next;
	return (list->index);
}

int			ft_minsize(int nbform)
{
	int		size;

	size = 2;
	while (size * size < nbform * 4)
		size++;
	return (size);
}

t_square	ft_initsqr(int size)
{
	int			y;
	t_square	sqr;

	y = 0;
	while (y < size)
	{
		ft_memset(sqr.array[y], '.', size);
		y++;
	}
	sqr.fault = 0;
	sqr.size = size;
	sqr.error = 0;
	sqr.sizeout = 0;
	return (sqr);
}

void		ft_displaysquare(t_square sqr, int x, int y, int size)
{
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			ft_putchar(sqr.array[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}
