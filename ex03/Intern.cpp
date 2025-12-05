/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:43:16 by yyaniv            #+#    #+#             */
/*   Updated: 2025/12/05 15:58:19 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){}

Intern::Intern(const Intern &other)
{
    *this = other;
}

Intern::~Intern(){}

Intern& Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}


Form    *Intern::makeForm(const std::string &formName, const std::string &target) const
{
    Form        *result = NULL;
    t_form      data[] =
    {
        {"presidential pardon", new PresidentialPardonForm(target)}, 
        {"robotomy request", new RobotomyRequestForm(target)}, 
        {"shrubbery creation", new ShrubberyCreationForm(target)}, 
        {"", NULL}
    };
    for (int i = 0; data[i]._form; i++)
    {
        if (data[i]._type == formName)
            result = data[i]._form;
        else
            delete data[i]._form;
    }
    if (!result)
        std::cout << "Intern couldn't find form " << formName << "\n";
    else
        std::cout << "Intern creates " << formName << "\n";
    
    return (result);
}