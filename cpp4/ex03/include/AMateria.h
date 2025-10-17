/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:47:56 by arvoyer           #+#    #+#             */
/*   Updated: 2024/12/10 13:23:26 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
# define AMATERIA_H

#include <string>
#include "ICharacter.h"

class AMateria
{
	public:
		AMateria(void);
		AMateria(std::string const & type);
		AMateria(const AMateria &copy);
		AMateria& operator=(const AMateria &other);
		virtual ~AMateria(void);

		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
	protected:
		std::string _type;
	
};

#endif