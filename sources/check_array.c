/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <cchameyr@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 07:21:07 by cchameyr          #+#    #+#             */
/*   Updated: 2015/12/14 16:48:14 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int		ft_checkarray(t_form *form, t_point pt)
{
	int		sharp;

	sharp = 0;
	while (pt.y < 4)
	{
		pt.x = 0;
		while (pt.x < 4)
		{
			if (form->shape[pt.y][pt.x] != '#' &&
				form->shape[pt.y][pt.x] != '.' &&
				form->shape[pt.y][pt.x] != '\n')
				return (0);
			if (form->shape[pt.y][pt.x] == '#')
				sharp++;
			pt.x++;
		}
		pt.y++;
	}
	if (sharp == 4)
		return (1);
	return (0);
}

int		ft_checklistform(t_form *list_form)
{
	t_form		*form;
	t_point		pt;

	pt.x = 0;
	pt.y = 0;
	if (!list_form)
		return (0);
	form = list_form;
	while (form)
	{
		if (ft_checkarray(form, pt))
		{
			if (!(ft_checklinkedform(form, pt)))
				return (0);
		}
		else
			return (0);
		form = form->next;
	}
	return (1);
}
