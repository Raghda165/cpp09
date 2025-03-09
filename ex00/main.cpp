/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryagoub <ryagoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 03:03:41 by ryagoub           #+#    #+#             */
/*   Updated: 2025/03/09 07:56:33 by ryagoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac,char **av)
{
    std::string line;
   if(ac == 2)
   {
     std::ifstream db_file(av[1]);

     if(db_file)
     {
		std::getline(db_file,line);
        while(std::getline(db_file,line))
         {
			 parse(line);

		 }
     }
   }
}
