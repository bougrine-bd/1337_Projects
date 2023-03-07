/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:22:07 by abougrin          #+#    #+#             */
/*   Updated: 2021/12/18 14:57:09 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTAILPARONFROM_HPP
#define PRESIDENTAILPARONFROM_HPP

#include "Form.hpp"
#include <fstream>

class PresidentialPardonForm : public Form
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &obj);
		PresidentialPardonForm &operator = (const PresidentialPardonForm &obj);
		~PresidentialPardonForm();

		void execute(Bureaucrat const & executor) const;
};


#endif
