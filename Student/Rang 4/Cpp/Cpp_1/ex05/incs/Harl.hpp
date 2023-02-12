/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:07:46 by zelinsta          #+#    #+#             */
/*   Updated: 2023/02/06 13:20:35 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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