/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:17:56 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/22 10:14:14 by abougrin         ###   ########.fr       */
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
		Form();
	public:
		Form(std::string const name, int const sGrade, int const eGrade);
		Form(Form const &obj);
		Form &operator = (Form const &obj);
		~Form();

		std::string	getName() const;
		bool	getSign() const;
		int	getSGrade() const;
		int getEGrade() const;
		
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
};

std::ostream &operator << (std::ostream const &output, const Form &obj);


#endif