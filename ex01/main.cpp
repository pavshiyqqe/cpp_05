/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 09:55:51 by yyaniv            #+#    #+#             */
/*   Updated: 2025/11/28 16:30:15 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat	Odin("Odin", 1);
	Bureaucrat	Loki("Loki", 150);

	std::cout << "Just created two bureaucrat gods!" << std::endl;
	std::cout << Odin << std::endl;
	std::cout << Loki << std::endl;

	std::cout << "\nLet's try creating Thor with grade 0" << std::endl;
	/* GradeTooHighException */
	try
	{
		Bureaucrat Thor("Thor", 0);
	}
	catch (std::exception& e)
	{
		std::cout << "Cannot create Thor!" << std::endl;
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "\nLet's try creating John with grade 151" << std::endl;
	/* GradeTooLowException */
	try
	{
		Bureaucrat John("Thor", 151);
	}
	catch (std::exception& e)
	{
		std::cout << "Cannot create John!" << std::endl;
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "\nLet's try promoting Odin!" << std::endl;
	/* Increment throwing exception */
	try
	{
		Odin.inceaseGrade();
	}
	catch (std::exception& e)
	{
		std::cout << "Cannot increment the grade of Odin!" << std::endl;
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "\nLet's try demoting Loki!" << std::endl;
	/* Decrement throwing exception */
	try
	{
		Loki.decreaseGrade();
	}
	catch (std::exception& e)
	{
		std::cout << "Cannot decrement the grade of Loki!" << std::endl;
		std::cout << "Exception: " << e.what() << std::endl;
	}
}
