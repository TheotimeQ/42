#ifndef HARL_H
# define HARL_H

# include <string>
# include <iostream>

class Harl
{
    private:

        void debug(void) const;
        void info(void) const;
        void warning(void) const;
        void error(void) const;

    public:

        Harl();
        ~Harl();

        void complain(const std::string &level) const;
};

#endif