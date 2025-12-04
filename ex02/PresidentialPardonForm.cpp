/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 23:31:08 by yyaniv            #+#    #+#             */
/*   Updated: 2025/12/04 14:32:16 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5), _target("")
{

}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : Form("PresidentialPardonForm", 25, 5), _target (target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): Form("PresidentialPardonForm", 25, 5), _target(other.getTarget())
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{

}


const std::string       &PresidentialPardonForm::getTarget() const
{
    return (this->_target);
}

void                    PresidentialPardonForm::execute(const Bureaucrat &exec) const
{
    this->checkExecutability(exec);
    std::cout << this->_target << " has been pardoned by Zafod Beeblebrox.\n";
}