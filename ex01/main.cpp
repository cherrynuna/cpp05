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

		AForm	passport("Passport", 8, 9);
		AForm	martialLaw("Martial Law", 0, 7);
		AForm	meetingPermit("Meeting Permit", 151, 7);

		std::cout << passport << std::endl;
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
