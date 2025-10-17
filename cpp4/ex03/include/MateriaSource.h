/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:49:39 by arvoyer           #+#    #+#             */
/*   Updated: 2024/12/10 13:22:52 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

#include "IMateriaSource.h"
#include "AMateria.h"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource &copy);
		MateriaSource& operator=(const MateriaSource &other);
		~MateriaSource(void);

		void		learnMateria(AMateria * m);
		AMateria*	createMateria(std::string const & type);
	private:
		AMateria	*_inventory[4];
};

#endif