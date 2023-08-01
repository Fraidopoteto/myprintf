/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmunk <jschmunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:38:48 by jschmunk          #+#    #+#             */
/*   Updated: 2023/07/15 20:34:13 by jschmunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_allocate(int len)
{
	char	*str;

	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	else
		return (str);
}

static char	*ft_convert(int temp2, int temp, int len, int isminus)
{
	int		i;
	char	*str;

	while (temp > 0)
	{
		len++;
		temp = temp / 10;
	}
	str = ft_allocate(len);
	if (str == NULL)
		return (NULL);
	i = len;
	while (temp2 > 0)
	{
		i--;
		str[i] = temp2 % 10 + '0';
		temp2 = temp2 / 10;
	}
	str[len] = '\0';
	if (isminus == 1)
		str[0] = '-';
	return (str);
}
/// @brief itoa_pf wandelt eine Ganzzahl in eine Zeichenkette (String) um.
/// (angepasst für printf)
/// @param len 
/// @return 

char	*ft_itoa_pf(int temp2)
{
	int		len;
	int		isminus;
	int		temp;

	len = 0;
	isminus = 0;
	temp = temp2;
	if (temp2 == -2147483648)
		return (ft_strdup_pf("-2147483648"));
	if (temp2 == 0)
		return (ft_strdup_pf("0"));
	if (temp2 < 0)
	{
		temp2 = -temp2;
		temp = -temp;
		len = 1;
		isminus = 1;
	}
	return (ft_convert(temp2, temp, len, isminus));
}
