/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryagoub <ryagoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:21:58 by ryagoub           #+#    #+#             */
/*   Updated: 2025/03/14 07:14:39 by ryagoub          ###   ########.fr       */
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
		std::cout<<"Before: ";
		for(unsigned int i=0 ; i < vec.size(); i++)
		{
			std::cout<<vec[i]<<" ";
		}
		 merge_sort(vec);
		std::cout<<"After: ";
		for(unsigned int i=0 ; i < vec.size(); i++)
		{
			std::cout<<vec[i]<<" ";
		}
		std::cout<<std::endl;
	}

}
