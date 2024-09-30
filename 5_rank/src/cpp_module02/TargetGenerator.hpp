#pragma once
#include <map>
#include "ATarget.hpp"

class TargetGenerator
{
	private:
		TargetGenerator(const TargetGenerator &copyObj);
		TargetGenerator &operator=(const TargetGenerator &assignCopy);
		std::map<std::string, ATarget*> _target;
	public:
		TargetGenerator();
		~TargetGenerator();

		void learnTargetType(ATarget*);
		void forgetTargetType(std::string const &);
		ATarget* createTarget(std::string const &);
};