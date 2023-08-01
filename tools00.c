/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmunk <jschmunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:37:19 by jschmunk          #+#    #+#             */
/*   Updated: 2023/07/12 18:38:15 by jschmunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/// @brief strlen gibt die Länge eines 
///Null-terminierten Zeichenstrings zurück, 
///indem sie die Anzahl der Zeichen im String zählt,
/// bevor das Null-Terminierungszeichen erreicht wird.
/// @param str 
/// @return 
size_t	ft_strlen_pf(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

/// @brief strdup erstellt eine Kopie eines Null-terminierten 
//Zeichenstrings.
/// @param s1 
/// @return 
char	*ft_strdup_pf(const char *s1)
{
	size_t	len;
	char	*dst;

	len = ft_strlen_pf(s1) + 1;
	dst = (char *)malloc(len);
	if (dst != NULL)
	{
		ft_memcpy_pf(dst, s1, len);
	}
	return (dst);
}

/// @brief memcpy kopiert eine angegebene Anzahl von Bytes
/// von einem Speicherbereich in einen anderen Speicherbereich.
/// @param dst 
/// @param src 
/// @param n 
/// @return 
void	*ft_memcpy_pf(void *dst, const void *src, size_t n)
{
	unsigned char		*dp;
	const unsigned char	*sp;

	dp = (unsigned char *)dst;
	sp = (const unsigned char *)src;
	if (dp == 0 && sp == 0)
		return (dst);
	while (n > 0)
	{
		*dp++ = *sp++;
		n--;
	}
	return (dst);
}
