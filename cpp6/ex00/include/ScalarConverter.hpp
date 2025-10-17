/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:48:27 by arvoyer           #+#    #+#             */
/*   Updated: 2025/01/21 17:28:41 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter &copy);
		ScalarConverter& operator=(const ScalarConverter &other);
		~ScalarConverter(void);
	public:
		static void	convert(std::string s);
};

#endif