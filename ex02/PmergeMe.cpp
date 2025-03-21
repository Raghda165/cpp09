/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryagoub <ryagoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:21:31 by ryagoub           #+#    #+#             */
/*   Updated: 2025/03/21 05:46:42 by ryagoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


Pmergeme::Pmergeme(){}
Pmergeme::Pmergeme(const Pmergeme &obj){(void)obj;}
Pmergeme & Pmergeme::operator=(const Pmergeme &other)
{
	(void)other;
	return (*this);}
Pmergeme::~Pmergeme(){}

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
	j = 4;
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
			if(in_jacob(real_sequance[i], jacob_sequance)==0 )
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
 void Pmergeme:: merge_insertion_sort(std::vector<int> &vec)
  {
	clock_t start = clock();
	 if(vec.size()==2)
	{ 	if(vec[1]<vec[0])
			swap(vec[0],vec[1]);
	}
	else
	{std::vector <std::pair<int,int> > pair_vec;
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
			unsigned int index = std::distance(main.begin(), it);
			main.insert(main.begin() + index , pend[index_vec[j]-1]);
			j++;
			k++;
		}
	}
	vec= main;
	}
	std::cout<<"After: ";
	for(unsigned int i=0 ; i < vec.size(); i++)
	{
		std::cout<<vec[i]<<" ";
	}
	std::cout<<"\n";
	clock_t end = clock();
	 double elapsed_time = (double(end - start) / CLOCKS_PER_SEC)*1000000;
	 std::cout << "Time to process a range of " << vec.size()<<" elements with std::vector : "<< elapsed_time << " us" << std::endl;
    }

bool Pmergeme:: parse(std::string s)
{
	std :: stringstream ss(s);
	double num;
	ss>>num;
	if (num > INT_MAX|| num < INT_MIN)
		return(0);
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
	j =4;
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
 void Pmergeme:: merge_insertion_sort_deq(std::deque <int>& deq)
  {
	 clock_t start = clock();
	 if(deq.size()==2)
	{ 	if(deq[1]<deq[0])
			swap(deq[0],deq[1]);
	}
	else
	{
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
				unsigned int index = std::distance(main.begin(), it);
				main.insert(main.begin() + index , pend[index_vec[j]-1]);
				j++;
				k++;
			}
		}
		deq= main;
	}
	clock_t end = clock();
	 double elapsed_time = double(end - start) / CLOCKS_PER_SEC*1000000;
	 std::cout << "Time to process a range of " << deq.size()<<" elements with std::deque : "<< elapsed_time << " us" << std::endl;

    }






































































































