/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:48:20 by arvoyer           #+#    #+#             */
/*   Updated: 2025/01/21 17:58:35 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <string>


int main(int argc, char **argv)
{
	std::string s1;

	if (argc == 1)
		return (0);
	s1 = argv[1];
	ScalarConverter::convert(s1);
}