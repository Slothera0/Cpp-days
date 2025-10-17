/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:03:10 by arvoyer           #+#    #+#             */
/*   Updated: 2025/01/28 18:11:30 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>
#include <iostream>

template <class T>
class Array
{
	private:
	    T 				*_array;
		unsigned int 	_len;
	public:
	    Array()
		{
			_len = 0;
			_array = NULL;
		};
		Array(unsigned int n)
		{
			_len = n;
			_array = new T[n];
		}
		Array(Array &copy)
		{
			this->_array = NULL;
			*this = copy;
		}
		
		~Array()
		{
			if (_array)
				delete[] _array;
		}

		Array& 	operator=(Array &other)
		{
			if (this->_array == other._array)
				return (*this);
			if (this->_array)
				delete[] this->_array;
			this->_array = new T[other._len];
			for (unsigned int i = 0 ; i < other._len; i++)
			{
				this->_array[i] = other._array[i];
			}

			this->_len = other._len;
			return (*this);
		}
		
		T&		operator[](unsigned int i)
		{
			if (i >= _len)
				throw std::exception();
			return (_array[i]);
		}
		
		unsigned int	size()
		{
			return (_len);
		}

		const T&		operator[](unsigned int i) const
		{
			if (i >= _len)
				throw std::exception();
			return (_array[i]);
		}
		
		unsigned int	size() const
		{
			return (_len);
		}
};

#endif