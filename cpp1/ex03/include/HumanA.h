/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:46:23 by arvoyer           #+#    #+#             */
/*   Updated: 2024/10/19 20:05:29 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

#include "Weapon.h"

class HumanA
{
	public:
		HumanA(std::string name, Weapon &weapon);
		void	attack(void);
	private:
		std::string	_name;
		Weapon		&_weapon;
};

#endif