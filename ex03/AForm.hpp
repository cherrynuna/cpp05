#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <stdexcept>

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	target;
		bool				isSigned;
		const int			signGrade;
		const int			executeGrade;
	public:
		AForm(const std::string& target, const int& sign, const int& execute);
		AForm(const AForm& obj);
		AForm&	operator=(const AForm& obj);
		virtual ~AForm();

		const std::string&	getTarget() const;
		const bool&			getIsSigned() const;
		const int&			getSignGrade() const;
		const int&			getExecuteGrade() const;

		void	beSigned(const Bureaucrat& bureaucrat);
		virtual void execute(Bureaucrat const & executor) const = 0;

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
		class	FormNotSignedException : public std::exception
		{
			public:
				const char * what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const AForm& b);//<<스트림 출력 연산자를 오버라이드

#endif
