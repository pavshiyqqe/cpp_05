/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:35:20 by yyaniv            #+#    #+#             */
/*   Updated: 2025/12/04 15:24:18 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include    "Form.hpp"

class PresidentialPardonForm : public Form 
{
    private:
        const std::string   _target;

        PresidentialPardonForm();

    public:
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(const PresidentialPardonForm &other);
        ~PresidentialPardonForm();
        using Form::operator=;

        const std::string   &getTarget() const;
        void                execute(const Bureaucrat &exec) const;
};