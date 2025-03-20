/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryagoub <ryagoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:21:31 by ryagoub           #+#    #+#             */
/*   Updated: 2025/03/21 01:25:43 by ryagoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
// #include <bits/stdc++.h>

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


void merge(std::vector<std::pair<int, int> > &pair_vec,
           std::vector<std::pair<int, int> > &vec_a,
           std::vector<std::pair<int, int> > &vec_b)
{
	std::vector<std::pair<int, int> > sorted_vec;
    unsigned int i = 0, j = 0;
    while (i < vec_a.size() && j < vec_b.size()) {
        if (vec_a[i].second <= vec_b[j].second) {
            sorted_vec.push_back(vec_a[i++]);
        } else {
            sorted_vec.push_back(vec_b[j++]);
        }
    }

    while (i < vec_a.size()) {
        sorted_vec.push_back(vec_a[i++]);
    }
    while (j < vec_b.size()) {
        sorted_vec.push_back(vec_b[j++]);
    }
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
bool in_jacob(int element,std::vector<int> jacob_sequance)
{
	for(unsigned int i = 0; i < jacob_sequance.size();i++)
	{
		if(jacob_sequance[i] == element)
			return(1);
	}
	return(0);
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

	while(j < pend.size() * 3)
	{
		jacob_sequance.push_back(jacob_sequance[j -1]+ 2 *jacob_sequance[j - 2]);
		j++;
	}

	while(i < pend.size()* 3)
	{
		real_sequance.push_back( i+1);
		i++;
	}
	j =0;
	i = 0;
	int last=0;
	if(jacob_sequance.size()< 4)
	{
		comb_sequance = real_sequance;
	}
	if(jacob_sequance.size()>= 4)
	{
		comb_sequance.push_back(jacob_sequance[3]);
		 last=comb_sequance[0];
	}
	while( j < pend.size() * 3)
	{
		while (i < real_sequance.size()&& real_sequance[i]< last)
		{
			if(in_jacob(real_sequance[i], jacob_sequance)==0)
				comb_sequance.push_back(real_sequance[i]);
			i++;
		}
		comb_sequance.push_back(jacob_sequance[j]);
		last = jacob_sequance[j];
		j++;
	}
	return (comb_sequance);
}


// pairwise
 void merge_insertion_sort(std::vector<int> &vec)
  {
	clock_t start = clock();
	std::vector <std::pair<int,int> > pair_vec;
	std::pair <int,int> p;
	std::vector <int> pend;
	std::vector <int> main;

	make_pairs(vec ,pair_vec );
	sort_large_ones(pair_vec);
	unsigned int i=1;
	main.push_back(pair_vec[0].first);
	main.push_back(pair_vec[0].second);
	pend.push_back(pair_vec[0].first);
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
	std::vector <int> index_vec;
	index_vec = Jacobsthal(pend);
	for (unsigned int i = 0; i < pend.size();i++)
		std::cout<<"pend[i]"<<pend[i]<<"\n";
	for (unsigned int i = 0; i < main.size();i++)
		std::cout<<"main[i]"<<main[i]<<"\n";
	 unsigned int j=0;
	 unsigned int k = 0;
	 if(index_vec.size()!= 0)
	{
		while (k < pend.size() && j < index_vec.size())
		{
			if (static_cast<unsigned int>(index_vec[j]-1) >=pend.size())
			{
				j++;
				k++;
				continue ;}
			std::vector<int>::iterator it = std::lower_bound(main.begin(), main.end(), pend[index_vec[j]- 1]);

			if (it != main.end())
			{
				unsigned int index = std::distance(main.begin(), it);
				main.insert(main.begin() + index , pend[index_vec[j]-1]);
				std::cout<<"im inserting this"<<pend[index_vec[j]-1]<<"which is in this location"<<index_vec[j]-1<<"and pend size is"<<pend.size()<<"\n";
			}
			j++;
			k++;
		}
	}
	vec= main;
	clock_t end = clock();
	 double elapsed_time = double(end - start) / CLOCKS_PER_SEC;
	 std::cout << "Execution time using vectors: " << elapsed_time << " seconds" << std::endl;
    }

bool parse(std::string s)
{
	int len= s.length();
	for(int i = 0; i < len; i++)
	{
		if( s[i] == '-'||s[i]== '+')
			i++;
		 if(!isdigit(s[i]))
			return(0);
	}
	return(1);
}
// deque
bool in_jacob_deq(int element,std::deque<int> jacob_sequance)
{
	for(unsigned int i = 0; i < jacob_sequance.size();i++)
	{
		if(jacob_sequance[i] == element)
			return(1);
	}
	return(0);
}
void merge_deq(std::deque<std::pair<int, int> > &pair_deq,
           std::deque<std::pair<int, int> > &deq_a,
           std::deque<std::pair<int, int> > &deq_b)
{
	std::deque<std::pair<int, int> > sorted_deq;
    unsigned int i = 0, j = 0;
    while (i < deq_a.size() && j < deq_b.size()) {
        if (deq_a[i].second <= deq_b[j].second) {
            sorted_deq.push_back(deq_a[i++]);
        } else {
            sorted_deq.push_back(deq_b[j++]);
        }
    }

    while (i < deq_a.size()) {
        sorted_deq.push_back(deq_a[i++]);
    }
    while (j < deq_b.size()) {
        sorted_deq.push_back(deq_b[j++]);
    }
	pair_deq = sorted_deq;
}
void sort_large_ones_deq(std::deque <std::pair<int,int> > &pair_deq)
{
	if (pair_deq.size() <= 1)
		return ;
	unsigned int n = pair_deq.size()/2;
	std::deque <std::pair<int,int> > deq_a(pair_deq.begin(),pair_deq.begin()+n);
	std::deque <std::pair<int,int> > deq_b(pair_deq.begin()+ n ,pair_deq.begin()+pair_deq.size());
	sort_large_ones_deq(deq_a);
	sort_large_ones_deq(deq_b);
	merge_deq(pair_deq,deq_a,deq_b);

}

void make_pairs_deq(std::deque<int> &deq ,std::deque <std::pair<int,int> > &pair_deq )
{
	std::pair <int,int> p;
	unsigned int i=0;
	while(i+1 < deq.size())
	{
		if(deq[i] <= deq[i+1])
		{
			p.first=deq[i];
			p.second = deq[i+1];
		}
		else
		{
			p.first=deq[i + 1];
			p.second = deq[i];
		}
		pair_deq.push_back(p);
		i+=2;
	}

}
std::deque<int> Jacobsthal_deq(std::deque<int> &pend)
{
	std::deque<int> jacob_sequance;
	std::deque<int> real_sequance;
	std::deque<int> comb_sequance;
	unsigned int j =3;
	unsigned int i =0;
	jacob_sequance.push_back(0);
	jacob_sequance.push_back(1);
	jacob_sequance.push_back(1);

	while(j < pend.size() * 3)
	{
		jacob_sequance.push_back(jacob_sequance[j -1]+ 2 *jacob_sequance[j - 2]);
		j++;
	}

	while(i < pend.size()* 3)
	{
		real_sequance.push_back( i+1);
		i++;
	}
	j =0;
	i = 0;
	int last=0;
	if(jacob_sequance.size()< 4)
	{
		comb_sequance = real_sequance;
	}
	if(jacob_sequance.size()>= 4)
	{
	comb_sequance.push_back(jacob_sequance[3]);
	last=comb_sequance[0];}
	while( j < pend.size() * 3)
	{
		std ::cout<<"im here in the lower bound"<<"\n"<<"\n";
		while ( i < real_sequance.size()&&real_sequance[i] < last)
		{
			if(in_jacob_deq(real_sequance[i], jacob_sequance)==0)
				comb_sequance.push_back(real_sequance[i]);
			i++;
		}
		comb_sequance.push_back(jacob_sequance[j]);
		last = jacob_sequance[j];
		j++;
	}
	return (comb_sequance);
}
 void merge_insertion_sort_deq(std::deque <int>& deq)
  {
	 clock_t start = clock();
	std::deque <std::pair<int,int> > pair_deq;
	std::pair <int,int> p;
	std::deque <int> pend;
	std::deque <int> main;

	make_pairs_deq(deq ,pair_deq );
	sort_large_ones_deq(pair_deq);
	unsigned int i=1;
	main.push_back(pair_deq[0].first);
	main.push_back(pair_deq[0].second);
	pend.push_back(pair_deq[0].first);
	while(i < pair_deq.size())
	{
		main.push_back(pair_deq[i].second);
		pend.push_back(pair_deq[i].first);
		i++;
	}
	if(deq.size()%2!=0)
	{
		pend.push_back(deq[deq.size()-1]);
	}
	std::deque <int> index_vec;
	index_vec = Jacobsthal_deq(pend);

	 unsigned int j=0;
	 unsigned int k = 0;
	 if(index_vec.size()!= 0)
	{
		while (k < pend.size() && j < index_vec.size())
		{
			if (static_cast<unsigned int>(index_vec[j]-1) >= pend.size())
			{
				j++;
				k++;
				continue ;}

			std::deque<int>::iterator it = std::lower_bound(main.begin(), main.end(), pend[index_vec[j]- 1]);

			if (it != main.end())
			{
				unsigned int index = std::distance(main.begin(), it);
				main.insert(main.begin() + index , pend[index_vec[j]-1]);
			}
			j++;
			k++;
		}
	}
	deq= main;
	clock_t end = clock();
	 double elapsed_time = double(end - start) / CLOCKS_PER_SEC;
	 std::cout << "Execution time using deque: " << elapsed_time << " seconds" << std::endl;

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




