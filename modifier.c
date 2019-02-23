/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifier.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzanouji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 08:52:33 by mzanouji          #+#    #+#             */
/*   Updated: 2019/02/23 16:00:05 by mzanouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"
#include "ft_modifier.h"

void	clean_signe(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '-' && str[i])
		i++;
	if (str[i] == '-' && str[i - 1] == '0')
	{
		str[i] = '0';
		str[0] = '-';
	}
}

int		analyze_mod(char *str, char flag, int i)
{
	int p;
	int	neg;

	neg = 0;
	p = 0;
	while (str[i] != flag && str[i])
	{
		while (g_mod[p].mod != str[i] && g_mod[p].mod != 'w')
			p++;
		if (g_mod[p].mod == str[i] && g_mod[p].mod != 'w')
			i = g_mod[p].f(str, p, i);
		else if (ft_isdigit(str[i]))
		  i = g_mod[6].f(str, 6, i);
		else
			i++;
		p = 0;
    }
	//g_mod[6].bool -= g_mod[0].bool;
    return (i);
}

int     mod_digit(char *str, int p, int i)
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

int		mod_zero(char *str, int p, int i)
{
	if (g_mod[p].bool != 0)
		exit(0);
    while (str[i] == '0')
        //g_mod[p].bool = g_mod[p].bool * 10 + str[i] - '0';
        i++;
	g_mod[p].bool = 1;
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

int		mod_point(char *str, int p, int i)
{
	if (g_mod[p].bool != -1) //|| (ft_isdigit(str[i + 1]) == 0 && str[i + 1] != g_mod[p].mod))
		exit(0);
	while (str[i] == '.')
		i++;
	g_mod[p].bool = 0;//ft_atoi(str + i);
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

void	reset_mod(void)
{
	int i;

	i = 0;
	while (g_mod[i].mod != 'w')
	{
		if (g_mod[i].mod == '.')
			g_mod[i].bool = -1;
		else
			g_mod[i].bool = 0;
		i++;
	}
}

int		is_neg(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

char	*apply_mod(char *str, char flag)
{
	int	signe;

	signe = is_neg(str);
	if (flag == 'c' || flag == 's')
	{
		if (flag == 's' && g_mod[5].bool != -1)
		{
			str = ft_strsub(str, 0, g_mod[6].bool);
		printf("\n2str:%s et %d", str, g_mod[6].bool);
		}
		else
			str = ft_strjoin(str, "\0");
	}
	else
	{
		if ((size_t)g_mod[2].bool > ft_strlen(str))
			str = ft_strjoin(str, ft_strcar(g_mod[2].bool - ft_strlen(str), ' '));
		else if (g_mod[5].bool != -1 && (size_t)g_mod[6].bool > ft_strlen(str) && g_mod[2].bool == 0)
			str = ft_strjoin(ft_strcar(g_mod[6].bool - ft_strlen(str), '0'), str);
		else if (g_mod[3].bool != 0 && (size_t)g_mod[6].bool > ft_strlen(str) && g_mod[2].bool == 0)
			str = ft_strjoin(ft_strcar(g_mod[6].bool - ft_strlen(str), '0'), str);
		if (g_mod[0].bool != 0 && (flag == 'd' || flag == 'i' || flag == 'f') && signe == 0)
			str = ft_strjoin("+", str);
		else if (g_mod[1].bool != 0 && (flag == 'd' || flag == 'i' || flag == 'f') && g_mod[2].bool == 0 && signe == 0)
		{
			if (str[0] == '0')
				str[0] = ' ';
			else
				str = ft_strjoin(ft_strcar(1, ' '), str);
		}
		if ((unsigned long)g_mod[6].bool > ft_strlen(str))
			str = ft_strjoin(ft_strcar(g_mod[6].bool - ft_strlen(str), ' '), str);
	}
	clean_signe(str);
	reset_mod();
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
