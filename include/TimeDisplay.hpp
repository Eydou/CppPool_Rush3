/*
** EPITECH PROJECT, 2020
** TimeDisplay
** File description:
** TimeDisplay
*/

#ifndef TIMEDISPLAY_HPP_
#define TIMEDISPLAY_HPP_

#include "IMonitorDisplay.hpp"
#include "TimeModule.hpp"

class TimeDisplay : public virtual IMonitorDisplay, public TimeModule {
	public:
		TimeDisplay(int monitorX, int monitorY, displayMode mode);
        TimeDisplay(const TimeDisplay &other);
		~TimeDisplay();

        virtual void displayGraphical(sf::RenderWindow &window) final;
        virtual void displayTextual() final;
	protected:
	private:
		sf::Text TimeTxt;
		sf::Text TimeTxtInfo;
    	sf::Font font;
};

#endif /* !TIMEDISPLAY_HPP_ */
