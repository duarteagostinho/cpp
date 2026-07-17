#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>

int main() {
	std::cout << "--- vector: find first ---" << std::endl;
	std::vector<int> v;
	v.push_back(10);
	v.push_back(10);
	std::vector<int>::iterator it_v = easyfind(v, 10);
	std::cout << *it_v << " (index " << it_v - v.begin() << ")" << std::endl;

	std::cout << "--- modify via iterator ---" << std::endl;
	*easyfind(v, 10) = 99;
	std::cout << v[0] << " " << v[1] << std::endl;

	std::cout << "--- deque ---" << std::endl;
	std::deque<int> d;
	d.push_back(2);
	d.push_back(3);
	std::deque<int>::iterator it_d = easyfind(d, 3);
	std::cout << *it_d << std::endl;

	std::cout << "--- list ---" << std::endl;
	std::list<int> l;
	l.push_back(42);
	l.push_back(21);
	std::list<int>::iterator it_l = easyfind(l, 21);
	std::cout << *it_l << std::endl;

	std::cout << "--- not found exception ---" << std::endl;
	try {
		easyfind(l, 999);
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "--- empty container exception ---" << std::endl;
	try {
		std::vector<int> empty;
		easyfind(empty, 1);
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "--- last element ---" << std::endl;
	std::vector<int> last;
	last.push_back(1);
	last.push_back(2);
	last.push_back(3);
	std::vector<int>::iterator it_last = easyfind(last, 3);
	std::cout << *it_last << " (index " << it_last - last.begin() << ")" << std::endl;

}
