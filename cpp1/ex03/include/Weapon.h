/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:34:43 by arvoyer           #+#    #+#             */
/*   Updated: 2024/10/19 20:03:40 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

#include <string>

class Weapon
{
	public:
		Weapon();
		Weapon(std::string type);
		const std::string	&getType();
		void				setType(std::string type);
	private:
		std::string	_type;
};

#endif