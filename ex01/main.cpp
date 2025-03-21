/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryagoub <ryagoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 04:19:36 by ryagoub           #+#    #+#             */
/*   Updated: 2025/03/21 05:25:05 by ryagoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
int main(int ac,char **av)
{
	int res= 0;
	Rpn calculate;
	if(ac==2)
	{
		res = calculate. handle_av(av[1]);
		std::cout<<res<<"\n";

	}
	else
	{
		std::cout<<"the number of arguments  must be only two"<<"\n";
	}
}
