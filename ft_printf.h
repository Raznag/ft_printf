/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzanouji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 10:47:31 by mzanouji          #+#    #+#             */
/*   Updated: 2019/02/23 17:40:56 by mzanouji         ###   ########.fr       */
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

typedef struct			s_flag
{
	char				flag;
	char				*(*f)(char *, void *);
}						t_flag;

typedef struct			s_modifier
{
	char				mod;
	int					bool;
	int					(*f)(char *, int, int);
}						t_modifier;

typedef struct	s_var
{
	signed char			hhdi;
	short				hdi;
	long				ldi;
	long long			lldi;
	unsigned char		hhouxx;
	unsigned short		houxx;
	unsigned long		louxx;
	unsigned long long	llouxx;
}						t_var;

int				mod_digit(char *str, int p, int i);
int				mod_point(char *str, int p, int i);
int				mod_minus(char *str, int p, int i);
int				mod_plus(char *str, int p, int i);
char			*apply_mod(char *str, char flag);
char			*ft_strcar(size_t size, char caracter);
int				analyze_mod(char *str, char flag, int i);
int				mod_diese(char *str, int p, int i);
int				mod_zero(char *str, int p, int i);
int				mod_space(char *str, int p, int i);
char			*ft_itoa_base(unsigned long long nb, int base);
char			*flag_s(char *str, void *arg_s);
char			*flag_c(char *str, void *num);
char			*flag_X(char *str, void *num);
char			*flag_x(char *str, void *num);
char			*flag_o(char *str, void *num);
char			*flag_di(char *str, void *num);
char			*flag_u(char *str, void *num);

#endif
