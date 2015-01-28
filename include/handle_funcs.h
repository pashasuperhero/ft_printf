/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_funcs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 12:45:58 by rlambert          #+#    #+#             */
/*   Updated: 2015/01/28 22:30:45 by rlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_FUNCS_H
# define HANDLE_FUNCS_H
# include <stdarg.h>
# include "ft_printf.h"
# include <stdint.h>
#include <sys/types.h>

typedef struct	s_arg
{
	int				force_prefix : 1;
	int				pad_zeroes : 1;
	int				right_pad : 1;
	int				force_sign : 1;
	int				blank_sign : 1;
	int				got_width : 1;
	int				got_precision : 1;
	unsigned int	width;
	unsigned int	precision;
	enum {
		none,
		hh,
		h,
		l,
		ll,
		j,
		z,
	}				length;
}					t_arg;

typedef ssize_t(*t_handler)(char**, va_list*, t_arg*);
ssize_t		handle_escape(char **format, va_list *args, t_arg *arg);
ssize_t		handle_str(char **format, va_list *args, t_arg *arg);
ssize_t		handle_wstr(char **format, va_list *args, t_arg *arg);
ssize_t		handle_ptr(char **format, va_list *args, t_arg *arg);
ssize_t		handle_int(char **format, va_list *args, t_arg *arg);
ssize_t		handle_long(char **format, va_list *args, t_arg *arg);
ssize_t		handle_octal(char **format, va_list *args, t_arg *arg);
ssize_t		handle_unsigned(char **format, va_list *args, t_arg *arg);
ssize_t		handle_hex(char **format, va_list *args, t_arg *arg);
ssize_t		handle_char(char **format, va_list *args, t_arg *arg);
ssize_t		handle_wchar(char **format, va_list *args, t_arg *arg);
ssize_t		handle_null(char**format, va_list *args, t_arg *arg);
ssize_t		generic_handle_unsigned(char **, va_list *, t_arg *, char *, char *);
t_handler	get_handler(char c);
#endif