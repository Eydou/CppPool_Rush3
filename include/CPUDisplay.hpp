/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** CPUDisplay
*/

#ifndef CPUDISPLAY_HPP_
#define CPUDISPLAY_HPP_


#include "IMonitorDisplay.hpp"

#include "CPUModule.hpp"

class CPUDisplay : public virtual IMonitorDisplay, public CPUModule {
	public:
		CPUDisplay(int monitorX, int monitorY, displayMode mode);
		CPUDisplay(const CPUDisplay &ref);
        ~CPUDisplay();

        void createRectangle(sf::RenderWindow &window);
		void createMultipleCPU(sf::RenderWindow &window);
		void createRecMultipleCPU(sf::RenderWindow &window);
		void createBorderLineCPU(sf::RenderWindow &window);
		void createPercentCPU(sf::RenderWindow &window);

        virtual void displayGraphical(sf::RenderWindow &window) final;
        virtual void displayTextual() final;

	protected:
	private:
		sf::Text _CPUtxt;
        sf::Text _info;
    	sf::Font font;
};

#endif /* !CPUDISPLAY_HPP_ */
