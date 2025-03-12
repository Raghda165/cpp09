/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryagoub <ryagoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:21:31 by ryagoub           #+#    #+#             */
/*   Updated: 2025/03/12 04:35:35 by ryagoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
template <typename T>
void swap(T &a , T &b)
{
	T temp;
	temp= a;
	a = b;
	b = temp;
}

void merge(std::vector<int> &vec) {
    unsigned int order = 1;

    while (order < vec.size()) {
        std::vector<std::vector<int> > pair_group;
        unsigned int i = 0;
        while (i < vec.size()) {
            std::vector<int> pair;
            for (unsigned int j = 0; j < order && i < vec.size(); j++, i++) {
                pair.push_back(vec[i]);
            }
            pair_group.push_back(pair);
        }
        for (unsigned int i = 0; i + 1 < pair_group.size(); i+=2)
		{
            if (pair_group[i].size() >= order && pair_group[i + 1].size() >= order)
			{
                if (pair_group[i][order - 1] > pair_group[i + 1][order - 1]) {
                    std::swap(pair_group[i], pair_group[i + 1]);
                }
            }

        }

       unsigned int index = 0;
		for (unsigned int i = 0; i < pair_group.size(); i++)
		{
			for (unsigned int j = 0; j < pair_group[i].size(); j++) {
				if (index < vec.size()) {
					vec[index++] = pair_group[i][j];
				}
			}
		}
		std::cout<<"the order is"<<order<<"\n";
        order *= 2;
    }
}

void insertion(int order , std::vector <int> vec)
{
	order = order/2;
	while (order >= 1)
	{
		
	}
}


