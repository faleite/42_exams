#pragma once
#include <map>
#include "ASpell.hpp"

class SpellBook
{
	private:
		SpellBook(const SpellBook &copyObj);
		SpellBook &operator=(const SpellBook &assignCopy);
		std::map<std::string, ASpell*> _SpellBook;
	public:
		SpellBook();
		~SpellBook();

		void learnSpell(ASpell*);
		void forgetSpell(std::string const &);
		ASpell* createSpell(std::string const &);
};