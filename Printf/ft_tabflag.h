/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabflag.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzanouji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 15:33:44 by mzanouji          #+#    #+#             */
/*   Updated: 2019/02/04 10:07:12 by mzanouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TABFLAG_H
# define FT_TABFLAG_H

t_flag		g_tab[] =
{
	{'d', &flag_di},
	{'i', &flag_di},
	{'u', &flag_u},
	{'o', &flag_o},
	{'x', &flag_x},
	{'X', &flag_X},
	{'w', NULL}
};

/*t_modifier	g_mod[] =
{
	{' ', 0, &mod_space},
	{'-', 0, NULL},
	{'+', 0, NULL},
	{'0', 0, &mod_zero},
	{'#', 0, &mod_diese},
	{'w', 0, NULL}
	};*/

//extern t_modifier g_mod[];
//extern t_flag g_tab[];

#endif
