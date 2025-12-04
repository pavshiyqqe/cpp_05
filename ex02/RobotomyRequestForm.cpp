/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:46:37 by yyaniv            #+#    #+#             */
/*   Updated: 2025/12/04 14:33:49 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45), _target("")
{

}


RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : Form("RobotomyRequestForm", 72, 45), _target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : Form("RobotomyRequestForm", 72, 45), _target(other.getTarget())
{

}


RobotomyRequestForm::~RobotomyRequestForm()
{

}


const   std::string &RobotomyRequestForm::getTarget() const
{
    return this->_target;
}



void                RobotomyRequestForm::execute(const Bureaucrat &exec) const
{
    this->checkExecutability(exec);

    std::cout << "* Unbearable drilling noises *\n";
    if (rand() % 2)
    {
        std::cout << "The victim... " << this->_target << " has been successfully robotomized!\n";
    }
    else
    {
        std::cout << "The robotomization on " << this->_target << " failed!\n";
    }
}