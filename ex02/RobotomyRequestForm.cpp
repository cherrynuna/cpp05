#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : AForm(obj)
{
	*this = obj;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
	if (this != &obj)
		this->target = obj.target;

	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (!(this->getIsSigned()))
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getExecuteGrade())
		throw AForm::GradeTooLowException();

	static bool initialized = false;
	
	if (!initialized)//최초 한 번만 호출
	{
		std::srand(std::time(0));  // 동일한 난수 패턴이지만+매번 다른 시드로 다른 값이 나오게
		initialized = true;
	}

	std::cout << "*drilling noises*" << std::endl;

	if (std::rand() % 2)
		std::cout << this->target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "The robotomy failed on " << this->target << "." << std::endl;
}
