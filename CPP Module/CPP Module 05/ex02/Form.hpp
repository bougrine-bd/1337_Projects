/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:17:56 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/22 11:18:29 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"      

class Bureaucrat;

class Form 
{
	private:
		std::string const _name;
		bool _sign;
		int const _sGrade;
		int const _eGrade;
		std::string _target;
		Form();
	public:
		Form(std::string name, std::string target, int sGrade, int eGrade);
		Form(Form const &obj);
		Form &operator = (Form const &obj);
		virtual ~Form();

		std::string	getName() const;
		bool	getSign() const;
		void	setSign(bool sign);
		int	getSGrade() const;
		int getEGrade() const;
		std::string	getTarget() const;
		void	setTarget(std::string const &target);
		
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		
		void beSigned(Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const & executor) const = 0;

};

std::ostream &operator << (std::ostream const &output, const Form &obj);

#endif