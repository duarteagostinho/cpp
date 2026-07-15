#include "iter.hpp"

int		arr[] = {1,2,3,4,5};
double	dubz[] = {1.2, 2.1, 42.42, 6.231, 1904.1904};
float	floatz[] = {1.2000f, 239131.f, 0.0f, 1904.00002f, 42424242.424242f};
char	charz[] = {'a', 'b', 'c', 'd', 'e'};
std::string strings[] = {"This", "is", "a", "test", "!!!!"};

int main() {
	Print("----- INT -----");
	iter(arr, arr_size(arr), Print<int>);
	Print("----- DOUBLE -----");
	iter(dubz, arr_size(dubz), Print<double>);
	Print("----- FLOAT -----");
	iter(floatz, arr_size(floatz), Print<float>);
	Print("----- CHAR -----");
	iter(charz, arr_size(charz), Print<char>);
	Print("----- STRING -----");
	iter(strings, arr_size(strings), Print<std::string>);
}
