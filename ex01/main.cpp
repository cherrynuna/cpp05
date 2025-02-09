#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	elsa("Elsa", 7);
		std::cout << elsa << std::endl;

		Bureaucrat	anna("Anna", 9);
		std::cout << anna << std::endl;

		Form	passport("Passport", 8, 9);
		Form	martialLaw1("Martial Law", 0, 7);
		Form	martialLaw2("Martial Law", 1, 7);
		Form	meetingPermit1("Meeting Permit", 151, 7);
		Form	meetingPermit2("Meeting Permit", 150, 7);

		std::cout << passport << std::endl;
		anna.signForm(passport);
		elsa.signForm(passport);
		anna.signForm(passport);
		std::cout << passport << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
