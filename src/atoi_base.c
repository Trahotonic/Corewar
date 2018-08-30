/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 16:30:44 by msemenov          #+#    #+#             */
/*   Updated: 2018/08/30 16:30:51 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

char		*ft_uitoa_base2(unsigned int value, int base)
{
	char	*array;
	char	tmp[60];
	char	*ret;
	int		size;
	int		ptr;

	if (value == 0)
		return (ft_go_zero());
	array = "0123456789abcdef";
	size = 0;
	ptr = 59;
	while (value != 0)
	{
		tmp[ptr--] = array[value % base];
		value /= base;
		size++;
	}
	ptr++;
	ret = (char*)malloc(sizeof(char) * (size + 1));
	size = 0;
	while (ptr <= 59)
		ret[size++] = tmp[ptr++];
	ret[size] = '\0';
	return (ret);
}
