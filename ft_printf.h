/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmunk <jschmunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 19:40:48 by jschmunk          #+#    #+#             */
/*   Updated: 2023/07/15 18:44:03 by jschmunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h> 

int		ft_printf(char const *str, ...);
void	ft_putchar_pf(char c, size_t *counter);
void	ft_putnbr_pf(int n, size_t *counter);
void	ft_putstr_pf(char *str, size_t *counter);
void	ft_putperc_pf(char c, size_t *counter);
void	ft_putunsigned_pf(unsigned int c, size_t *counter);
char	*ft_itoa_pf(int temp2);
size_t	ft_strlen_pf(const char *str);
char	*ft_strdup_pf(const char *s1);
void	*ft_memcpy_pf(void *dst, const void *src, size_t n);
void	ft_puthexlow_pf(unsigned int n, size_t *counter);
void	ft_puthexup_pf(unsigned long long n, size_t *counter);
void	ft_putptr_pf(unsigned long n, size_t *counter);

#endif