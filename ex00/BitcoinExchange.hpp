#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE
#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <fstream>
 typedef struct s_info
{
	int day;
	int month;
	int year;
	float value;
}t_info;
class BitcoinExchange
 {
	public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &obj);
	BitcoinExchange&operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	void parse(std::string &line);
 };



#endif
