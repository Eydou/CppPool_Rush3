/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** RamDisplay
*/

#include "RamDisplay.hpp"

#include "KernelDisplay.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

void RamDisplay::createRecLoader(sf::RenderWindow &window, float count)
{
    float a = this->getRamUsed();
    float b = this->getRamSize();
    int percent = a / b * 100;
    sf::Text PercTxt;
    PercTxt.setFont(this->font);

    sf::RectangleShape rec(sf::Vector2f(count, 80));
    if (count < 250)
        rec.setFillColor(sf::Color::Green);
    else if (count < 500)
        rec.setFillColor(sf::Color(250, 150, 100));
    else
        rec.setFillColor(sf::Color::Red);
    rec.setPosition(15.f, 240.f);
    window.draw(rec);

    PercTxt.setCharacterSize(40);
    PercTxt.setString(std::to_string(percent));
    PercTxt.setPosition(count - 180 , 250.f);
    window.draw(PercTxt);
}

void createRectangleRam(sf::RenderWindow &window)
{
    sf::RectangleShape rec(sf::Vector2f(778 , 130));
    rec.setFillColor(sf::Color::Transparent);
    rec.setOutlineThickness(5);
    rec.setOutlineColor(sf::Color(0, 150, 255));
    rec.setPosition(10.f, 230.f);
    window.draw(rec);
}

RamDisplay::RamDisplay(int monitorX, int monitorY, displayMode mode) : RamModule()
{
    this->_monitorWidth = monitorX;
    this->_monitorHeight = monitorY;
    this->_mode = mode;
    this->font.loadFromFile("asset/MLSIX.ttf");
    this->RamTxtInfo.setFont(font);
    this->RamTxtMin.setFont(font);
    this->RamTxtMax.setFont(font);
    this->RamTxtInfo.setCharacterSize(20);
    this->RamTxtMin.setCharacterSize(20);
    this->RamTxtMax.setCharacterSize(20);
    this->_Type = RAM;
}

RamDisplay::RamDisplay(const RamDisplay &ref)
{
    this->_monitorWidth = ref._monitorWidth;
    this->_monitorHeight = ref._monitorHeight;
    this->_mode = ref._mode;
    this->font.loadFromFile("asset/MLSIX.ttf");
    this->RamTxtInfo.setFont(font);
    this->RamTxtMin.setFont(font);
    this->RamTxtMax.setFont(font);
    this->RamTxtInfo.setCharacterSize(20);
    this->RamTxtMin.setCharacterSize(20);
    this->RamTxtMax.setCharacterSize(20);
}

RamDisplay::~RamDisplay()
{
}

void RamDisplay::displayGraphical(sf::RenderWindow &window)
{
    float a = this->getRamUsed();
    float b = this->getRamSize();
    float count = a / b * 768;
    std::stringstream myString;
    std::string size = std::to_string(this->getRamSize());
    myString << "Max " << size << " kb";
    std::string stringResult = myString.str();

    this->getModuleData();
    createRecLoader(window, count);
    createRectangleRam(window);
    RamTxtMin.setString("Min 0 kb");
    RamTxtMax.setString(stringResult);
    RamTxtMax.setPosition(610.f, 325.f);
    RamTxtMin.setPosition(15.f, 325.f);
    RamTxtInfo.setString("Ram Info");
    RamTxtInfo.setPosition(15.f, 200.f);
    window.draw(RamTxtInfo);
    window.draw(RamTxtMin);
    window.draw(RamTxtMax);
}

void RamDisplay::displayTextual()
{
    this->getModuleData();
    float a = this->getRamSize();
    float b = this->getRamUsed();
    int intpart;
    int percentage;
    init_pair(1, COLOR_BLACK, COLOR_GREEN);
    init_pair(2, COLOR_BLACK, COLOR_YELLOW);
    init_pair(3, COLOR_BLACK, COLOR_RED);
    percentage = (b/ a) * 100;
    intpart = (int)percentage/10;
    
    printw("Ram size : %d\n", this->getRamSize());
    printw("Ram available : %d\n", this->getRamAvail());
    printw("Ram used : %d  [", this->getRamUsed());
    for (int i = 0; i != intpart; i++) {
        if (intpart <= 4) {
            attron(COLOR_PAIR(1));
            printw("|");
            attroff(COLOR_PAIR(1));
        }
        else if (intpart >= 4 && intpart <= 7) {
            attron(COLOR_PAIR(2));
            printw("|");
            attroff(COLOR_PAIR(2));
        }
        else {
            attron(COLOR_PAIR(3));
            printw("|");
            attroff(COLOR_PAIR(3));
        }
    } 
    printw("] %d%%\n", percentage);
}