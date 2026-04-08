#include "FragTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap Default Constructor has been called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDmg = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap Constructor has been called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDmg = 30;
}

FragTrap::FragTrap( const FragTrap & src ) : ClapTrap(src)
{
	std::cout << "FragTrap Copy Constructor has been called" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor has been called" << std::endl;

}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

FragTrap &				FragTrap::operator=( FragTrap const & rhs )
{
	if ( this != &rhs )
	{
		ClapTrap::operator=(rhs);
	}
	return (*this);
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	FragTrap::attack(const std::string &target)
{
	if (this->energyPoints < 1)
	{
		std::cout << "Insufficient energy points! " << getEnergyPoints() 
										<< " currently available." << std::endl;
		return ;
	}
	if (this->hitPoints < 1)
	{
		std::cout << "Insufficient hit points! " << getHitPoints()
										<< " currently available." << std::endl;
		return ;
	}
	this->energyPoints -= 1;
	std::cout << "FragTrap " << getName() << " attacks " << target 
		<< ", causing " << getAttackDmg() << " points of damage!" << std::endl;
	std::cout << "FragTrap " << getName() << " has " << getEnergyPoints()
									<< " energy points remaining!" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "Frag high-fives everybody" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
