/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modifier.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzanouji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 09:42:02 by mzanouji          #+#    #+#             */
/*   Updated: 2019/02/11 15:37:24 by mzanouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MODIFIER_H
# define FT_MODIFIER_H

#include "ft_printf.h"

t_modifier  g_mod[] =
{
    {'+', 0, &mod_plus},
    {' ', 0, &mod_space},
    {'-', 0, &mod_minus},//o u et x ignores
    {'0', 0, &mod_zero},
    {'#', 0, &mod_diese},
	{'.', -1, &mod_point},//5
	{'9', 0, &mod_digit},
    {'w', 0, NULL}
};

#endif
