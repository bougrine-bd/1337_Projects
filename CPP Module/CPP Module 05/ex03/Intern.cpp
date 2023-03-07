/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:39:05 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/23 10:38:40 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() : _sForm(NULL), _rForm(NULL), _pForm(NULL)
{
}

Intern::Intern(Intern const &intern)
{
    *this = intern;
}

Intern &Intern::operator = (Intern const &)
{
    return (*this);
}

Intern::~Intern()
{
    if (_sForm)
        delete (_sForm);
    if (_rForm)
        delete (_rForm);
    if (_pForm)
        delete (_pForm);
}

Form	*Intern::makeSform(std::string target)
{
    _sForm = new ShrubberyCreationForm(target);
    return (_sForm);
}

Form	*Intern::makeRform(std::string target)
{
    _rForm = new RobotomyRequestForm(target);
    return (_rForm);
}

Form	*Intern::makePform(std::string target)
{
    _pForm = new PresidentialPardonForm(target);
    return (_pForm);
}

Form  *Intern::makeForm(std::string formName, std::string formTarget)
{
    std::string name[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    Form *(Intern::*arrForm[3])(std::string) = {&Intern::makeSform, &Intern::makeRform, &Intern::makePform};
    for (int i = 0; i < 3; i++)
    {
        if (name[i] == formName)
        {
            std::cout << "Intern creates " << formName <<  std::endl;
            return ((this->*arrForm[i])(formTarget));
        }
    }
    std::cout << "Intern dosn't creates any form" << std::endl;
    return 0;
}
