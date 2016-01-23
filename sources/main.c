/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <cchameyr@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 16:26:41 by cchameyr          #+#    #+#             */
/*   Updated: 2015/12/18 14:18:00 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

char	*ft_fdcapture(char *path)
{
	int		fd;
	char	c;
	char	*str;
	t_str	*l_str;
	int		max;

	max = 546;
	l_str = NULL;
	str = NULL;
	if ((fd = open(path, O_RDONLY)) < 0)
		return (NULL);
	while (read(fd, &c, 1) && max--)
		l_str = ft_addc(l_str, c);
	if (!max)
		return (NULL);
	str = ft_exportstr(l_str);
	ft_freelststr(l_str);
	return (str);
}

int		ft_fillit(char *path)
{
	t_form		*begin_form;
	t_point		pt;
	char		*str;
	t_square	sqr;

	pt.x = 0;
	pt.y = 0;
	if (!(str = ft_fdcapture(path)))
		return (0);
	if (!(begin_form = ft_getform(str, pt, 0)))
		return (0);
	if (!(ft_checklistform(begin_form)))
		return (0);
	begin_form = ft_initform(begin_form, pt);
	sqr.size = ft_minsize(ft_cptform(begin_form));
	sqr.sizeout = 1;
	while (sqr.sizeout == 1)
	{
		sqr = ft_compct(ft_initsqr(sqr.size), begin_form, pt);
		if (sqr.sizeout == 1)
			sqr.size++;
	}
	ft_displaysquare(sqr, 0, 0, sqr.size);
	ft_freeform(begin_form);
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!ft_fillit(argv[1]))
			ft_putstr("error\n");
	}
	else
		ft_putstr("error\n");
	return (0);
}
