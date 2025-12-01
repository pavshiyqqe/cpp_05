/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 11:53:47 by yyaniv            #+#    #+#             */
/*   Updated: 2025/12/01 15:58:54 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Form.hpp"

/* Exceptions */

Form::GradeTooHighException::GradeTooHighException(void)
{
	this->m = "The grade is above max value";
}

Form::GradeTooHighException::GradeTooHighException(const char *message) : m(message) {}

const char	*Form::GradeTooHighException::what() const throw()
{
	return (this->m);
}

Form::GradeTooLowException::GradeTooLowException(void)
{
	this->m = "The grade is below the min value";
}

Form::GradeTooLowException::GradeTooLowException(const char *message) : m(message) {}

const char	*Form::GradeTooLowException::what() const throw()
{
	return (this->m);
}

// New Exceptions

Form::InvalidFormException::InvalidFormException()
{
	this->m = "Form CAN'T be executed.";
}

Form::InvalidFormException::InvalidFormException(const char *m) : m(m)
{

}

const char	*Form::InvalidFormException::what() const throw()
{
	return (this->m);
}



/* Constructors and the destructor of the Form */

Form::Form() : _name(), _gradeToSign(1), _gradeToExecute(1), _signed(false)
{
	
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) 
	: _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();

	this->_signed = false;
}

Form::Form(const Form &copy) : _name(copy._name), _gradeToSign(copy._gradeToSign),
_gradeToExecute(copy._gradeToExecute), _signed(copy._signed) {}


Form::~Form()
{

}




/* Public methods */

Form&				Form::operator=(const Form& other)
{
	this->_signed = other._signed;
	return (*this);
}

const std::string&	Form::getName(void) const
{
	return (this->_name);
}

int 				Form::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int 				Form::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

bool				Form::isSigned(void) const
{
	return (this->_signed);
}

void				Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > this->_gradeToSign)
		throw GradeTooLowException("Bureaucrat is not authorized to sign the form!");
	this->_signed = true;
}


void				Form::checkExecutability(const Bureaucrat &exc) const
{
	if (exc.getGrade() > _gradeToExecute)
		throw GradeTooLowException("Bureaucrat CAN'T execute the form.");
	if (!this->_signed)
		throw InvalidFormException("Form's NOT signed to be executed.");
}





std::ostream&	operator<<(std::ostream& out, Form& form)
{
	out << "Form: " << form.getName() << " Signed: " << (form.isSigned() ? "true" : "false");
	out << " GradeToSign: " << form.getGradeToSign();
	out << " GradeToExecute: " << form.getGradeToExecute();

	return (out);
}
