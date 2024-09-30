#include "Warlock.hpp"

Warlock::Warlock() {}

Warlock::Warlock(const std::string &name, const std::string &title): _name(name), _title(title)
{
	std::cout << _name << ": This looks like another boring day." << std::endl;
}
Warlock::Warlock(const Warlock &copyObj)
{
	*this = copyObj;
}

Warlock &Warlock::operator=(const Warlock &assignCopy)
{
	_name = assignCopy._name;
	_title = assignCopy._title;
	return (*this);
}

Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!" << std::endl;
}

const std::string &Warlock::getName() const
{
	return (_name);
}

const std::string &Warlock::getTitle() const
{
	return (_title);
}

void Warlock::setTitle(const std::string &str)
{
	_title = str;
}

void Warlock::introduce() const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}
