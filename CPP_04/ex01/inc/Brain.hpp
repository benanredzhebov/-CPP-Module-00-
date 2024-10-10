/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:44:55 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/10 09:53:29 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
// #include "./Animal.hpp"

class Brain {
	private:
	std::string _ideas[100];

	public:
	Brain();
	Brain(const Brain &other);
	~Brain();

	Brain		&operator=(const Brain &other);
	void		setIdeas(int index, std::string idea);
	std::string	getIdeas(int index);
};

#endif