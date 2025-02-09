#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdexcept>

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			signGrade;
		const int			executeGrade;

		class	GradeTooHighException : public std::exception
		{
			public:
				const char*	what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				const char*	what() const throw();
		};
	public:
		Form(const std::string& name, const int& sign, const int& execute);
		Form(const Form& obj);
		Form&	operator=(const Form& obj);
		~Form();

		const std::string&	getName() const;
		const bool&			getIsSigned() const;
		const int&			getSignGrade() const;
		const int&			getExecuteGrade() const;

		void	beSigned(const Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& out, const Form& b);//<<스트림 출력 연산자를 오버라이드


#endif
