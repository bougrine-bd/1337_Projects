/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:22:04 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/22 11:01:09 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("", "", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("P", target, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : Form("P", obj.getTarget(), 25, 5)
{
	*this = obj;
}

PresidentialPardonForm &PresidentialPardonForm::operator = (const PresidentialPardonForm &obj)
{
	setSign(obj.getSign());
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (getEGrade() > executor.getGrade() && getSign())
	{
		std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
	}
	else
		throw GradeTooLowException();
}