/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:05:08 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/23 10:57:48 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &obj) : _name(obj._name)
{
	*this = obj;
}

Bureaucrat &Bureaucrat::operator = (Bureaucrat const &obj)
{
	_grade = obj._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

std::string Bureaucrat::getName() const
{
	return (_name);
}
int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::increment()
{
	_grade--;
	if (_grade < 1)
		throw GradeTooHighException();
}

void Bureaucrat::decrement()
{
	_grade++;
	if (_grade > 150)
		throw GradeTooLowException();
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signs " << form.getName() << "." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << _name << " cannot sign " << form.getName() << ", because " << _name << " " << e.what() << "." << std::endl;
	}
}

void Bureaucrat::executeForm(Form const &form)
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executes " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << _name << " cannot executes " << form.getName() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is Too High!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is Too Low!");
}

std::ostream &operator << (std::ostream &output, const Bureaucrat &obj)
{
	output <<  obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return (output);
}
