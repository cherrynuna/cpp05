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
		std::cout << std::endl;

		anna.signForm(scf);
		std::cout << scf << std::endl;
		elsa.signForm(scf);
		std::cout << scf << std::endl;
		anna.signForm(scf);

		scf.execute(olaf);

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;

		RobotomyRequestForm	rrf("chris");
		anna.signForm(rrf);
		elsa.signForm(rrf);

		rrf.execute(olaf);

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;

		PresidentialPardonForm	ppf("inryu");
		anna.signForm(ppf);
		elsa.signForm(ppf);

		ppf.execute(elsa);
		ppf.execute(olaf);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
