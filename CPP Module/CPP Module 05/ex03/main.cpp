/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:05:13 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/23 10:38:17 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

std::ostream &operator << (std::ostream &output, const Form &obj);

int main()
{
	try
	{
		Bureaucrat bureaucrat("someone", 1);
		Intern intern;
		Form *ptrForm;

		ptrForm = intern.makeForm("presidential pardon", "flan");
		std::cout << *ptrForm << std::endl;
		ptrForm->beSigned(bureaucrat);
		ptrForm->execute(bureaucrat);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}