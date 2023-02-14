#ifndef WEAPON_H
# define WEAPON_H

# include <string>
# include <iostream>

class Weapon
{
    private:
    
        std::string type;
        
    public:

        Weapon();
		Weapon(const std::string &name);
		~Weapon();

        const std::string& getType() const;
        void setType(const std::string &type);

};

#endif
