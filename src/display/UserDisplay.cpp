/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** UserDisplay
*/

#include "UserDisplay.hpp"

void createRectangleUser(sf::RenderWindow &window)
{
    sf::RectangleShape rec(sf::Vector2f(218, 100));
    rec.setFillColor(sf::Color::Transparent);
    rec.setOutlineThickness(5);
    rec.setOutlineColor(sf::Color(0, 150, 255));
    rec.setPosition(570.f, 80.f);
    window.draw(rec);
}

UserDisplay::UserDisplay(int monitorX, int monitorY, displayMode mode) : UserModule()
{
    this->_monitorWidth = monitorX;
    this->_monitorHeight = monitorY;
    this->_mode = mode;
    this->font.loadFromFile("asset/MLSIX.ttf");
    this->UserTxt.setFont(font);
    this->UserTxtInfo.setFont(font);
    this->HostTxt.setFont(font);
    this->HostTxt.setCharacterSize(20);
    this->UserTxt.setCharacterSize(20);
    this->UserTxtInfo.setCharacterSize(20);
    this->_Type = USER;
}

UserDisplay::UserDisplay(const UserDisplay &ref)
{
    this->_monitorWidth = ref._monitorWidth;
    this->_monitorHeight = ref._monitorHeight;
    this->_mode = ref._mode;
    this->font.loadFromFile("asset/MLSIX.ttf");
    this->UserTxt.setFont(font);
    this->UserTxtInfo.setFont(font);
    this->HostTxt.setFont(font);
    this->HostTxt.setCharacterSize(20);
    this->UserTxt.setCharacterSize(20);
    this->UserTxtInfo.setCharacterSize(20);
}


UserDisplay::~UserDisplay()
{
}

void UserDisplay::displayGraphical(sf::RenderWindow &window)
{
    createRectangleUser(window);

    UserTxt.setString(this->getUser().c_str());
    HostTxt.setString(this->getHost().c_str());
    UserTxtInfo.setString("User Info");
    UserTxtInfo.setPosition(570.f, 45.f);
    UserTxt.setPosition(575.f, 130.f);
    HostTxt.setPosition(575.f, 100.f);
    window.draw(UserTxtInfo);
    window.draw(UserTxt);
    window.draw(HostTxt);
}

void UserDisplay::displayTextual()
{
    printw("User Name : ");
    printw(this->getUser().c_str());
    printw("\t");
    printw("Host Name : ");
    printw(this->getHost().c_str());
    printw("\n");
}
