#include "Warlock.hpp"

Warlock::Warlock(const std::string &name, const std::string &title) : _name(name), _title(title)
{
	std::cout << name << ": This looks like another boring day." << std::endl;
}
Warlock::~Warlock() {
	std::cout << _name << ": My job here is done!" << std::endl;
}
std::string Warlock::getName() const {
	return _name;
}
std::string Warlock::getTitle() const {
	return _title;
}
void Warlock::setTitle(const std::string &newTitle) {
	_title = newTitle;
}
void Warlock::introduce() const {
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}