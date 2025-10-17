/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:21:59 by arvoyer           #+#    #+#             */
/*   Updated: 2024/12/05 11:01:35 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H

#include <string>

class Brain
{
	public:
		Brain(void);
		Brain(Brain &copy);
		Brain& operator=(const Brain &other);
		~Brain(void);

		void add_idea(std::string std);
		void show_brain(void);
	private:
		std::string _ideas[100];
};

#endif