/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** MainWindow
*/

#ifndef MAINWINDOW_HPP_
#define MAINWINDOW_HPP_

#include "IMonitorDisplay.hpp"
#include "KernelDisplay.hpp"
#include <vector>

class MainWindow : public virtual IMonitorDisplay {
	public:
		MainWindow(displayMode mode);
		MainWindow(const MainWindow &window);
		~MainWindow();
        MainWindow &operator=(const MainWindow &ref);
        virtual void displayTextual() {};
        virtual void displayGraphical(sf::RenderWindow &w) {(void)w;};
        void HotSwap(int ch);
        void AddModuleType(IMonitorDisplay::ModuleType type);
        void DeleteModuleType(IMonitorDisplay::ModuleType type);
        void createBackground();
        void myEvent(sf::RenderWindow &window);

        void fillModules();
        void loopGraphical();
        void loopTextual();

	protected:
	private:
        std::vector<IMonitorDisplay*> _modules;
        sf::Texture textureMouse;
        sf::Texture texture;
        sf::Sprite sprite;
        sf::Sprite spriteMouse;

};

#endif /* !MAINWINDOW_HPP_ */
