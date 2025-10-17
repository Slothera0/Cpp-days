/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 20:08:44 by arvoyer           #+#    #+#             */
/*   Updated: 2024/10/20 18:39:02 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <fstream>
#include <iostream>

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Please enter a filename and two strings" << std::endl;
		return (1);
	}
	
	if (argv[2][0] == '\0')
	{
		std::cout << "Can't use a null string in first string" << std::endl;
		return (1);
	}
	
	std::ifstream	in(argv[1]);
	if (in.is_open() == false)
	{
		std::cout << "Can't open the file" << std::endl;
		return (1);
	}
	
	std::ofstream	out(((std::string)argv[1]).append(".replace").c_str());
	
	if (out.is_open() == false)
	{
		std::cout << "Can't create the outfile" << std::endl;
		return (1);
	}
	
	std::string	line;
	size_t		last_pos;

	while (in.eof() == false)
	{
		std::getline(in, line);
		last_pos = 0;
		while ((last_pos = line.find(argv[2], last_pos)) != line.npos)
		{
			line.erase(last_pos, ((std::string)argv[2]).length());
			line.insert(last_pos, argv[3]);
			last_pos += ((std::string)argv[3]).length();
		}
		if (in.eof() == false)
			out << line << std::endl;
		else
			out << line;
	}
	return (0);
}
