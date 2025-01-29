#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;//grade 1 is the highest one and 150 the lowest

		class	GradeTooHighException : public std::exception//상속
		{
			public:
				const char* what() const throw();//예외 발생 시 메메시지를 반환하는 표준함수...오버라이드
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
	public:
		Bureaucrat(const std::string& name, const int& grade);
		Bureaucrat(const Bureaucrat& obj);
		Bureaucrat&	operator=(const Bureaucrat& obj);
		~Bureaucrat();

		const std::string	getName() const;
		int			getGrade() const;

		void	incrementGrade();
		void	decrementGrade();
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);//<<스트림 출력 연산자를 오버라이드

#endif
