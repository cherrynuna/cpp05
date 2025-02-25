#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm(target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : AForm(obj) {}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
	(void) obj;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	(void) executor;
	static bool initialized = false;
	if (!initialized)//프로그램 시작 시 한 번만 호출
	{
		std::srand(std::time(0));  // 동일한 난수 패턴이지만+매번 다른 시드로 다른 값이 나오게
		initialized = true;
	}

	std::cout << "*drilling noises*" << std::endl;

	if (std::rand() % 2)
		std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
	else
		std::cout << "The robotomy failed on " << this->getTarget() << "." << std::endl;
}
