/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 23:18:51 by arvoyer           #+#    #+#             */
/*   Updated: 2024/12/02 07:08:52 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

#include <string>

class Animal
{
	public:
		Animal(void);
		Animal(std::string type);
		Animal(Animal &copy);
		Animal& operator=(const Animal &other);
		virtual ~Animal(void);

		void			setType(std::string type);
		std::string 	getType(void) const;
		virtual void	makeSound(void) const;
	protected:
		std::string	_type;
};

#endif