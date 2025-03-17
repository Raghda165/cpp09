/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryagoub <ryagoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:21:31 by ryagoub           #+#    #+#             */
/*   Updated: 2025/03/17 06:11:36 by ryagoub          ###   ########.fr       */
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
// int merge_sort(int l,int r,std::vector <std::pair<int,int> > &pair_vec)
// {
// 	if(l < r)
// 	{
// 		merge_sort(l,r,pair_vec);
// 	}
// 	if(l==r)
// 		return l;


// }



// void deep_swap(int i,std::vector <std::pair<int,int> > &pair_vec,unsigned int order )
// {
// 	unsigned int size = pair_vec.size()/2;
// 	int l = 0;
// 	int r = pair_vec.size();
// 	merge_sort(l,r,pair_vec);

// }
// void merge(std::vector <std::pair<int,int> > &pair_vec,std::vector <std::pair<int,int> > &vec_a,std::vector <std::pair<int,int> > &vec_b)
// {
// 	unsigned int i = 0;
// 	unsigned int j = 0;
// 	static int k;
// 	while (i < vec_a.size() && j < vec_b.size())
// 	{
// 		if(vec_a[i].second<= vec_b[j].second)
// 		{
// 			pair_vec[k] = vec_a[i];
// 			i++;
// 		}
// 		else
// 		{
// 			pair_vec[k] = vec_b[j];
// 			j++;
// 		}
// 		k++;
// 	}
// 	if(i == vec_a.size())
// 	{
// 		pair_vec.insert(pair_vec.begin()+ k,vec_b.begin()+j,vec_b.begin()+vec_b.size());
// 	}
// 	else if(j == vec_b.size())
// 	{
// 		pair_vec.insert(pair_vec.begin()+ k,vec_a.begin()+i,vec_a.begin()+vec_a.size());
// 	}


// }
void print_pair (std::vector <std::pair<int,int> > &pair_vec)
{
	unsigned int i =0;
	while(i < pair_vec.size())
	{
		std::cout<< "["<<pair_vec[i].first << ","<<pair_vec[i].second<<"]"<<"\n";
		i++;
	}
}
void merge(std::vector<std::pair<int, int> > &pair_vec,
           std::vector<std::pair<int, int> > &vec_a,
           std::vector<std::pair<int, int> > &vec_b)
{
	std::vector<std::pair<int, int> > sorted_vec;
    unsigned int i = 0, j = 0;
    // Resize pair_vec before modifying it
    // pair_vec.resize(vec_a.size() + vec_b.size());
	//   pair_vec.clear();
    // pair_vec.reserve(vec_a.size() + vec_b.size());

    // Merge vec_a and vec_b into pair_vec
    while (i < vec_a.size() && j < vec_b.size()) {
        if (vec_a[i].second <= vec_b[j].second) {
			std::cout<<"im in a"<<"\n";
            sorted_vec.push_back(vec_a[i++]);
			std::cout<<"this is  vec_a"<<":";
			print_pair (vec_a);
			std::cout<<"this is it"<<"\n"<<"\n";
        } else {
            sorted_vec.push_back(vec_b[j++]);
			std::cout<<"im in b"<<"\n";
			std::cout<<"this is vec_b"<<":";
			print_pair (vec_b);
			std::cout<<"this is it"<<"\n"<<"\n";
        }
    }

    // Copy remaining elements from vec_a
    while (i < vec_a.size()) {
        sorted_vec.push_back(vec_a[i++]);
    }

    // Copy remaining elements from vec_b
    while (j < vec_b.size()) {
        sorted_vec.push_back(vec_b[j++]);
    }
	std::cout<<"this is pair vec"<<":";
	print_pair (sorted_vec);
	std::cout<<"this is it"<<"\n"<<"\n";
	pair_vec = sorted_vec;
}



void sort_large_ones(std::vector <std::pair<int,int> > &pair_vec)
{
	if (pair_vec.size() <= 1)
		return ;
	unsigned int n = pair_vec.size()/2;
	std::vector <std::pair<int,int> > vec_a(pair_vec.begin(),pair_vec.begin()+n);
	std::vector <std::pair<int,int> > vec_b(pair_vec.begin()+ n ,pair_vec.begin()+pair_vec.size());
	sort_large_ones(vec_a);
	// std::cout<<"this is a"<<":";
	// print_pair ( vec_a);
	// std::cout<<"this is b"<<":";
	// print_pair ( vec_b);
	sort_large_ones(vec_b);
	merge(pair_vec,vec_a,vec_b);

}
void rebuild(std::vector<int> &vec,std::vector <std::pair<int,int> > &pair_vec)
{
	unsigned int i = 0;
	vec.clear();
	while(i < pair_vec.size())
	{
		vec.push_back(pair_vec[i].first);
		vec.push_back(pair_vec[i].second);
		i++;

	}
}
std::vector<int> Jacobsthal(std::vector<int> &pend)
{
	std::vector<int> jacob_sequance;
	std::vector<int> real_sequance;
	std::vector<int> comb_sequance;
	unsigned int j =3;
	unsigned int i =0;
	jacob_sequance.push_back(0);
	jacob_sequance.push_back(1);
	jacob_sequance.push_back(1);

	while(j < pend.size())
	{
		jacob_sequance.push_back(jacob_sequance[j -1]+ 2 *jacob_sequance[j - 2]);
		j++;
	}

	while(i < pend.size())
	{
		real_sequance.push_back( i+2);
		i++;
	}
	j =1;
	i = 0;
	comb_sequance.push_back( jacob_sequance[3]);
	int last=comb_sequance[0];
	std::cout<<"\n"<<"\n"<<"im hereeee"<<"\n";
	while(i<pend.size()&&j<pend.size())
	{
		while (real_sequance[i]< last&&real_sequance[i]!= 1)
		{
			comb_sequance.push_back(real_sequance[i]);
			i++;
		}
		comb_sequance.push_back (jacob_sequance[j]);
		last = jacob_sequance[j];
		j++;
	}
	unsigned int l =0;
	std::cout<<"\n"<<"\n"<<"\n";
	while (l < comb_sequance.size())
	{
		std::cout<<comb_sequance[l]<<"     ";
		l++;
	}
	std::cout<<"\n"<<"\n"<<"\n";

	// unsigned int l =0;
	// std::cout<<"\n"<<"\n"<<"\n";
	// while (l < jacob_sequance.size())
	// {
	// 	std::cout<<jacob_sequance[l]<<"     ";
	// 	l++;
	// }
	// std::cout<<"\n"<<"\n"<<"\n";

	return (comb_sequance);
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
	rebuild(vec,pair_vec);

	unsigned int i=1;
	main.push_back(pair_vec[0].first);
	main.push_back(pair_vec[0].second);
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
	Jacobsthal(pend);
	//  unsigned int j=0;
	//  std::cout<<"im in main"<<"\n";
	//  while(j<main.size())
	// {
	// 	std::cout<<main[j]<<"\n";
	// 	j++;
	// }

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




