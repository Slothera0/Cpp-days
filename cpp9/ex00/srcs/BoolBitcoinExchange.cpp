/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BoolBitcoinExchange.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:16:55 by arvoyer           #+#    #+#             */
/*   Updated: 2025/03/18 18:25:00 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool	BitcoinExchange::isADate(std::string date)
{
	if (!this->isAYear(date.substr(0,4)))
		return (false);
	std::string year = date.substr(0,4);
	date.erase(0,4);
	if (date[0] != '-')
		return (false);
	date.erase(0,1);
	if (!this->isAMonth(date.substr(0,2)))
		return (false);
	std::string month = date.substr(0,2);
	date.erase(0,2);
	if (date[0] != '-')
		return (false);
	date.erase(0,1);
	if (!this->isADay(date.substr(0,2), month, year))
		return (false);
	date.erase(0,2);
	while (isspace(date[0]))
		date.erase(0,1);
	if (date.size() != 0)
		return (false);
	return (true);
}

bool	BitcoinExchange::isAValue(std::string value)
{
	char **pos = NULL;
	float nb = strtof(value.c_str(), pos);
	if (pos != NULL)
		return (false);
	if (nb < 0 || nb > 1000)
		return (false);
	return (true);
}

bool	BitcoinExchange::isAYear(std::string year)
{
	for (std::string::iterator i = year.begin(); i != year.end(); i++)
	{
		if (!isdigit(*i))
			return (false);
	}
	return (true);
}

bool	BitcoinExchange::isAMonth(std::string month)
{
	for (std::string::iterator i = month.begin(); i != month.end(); i++)
	{
		if (!isdigit(*i))
			return (false);
	}
	int Dmonth = atoi(month.c_str());
	if (Dmonth < 1 || Dmonth > 12)
		return (false);
	return (true);
}

bool	BitcoinExchange::isADay(std::string day, std::string month, std::string year)
{	
	for (std::string::iterator i = day.begin(); i != day.end(); i++)
	{
		if (!isdigit(*i))
			return (false);
	}
	
	int Dmonth = atoi(month.c_str());
	int Dday = atoi(day.c_str());
	int Dyear = atoi(year.c_str());
	
	if ((Dmonth <= 7 && Dmonth % 2 == 1) || (Dmonth > 7 && Dmonth % 2 == 0))
	{
		if (Dday < 1 || Dday > 31)
			return (false);
	}
	else if (Dmonth != 2)
	{
		if (Dday < 1 || Dday > 30)
			return (false);
	}
	else
	{
		if (Dyear % 400 == 0 || ((Dyear % 4 == 0 && Dyear % 100 != 0) || (Dyear % 4 != 0 && Dyear % 100 == 0)))
		{
			if (Dday < 1 || Dday > 29)
				return (false);
		}
		else
		{
			if (Dday < 1 || Dday > 28)
				return (false);
		}
	}
	return (true);
}