/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzanouji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 10:16:39 by mzanouji          #+#    #+#             */
/*   Updated: 2019/02/23 17:53:11 by mzanouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	lengths(unsigned long long n, size_t *len,
             unsigned long long *weight, unsigned long long base)
{
    *len = 1;
    *weight = 1;
    while (n / *weight > base - 1)
    {
        *weight *= base;
        *len += 1;
    }
}

char	*ft_itoa_base(unsigned long long n, int base)
{
    size_t              len;
    unsigned long long  weight;
    size_t              cur;
    char                *str;

    lengths(n, &len, &weight, base);
    if (!(str = (char *)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
    cur = 0;
    while (weight >= 1)
    {
        str[cur++] = "0123456789ABCDEF"[n / weight % base];
        weight /= base;
    }
    str[cur] = '\0';
    return (str);
}
