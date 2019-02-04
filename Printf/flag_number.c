/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzanouji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 10:58:56 by mzanouji          #+#    #+#             */
/*   Updated: 2019/02/04 14:48:01 by mzanouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*flag_di(char *str, void *num)
{
	int i;
	char *tmp;
	char *new;

	i = 0;
	while (str[i] != '%')
		i++;
	tmp = ft_strsub(str, 0, i);
	i = analyze_mod(str, 'd', i);
	new = apply_mod(ft_itoa((int)num), 'd');
	tmp = ft_strjoin(tmp, new);
	/*while (str[i] != 'd' && str[i] != 'i' && str[i] != '\0')
	  i++;*/
	tmp = ft_strjoin(tmp, str + i + 1);
	ft_putendl(tmp);
	return (tmp);
}

char    *flag_u(char *str, void *num)
{
    int i;
    char *tmp;

    i = 0;
    while (str[i] != '%')
        i++;
    tmp = ft_strsub(str, 0, i);
    tmp = ft_strjoin(tmp, ft_itoa((unsigned int)num));
    while (str[i] != 'u' && str[i] != '\0')
        i++;
    tmp = ft_strjoin(tmp, str + i + 1);
    ft_putendl(tmp);
    return (tmp);
}

char	*flag_o(char *str, void *num)
{
	int	i;
	char *tmp;

	i = 0;
	while (str[i] != '%')
		i++;
    tmp = ft_strsub(str, 0, i);
    tmp = ft_strjoin(tmp, ft_itoa_octal((unsigned int)num));
    while (str[i] != 'o' && str[i])
		i++;
    tmp = ft_strjoin(tmp, str + i + 1);
    ft_putendl(tmp);
    return (tmp);
}

char    *flag_X(char *str, void *num)
{
    int i;
    char *tmp;

    i = 0;
    while (str[i] != '%')
        i++;
    tmp = ft_strsub(str, 0, i);
    tmp = ft_strjoin(tmp, ft_itoa_hex((unsigned int)num));
    while (str[i] != 'X' && str[i])
        i++;
    tmp = ft_strjoin(tmp, str + i + 1);
    ft_putendl(tmp);
    return (tmp);
}

char	*flag_x(char *str, void *num)
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
