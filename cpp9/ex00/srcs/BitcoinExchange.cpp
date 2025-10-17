/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:05:50 by arvoyer           #+#    #+#             */
/*   Updated: 2025/03/28 14:12:11 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{	
	std::ifstream	in("data.csv");
	if (in.is_open() == false)
	{
		throw std::exception();
	}
	
	std::string	line;
	while (in.eof() == false)
	{
		std::getline(in, line);
		size_t midPos = line.find(",");
		if (midPos == line.npos)
			continue ;
		std::string date = line.substr(0, midPos);
		std::string value = line.substr(midPos + 1, line.npos);

		this->clearSpace(date);
		this->clearSpace(value);
		if (!(this->isADate(date)))
			continue ;
		
		_map[date] = atof(value.c_str());
	}
}

BitcoinExchange::BitcoinExchange(BitcoinExchange &copy)
{
	*this = copy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		this->_map = other._map;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void) {}

void	BitcoinExchange::parseDB(std::string DB)
{
	std::ifstream	in(DB.c_str());
	if (in.is_open() == false)
	{
		std::cerr << "Error: can't open the file" << std::endl;
		return ;
	}
	
	std::string	line;
	if (in.eof() != false) 
		return ;
	std::getline(in, line);
	char sep = this->getSep(line);
	if (!sep)
	{
		std::cerr << "Error: wrong format. A good format is => \" date one_char_sep value\"" << std::endl;
		return ;
	}

	while (in.eof() == false)
	{
		std::getline(in, line);
		this->clearSpace(line);
		if (line.size() == 0)
			continue ;
		size_t midPos = line.find(sep);
		if (midPos == line.npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}
		std::string date = line.substr(0, midPos);
		std::string value = line.substr(midPos + 1, line.npos);

		this->clearSpace(date);
		this->clearSpace(value);
		if (!(this->isADate(date)))
		{
			std::cerr << "Error: not a valid date, the date format is YYYY-MM-DD " << std::endl;
			continue ;
		}
		if (!(this->isAValue(value)))
		{
			std::cerr << "Error: not a valid value, the value must be between 0 and 1000" << std::endl;
			continue ;
		}
		this->findValue(date, strtof(value.c_str(), NULL));
	}
}

void	BitcoinExchange::findValue(std::string date, float value)
{
	for (std::map<std::string, double>::iterator i = this->_map.begin(); i != _map.end(); i++)
	{
		if (i->first > date)
		{
			if (i == this->_map.begin())
			{
				std::cerr << "Error: this date is older than all dates of the datebase" << std::endl;
				return ;
			}
			i--;
			std::cout << date << " => " << value << " = " << value * i->second << std::endl;
			return ;
		}
	}
	if (_map.size() != 0)
		std::cout << date << " => " << value << " = " << value * (--(this->_map.end()))->second << std::endl;
}


size_t	BitcoinExchange::size()
{
	return (this->_map.size());
}

void	BitcoinExchange::show()
{
	for (std::map<std::string, double>::iterator i = this->_map.begin(); i != _map.end(); i++)
	{
		std::cout << i->first << ":" << i->second << std::endl;
	}
}

char	BitcoinExchange::getSep(std::string line)
{
	this->clearSpace(line);
	if (line.find("date", 0, 4) == line.npos)
		return (0);
	line.erase(0,4);
	if (line.size() == 0)
		return (0);
	char sep = line[0];
	line.erase(0,1);
	if (line.find("value", 0, 5) == line.npos)
		return (0);
	line.erase(0,5);
	if (line.size() == 0)
		return (sep);
	return (0);
}

void	BitcoinExchange::clearSpace(std::string &str)
{
	int i = 0;
	while (str[i])
	{
		if (isspace(str[i]))
			str.erase(i, 1);
		else
			i++;
	}
}