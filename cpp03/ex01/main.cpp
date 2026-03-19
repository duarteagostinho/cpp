#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap cT("Clappy");
	ScavTrap sT("Scav");

	cT.attack("training dummy");
	sT.attack("training dummy");
	sT.guardGate();
	return 0;
}
