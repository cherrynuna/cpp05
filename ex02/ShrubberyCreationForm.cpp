#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreation", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) : AForm(obj)
{
	*this = obj;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
	if (this != &obj)
		this->target = obj.target;

	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (!(this->getIsSigned()))
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getExecuteGrade())
		throw AForm::GradeTooLowException();

	std::ofstream	file((this->target + "_shrubbery").c_str());
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
