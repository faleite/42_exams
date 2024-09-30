#pragma once
#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
	private:
		std::string _type;
	public:
		ATarget(std::string type);
		ATarget(const ATarget &copyObj);
		ATarget &operator=(const ATarget &assignCopy);
		virtual ~ATarget();

		const std::string &getType() const;
		virtual ATarget *clone() const = 0;
		void getHitBySpell(const ASpell &spell) const;
};