#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm(target, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) : AForm(obj) {}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
	(void) obj;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	std::ofstream	file((this->getTarget() + "_shrubbery").c_str());
	if (!file)
	{
		std::cerr << "Error: Failed to create file\n";
		return ;
	}

	file << "      /\\      " << std::endl;
	file << "     /  \\     " << std::endl;
	file << "    /    \\    " << std::endl;
	file << "   /______\\   " << std::endl;
	file << "     ||||     " << std::endl;
	file << "     ||||     " << std::endl;

	file.close();
}
