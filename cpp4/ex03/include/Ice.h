/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:58:10 by arvoyer           #+#    #+#             */
/*   Updated: 2024/12/10 13:35:26 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
# define ICE_H

#include "AMateria.h"

class Ice : public AMateria
{
	public:
		Ice(void);
		Ice(const Ice &copy);
		Ice& operator=(const Ice &other);
		~Ice(void);

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif

