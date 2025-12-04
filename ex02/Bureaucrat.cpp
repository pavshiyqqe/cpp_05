/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:47:13 by yyaniv            #+#    #+#             */
/*   Updated: 2025/12/04 14:22:18 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char      *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade above max value");
}

const char      *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade below min value");
}


Bureaucrat::Bureaucrat()
{

}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
    
}

Bureaucrat  &Bureaucrat::operator=(const Bureaucrat &other)
{
    this->_grade = other._grade;
    return (*this);
}

const std::string   &Bureaucrat::getName() const
{
    return (this->_name);
}

int                 Bureaucrat::getGrade() const
{
    return (this->_grade);
}

void                Bureaucrat::inceaseGrade()
{
    if (this->_grade == Bureaucrat::_maxGrade)
        throw GradeTooHighException();
    this->_grade--;
}

void                Bureaucrat::decreaseGrade()
{
    if (this->_grade == Bureaucrat::_minGrade)
        throw GradeTooLowException();
    this->_grade++;
}

void                Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << "Bureaucrat " << this->_name << " successfully signed the form " << form.getName() << ".\n";
    }
    catch(const std::exception &e)
    {
        std::cout << *this << "| " << e.what() << "\n";
    }
}


void                Bureaucrat::executeForm(const Form &form)
{
    try
    {
        form.execute(*this);
        std::cout << this->_name << " executes form " << form.getName() << "\n";
    }
    catch (Form::InvalidFormException &exc)
    {
        std::cout << exc.what() << "\n";
    }
}  







std::ostream    &operator<<(std::ostream &out, Bureaucrat &b)
{
    out << b.getName() << ", bureaucrat grade's " << b.getGrade();
    return (out);
}