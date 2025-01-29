#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <stdexcept>

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			sign;
		const int			execute;

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
		AForm(const std::string& name, const int& sign, const int& execute);
		AForm(const AForm& obj);
		AForm&	operator=(const AForm& obj);
		~AForm();

		const std::string&	getName() const;
		const bool&			getIsSigned() const;
		const int&			getSign() const;
		const int&			getExecute() const;

		void	beSigned(const Bureaucrat& bureaucrat);
		virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream& operator<<(std::ostream& out, const AForm& b);//<<스트림 출력 연산자를 오버라이드


#endif
