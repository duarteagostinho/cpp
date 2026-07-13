#ifndef BASE_HPP
# define BASE_HPP

class Base {

	protected:
		Base();
    public:
		virtual ~Base() = 0;
};
Base*	generate(void);
void	identify(Base *ptr);
void	identify(Base &ref);
#endif
