/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:46:49 by yyaniv            #+#    #+#             */
/*   Updated: 2025/11/28 16:38:01 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"
#include <stdexcept>
#include <iostream>
#include <string>

class Bureaucrat 
{
    private:
        static const int    _maxGrade = 1;
        static const int    _minGrade = 150;
        const std::string   _name;
        int                 _grade;
        Bureaucrat();
    
    public:
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &other);
        ~Bureaucrat();

        Bureaucrat          &operator=(const Bureaucrat &other);
        const std::string   &getName() const;
        int                 getGrade() const;
        void                inceaseGrade();
        void                decreaseGrade();
        void                signForm(Form &form);
    
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