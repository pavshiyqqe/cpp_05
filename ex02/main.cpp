/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:19:25 by yyaniv            #+#    #+#             */
/*   Updated: 2025/12/05 16:07:34 by yyaniv           ###   ########.fr       */
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


    std::cout << "Attempting to execute an unsigned presidential pardon form\n";
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


    std::cout << "\nSigning and executing a presidential pardon form\n";
    try
    {
        document = new PresidentialPardonForm("B202");
        document->beSigned(Zeus);
        document->execute(Zeus);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << "\n";
    }
    if (document)
    {
        delete document;
        document = NULL;
    }


    std::cout << "\nExecuting a robotomy request form with different bureaucrats\n";
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
        std::cout << "Exception: " << e.what() << "\n";
    }
    if (document)
    {
        delete document;
        document = NULL;
    }


    std::cout << "\nExecuting shrubbery creation form with insufficient clearance\n";
    try
    {
        document = new ShrubberyCreationForm("zxc");
        Zeus.signForm(*document);
        Hera.executeForm(*document);
        Hades.executeForm(*document);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << "\n";
    }
    if (document)
    {
        delete document;
        document = NULL;
    }

    return 0;
}
