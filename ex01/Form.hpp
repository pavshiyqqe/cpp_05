/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 10:49:28 by yyaniv            #+#    #+#             */
/*   Updated: 2025/12/01 14:43:31 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
    private:
        static const int    _maxGrade = 1;
        static const int    _minGrade = 150;

        const std::string   _name;
        
        const int           _gradeToSign;
        const int           _gradeToExecute;
        bool                _signed;

        Form();
    
    public:
        Form(const std::string &_name, int _gradetoSign, int _gradeToExecute);
        Form(const Form &other);
        ~Form();
        Form    &operator=(const Form &other);

        const std::string   &getName() const;
        int                 getGradeToSign() const;
        int                 getGradeToExecute() const;
        bool                isSigned() const;
        void				beSigned(const Bureaucrat& b);

    private:
        class GradeTooHighException : public std::exception
        {
            private:
                const char *m;
            
            public:
                GradeTooHighException();
                GradeTooHighException(const char *m);
                const char  *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            private:
                const char *m;
            
            public:
                GradeTooLowException();
                GradeTooLowException(const char *m);
                const char  *what() const throw();
        };
};

std::ostream    &operator<<(std::ostream &out, Form &form);