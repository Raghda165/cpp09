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
 typedef struct s_info
{
	int day;
	int month;
	int year;
	float value;
}t_info;


void parse(std::string &line);
std::vector<std::string> split(std::string s, char delim);

#endif
