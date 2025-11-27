/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:46:49 by yyaniv            #+#    #+#             */
/*   Updated: 2025/11/27 14:28:52 by yyaniv           ###   ########.fr       */
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
        
};