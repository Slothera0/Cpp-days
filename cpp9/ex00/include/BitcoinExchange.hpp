/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:05:53 by arvoyer           #+#    #+#             */
/*   Updated: 2025/03/28 14:11:42 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <exception>

class BitcoinExchange
{
	public:
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange &copy);
		BitcoinExchange& operator=(const BitcoinExchange &other);
		~BitcoinExchange(void);

		void	parseDB(std::string DB);
		void	findValue(std::string date, float value);
		
		size_t	size();
		char	getSep(std::string line);
		void	show();
		void	clearSpace(std::string &str);
		
		bool	isADate(std::string date);
		bool	isAValue(std::string value);
		bool	isAYear(std::string year);
		bool	isAMonth(std::string month);
		bool	isADay(std::string day, std::string month, std::string year);

	private:
		std::map<std::string, double> _map;
};

#endif