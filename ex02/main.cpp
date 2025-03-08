/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryagoub <ryagoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 04:19:36 by ryagoub           #+#    #+#             */
/*   Updated: 2025/03/08 06:13:16 by ryagoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <cstdlib>
int calculate_res(int op1,std::string sign,int op2)
{
	int res= 0;
	if(sign == "*")
	{
		std::cout<<"im here"<<"\n";
			return(op1*op2);}
	else if(sign == "/")
		return(op1/op2);
	else if(sign=="-")
		return(op1 - op2);
	else if(sign=="+")
		return(op1 + op2);
	return(res);
}
int handle_av(char **s,int ac)
{
	int j = 0;
	int op1=0;
	int op2 =0 ;
	int result =0;
	std::stack <int> container;
	while (j < ac)
	{
		if( j!= 1&&j%2!=0)
		{
			op1 = container.top();
			container.pop();
			op2=container.top();
			container.pop();
			std::cout<<"op1"<<op1<<"\n";
			std::cout<<"op2"<<op2<<"\n";
			result=calculate_res(op1,s[j],op2);
			container.push(result);
		}
		else
		{
			container.push(std::atoi(s[j]));
		}
		j++;
	}
	return(result);
}
int main(int ac,char **av)
{
	int res= 0;
	if(ac>3)
	{
		res = handle_av(av,ac);
		std::cout<<res<<"\n";

	}
	else
	{
		std::cout<<"the number of arguments minimum must be three";
	}
}
