/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 15:04:22 by msemenov          #+#    #+#             */
/*   Updated: 2018/09/12 14:05:23 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

int		ft_iswhitespace(char const c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v'
		|| c == '\r' || c == '\f')
		return (1);
	return (0);
}

int		baser(int c, int base)
{
	char	*str;
	char	*str2;
	int		i;

	i = 0;
	str = "0123456789abcdef";
	str2 = "0123456789abcdef";
	while (i < base)
	{
		if (c == str[i] || c == str2[i])
			return (i);
		i++;
	}
	return (-1);
}

int		ab(char *str, int base)
{
	int	num;
	int	minus;
	int	n;

	num = 0;
	n = 0;
	minus = 0;
	while (ft_iswhitespace(str[n]))
		++n;
	if (str[n] == '+' || str[n] == '-')
	{
		if (str[n] == '-')
			minus = 1;
		++n;
	}
	while (baser(str[n], base) != -1)
	{
		num = num * base;
		num = num + baser(str[n], base);
		++n;
	}
	if (minus)
		return (-num);
	return (num);
}

int		saver(int tmp, int base, int plus)
{
	char	*str;
	int		i;

	str = ft_strnew(base);
	base -= 1;
	while (base + 1)
	{
		str[base] = tmp % 2 + 48;
		tmp /= 2;
		base--;
	}
	if (str[0 + plus] == '0' && str[1 + plus] == '1')
		i = 1;
	else if (str[0 + plus] == '1' && str[1 + plus] == '0')
		i = 2;
	else if ((str[0 + plus] == '1') && (str[1 + plus] == '1'))
		i = 3;
	else
		i = 0;
	ft_strdel(&str);
	return (i);
}
