/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 20:20:17 by yyaniv            #+#    #+#             */
/*   Updated: 2025/12/01 14:41:30 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << "Creating a form with grade to sign 0\n";
    try
    {
        Form    f("Contract_A1", 0, 50);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << "\n";
    }
    
    std::cout << "\nCreating a form with grade to execute 0\n";
    try
    {
        Form    f("Contract_A2", 75, 0);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << "\n";
    }
    
    std::cout << "\nCreating a form with grade to execute 151\n";
    try
    {
        Form    f("Contract_A3", 25, 151);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << "\n";
    }
    
    std::cout << "\nCreating a form with grade to sign 151\n";
    try
    {
        Form    f("Contract_A4", 151, 100);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << "\n";
    }
    
    std::cout << "\nSigning a form with appropriate bureaucrat\n\n";
    try
    {
        Bureaucrat  Zeus("Zeus", 5);
        Form        f("Contract_B1", 100, 120);
        std::cout << f << "\n";
        Zeus.signForm(f);
        std::cout << f << "\n";
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << "\n";
    }
    std::cout << "\n";
    
    std::cout << "\nSigning a form with inappropriate bureaucrat\n\n";
    try
    {
        Bureaucrat  Hermes("Hermes", 50);
        Form        f("Contract_B2", 10, 20);
        std::cout << f << "\n";
        Hermes.signForm(f);
        std::cout << f << "\n";
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << "\n";
    }
    
    return 0;
}