/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_c_s_d_i_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmunk <jschmunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:32:50 by jschmunk          #+#    #+#             */
/*   Updated: 2023/07/15 20:59:15 by jschmunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_pf(char c, size_t *counter)
{
	write(1, &c, 1);
	(*counter)++;
}

void	ft_putnbr_pf(int n, size_t *counter)
{
	int		temp2;
	int		i;
	char	*str;

	temp2 = n;
	str = ft_itoa_pf(temp2);
	i = ft_strlen_pf(str);
	i = *counter;
	if (n == -2147483648)
	{
		ft_putstr_pf("-2147483648", counter);
	}
	else
	{
		if (n < 0)
		{
			ft_putchar_pf('-', counter);
			n = -n;
		}
		if (n < 10)
		{
			ft_putchar_pf(n + '0', counter);
		}
		else
		{
			ft_putnbr_pf(n / 10, counter);
			ft_putnbr_pf(n % 10, counter);
		}
	}
}

void	ft_putstr_pf(char *str, size_t *counter)
{
	if (!str)
	{
		str = "(null)";
	}
	while (*str)
	{
		ft_putchar_pf(*str, counter);
		str++;
	}
}

void	ft_putunsigned_pf(unsigned int n, size_t *counter)
{
	if (n < 10)
	{
		ft_putchar_pf(n + '0', counter);
	}
	else
	{
		ft_putunsigned_pf(n / 10, counter);
		ft_putunsigned_pf(n % 10, counter);
	}
}
