/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:34:39 by arvoyer           #+#    #+#             */
/*   Updated: 2024/10/20 20:13:16 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed &copy);
		Fixed& operator=(const Fixed &other);
		~Fixed(void);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
	private:
		int					_RawBits;
		static const int	_fractionalBits = 8;
};

#endif