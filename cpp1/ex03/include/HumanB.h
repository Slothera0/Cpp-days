/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:49:33 by arvoyer           #+#    #+#             */
/*   Updated: 2024/10/19 19:55:42 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

#include "Weapon.h"

class HumanB
{
	public:
		HumanB(std::string name);
		void	attack(void);
		void	setWeapon(Weapon &weapon);
	private:
		std::string	_name;
		Weapon		*_weapon;
};

#endif