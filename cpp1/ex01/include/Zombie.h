/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:41:46 by arvoyer           #+#    #+#             */
/*   Updated: 2024/10/19 16:57:31 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>

class Zombie
{
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void	set_name(std::string name);
		void	annonce(void);
	private:
		std::string	_name;
};

#endif