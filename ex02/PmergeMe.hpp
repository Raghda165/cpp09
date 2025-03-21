/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryagoub <ryagoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:47:34 by ryagoub           #+#    #+#             */
/*   Updated: 2025/03/21 05:04:25 by ryagoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME
#define PMERGEME
 #include <deque>
 #include <vector>
 #include <iostream>
 #include <cstdlib>
 #include <sstream>

 class Pmergeme
 {
	public:
	Pmergeme();
	Pmergeme(const Pmergeme &obj);
	Pmergeme &operator=(const Pmergeme &other);
	~Pmergeme();

	void merge_insertion_sort(std::vector<int> &vec);
	bool parse(std::string s);
	void merge_insertion_sort_deq(std::deque <int>& deq);
 };

#endif


