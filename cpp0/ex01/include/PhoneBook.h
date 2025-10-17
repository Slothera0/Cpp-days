/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 08:28:32 by arvoyer           #+#    #+#             */
/*   Updated: 2024/10/03 03:09:04 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.h"

class PhoneBook
{
	public:
		void		add(int nb_ctt);
		void		search();
		std::string	ask(std::string question);
		void		print();
	private:
		Contact	contact[8];
};

#endif