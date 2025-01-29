#include "Form.hpp"

AForm::AForm(const std::string& name, const int& sign, const int& execute) : name(name), isSigned(0), sign(sign), execute(execute)
{
	if (sign < 1 || execute < 1)
		throw GradeTooHighException();
	if (sign > 150 || execute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& obj) : name(obj.name), isSigned(0), sign(obj.sign), execute(obj.execute) {}

AForm&	AForm::operator=(const AForm& obj)
{
	// if (this != &obj)
		
	(void) obj;
	return (*this);
}

AForm::~AForm() {}

const std::string&	AForm::getName() const
{
	return (this->name);
}

const bool&			AForm::getIsSigned() const
{
	return (this->isSigned);
}

const int&			AForm::getSign() const
{
	return (this->sign);
}

const int&			AForm::getExecute() const
{
	return (this->execute);
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (this->sign < bureaucrat.getGrade())
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

std::ostream& operator<<(std::ostream& out, const AForm& b)
{
	std::string	isSigned;
	
	if (b.getIsSigned())
		isSigned = "signed";
	else
		isSigned = "not signed";
	out << b.getName() << " can be singed by higher than " << b.getSign() << " and executed by higher than " << b.getExecute() << ", and it is " << isSigned;

	return (out);
}
