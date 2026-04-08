#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap Default constructor has been called" << std::endl;
	this->name = "Default";
	this->energyPoints = 10;
	this->hitPoints = 10;
	this->attackDmg = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap Constructor has been called" << std::endl;
	this->name = name;
	this->energyPoints = 10;
	this->hitPoints = 10;
	this->attackDmg = 0;
}

ClapTrap::ClapTrap( const ClapTrap & src )
{
	std::cout << "ClapTrap Copy constructor has been called" << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor has been called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap &	ClapTrap::operator=( ClapTrap const & rhs )
{
	std::cout << "ClapTrap Copy assignment operator has been called" << std::endl;
	if ( this != &rhs )
	{
		this->name = rhs.name;
		this->hitPoints = rhs.hitPoints;
		this->energyPoints = rhs.energyPoints;
		this->attackDmg = rhs.attackDmg;
	}
	return (*this);
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	ClapTrap::attack(const std::string &target)
{
	if (this->energyPoints < 1)
	{
		std::cout << "Insufficient energy points! " << getEnergyPoints() << " currently available." << std::endl;
		return ;
	}
	if (this->hitPoints < 1)
	{
		std::cout << "Insufficient hit points! " << getHitPoints() << " currently available." << std::endl;
		return ;
	}
	this->energyPoints -= 1;
	std::cout << "ClapTrap " << getName() << " attacks " << target << ", causing " << getAttackDmg() << " points of damage!" << std::endl;
	std::cout << "ClapTrap " << getName() << " has " << getEnergyPoints() << " energy points remaining!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= this->hitPoints)
		this->hitPoints = 0;
	else
		this->hitPoints -= amount;
	std::cout << getName() << " takes " << amount << " points of damage!" << std::endl;
	std::cout << getName() << " has " << getHitPoints() << " hit points remaining!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints < 1)
	{
		std::cout << "Insufficient energy points! " << getEnergyPoints() << " currently available." << std::endl;
		return ;
	}
	if (this->hitPoints < 1)
	{
		std::cout << "Insufficient hit points! " << getHitPoints() << " currently available." << std::endl;
		return ;
	}
	this->energyPoints -=1;
	this->hitPoints += amount;
	std::cout << getName() << " regains " << amount << " hit points!" << std::endl;
	std::cout << getName() << " has " << getHitPoints() << " hit points remaining!" << std::endl;
	std::cout << getName() << " has " << getEnergyPoints() << " energy points remaining!" << std::endl;
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	ClapTrap::getName(void)
{
	return (this->name);
}

unsigned int	ClapTrap::getHitPoints(void)
{
	return (this->hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints(void)
{
	return (this->energyPoints);
}

unsigned int	ClapTrap::getAttackDmg(void)
{
	return (this->attackDmg);
}

/* ************************************************************************** */