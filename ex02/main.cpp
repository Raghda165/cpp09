/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryagoub <ryagoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:21:58 by ryagoub           #+#    #+#             */
/*   Updated: 2025/03/12 00:05:13 by ryagoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char ** av)
{
	if (ac > 3)
	{
		int i = 1;
		std::vector <int> vec;
		std::deque <int> deq;
		while(i < ac)
		{
			vec.push_back(atoi(av[i]));
			deq.push_back(atoi(av[i]));
			i++;
		}
		merge(vec);
		std::cout<<"Befor: ";
		for(unsigned int i=0 ; i < vec.size(); i++)
		{
			std::cout<<vec[i]<<" ";
		}
		std::cout<<std::endl;
	}

}
