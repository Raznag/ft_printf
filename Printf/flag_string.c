/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzanouji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:51:33 by mzanouji          #+#    #+#             */
/*   Updated: 2019/01/29 16:59:31 by mzanouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_tabflag.h"

char	*flag_c(char *str, void *num)
{
	char *tmp;
	int i;

	i = 0;
	while (str[i] != '%')
		i++;
	tmp = ft_strsub(str, 0, i);
	tmp = ft_strjoin(tmp, ft_capitalize(ft_itoa_hex((unsigned int)num)));
	while (str[i] != 'x' && str[i])
		i++;
	tmp = ft_strjoin(tmp, str + i + 1);
	ft_putendl(tmp);
	return (tmp);
}
