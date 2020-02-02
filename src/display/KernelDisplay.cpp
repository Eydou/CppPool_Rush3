/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** KernelDisplay
*/

#include "KernelDisplay.hpp"

void createRectangle(sf::RenderWindow &window)
{
    sf::RectangleShape rec(sf::Vector2f(300, 100));
    rec.setFillColor(sf::Color::Transparent);
    rec.setOutlineThickness(5);
    rec.setOutlineColor(sf::Color(0, 150, 255));
    rec.setPosition(10.f, 80.f);
    window.draw(rec);
}

KernelDisplay::KernelDisplay(int monitorX, int monitorY, displayMode mode) : KernelModule()
{
    this->_monitorWidth = monitorX;
    this->_monitorHeight = monitorY;
    this->_mode = mode;
    this->font.loadFromFile("asset/MLSIX.ttf");
    this->KernelTxtVersion.setFont(font);
    this->OsTxtName.setFont(font);
    this->MachineTxtInfo.setFont(font);
    this->MachineTxtInfo.setCharacterSize(20);
    this->KernelTxtVersion.setCharacterSize(20);
    this->OsTxtName.setCharacterSize(20);
    this->_Type = KERNEL;
}

KernelDisplay::KernelDisplay(const KernelDisplay &ref)
{
    this->_monitorWidth = ref._monitorWidth;
    this->_monitorHeight = ref._monitorHeight;
    this->_mode = ref._mode;
    this->font.loadFromFile("asset/MLSIX.ttf");
    this->KernelTxtVersion.setFont(font);
    this->OsTxtName.setFont(font);
    this->MachineTxtInfo.setFont(font);
    this->MachineTxtInfo.setCharacterSize(20);
    this->KernelTxtVersion.setCharacterSize(20);
    this->OsTxtName.setCharacterSize(20);
}


KernelDisplay::~KernelDisplay()
{
}

void KernelDisplay::displayGraphical(sf::RenderWindow &window)
{
    createRectangle(window);

    KernelTxtVersion.setString(this->getKernelVersion().c_str());
    OsTxtName.setString(this->getOsName().c_str());
    MachineTxtInfo.setString("Machine Info");
    MachineTxtInfo.setPosition(10.f, 45.f);
    KernelTxtVersion.setPosition(15.f, 130.f);
    OsTxtName.setPosition(15.f, 100.f);
    window.draw(MachineTxtInfo);
    window.draw(KernelTxtVersion);
    window.draw(OsTxtName);
}

void KernelDisplay::displayTextual()
{
    this->getModuleData();
    printw("Kernel version : ");
    printw(this->getKernelVersion().c_str());
    printw("\n");
    printw("Os Name : ");
    printw(this->getOsName().c_str());
    printw("\n");
}
