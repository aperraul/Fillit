/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:47:47 by cchameyr          #+#    #+#             */
/*   Updated: 2015/12/18 14:20:18 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdlib.h>
# include "libft.h"

typedef	struct		s_str
{
	char			str[32];
	int				index;
	struct s_str	*next;
}					t_str;

typedef struct		s_form
{
	char			shape[4][4];
	int				index;
	struct s_form	*next;
}					t_form;

typedef struct		s_square
{
	char			array[26][26];
	int				fault;
	int				size;
	int				sizeout;
	int				error;
}					t_square;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

t_str				*ft_addstr(t_str *begin, char *str);
t_str				*ft_addc(t_str *begin, char c);
t_str				*ft_newlstr(void);
int					ft_indexcpt(t_str *begin);
t_str				*ft_freelststr(t_str *begin);
char				*ft_exportstr(t_str *begin);

t_form				*ft_newform(int index);
void				ft_displaylist(t_form *begin, int x, int y);
void				ft_displayform(t_form *form, int x, int y);
t_form				*ft_freeform(t_form *form);

#endif
