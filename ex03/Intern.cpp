#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& obj)
{
	*this = obj;
}

Intern&	Intern::operator=(const Intern& obj)
{
	(void) obj;
	return (*this);
}

Intern::~Intern() {}

AForm*	Intern::makeForm(const std::string& name, const std::string target)
{
	std::string	forms[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	AForm*	meta;

	int	i;
	for (i = 0; i < 3; i++)
	{
		if (forms[i] == name)
			break;
	}

	switch (i)
	{
		case 0:
			meta = new ShrubberyCreationForm(target);
			break;
		case 1:
			meta = new RobotomyRequestForm(target);
			break;
		case 2:
			meta = new PresidentialPardonForm(target);
			break;
		default:
			std::cout << "Invalid form name\n";
			return (NULL);
	}

	std::cout << "Intern creates " << name << std::endl;
	return (meta);
}
