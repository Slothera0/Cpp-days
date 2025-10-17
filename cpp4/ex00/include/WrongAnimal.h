/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 23:18:51 by arvoyer           #+#    #+#             */
/*   Updated: 2024/12/02 07:04:44 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

#include <string>

class WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(std::string type);
		WrongAnimal(WrongAnimal &copy);
		WrongAnimal& operator=(const WrongAnimal &other);
		virtual ~WrongAnimal(void);

		void		setType(std::string type);
		std::string getType(void);
		void		makeSound(void) const;
	protected:
		std::string	_type;
};

#endif