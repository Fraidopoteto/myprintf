/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmunk <jschmunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:59:34 by jschmunk          #+#    #+#             */
/*   Updated: 2023/07/15 20:46:45 by jschmunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type(va_list argptr, const char *str, size_t *counter)
{
	if (*str == 'c')
		ft_putchar_pf(va_arg(argptr, int), counter);
	if (*str == 's')
		ft_putstr_pf(va_arg(argptr, char *), counter);
	if (*str == 'i' || *str == 'd')
		ft_putnbr_pf(va_arg(argptr, int), counter);
	if (*str == '%')
		ft_putperc_pf('%', counter);
	if (*str == 'u')
		ft_putunsigned_pf(va_arg(argptr, unsigned int), counter);
	if (*str == 'x')
		ft_puthexlow_pf(va_arg(argptr, unsigned int), counter);
	if (*str == 'X')
		ft_puthexup_pf(va_arg(argptr, unsigned int), counter);
	if (*str == 'p')
		ft_putptr_pf(va_arg(argptr, unsigned long), counter);
}

int	ft_printf(const char *str, ...)
{
	size_t	counter;
	va_list	argptr;

	counter = 0;
	if (!str)
		return (0);
	va_start(argptr, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str ++;
			ft_type(argptr, str, &counter);
		}
		else
			ft_putchar_pf(*str, &counter);
		str ++;
	}
	va_end(argptr);
	return ((int) counter);
}

int main(void)
{

	int count = ft_printf("%c%X ", 'a', 15);
	int count_og = printf("%c%X\n", 'a', 15);

	printf("\n");
	printf("%d ,%d \n", count, count_og);
	return (0);
}
