#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm(target, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) : AForm(obj) {}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
	(void) obj;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!(this->getIsSigned()))
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getExecuteGrade())
		throw AForm::GradeTooLowException();
	
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
