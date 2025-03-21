/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryagoub <ryagoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 03:03:41 by ryagoub           #+#    #+#             */
/*   Updated: 2025/03/21 05:32:21 by ryagoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
// parse do all the job
int main(int ac,char **av)
{
    std::string line;
	BitcoinExchange bc;
   if(ac == 2)
   {
     std::ifstream db_file(av[1]);

     if(db_file)
     {
		std::getline(db_file,line);
        while(std::getline(db_file,line))
         {
			bc.parse(line);
		 }
     }
   }
   else
      std::cout<< "the number of aguments should be only 2"<<"\n";
}
