/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 10:49:28 by yyaniv            #+#    #+#             */
/*   Updated: 2025/11/30 10:49:28 by yyaniv           ###   ########.fr       */
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
        
};