/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:59:03 by arvoyer           #+#    #+#             */
/*   Updated: 2024/12/10 13:56:45 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
# define CHARACTER_H

#include "ICharacter.h"


class Character : public ICharacter
{
	public:
		Character(void);
		Character(std::string name);
		Character(Character &copy);
		Character& operator=(const Character &other);
		~Character(void);

		std::string const & getName() const;
		AMateria	*getMateria(int idx);
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
	private:
		std::string	_name;
		AMateria	*_inventory[4];
};

#endif