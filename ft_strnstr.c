/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurst <nfurst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 15:15:34 by nfurst            #+#    #+#             */
/*   Updated: 2026/10/16 15:16:41 by nfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if(needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while(i < len && haystack[i] != '\0')
	{
		j = 0;
		while (i + j < len && haystack[i + j] != '\0'
			&& haystack[i + j] == needle[j] && needle[j] != '\0')
			j++;
		if(needle[j] == '\0')
			return((char *)(haystack + i));
		i++;
	}
	return(NULL);
}
