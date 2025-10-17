/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 07:46:58 by arvoyer           #+#    #+#             */
/*   Updated: 2024/10/03 03:33:50 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>

class Contact
{
	public:
		Contact();
		void	change_first_name(std::string str);
		void	change_last_name(std::string str);
		void	change_nick_name(std::string str);
		void	change_phone_number(std::string str);
		void	change_darkest_secret(std::string str);
		void	print_first_name(int n);
		void	print_last_name(int n);
		void	print_nick_name(int n);
		void	print_phone_number(int n);
		void	print_darkest_secret(int n);
		void	print();
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nick_name;
		std::string	phone_number;
		std::string	darkest_secret;
};

#endif