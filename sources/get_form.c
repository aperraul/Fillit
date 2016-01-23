/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_form.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <cchameyr@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 04:19:27 by cchameyr          #+#    #+#             */
/*   Updated: 2015/12/18 14:13:55 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

t_form		*ft_voidline(t_form *form, t_point pt)
{
	while (pt.x < 4)
	{
		if (form->shape[pt.y][pt.x] == '#')
			return (form);
		pt.x++;
		if (pt.x == 4)
		{
			pt.y++;
			while (pt.y < 4)
			{
				pt.x = 0;
				while (pt.x < 4)
				{
					form->shape[pt.y - 1][pt.x] = form->shape[pt.y][pt.x];
					form->shape[pt.y][pt.x] = '.';
					pt.x++;
				}
				pt.y++;
			}
			pt.y = 0;
			pt.x = 0;
		}
	}
	return (NULL);
}

t_form		*ft_voidcolon(t_form *form, t_point pt)
{
	while (pt.y < 4)
	{
		if (form->shape[pt.y][pt.x] == '#')
			return (form);
		pt.y++;
		if (pt.y == 4)
		{
			pt.x++;
			while (pt.x < 4)
			{
				pt.y = 0;
				while (pt.y < 4)
				{
					form->shape[pt.y][pt.x - 1] = form->shape[pt.y][pt.x];
					form->shape[pt.y][pt.x] = '.';
					pt.y++;
				}
				pt.x++;
			}
			pt.x = 0;
			pt.y = 0;
		}
	}
	return (NULL);
}

t_form		*ft_initform(t_form *begin_form, t_point pt)
{
	t_form *form;

	form = begin_form;
	while (form)
	{
		form = ft_voidline(form, pt);
		form = ft_voidcolon(form, pt);
		while (pt.y < 4)
		{
			while (pt.x < 4)
			{
				if (form->shape[pt.y][pt.x] != '#')
					form->shape[pt.y][pt.x] = 0;
				pt.x++;
			}
			pt.x = 0;
			pt.y++;
		}
		pt.y = 0;
		form = form->next;
	}
	return (begin_form);
}

t_form		*ft_getform(char *str, t_point pt, int i)
{
	t_form	*form;
	t_form	*begin;

	begin = ft_newform(1);
	form = begin;
	while (str[i])
	{
		pt.x = 0;
		while (pt.x < 4 && str[i])
		{
			form->shape[pt.y][pt.x] = str[i];
			pt.x++;
			i++;
		}
		i++;
		pt.y++;
		if (pt.y == 4 && str[i])
		{
			form->next = ft_newform(form->index + 1);
			form = form->next;
			pt.y = 0;
			i++;
		}
	}
	return (i - (5 * form->index + 1) == (form->index * 16) ? NULL : begin);
}
