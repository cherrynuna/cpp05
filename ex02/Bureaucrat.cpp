#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, const int& grade) : name(name), grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : name(obj.name)
{
	*this = obj;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& obj)
{
	if (this != &obj)
		this->grade = obj.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

const std::string	Bureaucrat::getName() const
{
	return (this->name);
}

int			Bureaucrat::getGrade() const
{
	return (this->grade);
}

void		Bureaucrat::incrementGrade()
{
	if (this->grade <= 1)
		throw GradeTooHighException();
	(this->grade)--;
}

void		Bureaucrat::decrementGrade()
{
	if (this->grade >= 150)
		throw GradeTooLowException();
	(this->grade)++;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()//클래스의 what함수의 동작 구현
{
	return ("Grade is too high!");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return out;
}

void	Bureaucrat::signForm(AForm& form)
{
	if (form.getIsSigned())
		std::cout << this->name << " couldn’t sign the form with the target " << form.getTarget() << " because it's already signed." << std::endl;
	else
	{
		form.beSigned(*this);
		std::cout << this->name << " signed the form with the target " << form.getTarget() << "." << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm& form)
{
	if (!(form.getIsSigned()))
		throw AForm::FormNotSignedException();
	if (this->grade > form.getExecuteGrade())
		throw AForm::GradeTooLowException();
	form.execute(*this);
}