#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>

class Zombie
{
	private:
		std::string name;
		
	public:

        Zombie();
		Zombie(const std::string& name);
		~Zombie();

		void announce(void) const;
};

#endif
