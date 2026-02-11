#include "Contact.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Contact::Contact()
{
	Name = "";
	Surname = "";
	Nickname = "";
	Secret = "";
	Number = "";
}

/*
** ------------------------------- DESTRUCTOR --------------------------------
*/

Contact::~Contact() {}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	Contact::set_name(std::string name){
	Name = name;
}
void	Contact::set_surname(std::string surname){
	Surname = surname;	
}
void	Contact::set_nick(std::string nick){
	Nickname = nick;
}
void	Contact::set_secret(std::string secret){
	Secret = secret;
}
void	Contact::set_nbr(std::string nbr){
	Number = nbr;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	Contact::get_name(){
	return Name;
}
std::string	Contact::get_surname(){
	return Surname;	
}
std::string	Contact::get_nick(){
	return Nickname;
}
std::string	Contact::get_secret(){
	return Secret;
}
std::string	Contact::get_nbr(){
	return Number;
}

/* ************************************************************************** */