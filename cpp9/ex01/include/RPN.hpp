/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 01:45:53 by arvoyer           #+#    #+#             */
/*   Updated: 2025/03/10 02:30:01 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <cstdlib>
#include <exception>

class RPN
{
	public:
		RPN(void);
		RPN(RPN &copy);
		RPN& operator=(const RPN &other);
		~RPN(void);

		int 	calculate(char *str);
		void	clear();
	private:
		std::stack<int> _stack;
};

#endif