/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzanouji <mzanouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 10:18:29 by mzanouji          #+#    #+#             */
/*   Updated: 2019/02/23 17:50:28 by mzanouji         ###   ########.fr       */
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
	//if (str[i] == '%' && str[i + 1] == '%')		
	if (str[i] == '%')
	{
		while (str[i] && flag != 1)
		{
			if ((x = ft_findflag(str[i])) != -1)
			{
				str = g_tab[x].f(str, va_arg(list, void*));
				ft_checkstr(str, i, list);
				flag = 1;
			}
			i++;
			if (str[i] == '\0')
				return (-1);
		}
	}
	else
		printf("%s", str);
	return (i);
}

int		ft_printf(char *str, ...)
{
	va_list list;
	int i;

	i = 0;
	va_start(list, str);
	//while (str[i]!= '\0')
	str = ft_strjoin(str, "\0");
		i = ft_checkstr(str, i, list);
	/*if (str[i] == '%')
	  str = g_tab[0].f(str, va_arg(list, void*));*/
	va_end(list);
	return (0);
}

/*
#define TEST "%10llu alors %10u et %u\n"
#define VALUE 126

int main()
{
	unsigned long *p;
	int a;

	size_t i;
	int *ptr_to_main;
	for (i = 0; i < sizeof ptr_to_main; i++)
		printf("test: %x", ((unsigned char *)&ptr_to_main)[i]);
	putchar('\n');
	printf(TEST, 123456789123456789, -20, -20);
	ft_printf(TEST, 123456789123456789, -20, -20);
	return (0);
}
*/
