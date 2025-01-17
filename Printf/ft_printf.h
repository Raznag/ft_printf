/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzanouji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 10:47:31 by mzanouji          #+#    #+#             */
/*   Updated: 2019/02/04 14:56:18 by mzanouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <limits.h>
#include "../Libft/libft.h"

typedef struct	s_flag
{
	char	flag;
	char	*(*f)(char *, void *);
}				t_flag;

typedef struct	s_modifier
{
	char	mod;
	int		bool;
	int    (*f)(char *, int, int);
}				t_modifier;

int     mod_minus(char *str, int p, int i);
int     mod_plus(char *str, int p, int i);
char    *apply_mod(char *str, char flag);
char    *ft_strcar(size_t size, char caracter);
int		analyze_mod(char *str, char flag, int i);
int		mod_diese(char *str, int p, int i);
int		mod_zero(char *str, int p, int i);
int		mod_space(char *str, int p, int i);
int		convert_hex(char *str, int i);
char	*ft_itoa_hex(unsigned int nb);
char	*ft_itoa_octal(unsigned int nb);
char	*to_binary(unsigned int nb);
char	*flag_X(char *str, void *num);
char	*flag_x(char *str, void *num);
char	*flag_o(char *str, void *num);
char	*flag_di(char *str, void *num);
char	*flag_u(char *str, void *num);

#endif
