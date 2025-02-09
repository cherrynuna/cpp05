#include "AForm.hpp"

AForm::AForm(const std::string& name, const int& sign, const int& execute) : target(name), isSigned(0), signGrade(sign), executeGrade(execute)
{
	if (sign < 1 || execute < 1)
		throw GradeTooHighException();
	if (sign > 150 || execute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& obj) : target(obj.target), isSigned(0), signGrade(obj.signGrade), executeGrade(obj.executeGrade) {}

AForm&	AForm::operator=(const AForm& obj)
{
	// if (this != &obj)
		
	(void) obj;
	return (*this);
}

AForm::~AForm() {}

const std::string&	AForm::getTarget() const
{
	return (this->target);
}

const bool&			AForm::getIsSigned() const
{
	return (this->isSigned);
}

const int&			AForm::getSignGrade() const
{
	return (this->signGrade);
}

const int&			AForm::getExecuteGrade() const
{
	return (this->executeGrade);
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (this->signGrade < bureaucrat.getGrade())
		throw GradeTooLowException();
	this->isSigned = 1;
}

const char*	AForm::GradeTooHighException::what() const throw()//클래스의 클래스의 what함수의 동작 구현
{
	return ("Grade is too high!");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

const char * AForm::FormNotSignedException::what() const throw()
{
	return ("This form is not signed yet!");
}

std::ostream& operator<<(std::ostream& out, const AForm& b)
{
	std::string	isSigned;
	
	if (b.getIsSigned())
		isSigned = "signed";
	else
		isSigned = "not signed";
	out << "A form with the target " << b.getTarget() << " can be signed by grades ≥ " << b.getSignGrade() << " and executed by higher than " << b.getExecuteGrade() << ", and it is " << isSigned;

	return (out);
}
