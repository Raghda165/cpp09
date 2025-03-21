/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryagoub <ryagoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 02:26:34 by ryagoub           #+#    #+#             */
/*   Updated: 2025/03/21 05:24:22 by ryagoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
Rpn::Rpn(){}
Rpn::Rpn(const Rpn &obj){(void)obj;}
Rpn & Rpn::operator=(const Rpn &other)
{
	(void)other;
	return (*this);}
Rpn::~Rpn(){}
int  calculate_res(int op1,char sign,int op2)
{
	int res= 0;
	if(sign == '*')
	{

			return(op1*op2);}
	else if(sign == '/')
	{
		if(op1 != 0)
			return(op2/op1);
		else
			std::cout<<"the second operator of the division should not be zero"<<"\n";
			exit(1);
			}
	else if(sign=='-')
		return(op2 - op1);
	else if(sign=='+')
		return(op1 + op2);
	return(res);
}

void do_op(std::stack <int> &st, std::string &s,unsigned int &j,int &flag,int &result)
{
	int op1=0;
	int op2 =0 ;
	if(st.size()>= 2)
	{
		flag = 0;
		op1 = st.top();
		st.pop();
		op2=st.top();
		st.pop();
		result=calculate_res(op1,s[j],op2);
		st.push(result);
		j++;
	}
	else
	{
		std::cerr<<"Error"<<"\n";
		exit(1);
	}

}
int Rpn:: handle_av(std::string s)
{
	unsigned int j = 0;
	int flag = 0;
	int m_flag = 0;
	int result = 0;
	std::string arthim_op = "*/-+";
	std::stack <int> container;
	while (j < s.length())
	{
		if(s[j]=='-'&& isdigit(s[j+1])&& m_flag == 0)
		{
			m_flag = 1;
			j++;
		}
		if(s[j]==' ')
		{
			j++;
			flag = 0;
			m_flag = 0;
		}
		else if((arthim_op.find(s[j])==std::string::npos)&&(!isdigit(s[j])) )
		{
			std::cerr<<"Error"<<"\n";
			exit(1);
		}
		else if(isdigit(s[j]))
		{
			if(flag == 1)
			{
				std::cerr<<"Error : the numbers should be less than 10"<<"\n";
				exit(1);
			}
			if (m_flag == 1)
				container.push(-1*(s[j] - '0'));
			else
				container.push(s[j] - '0');
			j++;
		}
	else
		do_op(container, s,j,flag, result);
	}
	return(result);
}
