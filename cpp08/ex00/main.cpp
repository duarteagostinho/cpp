# include "easyfind.hpp"
# include <vector>
# include <deque>
# include <list>

int main() {
	try
	{
		std::vector<int> vect;
		std::vector<int>::iterator it;

		vect.push_back(10);
		vect.push_back(40);
		it = easyfind(vect, 10);
		
		std::cout << "---- std::vector ----\n" << *it << std::endl;

		std::deque<int> deq;
		std::deque<int>::iterator it_dq;

		deq.push_back(2);
		deq.push_back(3);
		it_dq = easyfind(deq, 3);

		std::cout << "---- std::deque ----\n" << *it_dq << std::endl;

		std::list<int> lst;
		std::list<int>::iterator it_lst;

		lst.push_back(567);
		lst.push_back(32645);
		it_lst = easyfind(lst, 1);

		std::cout << "---- std::list ----\n" << *it_lst << std::endl;
	}
	catch(std::exception &e) {
		std::cout << "Exception thrown: " << e.what() << std::endl; 
	}
}
