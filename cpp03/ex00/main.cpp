#include "ClapTrap.hpp"

int main()
{
	ClapTrap ct("BOBBY");

	// Initial state
	std::cout << ct.getName() << " has " << ct.getHitPoints() << " hit points and "
		<< ct.getEnergyPoints() << " energy points" << std::endl;

	// Attacks using energy points
	ct.attack("training_dummy");
	ct.attack("target_dummy");

	// Take some damage
	ct.takeDamage(3);

	// Repair until energy runs out (more than 10 times)
	for (int i = 0; i < 12; i++)
		ct.beRepaired(1);

	// Make ClapTrap reach 0 hit points, then try actions
	ct.takeDamage(100);
	ct.attack("after_death_dummy");
	ct.beRepaired(1);
	return 0;
}