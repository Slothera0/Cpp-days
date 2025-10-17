/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:22:50 by arvoyer           #+#    #+#             */
/*   Updated: 2025/02/19 12:59:24 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T> >
{
	public:
		typedef typename std::deque<T>::iterator iterator;
		typedef typename std::deque<T>::reverse_iterator reverse_iterator;

		iterator begin(void)
		{
			return (this->c.begin());
		}
		iterator end(void)
		{
			return (this->c.end());
		}
		reverse_iterator rbegin(void)
		{
			return (this->c.rbegin());
		}
		reverse_iterator rend(void)
		{
			return (this->c.rend());
		}
};

#endif