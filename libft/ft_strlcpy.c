/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: border <border@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:43:11 by border            #+#    #+#             */
/*   Updated: 2020/11/24 16:43:34 by border           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	const char	*osrc;
	size_t		nleft;

	osrc = src;
	if (!(dst) || !(osrc))
		return (0);
	nleft = size;
	if (nleft != 0)
	{
		while (--nleft != 0 && *src != '\0')
		{
			*dst = *src;
			dst++;
			src++;
		}
		*dst = *src;
	}
	if (nleft == 0)
	{
		if (size != 0)
			*dst = '\0';
		while (*src++)
			;
	}
	return (src - osrc - 1);
}
