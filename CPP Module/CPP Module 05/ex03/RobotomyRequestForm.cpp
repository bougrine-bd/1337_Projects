/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:22:09 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/23 09:24:12 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("", "", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("R", target, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : Form("R", getTarget(), 72, 45)
{
	*this = obj;
}

RobotomyRequestForm &RobotomyRequestForm::operator = (const RobotomyRequestForm &obj)
{
	setSign(obj.getSign());
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (getEGrade() > executor.getGrade() && getSign())
	{
		srand(time(0));
		int j = rand();
		if (j % 2) 
			std::cout << "khchkhchhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh, " << getTarget() << " has been robotomized successfully" << std::endl;
		else
			std::cout << "it's failure" << std::endl;
	}
	else
		throw GradeTooLowException();
}