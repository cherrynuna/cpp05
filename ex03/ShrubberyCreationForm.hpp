#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	target;
	public:
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& obj);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& obj);
		~ShrubberyCreationForm();

		void	execute(const Bureaucrat& executor) const;
};

#endif
