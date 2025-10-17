/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:47:56 by arvoyer           #+#    #+#             */
/*   Updated: 2024/12/10 13:30:02 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIALSOURCE_H
# define IMATERIALSOURCE_H

#include <string>
#include "AMateria.h"

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif