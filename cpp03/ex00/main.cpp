#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("Bob");
	ClapTrap b("Alice");

	a.attack("target");
	b.takeDamage(5);
	b.beRepaired(3);

	ClapTrap c(a);
	c.attack("enemy");

	ClapTrap d("Dave");
	d = b;
	d.attack("monster");

	for (int i = 0; i < 11; i++)
		a.attack("dummy");

	a.takeDamage(100);
	a.attack("ghost");

	return 0;
}