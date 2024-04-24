/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ma <abdel-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:17:11 by abdel-ma          #+#    #+#             */
/*   Updated: 2024/04/23 19:01:07 by abdel-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <strings.h>
# include <stdint.h>
#include <stdlib.h>


int		ft_printf(const char *format, ...);
void	ft_char(char c, int *len);
void	ft_str(char *str, int *len);
void	ft_uint(unsigned int n, int *len);
void	ft_int(int n, int *len);
void	ft_hex(unsigned int n, char x, int *len);
void	ft_check(va_list list, char format, int *len);
void	ft_ptr(unsigned long n, int *len);
void	ft_printadress(unsigned long n, int *len);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t count, size_t size);
int	ft_atoi(const char *str);
int	ft_isspace(int c);


#endif
