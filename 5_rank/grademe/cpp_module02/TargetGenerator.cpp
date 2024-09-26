#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{

}

TargetGenerator::TargetGenerator(const TargetGenerator &copyObj)
{
	*this = copyObj;
}

TargetGenerator &TargetGenerator::operator=(const TargetGenerator &assignCopy)
{
	_target = assignCopy._target;
	return (*this);
}

TargetGenerator::~TargetGenerator()
{
	
}

void TargetGenerator::learnTargetType(ATarget* target)
{
	if (target)
		_target[target->getType()] = target;
}

void TargetGenerator::forgetTargetType(std::string const &target)
{
	if (_target.find(target) != _target.end())
		_target.erase(_target.find(target));
}

ATarget* TargetGenerator::createTarget(std::string const &target)
{
	ATarget *tmp = NULL;
	if (_target.find(target) != _target.end())
		tmp = _target[target];
	return (tmp);
}
