/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurst <nfurst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 15:19:09 by nfurst            #+#    #+#             */
/*   Updated: 2026/10/16 15:19:12 by nfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	last = NULL;
	while(1)
	{
		if((unsigned char)*s == (unsigned char)c)
			last = s;
		if(*s == '\0')
			break ;
		s++;
	}
	return((char *)last);
}
