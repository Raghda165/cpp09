#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <fstream>
class BitCoinExchange
{
	private:
	std :: string _date;
	int day;
	int month;
	int year;
	double _value;

	public:
	BitCoinExchange();
	BitCoinExchange(std::string &d, float value);
	BitCoinExchange(const BitCoinExchange &obj);
	BitCoinExchange &operator=(const BitCoinExchange &other);
	~BitCoinExchange();

	void Set_date(std::string _date);
	void Set_value(double v);
	std::string Get_date(void);
	double Get_value(void);
	void calculate_price(void);
};

void parse(std::string &line);
std::vector<std::string> split(std::string s, char delim);

#endif
