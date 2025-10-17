/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 04:51:25 by arvoyer           #+#    #+#             */
/*   Updated: 2025/01/22 04:58:45 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data		data;
	uintptr_t	ptr;
	
	data.a = 'a';
	data.b = 42;
	
	std::cout << "Data : a = " << data.a << ", b = " << data.b << std::endl; 

	ptr = Serializer::serialize(&data);
	Data *data2 = Serializer::deserialize(ptr);

	std::cout << "Data2 : a = " << data2->a << ", b = " << data2->b << std::endl; 
}