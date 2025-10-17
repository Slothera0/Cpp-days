/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 03:33:28 by arvoyer           #+#    #+#             */
/*   Updated: 2025/01/22 04:51:19 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void)
{

}

Serializer::Serializer(Serializer &copy)
{
	static_cast<void>(copy);
}

Serializer& Serializer::operator=(const Serializer &other)
{
	static_cast<void>(other);
	return (*this);
}

Serializer::~Serializer(void)
{
	
}

uintptr_t 	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* 		Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}