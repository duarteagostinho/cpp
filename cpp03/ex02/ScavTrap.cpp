#include "ScavTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap Default Constructor has been called" << std::endl;
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDmg = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap Constructor has been called" << std::endl;
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDmg = 20;
}

ScavTrap::ScavTrap( const ScavTrap & src ) : ClapTrap(src)
{
	std::cout << "ScavTrap Copy constructor has been called" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor has been called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScavTrap &				ScavTrap::operator=( ScavTrap const & rhs )
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

void	ScavTrap::attack(const std::string &target)
{
	if (this->EnergyPoints < 1)
	{
		std::cout << "Insufficient energy points! " << getEnergyPoints() << " currently available." << std::endl;
		return ;
	}
	if (this->HitPoints < 1)
	{
		std::cout << "Insufficient hit points! " << getHitPoints() << " currently available." << std::endl;
		return ;
	}
	this->EnergyPoints -= 1;
	std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << getAttackDmg() << " points of damage!" << std::endl;
	std::cout << "ScavTrap " << getName() << " has " << getEnergyPoints() << " energy points remaining!" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */