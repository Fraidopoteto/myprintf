/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_ptr_hex_perc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmunk <jschmunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 20:53:15 by jschmunk          #+#    #+#             */
/*   Updated: 2023/07/15 21:01:27 by jschmunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr_pf(unsigned long n, size_t *counter)
{
	if (n == 0)
	{
		ft_putstr_pf("0x0", counter);
	}
	else
	{
		ft_putstr_pf("0x", counter);
		ft_puthexlow_pf(n, counter);
	}
}

void	ft_puthexlow_pf(unsigned int n, size_t *counter)
{
	if (n < 16)
	{
		if (n < 10)
		{
			ft_putchar_pf(n + '0', counter);
		}
		else
		{
			ft_putchar_pf(n - 10 + 'a', counter);
		}
	}
	else
	{
		ft_puthexlow_pf(n / 16, counter);
		ft_puthexlow_pf(n % 16, counter);
	}
}

void	ft_puthexup_pf(unsigned long long n, size_t *counter)
{
	if (n < 16)
	{
		if (n < 10)
		{
			ft_putchar_pf(n + '0', counter);
		}
		else
		{
			ft_putchar_pf(n - 10 + 'A', counter);
		}
	}
	else
	{
		ft_puthexup_pf(n / 16, counter);
		ft_puthexup_pf(n % 16, counter);
	}
}

void	ft_putperc_pf(char c, size_t *counter)
{
	write(1, &c, 1);
	(*counter)++;
}
