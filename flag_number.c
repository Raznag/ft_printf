/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzanouji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 10:58:56 by mzanouji          #+#    #+#             */
/*   Updated: 2019/02/23 17:43:32 by mzanouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*flag_s(char *str, void *arg_s)
{
	int		i;
	char	*tmp;
	char	*new;

	i = 0;
	while (str[i] != '%')
		i++;
	tmp = ft_strsub(str, 0, i);
	i = analyze_mod(str, 's', i);
	new = apply_mod((char*)arg_s, 's');
	tmp = ft_strjoinfree(tmp, new, 3);
	tmp = ft_strjoinfree(tmp, str + i + 1, 1);
	free(str);
	return (tmp);
}

char	*flag_c(char *str, void *num)
{
	char	*tmp;
	int		i;
	char	*car;

	i = 0;
	if (!(car = ft_strcar(1, (unsigned char)num)))
		return (NULL);
	while (str[i] != '%')
		i++;
	tmp = ft_strsub(str, 0, i);
	tmp = ft_strjoinfree(tmp, car, 3);
	while (str[i] != 'c' && str[i])
		i++;
	tmp = ft_strjoinfree(tmp, str + i + 1, 1);
	free(str);
	return (tmp);
}

char	*flag_di(char *str, void *num)
{
	int		i;
	char	*tmp;
	char	*new;

	i = 0;
	while (str[i] != '%')
		i++;
	tmp = ft_strsub(str, 0, i);
	i = analyze_mod(str, 'd', i);
	if (str[i - 1] == 'l' && str[i - 2] == 'l')
		new = apply_mod(ft_itoa((long long)num), 'd');
	else if (str[i - 1] == 'l')
		new = apply_mod(ft_itoa((long)num), 'd');
	else if (str[i - 1] == 'h' && str[i - 2] == 'h')
		new = apply_mod(ft_itoa((signed char)num), 'd');
	else if (str[i - 1] == 'h')
		new = apply_mod(ft_itoa((short)num), 'd');
	else
		new = apply_mod(ft_itoa((int)num), 'd');
	tmp = ft_strjoinfree(tmp, new, 3);
	tmp = ft_strjoinfree(tmp, str + i + 1, 1);
	free(str);
	return (tmp);
}

char    *flag_u(char *str, void *num)
{
    int		i;
    char	*tmp;
	char	*new;

    i = 0;
    while (str[i] != '%')
        i++;
    tmp = ft_strsub(str, 0, i);
	i = analyze_mod(str, 'u', i);
	if (str[i - 1] == 'l' && str[i - 2] == 'l')
		new = apply_mod(ft_itoa_base((unsigned long long)num, 10), 'u');
	else if (str[i -1] == 'l')
		new = apply_mod(ft_itoa_base((unsigned long)num, 10), 'u');
	else if (str[i - 1] == 'h' && str[i - 2] =='h')
		new = apply_mod(ft_itoa_base((unsigned char)num, 10), 'u');
	else if (str[i - 1] == 'h')
		new = apply_mod(ft_itoa_base((unsigned short)num, 10), 'u');
	else
		new = apply_mod(ft_itoa_base((unsigned int)num, 10), 'u');
	tmp = ft_strjoinfree(tmp, new, 3);
	tmp = ft_strjoinfree(tmp, str + i + 1, 1);
	free(str);
	return (tmp);
}

char	*flag_o(char *str, void *num)
{
	int		i;
	char	*tmp;
	char	*new;

	i = 0;
	while (str[i] != '%')
		i++;
    tmp = ft_strsub(str, 0, i);
	i = analyze_mod(str, 'o', i);
	if (str[i - 1] == 'l' && str[i - 2] == 'l')
		new = apply_mod(ft_itoa_base((unsigned long long)num, 8), 'o');
	else if (str[i -1] == 'l')
		new = apply_mod(ft_itoa_base((unsigned long)num, 8), 'o');
	else if (str[i - 1] == 'h' && str[i - 2] =='h')
		new = apply_mod(ft_itoa_base((unsigned char)num, 8), 'o');
	else if (str[i - 1] == 'h')
		new = apply_mod(ft_itoa_base((unsigned short)num, 8), 'o');
	else
		new = apply_mod(ft_itoa_base((unsigned int)num, 8), 'o');
	tmp = ft_strjoinfree(tmp, new, 3);
	tmp = ft_strjoinfree(tmp, str + i + 1, 1);
	free(str);
	return (tmp);
}

char    *flag_X(char *str, void *num)
{
	int		i;
	char	*tmp;
	char	*new;

	i = 0;
	while (str[i] != '%')
		i++;
	tmp = ft_strsub(str, 0, i);
	i = analyze_mod(str, 'X', i);
	if (str[i - 1] == 'l' && str[i - 2] == 'l')
		new = apply_mod(ft_itoa_base((unsigned long long)num, 16), 'X');
	else if (str[i -1] == 'l')
		new = apply_mod(ft_itoa_base((unsigned long)num, 16), 'X');
	else if (str[i - 1] == 'h' && str[i - 2] =='h')
		new = apply_mod(ft_itoa_base((unsigned char)num, 16), 'X');
	else if (str[i - 1] == 'h')
		new = apply_mod(ft_itoa_base((unsigned short)num, 16), 'X');
	else
		new = apply_mod(ft_itoa_base((unsigned int)num, 16), 'X');
	tmp = ft_strjoinfree(tmp, new, 1);
	tmp = ft_strjoinfree(tmp, str + i + 1, 1);
	free(str);
	return (tmp);
}

char	*flag_x(char *str, void *num)
{
	int		i;
	char 	*tmp;
	char	*new;

	i = 0;
	while (str[i] != '%')
		i++;
	tmp = ft_strsub(str, 0, i);
	i = analyze_mod(str, 'x', i);
    if (str[i - 1] == 'l' && str[i - 2] == 'l')
        new = apply_mod(ft_itoa_base((unsigned long long)num, 16), 'x');
    else if (str[i -1] == 'l')
        new = apply_mod(ft_itoa_base((unsigned long)num, 16), 'x');
    else if (str[i - 1] == 'h' && str[i - 2] =='h')
        new = apply_mod(ft_itoa_base((unsigned char)num, 16), 'x');
    else if (str[i - 1] == 'h')
        new = apply_mod(ft_itoa_base((unsigned short)num, 16), 'x');
    else
        new = apply_mod(ft_itoa_base((unsigned int)num, 16), 'x');
	tmp = ft_strjoinfree(tmp, ft_capitalize(new), 1);
	tmp = ft_strjoinfree(tmp, str + i + 1, 1);
	free(str);
	return (tmp);
}
