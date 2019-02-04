/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifier.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzanouji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 08:52:33 by mzanouji          #+#    #+#             */
/*   Updated: 2019/02/04 15:15:18 by mzanouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"
#include "ft_modifier.h"

int		analyze_mod(char *str, char flag, int i)
{
	int p;

	p = 0;
	while (str[i] != flag && str[i])
	{
		while (g_mod[p].mod != str[i] && g_mod[p].mod != 'w')
			p++;
		if (g_mod[p].mod == str[i] && g_mod[p].mod != 'w')
			i = g_mod[p].f(str, p, i);
		else
			i++;
		p = 0;
    }
    return (i);
}

int		mod_zero(char *str, int p, int i)
{
	if (g_mod[p].bool != 0)
		exit(0);
    while (ft_isdigit(str[i]))
    {
        g_mod[p].bool = g_mod[p].bool * 10 + str[i] - '0';
        i++;
    }
    return (i);
}

int		mod_space(char *str, int p, int i)
{
	if (g_mod[p].bool == 1)
		exit (0);
	while (ft_isspace(str[i]) || str[i] == '0')
	{
		g_mod[p].bool = 1;
		i++;
	}
	while (str[i - 1] == '0')
		i--;
	return (i);
}

int		mod_plus(char *str, int p, int i)
{
	while (str[i] == '+')
	{
		g_mod[p].bool = 1;
		i++;
	}
	return (i);
}

int     mod_minus(char *str, int p, int i)
{
    while (str[i] == '-')
    {
		g_mod[p].bool = 1;
        i++;
    }
	g_mod[p].bool = ft_atoi(str + i);
    return (i);
}

int		mod_diese(char *str, int p, int i)
{
    while (str[i] == '#')
    {
        g_mod[p].bool = 1;
        i++;
    }
    return (i);
}

char	*apply_mod(char *str, char flag)
{
	if (g_mod[0].bool != 0 && (flag == 'd' || flag == 'i' || flag == 'f'))
		str = ft_strjoin("+", str);
	else if (g_mod[1].bool != 0 && (flag == 'd' || flag == 'i' || flag == 'f'))
		str = ft_strjoin(ft_strcar(1, ' '), str);
	if (g_mod[2].bool > ft_strlen(str))
        str = ft_strjoin(str, ft_strcar(g_mod[2].bool - ft_strlen(str), ' '));
	else if (g_mod[3].bool > ft_strlen(str) && g_mod[2].bool == 0)
		str = ft_strjoin(ft_strcar(g_mod[3].bool - ft_strlen(str), '0'), str);
	return (str);
}

char	*ft_strcar(size_t size, char caracter)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!(str = (char*)malloc(sizeof(*str) * (size + 1))))
		return (NULL);
	str[size] = '\0';
	while (i < size)
		str[i++] = caracter;
	return (str);
}
