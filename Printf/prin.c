/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzanouji <mzanouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 10:18:29 by mzanouji          #+#    #+#             */
/*   Updated: 2019/02/04 16:31:13 by mzanouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"
#include "ft_tabflag.h"

int		ft_findflag(char c)
{
	int x;

	x = 0;
	while (g_tab[x].flag != c && g_tab[x].flag != 'w')
		x++;
	if (c != 'w' && g_tab[x].flag == c)
		return (x);
	return (-1);
}

int		ft_checkstr(char *str, int i, va_list list)
{
	int x;
	int flag;

	flag = 0;
	x = 0;
	while (str[i] != '%' && str[i] != '\0')
		i++;
	if (str[i] == '%')
	{
		while (str[i] && flag != 1)
		{
			if ((x = ft_findflag(str[i])) != -1)
			{
				g_tab[x].f(str, va_arg(list, void*));
				flag = 1;
			}
			i++;
		}
	}
	return (i);
}

int		ft_printf(char *str, ...)
{
	va_list list;
	int i;

	i = 0;
	va_start(list, str);
	i = ft_checkstr(str, i, list);
	if (str[i] == '%')
		str = g_tab[0].f(str, va_arg(list, void*));
	va_end(list);
	return (0);
}

int main()
{
	//char t[] = "12345";
	printf("atoi: %d\n", atoi("ss"));
	fflush(stdout);
	ft_printf("%- 20d\n", 0);
	printf("%- 20d\n", 0);
	//printf("% 5d\n", 256);
	//printf("max:%d ry min:%d\n", USHRT_MAX, SHRT_MIN);
	return (0);
}
