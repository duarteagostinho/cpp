#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap a("Scav1");
	ScavTrap b(a);
	ScavTrap c("Scav2");

	a.attack("enemy");
	a.takeDamage(30);
	a.beRepaired(20);
	a.guardGate();

	c = a;
	c.attack("target");
	c.guardGate();

	return 0;
}
