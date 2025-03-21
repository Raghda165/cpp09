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

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj){(void)obj;}
BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange &other)
{
	(void)other;
	return (*this);}
BitcoinExchange::~BitcoinExchange(){}

bool is_all_digit(std::string s)
{
	int len= s.length();
	for(int i = 0; i < len; i++)
	{
		if( s[i] == '-'||s[i]== '+'||s[i]=='.')
			i++;
		 if(((!isdigit(s[i]))&&len!=1 ))
			return(0);
	}
	return(1);
}

float parse_value(std::string s)
{
	float n = -1;
	std::stringstream ss(s);
	double num ;
	ss>>num;
	n = static_cast<float>(num);
	if(n < 1 || n > 1000)
	{
		if(n<0)
			std::cout << "Error: not a positive number."<<"\n";
		if(n > 1000)
			std::cout << "Error: too large a number."<<"\n";
	    return(-1);
	}
	return(n);
}

bool include_pipe(std::string &line)
{
	size_t i=0;
	while(i < line.length()&&(line[i]=='\n'||line[i]==' '))
		i++;
	if(i == line.length())
	 return(1);

    size_t pos = line.find('|');
    if(pos== std::string::npos)
        return(0);
    return(1);
}
std::list<std::string> split(std::string s, char delim)
{
	std::stringstream ss(s);
	std::string word;
	std::list <std::string> s_list;
	while (std::getline(ss,word,delim))
	{
		s_list.push_back(word);
	}
	return(s_list);
}
bool parse_day_month_year(std::string &s,int flag)
{
	std::stringstream ss(s);
	double num ;
	ss>>num;
	int n = static_cast<int>(num);
	if(flag==0)
	{
		if(n < 1 || n > 31)
			return(0);
	}
	if((flag==1) &&((s.length()!=2)|| (n < 1 || n > 12)))
		return(0);
	if(flag==2 &&((s.length()!=4)|| (n < 1 || n > 2025)))
	  return(0);
	return(1);
}

std::string parse_date(std::string & s)
{
	std::list <std::string> d_list= split(s,'-');
	if(d_list.size()< 3)
	{
		return("none");
	}
	std::list <std::string> :: iterator it = d_list.begin();
	if(parse_day_month_year(*it,2)==0)
		return("none");
	++it;
	if(parse_day_month_year(*it,1)==0)
		return("none");
	++it;
	if(parse_day_month_year(*it,0)==0)
		return("none");
	return (s);
}
int get_difference(t_info user_info, t_info origin_info)
{
	int days_difference= abs((user_info.year-origin_info.year)*365)+abs((user_info.month-origin_info.month)*30)+abs(user_info.day-origin_info.day);
	return(days_difference);
}
void extract_info(std::string date ,std::string value, t_info &d)
{

	std::stringstream s1(value);
	double num ;
	s1>>num;
	d.value = static_cast<float>(num);
	std::list <std::string> d_list= split(date,'-');
	if(d_list.size()<3 )
		return ;
	std::list <std::string> ::iterator it = d_list.begin();
	std::stringstream s3(*it);
	double num3 ;
	s3>>num3;
	d.year= static_cast<int> (num3);
	++it;
	std::stringstream s2(*it);
	double num2 ;
	s2>>num2;
	d.month= static_cast<int> (num2);
	++it;
	std::stringstream ss(*it);
	double num1 ;
	ss>>num1;
	d.day= static_cast<int> (num1);

}

void BitcoinExchange:: parse(std::string &line)
{
	std::string date;
	std::string value;
	t_info user_info;
	float target_value= 0;
		std:: list <std::string> s_list=split(line ,'|');
		if(s_list.size()> 2)
			return ;
        if(s_list.size()<= 2)
		{
			std:: list <std::string> ::iterator it = s_list.begin();
			if (parse_date(*it)== "none")
			{
				std::cout <<"Error: bad input => "<< *it<<"\n";
				 return ;
			}
			float value = parse_value(*(++it));
			if(value == -1)
			{
					return ;}
			std:: list <std::string> ::iterator it2 = s_list.begin();
			extract_info( *it2 , *(++it2),user_info);

			std::string line1;
			std::ifstream db_file("data.csv");
			std::getline(db_file,line1);
			int smallest_difference= 100000000;
			while(std::getline(db_file,line))
			{
				std::string value;
				std::string date;
				t_info origin_info;
				std:: list <std::string> s_list=split(line ,',');
				std:: list <std::string> ::iterator it = s_list.begin();
				date= *it;
				value = *(++it);
				extract_info( date , value,origin_info);
				if(smallest_difference > get_difference(user_info,origin_info))
				{
					smallest_difference= get_difference(user_info,origin_info);
					target_value = origin_info.value;
				}
			}
			std::cout<< user_info.year <<"-"<<user_info.month<<"-"<<user_info.day<<" => "<< user_info.value<<" = "<< target_value*user_info.value<<"\n";
		}

}
