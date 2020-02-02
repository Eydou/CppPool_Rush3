/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** MainWindow
*/

#include "MainWindow.hpp"
#include "TimeDisplay.hpp"
#include "UserDisplay.hpp"
#include "RamDisplay.hpp"
#include "CPUDisplay.hpp"
#include <algorithm>

void MainWindow::createBackground()
{
    texture.loadFromFile("asset/Background.jpg");
    sprite.setTexture(texture);
    textureMouse.loadFromFile("asset/cursor.png");
    spriteMouse.setTexture(textureMouse);
}

void MainWindow::myEvent(sf::RenderWindow &window)
{
    sf::Event event;

        while (window.pollEvent(event))
    {
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape)
                window.close();
            else if (event.key.code == sf::Keyboard::R)
                this->HotSwap('r');
            else if (event.key.code == sf::Keyboard::C)
                this->HotSwap('c');
            else if (event.key.code == sf::Keyboard::U)
                this->HotSwap('u');
            else if (event.key.code == sf::Keyboard::K)
                this->HotSwap('k');
            else if (event.key.code == sf::Keyboard::T)
                this->HotSwap('t');
        }
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

MainWindow::MainWindow(displayMode mode)
{
    this->_monitorWidth = 0;
    this->_monitorHeight = 0;
    this->_mode = mode;
    this->fillModules();
}

MainWindow::MainWindow(const MainWindow &window)
{
    this->_monitorWidth = window._monitorWidth;
    this->_monitorHeight = window._monitorHeight;
    this->_mode = window._mode;
    this->_modules = window._modules;
}

MainWindow::~MainWindow()
{
}

MainWindow &MainWindow::operator=(const MainWindow &ref)
{
    if (this != &ref)
    {
        this->_monitorWidth = ref._monitorWidth;
        this->_monitorHeight = ref._monitorHeight;
        this->_mode = ref._mode;
        this->_modules = ref._modules;
    }
    return *this;
}

void MainWindow::fillModules()
{
    this->_modules.push_back(new KernelDisplay(_monitorWidth, _monitorHeight, _mode));
    this->_modules.push_back(new TimeDisplay(_monitorWidth, _monitorHeight, _mode));
    this->_modules.push_back(new UserDisplay(_monitorWidth, _monitorHeight, _mode));
    this->_modules.push_back(new RamDisplay(_monitorWidth, _monitorHeight, _mode));
    this->_modules.push_back(new CPUDisplay(_monitorWidth, _monitorHeight, _mode));
}

void MainWindow::loopGraphical()
{
    sf::RenderWindow window(sf::VideoMode(800, 1000), "MyGKrellm", sf::Style::Close);
    window.setFramerateLimit(30);
    createBackground();
    window.setMouseCursorVisible(false);

    while (window.isOpen())
    {
        window.draw(sprite);
        myEvent(window);
        for (size_t i = 0; i < _modules.size(); i++)
        {
            _modules[i]->displayGraphical(window);
        }
        spriteMouse.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
        window.draw(spriteMouse);
        window.display();
         //window.clear();
    }
}

void MainWindow::AddModuleType(IMonitorDisplay::ModuleType type)
{
    bool found = false;
    for(size_t i = 0; i < this->_modules.size(); i++) {
        if(this->_modules[i]->_Type == type)
            found = true;
    }
    printw("%d\n", found);
    if (!found) {
        if (type == KERNEL)
            this->_modules.push_back(new KernelDisplay(0,0,_mode));
        if (type == CPU)
            this->_modules.push_back(new CPUDisplay(0,0,_mode));
        if (type == USER)
            this->_modules.push_back(new UserDisplay(0,0,_mode));
        if (type == RAM)
            this->_modules.push_back(new RamDisplay(0,0,_mode));
        if (type == TIME)
            this->_modules.push_back(new TimeDisplay(0,0,_mode));
    } else
        DeleteModuleType(type);
}

void MainWindow::DeleteModuleType(IMonitorDisplay::ModuleType type)
{
    for(size_t i = 0; i < this->_modules.size(); i++) {
        if(this->_modules[i]->_Type == type)
            _modules.erase(_modules.begin() + i);
    }
}

void MainWindow::HotSwap(int ch)
{
    switch (ch) {
        case 'r' :
            AddModuleType(RAM);
            break;
        case 'c' :
            AddModuleType(CPU);
            break;
        case 'u' :
            AddModuleType(USER);
            break;
        case 'k' : 
            AddModuleType(KERNEL);
            break;
        case 't' :
            AddModuleType(TIME);
            break;
        default :
            break;
    }
}
void MainWindow::loopTextual()
{
    int ch;
    initscr();
    noecho();
    nodelay(stdscr, TRUE);
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_GREEN);
    do {
        usleep(333333);
        clear();
        ch = getch();
        HotSwap(ch);
        for (size_t i = 0; i < _modules.size(); i++) {
            _modules[i]->displayTextual();
            attron(COLOR_PAIR(1));
            printw("------------------------------------------\n");
            printw("\n");
            attroff(COLOR_PAIR(1));
        }
        refresh();
    } while (ch != 'q');
    endwin();
    return;
}