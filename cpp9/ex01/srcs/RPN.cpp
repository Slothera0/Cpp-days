/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 01:45:45 by arvoyer           #+#    #+#             */
/*   Updated: 2025/03/10 02:40:45 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(RPN &copy)
{
	*this = copy;
}

RPN& RPN::operator=(const RPN &other)
{
	if (this != &other)
		this->_stack = other._stack;
	return (*this);
}

RPN::~RPN(void) {}

int RPN::calculate(char *str)
{
	int	i = 0;
	
	
	while (str[i])
	{
		if (isdigit(str[i]))
			this->_stack.push(str[i] - '0');
		else if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*')
		{
			if (this->_stack.size() < 2)
				throw std::exception();
			int	op2 = this->_stack.top();
			this->_stack.pop();
			int	op1 = this->_stack.top();
			this->_stack.pop();

			switch (str[i])
			{
				case '+':
				{
					this->_stack.push(op1 + op2);
					break ;
				}
				case '-':
				{
					this->_stack.push(op1 - op2);
					break ;
				}
				case '*':
				{
					this->_stack.push(op1 * op2);
					break ;
				}
				case '/':
				{
					if (op2 == 0)
						throw std::exception();
					this->_stack.push(op1 / op2);
					break ;
				}
			}
		}
		else
		{
			this->clear();
			throw std::exception();
		}
		i++;
		if (!isspace(str[i]) && str[i] != '\0')
		{
			this->clear();
			throw std::exception();
		}
		while (isspace(str[i]))
			i++;
	}
	if (this->_stack.size() != 1)
		throw std::exception();
	return (this->_stack.top());
}

void	RPN::clear()
{
	while (!this->_stack.empty())
		this->_stack.pop();
}