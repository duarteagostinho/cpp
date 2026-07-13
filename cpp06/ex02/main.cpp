# include "inc/Base.hpp"
# include <cstdlib>
# include <ctime>

int main() {

	std::srand(static_cast<unsigned>( std::time(NULL)));
	Base *ptr = generate();
	identify(ptr);
	identify(*ptr);
	delete ptr;
}
