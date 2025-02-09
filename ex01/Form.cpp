#include "Form.hpp"

Form::Form(const std::string& name, const int& signGrade, const int& executeGrade) : name(name), isSigned(0), signGrade(signGrade), executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& obj) : name(obj.name), isSigned(0), signGrade(obj.signGrade), executeGrade(obj.executeGrade) {}

Form&	Form::operator=(const Form& obj)
{
	// if (this != &obj)
		
	(void) obj;
	return (*this);
}

Form::~Form() {}

const std::string&	Form::getName() const
{
	return (this->name);
}

const bool&			Form::getIsSigned() const
{
	return (this->isSigned);
}

const int&			Form::getSignGrade() const
{
	return (this->signGrade);
}

const int&			Form::getExecuteGrade() const
{
	return (this->executeGrade);
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (this->signGrade < bureaucrat.getGrade())
		throw GradeTooLowException();
	this->isSigned = 1;
}

const char*	Form::GradeTooHighException::what() const throw()//클래스의 클래스의 what함수의 동작 구현
{
	return ("Grade is too high!");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

std::ostream& operator<<(std::ostream& out, const Form& b)
{
	std::string	isSigned;
	
	if (b.getIsSigned())
		isSigned = "signed";
	else
		isSigned = "not signed";
	out << b.getName() << " can be signed by higher than " << b.getSignGrade() << " and executed by higher than " << b.getExecuteGrade() << ", and it is " << isSigned;

	return (out);
}
