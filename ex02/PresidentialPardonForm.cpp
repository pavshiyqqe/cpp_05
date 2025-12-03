/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentalPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 23:31:08 by yyaniv            #+#    #+#             */
/*   Updated: 2025/12/03 23:31:08 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5), target("")
{

}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : Form("PresidentialPardonForm", 25, 5), target (target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): Form("PresidentialPardonForm", 25, 5), targer(other.getTarget())
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{

}


const std::string       &PresidentialPardonForm::getTarger() const
{
    return (this->target);
}

void                    PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    this->checkExecutability(executor);
    std::cout << this->target << " has been pardoned by Zafod Beeblebrox.\n";
}