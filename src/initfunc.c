/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initfunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 15:09:41 by msemenov          #+#    #+#             */
/*   Updated: 2018/08/30 15:09:49 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

void	initfunc(functions_t func[])
{
	func[0].codage = 0;
	func[0].cycles = 10;
	func[0].name2 = 1;
	func[1].codage = 1;
	func[1].cycles = 5;
	func[1].name2 = 2;
	func[2].codage = 1;
	func[2].cycles = 5;
	func[2].name2 = 3;
	func[3].codage = 1;
	func[3].cycles = 10;
	func[3].name2 = 4;
	func[4].codage = 1;
	func[4].cycles = 10;
	func[4].name2 = 5;
	func[5].codage = 1;
	func[5].cycles = 6;
	func[5].name2 = 6;
	func[6].codage = 1;
	func[6].cycles = 6;
	func[6].name2 = 7;
	func[7].codage = 1;
	func[7].cycles = 6;
	func[7].name2 = 8;
}

void	initfunc2(functions_t func[])
{
	func[8].codage = 0;
	func[8].cycles = 20;
	func[8].name2 = 9;
	func[9].codage = 1;
	func[9].cycles = 25;
	func[9].name2 = 10;
	func[10].codage = 1;
	func[10].cycles = 25;
	func[10].name2 = 11;
	func[11].codage = 0;
	func[11].cycles = 800;
	func[11].name2 = 12;
	func[12].codage = 1;
	func[12].cycles = 10;
	func[12].name2 = 13;
	func[13].codage = 1;
	func[13].cycles = 50;
	func[13].name2 = 14;
	func[14].codage = 0;
	func[14].cycles = 1000;
	func[14].name2 = 15;
	func[15].codage = 1;
	func[15].cycles = 2;
	func[15].name2 = 16;
}
