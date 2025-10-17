/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:51:04 by arvoyer           #+#    #+#             */
/*   Updated: 2024/12/10 13:35:14 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
# define CURE_H

#include "AMateria.h"

class Cure : public AMateria
{
	public:
		Cure(void);
		Cure(const Cure &copy);
		Cure& operator=(const Cure &other);
		~Cure(void);

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif