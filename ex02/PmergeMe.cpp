/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryagoub <ryagoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:21:31 by ryagoub           #+#    #+#             */
/*   Updated: 2025/03/12 23:49:21 by ryagoub          ###   ########.fr       */
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
void insertion(unsigned int order , std::vector <int> vec)
{
	std::cout<<"order"<<order<<"\n";
	order = order/2;
	std::cout<<"order"<<order<<"\n";
	unsigned int group_count=0;
	while (order >= 8)
	{
		std::vector<std::vector<int> > main;
		std::vector<std::vector<int> > pend;
		std::vector<std::vector<int> > leftover;
		unsigned int i = 0;
        while (i < vec.size())
		{
            std::vector<int> pair;
            for (unsigned int j = 0; j < order && i < vec.size(); j++, i++)
			{
                pair.push_back(vec[i]);
            }
			if(pair.size() == order)
			{if(group_count == 0 || group_count %2 != 0)
				main.push_back(pair);
			else
				pend.push_back(pair);}
			else
				leftover.push_back(pair);
			group_count++;
		}
		unsigned int k = 0;
		unsigned int m = 0;
		unsigned int l = 0;
		unsigned int n = 0;
		while (l < pend.size())
		{
			n = 0;
			std::cout<<"pend"<<"[";
			while(n < pend[l].size())
			{
				while (k < main.size())
				{
					m = 0;
					std::cout<<"main"<<"[";
					while(m < main[k].size()&&main[k][m]<pend[l][n])
							m++;
					// if(main[k][m]>pend[l][n])im here 

					k++;
				}
			}
			l++;

		}
		order= order/2;
    }
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
	insertion( order/2 , vec);
}




