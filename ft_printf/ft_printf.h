/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 14:18:07 by abougrin          #+#    #+#             */
/*   Updated: 2019/12/30 14:28:10 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# define D_VAL flag->dot.value
# define D_TYP flag->dot.type
# define Z_VAL flag->zero.value
# define Z_TYP flag->zero.type
# define M_VAL flag->minus.value
# define M_TYP flag->minus.type

typedef	struct	s_struc
{
	char		*type;
	int			value;
}				t_struc;
typedef struct	s_flagz
{
	t_struc		zero;
	t_struc		minus;
	t_struc		dot;
}				t_flagz;
/*
** ft_printf.c
*/
int				ft_printf(const char *format, ...);
/*
**ft_check_conv.c
*/
int				ft_check_conv(char **str, t_flagz *flag, va_list ap);
int				ft_check_flag(char **str, t_flagz *flag, va_list ap);
/*
**ft_itoa.c
*/
size_t			ft_strlen(char *str);
int				ft_nblen(long n);
char			*ft_itoa(long n);
/*
**ft_write.c
*/
int				ft_putchar(int c);
int				ft_putstr(char *str);
int				ft_rev_str(char *str);
/*
**ft_someft.c
*/
int				abss(int a);
int				printzero(int value, int nbr);
int				arg_gorl0(t_flagz *flag, int arg);
int				ft_dec_to_hex(size_t num, char str);
int				lenhex(size_t num, char str);
/*
**self
*/
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
/*
**ft_someft2.c
*/
int				nbofchar(char **str, int nb, t_flagz *flag);
int				putnull(char *null, char **arg);
int				extraline_z(t_flagz *flag, int larger);
int				extraline_m(t_flagz *flag, int lenarg);
/*
**ft_flagz.c
*/
t_flagz			ft_initia(void);
int				ft_zero(char *str, t_flagz *flag, va_list ap);
int				ft_dot(char *str, t_flagz *flag, va_list ap);
int				ft_minus(char *str, t_flagz *flag, va_list ap);
int				ft_width(char *str, t_flagz *flag, va_list ap);
/*
**ft_conv0-1.c
**ft_helpers.c
*/
int				ft_conv_c(t_flagz *flag, va_list ap);
int				ft_conv_d(t_flagz *flag, va_list ap);
int				ft_help_d(t_flagz *flag, int arg);
int				ft_conv_u(t_flagz *flag, va_list ap);
int				ft_help_u(t_flagz *flag, unsigned int arg);
int				ft_conv_x(char **str, t_flagz *flag, va_list ap);
int				ft_help_x(char **str, t_flagz *flag, unsigned int arg);
int				ft_conv_p(char **str, t_flagz *flag, va_list ap);
int				ft_conv_s(t_flagz *flag, va_list ap, int result);
int				ft_help_s(t_flagz *flag, char *arg);
int				ft_percent(t_flagz *flag);
int				ft_help_percent(t_flagz *flag);

#endif
