/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:39:58 by beredzhe          #+#    #+#             */
/*   Updated: 2024/09/26 14:57:10 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;

	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed(const int value);
		Fixed(const float value);
		~Fixed();
		
		Fixed &operator=(const Fixed &other);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw);
		
		float	toFloat( void ) const;
		int		toInt( void ) const;

		/* Comparison operators */
		bool	operator>(const Fixed &other) const;
		bool	operator<(const Fixed &other) const;
		bool	operator>=(const Fixed &other) const;
		bool	operator<=(const Fixed &other) const;
		bool	operator==(const Fixed &other) const;
		bool	operator!=(const Fixed &other) const;
		
		/* Arithmetic operators */
		Fixed	operator+(const Fixed &other) const;
		Fixed	operator-(const Fixed &other) const;
		Fixed	operator*(const Fixed &other) const;
		Fixed	operator/(const Fixed &other) const;

		/* Increment/ Decrement operators */
		Fixed	&operator++(); // Pre-increment
		Fixed	operator++(int); // Post-increment
		Fixed	&operator--(); // Pre-decrement
		Fixed	operator--(int); // Post-decrement

		/* Min/ Max static functions */
		static Fixed		&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);

		Fixed abs() const;
};
/* Stream output overload */
std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif