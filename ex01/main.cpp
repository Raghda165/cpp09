/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryagoub <ryagoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 04:19:36 by ryagoub           #+#    #+#             */
/*   Updated: 2025/03/08 23:07:25 by ryagoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <cstdlib>
int calculate_res(int op1,char sign,int op2)
{
	int res= 0;
	if(sign == '*')
	{
		std::cout<<"im here"<<"\n";
			return(op1*op2);}
	else if(sign == '/')
		return(op1/op2);
	else if(sign=='-')
		return(op2 - op1);
	else if(sign=='+')
		return(op1 + op2);
	return(res);
}
int handle_av(std::string s,int ac)
{
	unsigned int j = 0;
	int op1=0;
	int op2 =0 ;
	int result =0;
	std::string arthim_op = "*/-+";
	std::stack <int> container;
	while (j < s.length())
	{
		if(s[j]==' ')
			j++;
		else if((arthim_op.find(s[j])==std::string::npos)&&(!isdigit(s[j])) )
		{
			std::cerr<<"Error"<<"\n";
			exit(1);
		}
		else if(isdigit(s[j]))
		{	container.push(s[j] - '0');
			j++;
		}
	else
		{
			op1 = container.top();
			container.pop();
			op2=container.top();
			container.pop();
			std::cout<<"op1"<<op1<<"\n";
			std::cout<<"op2"<<op2<<"\n";
			result=calculate_res(op1,s[j],op2);
			std::cout<<"this is j"<<j<<"\n";
			container.push(result);
			j++;
		}
	}
	return(result);
}
int main(int ac,char **av)
{
	int res= 0;
	if(ac==2)
	{
		res = handle_av(av[1],ac);
		std::cout<<res<<"\n";

	}
	else
	{
		std::cout<<"the number of arguments minimum must be three";
	}
}
