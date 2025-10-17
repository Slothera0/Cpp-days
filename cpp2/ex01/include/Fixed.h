/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:34:39 by arvoyer           #+#    #+#             */
/*   Updated: 2024/10/20 21:06:17 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed &copy);
		Fixed(const int nb);
		Fixed(const float nb);
		~Fixed(void);

		Fixed& operator=(const Fixed &other);
		
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
	private:
		int					_RawBits;
		static const int	_fractionalBits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& nb);

#endif