/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:05:13 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/23 09:52:20 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

std::ostream &operator << (std::ostream &output, const Form &obj);

int main()
{
	try
	{
		Bureaucrat bureaucrat("abdeljalil", 1);
		ShrubberyCreationForm sCForm("Shrubbery");
		RobotomyRequestForm rRForm("flan");
		PresidentialPardonForm pPForm("flan ben fertelan");
		Form *form[3] = {&sCForm, &rRForm, &pPForm};
		
		form[0]->beSigned(bureaucrat);
		bureaucrat.executeForm(*form[0]);
		form[0]->execute(bureaucrat);
		form[1]->beSigned(bureaucrat);
		form[1]->execute(bureaucrat);
		form[2]->beSigned(bureaucrat);
		form[2]->execute(bureaucrat);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}