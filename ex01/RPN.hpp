/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryagoub <ryagoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 02:24:42 by ryagoub           #+#    #+#             */
/*   Updated: 2025/03/21 05:24:10 by ryagoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

 #include <iostream>
 #include <stack>
 #include <cstdlib>

 class Rpn
 {
	public:
	Rpn();
	Rpn(const Rpn &obj);
	Rpn&operator=(const Rpn &other);
	~Rpn();

	int handle_av(std::string s);
 };

#endif
