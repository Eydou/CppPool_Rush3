/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** UserDisplay
*/

#ifndef USERDISPLAY_HPP_
#define USERDISPLAY_HPP_

#include "IMonitorDisplay.hpp"
#include "UserModule.hpp"

class UserDisplay : public virtual IMonitorDisplay, public UserModule {
	public:
		UserDisplay(int monitorX, int monitorY, displayMode mode);
		UserDisplay(const UserDisplay &ref);
        ~UserDisplay();

        virtual void displayGraphical(sf::RenderWindow &window) final;
        virtual void displayTextual() final;

	protected:
		sf::Text UserTxt;
		sf::Text UserTxtInfo;
		sf::Text HostTxt;
    	sf::Font font;
	private:
};

#endif /* !USERDISPLAY_HPP_ */
