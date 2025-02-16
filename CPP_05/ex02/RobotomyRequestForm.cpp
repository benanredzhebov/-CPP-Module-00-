/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:12:09 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/21 10:14:47 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Default") {
	std::cout << "RobotomyRequestForm dflt constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
	std::cout << "RobotomyRequestForm parametrized constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target) {
	std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

std::string	RobotomyRequestForm::getTarget() const {
	return _target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

void		RobotomyRequestForm::executeForm() const {
	std::cout << "pffsss...Drggg...\n";
	std::cout << getTarget() << " has been robotomized.\n";
}

/* Simulates a robotomy procedure, which has 50% chance of success.
If robotomy fails , the badLuck exceprion can be thrown to signal this.*/
void	RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	time_t t; // is used to hold the current time.
	try {
		if (!this->getIsSigned())
			throw(AForm::FormNotSignedException());
		else if (executor.getGrade() > this->getGradeToExecute())
			throw(AForm::GradeTooLowException());
		else if (time(&t) % 2)
			throw(RobotomyRequestForm::BadLuck());
		else
			this->executeForm();
	}
	catch (const std::exception &e) {
		std::cerr << "Exception thrown: " << e.what() << "Robotomy failed." << std::endl;
	}
}