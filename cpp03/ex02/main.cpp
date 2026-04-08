# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

int main()
{
	FragTrap a("Frag1");
	FragTrap b(a);
	ScavTrap c("Scav1");

	a.attack("enemy");
	a.takeDamage(40);
	a.beRepaired(20);
	a.highFivesGuys();

	c.attack("target");
	c.guardGate();

	FragTrap d("Frag2");
	d = a;
	d.attack("monster");
	d.highFivesGuys();

	return 0;
}
