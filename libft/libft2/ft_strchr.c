/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 16:21:14 by zshanabe          #+#    #+#             */
/*   Updated: 2018/04/19 17:00:49 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	char *p;

	p = (char *)str;
	while (*p && *p != (char)c)
		p++;
	if (*p == (char)c)
		return (p);
	return (0);
}
