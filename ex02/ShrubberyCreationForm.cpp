#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm(target, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) {}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!(this->getIsSigned()))
		
	if (executor.getGrade() > this->getExecute())
		throw AForm::GradeTooLowException();
	
	std::ofstream	file((this->getName() + "_shrubbery").c_str());
	if (!file)
	{
		std::cerr << "Error: Failed to create file\n";
		return ;
	}

	file << "";

	file.close();
}
