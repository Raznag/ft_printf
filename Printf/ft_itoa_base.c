/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzanouji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 10:16:39 by mzanouji          #+#    #+#             */
/*   Updated: 2019/02/02 17:42:03 by mzanouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_rmzero(char *str)
{
	int i;

	i = 0;
	while (str[i] == '0')
		i++;
	return (i);
}

char	*to_binary(unsigned int nb)
{
	char *str;
	int i;

	i = 0;
    if (!(str = (char*)malloc(sizeof(char) * 33)))
        return (NULL);
    str[32] = '\0';
    while (i < 32)
        str[i++] = '0';
	i = 0;
	while (nb != 0)
    {
		str[i++] = (nb % 2) + '0';
        nb /= 2;
    }
	return (str);
}

char	*ft_itoa_octal(unsigned int nb)
{
	char *str;
	int i;
	char *new;
	int count = 0;
	int c;

	c = 10;
	if (!(new = (char*)malloc(sizeof(char) * 12)) || !(str = to_binary(nb)))
        return (NULL);
	i = 11;
	new[11] = '\0';
	while (--i > -1)
        new[i] = '0';
	while (++i < 32)
	{
		if (count == 0 && str[i] == '1')
			new[c] = new[c] + 1;
		else if (count != 0 && str[i] == '1')
			new[c] = new[c] + count * 2;
		if (count++ == 2 && c--)
			count = 0;
	}
	return (new + ft_rmzero(new));
}

int     convert_hex(char *str, int i)
{
    int     sum;
    int     count;

    count = 0;
    sum = 0;
    while (str[i] && count < 4 )
    {
		if (count == 0 && str[i] == '1')
			sum = sum + 1;
		else if (count == 3 && str[i] == '1')
			sum = sum + 8;
		else if (count != 0 && str[i] == '1')
			sum = sum + count * 2;
        i++;
		count++;
    }
    return (sum < 10 ? sum : sum + 7);
}

char    *ft_itoa_hex(unsigned int nb)
{
	char	*str;
	int		i;
	char	*new;
	int		count;
	int		c;

	count = -1;
	c = 10;
	if (!(new = (char*)malloc(sizeof(char) * 9)) || !(str = to_binary(nb)))
		return (NULL);
	i = 8;
	new[8] = '\0';
	while (i-- > 0)
		new[i] = '0';
	i = 0;
	while (i < 32)
	{
		new[c--] = convert_hex(str, i) + '0';
		i = i + 4;
	}
	return (new + ft_rmzero(new));
}
/*#include <unistd.h>

void ft_putchar(char c) { write(1, &c, 1); }
void lol(unsigned int nb)
{
	char *base = "0123456789ABCDEF";
	while (nb > 0)
	{
		ft_putchar(base[nb % 16]);
		nb /= 16;
	}
	ft_putchar('\n');
}
#include <limits.h>
#include <stdio.h>
int main()
{
	int b = -1;
	unsigned int a = -123456;
	printf("momo le gros naze %x\n", a);
	lol(-123456);
}
*/
