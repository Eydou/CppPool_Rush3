/*
** EPITECH PROJECT, 2020
** TimeDisplay
** File description:
** TimeDisplay
*/

#include "TimeDisplay.hpp"

void createRectangleTime(sf::RenderWindow &window)
{
    sf::RectangleShape rec(sf::Vector2f(200, 100));
    rec.setFillColor(sf::Color::Transparent);
    rec.setOutlineThickness(5);
    rec.setOutlineColor(sf::Color(0, 150, 255));
    rec.setPosition(340.f, 80.f);
    window.draw(rec);
}

TimeDisplay::TimeDisplay(int monitorX, int monitorY, displayMode mode) : TimeModule()
{
    this->_monitorWidth = monitorX;
    this->_monitorHeight = monitorY;
    this->_mode = mode;
    this->font.loadFromFile("asset/MLSIX.ttf");
    this->TimeTxt.setFont(font);
    this->TimeTxtInfo.setFont(font);
    this->TimeTxt.setCharacterSize(19);
    this->TimeTxtInfo.setCharacterSize(20);
    this->_Type = TIME;
}

TimeDisplay::TimeDisplay(const TimeDisplay &other)
{
    this->_monitorWidth = other._monitorWidth;
    this->_monitorHeight = other._monitorHeight;
    this->_mode = other._mode;
    this->font.loadFromFile("asset/MLSIX.ttf");
    this->TimeTxt.setFont(font);
    this->TimeTxtInfo.setFont(font);
    this->TimeTxt.setCharacterSize(19);
    this->TimeTxtInfo.setCharacterSize(20);
}

TimeDisplay::~TimeDisplay()
{
}

void TimeDisplay::displayGraphical(sf::RenderWindow &window)
{
    createRectangleTime(window);

    TimeTxt.setString(this->getDateTime().c_str());
    TimeTxtInfo.setString("Time Info");
    TimeTxt.setPosition(345.f, 100.f);
    TimeTxtInfo.setPosition(340.f, 45.f);
    this->getModuleData();
    window.draw(TimeTxt);
    window.draw(TimeTxtInfo);
}

void TimeDisplay::displayTextual()
{
    this->getModuleData();
    printw("Date : ");
    printw(this->getDateTime().c_str());
    printw("\n");
}
