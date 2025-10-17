/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 06:38:41 by arvoyer           #+#    #+#             */
/*   Updated: 2024/09/30 06:59:35 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static void	print_upper(char *str);

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}

	for (int i = 1; i < argc; i++)
		print_upper(argv[i]);
	std::cout << std::endl;
	
	return (0);
}

static void	print_upper(char *str)
{
	for (int i = 0; str[i]; i++)
		std::cout << (char)toupper(str[i]);
}
