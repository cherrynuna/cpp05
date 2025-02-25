#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	elsa("Elsa", 25);
		std::cout << elsa << std::endl;

		Bureaucrat	anna("Anna", 146);
		std::cout << anna << std::endl;

		Bureaucrat	olaf("Olaf", 5);
		std::cout << olaf << std::endl;

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;

		ShrubberyCreationForm	scf("gaepo");
		std::cout << scf << std::endl;
		anna.signForm(scf);//->beSigned->Form::GradeTooLowException
		std::cout << scf << std::endl;
		elsa.signForm(scf);
		std::cout << scf << std::endl;
		anna.signForm(scf);//already signed
		olaf.executeForm(scf);

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;

		RobotomyRequestForm	rrf("chris");
		anna.signForm(rrf);
		elsa.signForm(rrf);
		olaf.executeForm(rrf);

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;

		PresidentialPardonForm	ppf("inryu");
		anna.signForm(ppf);
		elsa.signForm(ppf);

		elsa.executeForm(ppf);
		olaf.executeForm(ppf);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
