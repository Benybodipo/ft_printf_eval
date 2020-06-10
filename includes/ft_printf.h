/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besteba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 11:12:41 by besteba           #+#    #+#             */
/*   Updated: 2018/08/22 11:55:14 by besteba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <wchar.h>
# include <inttypes.h>
# include <string.h>

typedef struct		s_format
{
	char			flag;
	char			sign;
	char			prefix;
	unsigned int	width;
	unsigned int	precision;
	char			*length;
	int				ilenth;
	char			specifier;
	int				is_negative;
}					t_format;

int					is_in_str(char *str, int c);
int					is_digit(int c);
size_t				ft_strlen(const char *str);
int					ft_atoi(char *str);
char				*ft_itoa_base(int num, int base);
char				*ft_uitoa_base(uintmax_t num, int base);
int					ft_strcmp(char *str1, char *str2);
char				*ft_strdup(const char *str);
char				*preppend(char *tmp, char *to_insert);

int					ft_printf(const char *format, ...);
void				print_percent(const char **format);
void				handle_format(t_format *form, va_list ap);
uintmax_t			get_unsigned_num(va_list args, t_format *form);
intmax_t			get_signed_num(va_list args, t_format *form);
char				*get_length(const char **str);
void				handle_length(va_list ap, t_format *form, char **tmp);
void				padding_right(char **tmp, char *from, int width, char c);
void				padding_left(char **tmp, char *from, int width, char c);
void				allocate_mem_pointer(char **str, int len);
void				set_pointer_len(char **p, unsigned int *len,
					t_format *form);
char				*pointer(char *pointer, t_format *form, int len);
void				get_pointer(char **tmp, void *ptr, t_format *form);
void				handle_precision(t_format *form, char **tmp);
int					get_base(char c);
char				*add_prefix(char *tmp, t_format *form);
void				handle_prefix(char **tmp, t_format *form);
void				print_char(char c, int specifier);
void				print_str(char *str, t_format *form);
void				flags_slector(t_format *form, const char **str);
void				handle_struct(const char **format, t_format *form,
					va_list ap);
void				reset_struct(t_format *form);
int					ft_wcharlen(wchar_t wchar);
size_t				ft_wstrlen(wchar_t *ws);
size_t				ft_wbytelen(wchar_t *ws);
int					wchar_utf8(wchar_t wc, char *convertion);
int					ft_wchartochar(wchar_t wc);
char				*ft_wstrtostr(wchar_t *wstr);
void				add_zero(char **tmp, t_format *form);
char				*get_num(const char **str, int *dot);
void				handle_is_negative(va_list ap, t_format *form, char **tmp);

#endif
