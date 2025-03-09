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
std::vector<std::string> split(std::string s, char delim)
{
	std::stringstream ss(s);
	std::string word;
	std::vector <std::string> s_vector;
	while (std::getline(ss,word,delim))
	{
		s_vector.push_back(word);
	}
	return(s_vector);
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
	std::vector <std::string> d_vec= split(s,'-');
	if(d_vec.size()< 3)
	{
		return("none");
	}
	if(parse_day_month_year(d_vec[2],0)==0)
		return("none");
	if(parse_day_month_year(d_vec[1],1)==0)
		return("none");
	if(parse_day_month_year(d_vec[0],2)==0)
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
	std::vector <std::string> d_vec= split(date,'-');
	std::stringstream ss(d_vec[2]);
	double num1 ;
	ss>>num1;
	d.day= static_cast<int> (num1);
	std::stringstream s2(d_vec[1]);
	double num2 ;
	s2>>num2;
	d.month= static_cast<int> (num2);
	std::stringstream s3(d_vec[0]);
	double num3 ;
	s3>>num3;
	d.year= static_cast<int> (num3);
}

void parse(std::string &line)
{
	std::string date;
	std::string value;
	t_info user_info;
	float target_value= 0;
    // if(include_pipe(line))
    // {
		std:: vector <std::string> s_vec=split(line ,'|');
		if(s_vec.size()> 2)
			return ;
        if(s_vec.size()<= 2)
		{
			if (parse_date(s_vec[0])== "none")
			{
				std::cout <<"Error: bad input => "<< s_vec[0]<<"\n";
				 return ;
			}
			float value = parse_value(s_vec[1]);
			if(value == -1)
			{
					return ;}
			extract_info( s_vec[0] , s_vec[1],user_info);

			std::string line1;
			std::ifstream db_file("data.csv");
			std::getline(db_file,line1);
			int smallest_difference= 100000000;
			while(std::getline(db_file,line))
			{
				std::string value;
				std::string date;
				t_info origin_info;
				std:: vector <std::string> s_vec=split(line ,',');
				date=s_vec[0];
				value = s_vec[1];
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
