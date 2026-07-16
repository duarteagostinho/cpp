# include "easyfind.hpp"
#include <vector>

int main() {
	std::vector<int> vect;
	std::vector<int>::iterator it;
	vect.push_back(10);
	vect.push_back(40);
	vect.push_back(60);
	vect.push_back(20);
	it = easyfind(vect, 10);
	std::cout << *it << std::endl;


	/* PRECISO DE LER MAIS E VER VIDEOS SOBRE CONTAINERS E ITERATOR */
}
