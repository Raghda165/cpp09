/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryagoub <ryagoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:21:31 by ryagoub           #+#    #+#             */
/*   Updated: 2025/03/16 05:43:33 by ryagoub          ###   ########.fr       */
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

void make_pairs(std::vector<int> &vec ,std::vector <std::pair<int,int> > &pair_vec )
{
	std::pair <int,int> p;
	unsigned int i=0;
	while(i+1 < vec.size())
	{
		if(vec[i] <= vec[i+1])
		{
			p.first=vec[i];
			p.second = vec[i+1];
		}
		else
		{
			p.first=vec[i + 1];
			p.second = vec[i];
		}
		pair_vec.push_back(p);
		i+=2;
	}

}
int merge_sort(int l,int r,std::vector <std::pair<int,int> > &pair_vec)
{
	if(l < r)
	{
		merge_sort(l,r,pair_vec);
	}
	if(l==r)
		return l;


}



void deep_swap(int i,std::vector <std::pair<int,int> > &pair_vec,unsigned int order )
{
	unsigned int size = pair_vec.size()/2;
	int l = 0;
	int r = pair_vec.size();
	merge_sort(l,r,pair_vec);

}
void sort_large_ones(std::vector <std::pair<int,int> > &pair_vec)
{
	unsigned int order = 1;

	while (order <= pair_vec.size())
	{
	    unsigned int i = order - 1;
		while(i + order < pair_vec.size())
		{
			if(pair_vec[i].second> pair_vec[i+order].second)
			{
				std::cout<<"pair_vec[i].second"<<pair_vec[i].second<<"\n";
				std::cout<<"pair_vec[i].second"<<pair_vec[i+1].second<<"\n";
				deep_swap(i,pair_vec,order);
			}
			i += 2* order;
		}
		order= order * 2;
		std::cout<<"order"<<order<<"\n";
	}
}
void print_pair (std::vector <std::pair<int,int> > pair_vec)
{
	unsigned int i =0;
	while(i < pair_vec.size())
	{
		std::cout<< "["<<pair_vec[i].first << ","<<pair_vec[i].second<<"]"<<"\n";
		i++;
	}
}
// pairwise
 void merge_sort(std::vector<int> &vec)
  {
	std::vector <std::pair<int,int> > pair_vec;
	std::pair <int,int> p;
	std::vector <int> pend;
	std::vector <int> main;

	make_pairs(vec ,pair_vec );
	print_pair(pair_vec);

	sort_large_ones(pair_vec);
	std::cout<<"after sort"<<"\n";
	print_pair(pair_vec);

	unsigned int i=0;
	while(i < pair_vec.size())
	{
		main.push_back(pair_vec[i].second);
		pend.push_back(pair_vec[i].first);
		i++;
	}
	if(vec.size()%2!=0)
	{
		pend.push_back(vec[vec.size()-1]);
	}
	//  unsigned int j=0;
	//  unsigned int k=0;
	// while(j<pend.size())
	// {
	// 	k=0;
	// 	while(k+1 < main.size())
	// 	{
	// 		if(pend[j] > main[k]&&pend[j]< main[k+1])
	// 		{
	// 			main.insert(main.begin() + k+1, pend[j]);
	// 			break ;
	// 		}
	// 		else if(pend[j] < main[k])
	// 		{
	// 			main.insert(main.begin() + k, pend[j]);
	// 			break ;
	// 		}
	// 		k++;
	// 	}
	// 	j++;
	// }

	//  unsigned int j=0;
	//  while(j<pend.size())
	// {
	// 	std::cout<<pend[j]<<"\n";
	// 	j++;
	// }
	 for (unsigned int i = 0; i < vec.size(); i++)
    {
        vec[i] = main[i];
    }
    }



















































































































// void insertion(unsigned int order , std::vector <int> &vec)
// {
// 	std::cout<<"order"<<order<<"\n";
// 	order = order/2;
// 	std::cout<<"order"<<order<<"\n";
// 	unsigned int group_count=0;
// 	while (order >= 1)
// 	{
// 		std::vector<std::vector<int> > main;
// 		std::vector<std::vector<int> > pend;
// 		unsigned int i = 0;
//         while (i < vec.size())
// 		{
//             std::vector<int> pair;
//             for (unsigned int j = 0; j < order && i < vec.size(); j++, i++)
// 			{
//                 pair.push_back(vec[i]);
//             }
// 			if(pair.size()==order&&(group_count == 0 || group_count %2 != 0))
// 				main.push_back(pair);
// 			else
// 				pend.push_back(pair);
// 			group_count++;
// 		}
// 		unsigned int k = 0;
// 		unsigned int m = 0;
// 		unsigned int l = 0;
// 		unsigned int n = 0;
// 		while (l < pend.size())
// 		{
// 			n = 0;
// 			while(n < pend[l].size())
// 			{
// 				while (k < main.size())
// 				{
// 					m = 0;
// 					while(m < main[k].size()&&main[k][m]<pend[l][n])
// 						m++;
// 					if(m < main[k].size()&&main[k][m]>=pend[l][n])
// 					{
// 						std::cout<<"pend[l][n]"<<pend[l][n]<<"\n";
// 						main[k].insert(main[k].begin() + m, pend[l][n]);
// 						pend[l].erase(pend[l].begin() + n);
// 						k=0;
// 						n--;
// 						if(n< pend[l].size())
// 						   std::cout<<"after pend[l][n]"<<pend[l][n]<<"\n";
// 						break ;
// 					}
// 					k++;
// 				}
// 				n++;
// 			}
// 			l++;

// 		}
// 		order= order/2;
// 		k= 0;
// 		m = 0;
// 		 while (k < main.size())
// 		 {
// 			 m = 0;
// 			 std::cout<<"[";
// 			 while(m < main[k].size())
// 			 {

// 		std::cout<<main[k][m]<<',';
// 				m++;
// 			 }
// 			 std::cout<<"]"<<"\n";
// 			 k++;
//     	}
// 		unsigned int index = 0;
// 		for (unsigned int i = 0; i < main.size(); i++)
// 		{
// 			for (unsigned int j = 0; j < main[i].size(); j++) {
// 				if (index < vec.size()) {
// 					vec[index++] = main[i][j];
// 				}
// 			}
// 		}
// 	}
// }

// void merge(std::vector<int> &vec) {
//     unsigned int order = 1;

//     while (order < vec.size()/2) {
//         std::vector<std::vector<int> > pair_group;
//         unsigned int i = 0;
//         while (i < vec.size())
// 		{
//             std::vector<int> pair;
//             for (unsigned int j = 0; j < order && i < vec.size(); j++, i++)
// 			 {
//                 pair.push_back(vec[i]);
//             }
//             pair_group.push_back(pair);
//         }
//         for (unsigned int i = 0; i + 1 < pair_group.size(); i+=2)
// 		{
//             if (pair_group[i].size() >= order && pair_group[i + 1].size() >= order)
// 			{
//                 if (pair_group[i][order - 1] > pair_group[i + 1][order - 1]) {
//                     std::swap(pair_group[i], pair_group[i + 1]);
//                 }
//             }

//         }
//        unsigned int index = 0;
// 		for (unsigned int i = 0; i < pair_group.size(); i++)
// 		{
// 			for (unsigned int j = 0; j < pair_group[i].size(); j++) {
// 				if (index < vec.size()) {
// 					vec[index++] = pair_group[i][j];
// 				}
// 			}
// 		}
// 		std::cout<<"the order is"<<order<<"\n";
//         order *= 2;
//     }
// 	insertion( order/2 , vec);
// 	std::cout<<vec.size()<<"s"<<"\n";

// }




