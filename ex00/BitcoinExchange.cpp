/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryagoub <ryagoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 01:02:55 by ryagoub           #+#    #+#             */
/*   Up_dated: 2025/03/04 02:37:59 by ryagoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void intialize_date()
{

}
BitCoinExchange::BitCoinExchange()
{
 std::cout <<"the default constructor has been called"<<std::endl;
}
BitCoinExchange::BitCoinExchange(const BitCoinExchange &obj)
{
	this->_date=obj._date;
	this->_value = obj._value;
}
BitCoinExchange &BitCoinExchange::operator=(const BitCoinExchange &other)
{
	if(this != &other)
	{
		this->_date=other._date;
	    this->_value = other._value;
	}
	return(*this);
}
BitCoinExchange::~BitCoinExchange()
{
	std::cout <<"the default destructor has been called"<<std::endl;
}
BitCoinExchange:: BitCoinExchange(std::string &d, float value)
{
	this ->_date = d;
	this->_value= value;
	std::vector <std::string> d_vec= split(this ->_date,'-');
	std::stringstream ss(d_vec[0]);
	double num1 ;
	ss>>num1;
	this->day= static_cast<int> (num1);
	std::stringstream s2(d_vec[1]);
	double num2 ;
	s2>>num2;
	this->month= static_cast<int> (num2);
	std::stringstream s3(d_vec[2]);
	double num3 ;
	s3>>num3;
	this-> year= static_cast<int> (num2);
}
std::string BitCoinExchange:: Get_date(void)
{
	return(this->_date);
}
double BitCoinExchange:: Get_value(void)
{
   return(this->_value);
}
int return_date()
{

}

void BitCoinExchange:: calculate_price(void)
{
	std::string line;
	std::ifstream datab_file("data.csv");
	 if(datab_file)
     {
        while(std::getline(datab_file,line))
		{
			std:: vector <std::string> s_vec=split(line ,',');
		}

     }

}
