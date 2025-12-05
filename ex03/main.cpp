/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:19:25 by yyaniv            #+#    #+#             */
/*   Updated: 2025/12/05 16:11:30 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main()
{
	Intern	intern;
	Form	*f;

	f = intern.makeForm("shrubbery creation", "28C");
	std::cout << *f << "\n\n";
	delete f;


	f = intern.makeForm("robotomy request", "28B");
	std::cout << *f << "\n\n";
	delete f;

	f = intern.makeForm("presidential pardon", "28A");
	std::cout << *f << "\n\n";
    delete f;
	
    try {
        f = intern.makeForm("undefined", "0U");
        delete f;
    } catch (std::exception &e) {
        std::cout << e.what() << "\n";
    }



	return 0;
}