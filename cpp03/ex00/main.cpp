#include "ClapTrap.hpp"

int main()
{
	ClapTrap ct("BOBBY");

	std::cout << ct.getName() << " has " << ct.getHitPoints() << " hit points and " << ct.getEnergyPoints() << " energy points" << std::endl;

	ct.attack("training_dummy");
	ct.attack("target_dummy");

	ct.takeDamage(3);

	for (int i = 0; i < 12; i++)
		ct.beRepaired(1);

	ct.takeDamage(100);
	ct.attack("after_death_dummy");
	ct.beRepaired(1);
	return 0;
}