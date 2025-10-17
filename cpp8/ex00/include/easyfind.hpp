/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:52:00 by arvoyer           #+#    #+#             */
/*   Updated: 2025/02/18 12:42:57 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <exception>

template<class T>
int	easyfind(T list, int value)
{
	typename T::iterator temp;

	temp = std::find(list.begin(), list.end(), value);
	if (temp == list.end())
		throw std::exception();
	return (*temp);
}