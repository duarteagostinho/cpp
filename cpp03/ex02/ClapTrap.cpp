#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap Default constructor has been called" << std::endl;
	this->Name = "Default";
	this->EnergyPoints = 10;
	this->HitPoints = 10;
	this->AttackDmg = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap Constructor has been called" << std::endl;
	this->Name = name;
	this->EnergyPoints = 10;
	this->HitPoints = 10;
	this->AttackDmg = 0;
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
		this->Name = rhs.Name;
		this->HitPoints = rhs.HitPoints;
		this->EnergyPoints = rhs.EnergyPoints;
		this->AttackDmg = rhs.AttackDmg;
	}
	return (*this);
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	ClapTrap::attack(const std::string &target)
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
	std::cout << "ClapTrap " << getName() << " attacks " << target << ", causing " << getAttackDmg() << " points of damage!" << std::endl;
	std::cout << "ClapTrap " << getName() << " has " << getEnergyPoints() << " energy points remaining!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->HitPoints -= amount;
	if (this->HitPoints < 1)
		this->HitPoints = 0;
	std::cout << getName() << " takes " << amount << " points of damage!" << std::endl;
	std::cout << getName() << " has " << getHitPoints() << " hit points remaining!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
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
	this->EnergyPoints -=1;
	this->HitPoints += amount;
	std::cout << getName() << " regains " << amount << " hit points!" << std::endl;
	std::cout << getName() << " has " << getHitPoints() << " hit points remaining!" << std::endl;
	std::cout << getName() << " has " << getEnergyPoints() << " energy points remaining!" << std::endl;
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	ClapTrap::getName(void)
{
	return (this->Name);
}

int	ClapTrap::getHitPoints(void)
{
	return (this->HitPoints);
}

int	ClapTrap::getEnergyPoints(void)
{
	return (this->EnergyPoints);
}

int	ClapTrap::getAttackDmg(void)
{
	return (this->AttackDmg);
}

/* ************************************************************************** */