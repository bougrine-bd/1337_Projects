/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:39:08 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/23 10:22:30 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		ShrubberyCreationForm *_sForm;
		RobotomyRequestForm *_rForm;
		PresidentialPardonForm *_pForm;
	public:
		Intern();
		Intern(Intern const &intern);
		Intern &operator = (Intern const &);
		~Intern();

		Form	*makeSform(std::string target);
		Form	*makeRform(std::string target);
		Form	*makePform(std::string target);
		Form	*makeForm(std::string formName, std::string formTarget);
};

#endif