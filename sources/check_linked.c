/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_linked.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <cchameyr@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 07:21:21 by cchameyr          #+#    #+#             */
/*   Updated: 2015/12/14 15:56:29 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int		ft_checklinkedfirstline(t_form *form, t_point pt)
{
	int match;

	match = 0;
	if (pt.x == 0)
	{
		if (form->shape[pt.y + 1][pt.x] == '#')
			match++;
		if (form->shape[pt.y][pt.x + 1] == '#')
			match++;
	}
	else if (pt.x > 0)
	{
		if (form->shape[pt.y + 1][pt.x] == '#')
			match++;
		if (form->shape[pt.y][pt.x - 1] == '#')
			match++;
		if (form->shape[pt.y][pt.x + 1] == '#')
			match++;
	}
	return (match);
}

int		ft_checklinkedlastline(t_form *form, t_point pt)
{
	int match;

	match = 0;
	if (pt.x == 0)
	{
		if (form->shape[pt.y - 1][pt.x] == '#')
			match++;
		if (form->shape[pt.y][pt.x + 1] == '#')
			match++;
	}
	else if (pt.x > 0)
	{
		if (form->shape[pt.y - 1][pt.x] == '#')
			match++;
		if (form->shape[pt.y][pt.x + 1] == '#')
			match++;
		if (form->shape[pt.y][pt.x - 1] == '#')
			match++;
	}
	return (match);
}

int		ft_checklinkedmiddle(t_form *form, t_point pt)
{
	int match;

	match = 0;
	if (pt.x == 0)
	{
		if (form->shape[pt.y - 1][pt.x] == '#')
			match++;
		if (form->shape[pt.y + 1][pt.x] == '#')
			match++;
		if (form->shape[pt.y][pt.x + 1] == '#')
			match++;
	}
	else if (pt.x > 0)
	{
		if (form->shape[pt.y - 1][pt.x] == '#')
			match++;
		if (form->shape[pt.y + 1][pt.x] == '#')
			match++;
		if (form->shape[pt.y][pt.x - 1] == '#')
			match++;
		if (form->shape[pt.y][pt.x + 1] == '#')
			match++;
	}
	return (match);
}

int		ft_checklinkedform(t_form *form, t_point pt)
{
	int			match;

	match = 0;
	while (pt.y < 4)
	{
		pt.x = 0;
		while (pt.x < 4)
		{
			if (form->shape[pt.y][pt.x] == '#')
			{
				if (pt.y == 0)
					match += ft_checklinkedfirstline(form, pt);
				else if (pt.y == 3)
					match += ft_checklinkedlastline(form, pt);
				else
					match += ft_checklinkedmiddle(form, pt);
			}
			pt.x++;
		}
		pt.y++;
	}
	if (match == 6 || match == 8)
		return (1);
	return (0);
}
