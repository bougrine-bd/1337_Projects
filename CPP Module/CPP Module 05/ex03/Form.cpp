/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:46:24 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/23 10:49:58 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


Form::Form() : _name("(null)"), _sign(false), _sGrade(75), _eGrade(75)
{
}

Form::Form(std::string name, std::string target, int sGrade, int eGrade) : _name(name), _sign(false), _sGrade(sGrade), _eGrade(eGrade), _target(target)
{
	if (sGrade > 150 || eGrade > 150)
		throw GradeTooLowException();
	else if (sGrade < 1 || eGrade < 1)
		throw GradeTooHighException();
}

Form::Form(Form const &obj)  : _name(obj._name), _sGrade(obj._sGrade), _eGrade(obj._eGrade)
{
	*this = obj;
}

Form &Form::operator = (Form const &obj)
{
	_sign = obj._sign;
	return *this;
}

Form::~Form()
{
}

std::string	Form::getName() const
{
	return _name;
}

bool	Form::getSign() const
{
	return _sign;
}

void	Form::setSign(bool sign)
{
	_sign = sign;
}

int	Form::getSGrade() const
{
	return _sGrade;
}

int Form::getEGrade() const
{
	return _eGrade;
}

std::string	Form::getTarget() const
{
	return _target;
}

void	Form::setTarget(std::string const &target)
{
	_target = target;
	
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (_sGrade >= bureaucrat.getGrade())
		_sign = true;
	else
		throw GradeTooLowException();
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Grade is Too High!");
}
		
const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream &operator << (std::ostream &output, const Form &obj)
{
	if (obj.getSign())
	{
		output << obj.getName() << " form signed " << ", Grade required to sign it " << obj.getSGrade()
			<< " and a grade required to execute it " << obj.getEGrade();
	}
	else
	{
		output << obj.getName() << " form not signed " << ", Grade required to sign it " << obj.getSGrade()
			<< " and a grade required to execute it " << obj.getEGrade();
	}
	return output;
}
