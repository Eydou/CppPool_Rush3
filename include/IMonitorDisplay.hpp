/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** IMonitorDisplay
*/

#ifndef IMONITORDISPLAY_HPP_
#define IMONITORDISPLAY_HPP_
#include <curses.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class IMonitorDisplay {
	public:
        enum displayMode {GRAPHICAL, TEXTUAL};
		virtual ~IMonitorDisplay() {};

         enum ModuleType {
                KERNEL,
                RAM,
                CPU,
                TIME,
                USER,
        };
        virtual void displayGraphical(sf::RenderWindow &window) = 0;
        virtual void displayTextual() = 0;
        ModuleType _Type;
	protected:
        int _monitorWidth;
        int _monitorHeight;
        displayMode _mode;
	private:
};

#endif /* !IMONITORDISPLAY_HPP_ */
