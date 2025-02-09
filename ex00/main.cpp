#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	elsa("Elsa", 1);
		elsa.decrementGrade();
		elsa.incrementGrade();
		std::cout << elsa << std::endl;
		Bureaucrat	anna("Anna", 150);
		anna.decrementGrade();
		anna.incrementGrade();
		std::cout << anna << std::endl;
		Bureaucrat	chris("Chris", 151);
		std::cout << chris << std::endl;
		Bureaucrat	olaf("Olaf", 0);
		std::cout << olaf << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
