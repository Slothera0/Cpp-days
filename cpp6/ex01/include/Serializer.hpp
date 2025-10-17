/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 03:34:04 by arvoyer           #+#    #+#             */
/*   Updated: 2025/01/22 04:48:11 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <stdint.h>
#include "Data.hpp"

class Serializer
{
	private:
		Serializer(void);
		Serializer(Serializer &copy);
		Serializer& operator=(const Serializer &other);
		~Serializer(void);
	
	public:
		static uintptr_t 	serialize(Data* ptr);
		static Data* 		deserialize(uintptr_t raw);
};

#endif