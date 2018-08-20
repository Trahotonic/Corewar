//
// Created by Roman KYSLYY on 7/12/18.
//

#include "../inc/corewar.h"

int  ft_iswhitespace(char const c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v'
		|| c == '\r' || c == '\f')
		return (1);
	return (0);
}

int base(int c, int base)
{
	char *str = "0123456789abcdef";
	char *str2 = "0123456789abcdef";
	int  i = 0;

	while (i < base)
	{
		if (c == str[i] || c == str2[i])
			return (i);
		i++;
	}
	return (-1);
}

int ft_atoi_base(const char *str, int str_base)
{
	int nb = 0;
	int negatif = 0;
	int i = 0;
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			negatif = 1;
		i++;
	}
	while (base(str[i], str_base) != -1)
	{
		nb = nb * str_base;
		nb = nb + base(str[i], str_base);
		i++;
	}
	if (negatif)
		return (-nb);
	return (nb);
}

int 	saver(int tmp, int base, int plus)
{
	char *str;

	str = ft_strnew(base);
	base -= 1;
	while (base + 1)
	{
		str[base] = tmp % 2 + 48;
		tmp /= 2;
		base--;
	}
	if (str[0 + plus] == '0' && str[1 + plus] == '1')
		return (1);
	else if (str[0 + plus] == '1' && str[1 + plus] == '0')
		return (2);
	else if (str[0 + plus] == '1' && str[1 + plus] == '1')
		return (3);
	else return (0);
}

