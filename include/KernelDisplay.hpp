/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** KernelDisplay
*/

#ifndef KERNELDISPLAY_HPP_
#define KERNELDISPLAY_HPP_

#include "IMonitorDisplay.hpp"

#include "KernelModule.hpp"

class KernelDisplay : public virtual IMonitorDisplay, public KernelModule {
	public:
		KernelDisplay(int monitorX, int monitorY, displayMode mode);
		KernelDisplay(const KernelDisplay &ref);
        ~KernelDisplay();

        virtual void displayGraphical(sf::RenderWindow &window) final;
        virtual void displayTextual() final;

	protected:
	private:
		sf::Text KernelTxtVersion;
		sf::Text OsTxtName;
		sf::Text MachineTxtInfo;
    	sf::Font font;
};

#endif /* !KERNELDISPLAY_HPP_ */
