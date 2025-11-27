/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:46:49 by yyaniv            #+#    #+#             */
/*   Updated: 2025/11/27 15:01:16 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat 
{
    private:
        static const int    maxGrade = 150;
        static const int    minGrade = 1;
        const std::string   name;
        int                 grade;
        Bureaucrat();
    
    public:
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &other);
        ~Bureaucrat();

        Bureaucrat  &operator=(const Bureaucrat &other);
        const std::string   &getName() const;
        int                 getgrade() const;
        void                inceaseGrade();
        void                decreaseGrade();
    
    private:
        class GradeTooHighException : public std::exception
        {
            public:
                const char  *what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char  *what() const throw();
        };
};

std::ostream    &operator<<(std::ostream &out, Bureaucrat &b);