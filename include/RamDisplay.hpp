/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** RamDisplay
*/

#ifndef RAMDISPLAY_HPP_
#define RAMDISPLAY_HPP_


#include "IMonitorDisplay.hpp"

#include "RamModule.hpp"

class RamDisplay : public virtual IMonitorDisplay, public RamModule {
	public:
		RamDisplay(int monitorX, int monitorY, displayMode mode);
		RamDisplay(const RamDisplay &ref);
        ~RamDisplay();

        virtual void displayGraphical(sf::RenderWindow &window) final;
        virtual void displayTextual() final;
		void createRecLoader(sf::RenderWindow &window, float count);

	protected:
		sf::Text RamTxtMax;
		sf::Text RamTxtMin;
		sf::Text RamTxtInfo;
    	sf::Font font;
	private:
};

#endif /* !RAMDISPLAY_HPP_ */
