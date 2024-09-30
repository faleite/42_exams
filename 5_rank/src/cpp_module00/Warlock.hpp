#include <iostream>

class Warlock
{
	private:
		std::string _name;
		std::string _title;
		Warlock();
		Warlock(const Warlock &copyObj);
		Warlock &operator=(const Warlock &assignCopy);
	public:
		Warlock(const std::string &name, const std::string &title);
		~Warlock();

		const std::string &getName() const;
		const std::string &getTitle() const;
		void setTitle(const std::string &str);
		void introduce() const;
};