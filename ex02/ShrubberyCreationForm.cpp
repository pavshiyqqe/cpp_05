/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:55:34 by yyaniv            #+#    #+#             */
/*   Updated: 2025/12/05 16:13:22 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137), _target("")
{
    
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : Form("ShrubberyCreationForm", 145, 137), _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : Form("ShrubberyCreationForm", 145, 137), _target(other.getTarget())
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}


const   std::string &ShrubberyCreationForm::getTarget() const
{
    return this->_target;
}




void                ShrubberyCreationForm::execute(const Bureaucrat &exec) const
{
    std::ofstream   file;
    std::string     name;

    this->checkExecutability(exec);
    name = _target + "_shrubbery";
    file.open(name.c_str(), std::ofstream::out);

    file << "           *           \n";
    file << "          ***          \n";
    file << "         *****         \n";
    file << "        *******        \n";
    file << "       *********       \n";
    file << "      ***********      \n";
    file << "     *************     \n";
    file << "    ***************    \n";
    file << "   *****************   \n";
    file << "          |||          \n";
    file << "          |||          \n";
    file << "          |||          \n";
    file << "         -----         \n";
}
