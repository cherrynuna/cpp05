#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

// void	f()
// {
// 	system("leaks a.out");
// }


int	main(void)
{
	// atexit(f);
	AForm*	form = NULL;
	try
	{
		Bureaucrat	elsa("Elsa", 25);
		Bureaucrat	anna("Anna", 146);
		Bureaucrat	olaf("Olaf", 5);

		Intern		intern;

		form = intern.makeForm("ShrubberyCreation", "gaepo");
		if (!form)
			return (0);
		elsa.signForm(*form);
		olaf.executeForm(*form);
		delete form;

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;

		form = intern.makeForm("RobotomyRequest", "chris");
		if (!form)
			return (0);
		anna.signForm(*form);
		elsa.signForm(*form);
		olaf.executeForm(*form);
		delete form;

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;

		form = intern.makeForm("PresidentialPardon", "inryu");
		if (!form)
			return (0);
		elsa.signForm(*form);
		olaf.executeForm(*form);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	if (form)
		delete form;
	return 0;
}
