#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ASpell.hpp"
#include "SpellBook.hpp"

class Warlock
{
	private:
		std::string _name;
		std::string _title;
		Warlock();
		Warlock(const Warlock &copyObj);
		Warlock &operator=(const Warlock &assignCopy);
		SpellBook _SpellBook;
	public:
		Warlock(const std::string &name, const std::string &title);
		~Warlock();

		const std::string &getName() const;
		const std::string &getTitle() const;
		void setTitle(const std::string &str);
		void introduce() const;

		void learnSpell(ASpell *spell);
		void forgetSpell(std::string SpellName);
		void launchSpell(std::string SpellName, const ATarget &target);
};