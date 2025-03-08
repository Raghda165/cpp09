/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryagoub <ryagoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 01:59:15 by ryagoub           #+#    #+#             */
/*   Up_dated: 2025/03/04 02:00:56 by ryagoub          ###   ########.fr       */
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
// int categorize(std::string &s)
// {
// 	if(s.length()==1 && isalpha(s[0]))
// 	    return(2);
// 	else if(isdigit(s[0])&&s[s.length()-1]== 'f'&&s.length()!=1)
// 		s.erase(s.size() - 1);
// 	else if(!is_all_digit(s))
// 		return(4);
// 	return(0);
// 	// else if
// }
float parse_value(std::string s)
{
	float n = -1;
	std::stringstream ss(s);
	double num ;
	ss>>num;
	n = static_cast<float>(num);
	if(n < 1 || n > 1000)
	{
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
	if(flag==0 &&(s.length()==2&& (n < 1 || n > 31)))
		return(std::cout <<"the date should be valid and  yyyy-mm-dd format remeber 0 on the left means nothing",0);
	if((flag==1) &&((s.length()!=2)|| (n < 1 || n > 12)))
		return(std::cout <<"the date should be valid and yyyy-mm-dd format remeber 0 on the left means nothing",0);
	if(flag==2 &&((s.length()!=4)|| (n < 1 || n > 2025)))
	  return(std::cout <<"the date should be valid and yyyy-mm-dd format remeber 0 on the left means nothing",0);
	return(1);
}

std::string parse_date(std::string & s)
{
	std::vector <std::string> d_vec= split(s,'-');
	if(d_vec.size()!= 3)
	{
		return("none");
	}
	std::string day= d_vec[0];
	std::string month=d_vec[1];
	std::string year= d_vec[2];
	if(!(parse_day_month_year(d_vec[0],0)||parse_day_month_year(d_vec[1],1)||parse_day_month_year(d_vec[2],2)))
		return("none");
	return(s);
}
void parse(std::string &line)
{
	std::string date;
	std::string value;
    if(include_pipe(line))
    {
		std:: vector <std::string> s_vec=split(line ,'|');
		if(s_vec.size()> 2)
			return ;
        if(s_vec.size()== 2)
		{
			float value = parse_value(s_vec[1]);
			if(value == -1)
			{
					return ;}
			if (parse_date(s_vec[0])== "none")
			{
				 return ;}

			BitCoinExchange row(s_vec[0],value);
		}

    }

}
