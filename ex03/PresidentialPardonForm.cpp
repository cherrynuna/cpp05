#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardon", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) : AForm(obj)
{
	*this = obj;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& obj)
{
	if (this != &obj)
		this->target = obj.target;

	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (!(this->getIsSigned()))
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getExecuteGrade())
		throw AForm::GradeTooLowException();

	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
