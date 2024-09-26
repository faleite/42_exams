## EXAM C++02

### Index
1. [main.cpp](#maincpp)
2. [Warlock.hpp](#warlockhpp)
3. [Warlock.cpp](#warlockcpp)
4. [ASpell.hpp](#aspellhpp)
5. [ASpell.cpp](#aspellcpp)
6. [ATarget.hpp](#atargethpp)
7. [ATarget.cpp](#atargetcpp)
8. [Fwoosh.hpp](#fwooshhpp)
9. [Fwoosh.cpp](#fwooshcpp)
10. [Dummy.hpp](#dummyhpp)
11. [Dummy.cpp](#dummycpp)
12. [Fireball.hpp](#fireballhpp)
13. [Fireball.cpp](#fireballcpp)
14. [Polymorph.hpp](#polymorphhpp)
15. [Polymorph.cpp](#polymorphcpp)
16. [BrickWall.hpp](#brickwallhpp)
17. [BrickWall.cpp](#brickwallcpp)
18. [SpellBook.hpp](#spellbookhpp)
19. [SpellBook.cpp](#spellbookcpp)
20. [TargetGenerator.hpp](#targetgeneratorhpp)
21. [TargetGenerator.cpp](#targetgeneratorcpp)
22. [subject](#subject)

### main.cpp
```cpp
#include "Warlock.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"
#include "BrickWall.hpp"
#include "Fireball.hpp"
#include "Polymorph.hpp"
#include "SpellBook.hpp"
#include "TargetGenerator.hpp"


int main()
{
  Warlock richard("Richard", "foo");
  richard.setTitle("Hello, I'm Richard the Warlock!");
  BrickWall model1;

  Polymorph* polymorph = new Polymorph();
  TargetGenerator tarGen;

  tarGen.learnTargetType(&model1);
  richard.learnSpell(polymorph);

  Fireball* fireball = new Fireball();

  richard.learnSpell(fireball);

  ATarget* wall = tarGen.createTarget("Inconspicuous Red-brick Wall");

  richard.introduce();
  richard.launchSpell("Polymorph", *wall);
  richard.launchSpell("Fireball", *wall);
}
```
[***index***](#index)

### Warlock.hpp
```cpp

#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock {

	private :
		std::string _name;
		std::string _title;
		SpellBook _SpellBook;
		Warlock & operator=(Warlock const & rhs);
		Warlock(Warlock const & obj);
		Warlock();

	public :
		Warlock(std::string const &name, std::string const &title);
		~Warlock();
		std::string const & getName() const;
		std::string const & getTitle() const;
		void	setTitle(std::string const & str);
		void	introduce() const;
		void learnSpell(ASpell* spell);
		void forgetSpell(std::string SpellName);
		void launchSpell(std::string SpellName, ATarget const & target);
};
```
[***index***](#index)

### Warlock.cpp
```cpp
#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title) : _name(name), _title(title)
{
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::Warlock()
{
}

Warlock & Warlock::operator=(Warlock const & rhs)
{
	this->_name = rhs._name;
	this->_title = rhs._title;
	return *this;
}

Warlock::Warlock(Warlock const & obj)
{
	*this = obj;
}

Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!" << std::endl;
}

std::string const & Warlock::getName() const
{
	return (_name);
}

std::string const & Warlock::getTitle() const
{
	return (_title);
}

void	Warlock::setTitle(std::string const & str)
{
	_title = str;
}

void	Warlock::introduce() const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell* spell)
{
	_SpellBook.learnSpell(spell);
}

void Warlock::forgetSpell(std::string SpellName)
{
	_SpellBook.forgetSpell(SpellName);
}

void Warlock::launchSpell(std::string SpellName, ATarget const & target)
{
	if (_SpellBook.createSpell(SpellName))
		_SpellBook.createSpell(SpellName)->launch(target);
}
```
[***index***](#index)

### ASpell.hpp
```cpp
#pragma once
#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell 
{
	protected :
		std::string _name;
		std::string _effects;
	
	public :
		ASpell(std::string name, std::string effects);
		ASpell & operator=(ASpell const & rhs);
		ASpell(ASpell const & obj);
		virtual ~ASpell();
		std::string getName() const;
		std::string getEffects() const;
		virtual ASpell* clone() const = 0;
		void launch(ATarget const & target) const;
};
```
[***index***](#index)

### ASpell.cpp
```cpp
#include "ASpell.hpp"

ASpell::ASpell(std::string name, std::string effects) : _name(name), _effects(effects)
{

}

ASpell & ASpell::operator=(ASpell const & rhs)
{
	_name = rhs.getName();
	_effects = rhs.getEffects();
	return *this;
}

ASpell::ASpell(ASpell const & obj)
{
	*this = obj;
}

ASpell::~ASpell()
{

}

std::string ASpell::getName() const
{
	return (_name);
}

std::string ASpell::getEffects() const
{
	return (_effects);
}

void ASpell::launch(ATarget const & target) const
{
	target.getHitBySpell(*this);
}
```
[***index***](#index)

### ATarget.hpp
```cpp

#pragma once
#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget 
{
	protected :
		std::string _type;
	
	public :
		ATarget(std::string type);
		ATarget & operator=(ATarget const & rhs);
		ATarget(ATarget const & obj);
		virtual ~ATarget();
		std::string getType() const;
		virtual ATarget* clone() const = 0;
		void	getHitBySpell(ASpell const & spell) const;
};
```
[***index***](#index)

### ATarget.cpp
```cpp

#include "ATarget.hpp"

ATarget::ATarget(std::string type) : _type(type)
{

}

ATarget & ATarget::operator=(ATarget const & rhs)
{
	_type = rhs.getType();
	return *this;
}

ATarget::ATarget(ATarget const & obj)
{
	*this = obj;
}

ATarget::~ATarget()
{

}

std::string ATarget::getType() const
{
	return (_type);
}

void	ATarget::getHitBySpell(ASpell const & spell) const
{
	std::cout << _type << " has been " << spell.getEffects() << "!" << std::endl;
}
```
[***index***](#index)

### Fwoosh.hpp
```cpp

#pragma once
#include "ASpell.hpp"

class Fwoosh : public ASpell
{
	public :
		Fwoosh();
		~Fwoosh();
		ASpell* clone() const;
};
```
[***index***](#index)

### Fwoosh.cpp
```cpp

#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed")
{

}

Fwoosh::~Fwoosh()
{}

ASpell* Fwoosh::clone() const
{
	return (new Fwoosh());
}
```
[***index***](#index)

### Dummy.hpp
```cpp

#pragma once
#include "ATarget.hpp"

class Dummy : public ATarget
{
	public :
		Dummy();
		~Dummy();
		ATarget* clone() const;
};
```
[***index***](#index)

### Dummy.cpp
```cpp

#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy")
{
}

Dummy::~Dummy()
{}

ATarget* Dummy::clone() const
{
	return (new Dummy());
}
```
[***index***](#index)

### Fireball.hpp
```cpp

#pragma once
#include "ASpell.hpp"

class Fireball : public ASpell
{
	public :
		Fireball();
		~Fireball();
		ASpell* clone() const;
};
```
[***index***](#index)

### Fireball.cpp
```cpp

#include "Fireball.hpp"

Fireball::Fireball() : ASpell("Fireball", "burnt to a crisp")
{
}

Fireball::~Fireball()
{}

ASpell* Fireball::clone() const
{
	return (new Fireball());
}
```
[***index***](#index)

### Polymorph.hpp
```cpp
#pragma once
#include "ASpell.hpp"

class Polymorph : public ASpell
{
	public :
		Polymorph();
		~Polymorph();
		ASpell* clone() const;
};
```
[***index***](#index)

### Polymorph.cpp
```cpp
#include "Polymorph.hpp"

Polymorph::Polymorph() : ASpell("Polymorph", "turned into a critter")
{
}

Polymorph::~Polymorph()
{}

ASpell* Polymorph::clone() const
{
	return (new Polymorph());
}
```
[***index***](#index)

### BrickWall.hpp
```cpp
#pragma once
#include "ATarget.hpp"

class BrickWall : public ATarget
{
	public :
		BrickWall();
		~BrickWall();
		ATarget* clone() const;
};
```
[***index***](#index)

### BrickWall.cpp
```cpp

#include "BrickWall.hpp"

BrickWall::BrickWall() : ATarget("Inconspicuous Red-brick Wall")
{
}

BrickWall::~BrickWall()
{}

ATarget* BrickWall::clone() const
{
	return (new BrickWall());
}
```
[***index***](#index)

### SpellBook.hpp
```cpp
#pragma once
#include "ASpell.hpp"
#include <map>

class SpellBook
{
	private :
		SpellBook(SpellBook const & src);
		SpellBook & operator=(SpellBook const & src);
		std::map < std::string, ASpell*> _SpellBook;
	public :
		SpellBook();
		~SpellBook();
		void learnSpell(ASpell*);
		void forgetSpell(std::string const &);
		ASpell* createSpell(std::string const &);
};
```
[***index***](#index)

### SpellBook.cpp
```cpp

#include "SpellBook.hpp"

SpellBook::SpellBook(SpellBook const & src)
{
	*this = src;
}

SpellBook & SpellBook::operator=(SpellBook const & src)
{
	_SpellBook = src._SpellBook;
	return (*this);
}

SpellBook::SpellBook()
{}

SpellBook::~SpellBook()
{
	for (std::map<std::string, ASpell*>::iterator it = _SpellBook.begin(); it != _SpellBook.end(); ++it) {
		delete it->second;
	}
	_SpellBook.clear();
}

void SpellBook::learnSpell(ASpell* spell)
{
	if (spell)
	{
		_SpellBook[spell->getName()] = spell->clone();
	}
}

void SpellBook::forgetSpell(std::string const & SpellName)
{
	std::map<std::string, ASpell*>::iterator it = _SpellBook.find(SpellName);
	if (it != _SpellBook.end())
	{
		delete it->second;
		_SpellBook.erase(it);
	}
}

ASpell* SpellBook::createSpell(std::string const &SpellName)
{
	ASpell* tmp = NULL;
	if (_SpellBook.find(SpellName) != _SpellBook.end())
		tmp = _SpellBook[SpellName];
	return (tmp);
}
```
[***index***](#index)

### TargetGenerator.hpp
```cpp

#pragma once
#include "ATarget.hpp"
#include <map>

class TargetGenerator
{
	private :
		TargetGenerator(TargetGenerator const & src);
		TargetGenerator & operator=(TargetGenerator const & src);
		std::map < std::string, ATarget*> _target;
	public :
		TargetGenerator();
		~TargetGenerator();
		void learnTargetType(ATarget*);
		void forgetTargetType(std::string const &);
		ATarget* createTarget(std::string const &);
};
```
[***index***](#index)

### TargetGenerator.cpp
```cpp
#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(TargetGenerator const & src)
{
	*this = src;
}

TargetGenerator & TargetGenerator::operator=(TargetGenerator const & src)
{
	_target = src._target;
	return (*this);
}


TargetGenerator::TargetGenerator()
{}

TargetGenerator::~TargetGenerator()
{}

void TargetGenerator::learnTargetType(ATarget* target)
{
	if (target)
	{
		_target[target->getType()] = target;
	}
}

void TargetGenerator::forgetTargetType(std::string const & target)
{
	if (_target.find(target) != _target.end())
		_target.erase(_target.find(target));
}

ATarget* TargetGenerator::createTarget(std::string const &target)
{
	ATarget* tmp = NULL;
	if (_target.find(target) != _target.end())
		tmp = _target[target];
	return (tmp);
}
```
[***index***](#index)

### subject
```txt
Assignment name  : cpp_module_02
Expected files   : Warlock.cpp Warlock.hpp
                   ASpell.hpp ASpell.cpp
				   ATarget.hpp ATarget.cpp
				   Fwoosh.hpp Fwoosh.cpp
				   Dummy.hpp Dummy.cpp
				   Fireball.hpp Fireball.cpp
				   Polymorph.hpp Polymorph.cpp
				   BrickWall.hpp BrickWall.cpp
				   SpellBook.hpp SpellBook.cpp
				   TargetGenerator.hpp TargetGenerator.cpp
--------------------------------------------------------------------------------

In the Warlock, SpellBook and TargetGenerator classes, the switch statement is
FORBIDDEN and its use would result in a -42.

Create the following two spells, on the same model as Fwoosh:

* Fireball (Name: "Fireball", Effects: "burnt to a crisp")
* Polymorph (Name: "Polymorph", Effects: "turned into a critter")

In addition to this, just so he won't have only dummy to attack, let's make a
new target for him, which will be the BrickWall (Type: "Inconspicuous Red-brick Wall").

Now, make a SpellBook class, in canonical form, that can't be copied or instantiated
by copy. It will have the following functions:

* void learnSpell(ASpell*), that COPIES a spell in the book
* void forgetSpell(string const &), that deletes a spell from the book, except
  if it isn't there
* ASpell* createSpell(string const &), that receives a string corresponding to
  the name of a spell, creates it, and returns it.

Modify the Warlock, now, make it have a spell book that will be created with
him and destroyed with him. Also make his learnSpell and forgetSpell functions
call those of the spell book.

The launchSpell function will have to use the SpellBook to create the spell
it's attempting to launch.

Make a TargetGenerator class, in canonical form, and as before,
non-copyable.

It will have the following functions:

* void learnTargetType(ATarget*), teaches a target to the generator

* void forgetTargetType(string const &), that makes the generator forget a
  target type if it's known

* ATarget* createTarget(string const &), that creates a target of the
  specified type

Phew, that's done. Now here's a test main. It's not very thorough, so make sure 
to use your own aswell.

int main()
{
  Warlock richard("Richard", "foo");
  richard.setTitle("Hello, I'm Richard the Warlock!");
  BrickWall model1;

  Polymorph* polymorph = new Polymorph();
  TargetGenerator tarGen;

  tarGen.learnTargetType(&model1);
  richard.learnSpell(polymorph);

  Fireball* fireball = new Fireball();

  richard.learnSpell(fireball);

  ATarget* wall = tarGen.createTarget("Inconspicuous Red-brick Wall");

  richard.introduce();
  richard.launchSpell("Polymorph", *wall);
  richard.launchSpell("Fireball", *wall);
}

~$ ./a.out | cat -e
Richard: This looks like another boring day.$
Richard: I am Richard, Hello, I'm Richard the Warlock!!$
Inconspicuous Red-brick Wall has been turned into a critter!$
Inconspicuous Red-brick Wall has been burnt to a crisp!$
Richard: My job here is done!$
~$
```
[***index***](#index)