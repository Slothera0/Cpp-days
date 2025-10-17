/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 23:21:42 by arvoyer           #+#    #+#             */
/*   Updated: 2024/12/05 11:10:37 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

#include "Animal.h"
#include "Brain.h"

class Cat : virtual public Animal
{
	public:
		Cat(void);
		Cat(Cat &copy);
		Cat& operator=(const Cat &other);
		~Cat(void);

		void	setType(std::string type);
		void	makeSound(void) const;
		void	add_idea(std::string std);
		void	show_ideas(void);
	private:
		Brain	*_brain;
};

#endif