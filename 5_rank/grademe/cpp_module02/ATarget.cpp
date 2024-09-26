#include "ATarget.hpp"

ATarget::ATarget(std::string type): _type(type)
{
	
}

ATarget::ATarget(const ATarget &copyObj)
{
	*this = copyObj;
}

ATarget &ATarget::operator=(const ATarget &assignCopy)
{
	_type = assignCopy.getType();
	return (*this);
}

ATarget::~ATarget()
{
	
}

const std::string &ATarget::getType() const
{
	return (_type);
}

void ATarget::getHitBySpell(const ASpell &spell) const
{
	std::cout << _type << " has been " << spell.getEffects() << "!" << std::endl;
}
