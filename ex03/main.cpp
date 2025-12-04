/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:19:25 by yyaniv            #+#    #+#             */
/*   Updated: 2025/12/04 15:31:28 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>
#include <iostream>

int main()
{
    Bureaucrat Zeus("Zeus", 1);
    Bureaucrat Hera("Hera", 40);
    Bureaucrat Hades("Hades", 150);
    Form* document = NULL;

    srand(time(NULL));

    // Attempting to execute an unsigned presidential pardon form
    std::cout << "Attempting to execute an unsigned presidential pardon form" << std::endl;
    try
    {
        document = new PresidentialPardonForm("A101");
        document->execute(Zeus);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    if (document)
    {
        delete document;
        document = NULL;
    }

    // Signing and executing a presidential pardon form
    std::cout << "\nSigning and executing a presidential pardon form" << std::endl;
    try
    {
        document = new PresidentialPardonForm("B202");
        document->beSigned(Zeus);
        document->execute(Zeus);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    if (document)
    {
        delete document;
        document = NULL;
    }

    //  Executing a robotomy request form with different bureaucrats ===
    std::cout << "\nExecuting a robotomy request form with different bureaucrats" << std::endl;
    try
    {
        document = new RobotomyRequestForm("C303");
        Zeus.signForm(*document);
        std::cout << std::endl;
        Hera.executeForm(*document);
        Hera.executeForm(*document);
        Hera.executeForm(*document);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    if (document)
    {
        delete document;
        document = NULL;
    }

    // Executing shrubbery creation form with insufficient clearance 
    std::cout << "\nExecuting shrubbery creation form with insufficient clearance" << std::endl;
    try
    {
        document = new ShrubberyCreationForm("zxc");
        Zeus.signForm(*document);
        Hera.executeForm(*document);
        Hades.executeForm(*document);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    if (document)
    {
        delete document;
        document = NULL;
    }

    return 0;
}
