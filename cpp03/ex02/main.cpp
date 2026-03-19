# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

int main()
{
	ClapTrap cT("Clappy");
	ScavTrap sT("Scav");
	FragTrap fT("Frag");

	fT.attack("training dummy");
	cT.attack("training dummy");
	sT.attack("training dummy");
	sT.guardGate();
	fT.highFivesGuys();
	return 0;
}
