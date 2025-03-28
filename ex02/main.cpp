/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryagoub <ryagoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:21:58 by ryagoub           #+#    #+#             */
/*   Updated: 2025/03/21 05:16:50 by ryagoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char ** av)
{
	Pmergeme sort;
	if (ac >= 3)
	{
		int i = 1;
		std::vector <int> vec;
		std::deque <int> deq;
		while(i < ac)
		{
			if(sort.parse(av[i]))
			{
			vec.push_back(atoi(av[i]));
			deq.push_back(atoi(av[i]));
			i++;}
			else
			{
				std::cerr<<"your input is not as it is suppose to be "<<std::endl;
				return(1);
			}
		}
		std::cout<<"Before: ";
		for(unsigned int i=0 ; i < vec.size(); i++)
		{
			std::cout<<vec[i]<<" ";
		}
		std::cout<<"\n";
		 sort.merge_insertion_sort(vec);
		 sort.merge_insertion_sort_deq(deq);
		// std::cout<<std::endl;
		// if (std::is_sorted(vec.begin(), vec.end()))
        // {	std::cout << "Sorted" << std::endl;
		// std::cout<<"vec.size"<<vec.size()<<"\n";
		// }
    	// else
        // 	std::cout << "Not Sorted" << std::endl;
	}
}
