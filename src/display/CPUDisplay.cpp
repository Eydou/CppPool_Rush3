/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** CPUDisplay
*/

#include "CPUDisplay.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

CPUDisplay::CPUDisplay(int monitorX, int monitorY, displayMode mode) : CPUModule()
{
    this->_monitorWidth = monitorX;
    this->_monitorHeight = monitorY;
    this->_mode = mode;
    this->font.loadFromFile("asset/MLSIX.ttf");
    this->_info.setFont(this->font);
    this->_info.setCharacterSize(20);
    this->_CPUtxt.setFont(this->font);
    this->_CPUtxt.setCharacterSize(20);
    this->_Type = CPU;
}

CPUDisplay::CPUDisplay(const CPUDisplay &ref)
{
    this->_monitorHeight = ref._monitorHeight;
    this->_monitorWidth = ref._monitorWidth;
    this->_mode = ref._mode;
    this->_CPUtxt.setFont(this->font);
    this->_CPUtxt.setCharacterSize(20);
}

CPUDisplay::~CPUDisplay()
{
}


void CPUDisplay::createRectangle(sf::RenderWindow &window)
{
    sf::RectangleShape rec(sf::Vector2f(778, (20 * _result.size())));
    rec.setFillColor(sf::Color::Transparent);
    rec.setOutlineThickness(5);
    rec.setOutlineColor(sf::Color(0, 150, 255));
    rec.setPosition(10.f, 430.f);
    window.draw(rec);
}

void CPUDisplay::createBorderLineCPU(sf::RenderWindow &window)
{
    float x = 38.f;
    float y = 435.f;

    std::vector<sf::RectangleShape> BorderCPU;
    for (size_t i = 0; i < _result.size(); i++)
    {
        if (!i)
            x = 60.f;
        sf::RectangleShape rect(sf::Vector2f(190, 20));
        rect.setFillColor(sf::Color::Transparent);
        rect.setOutlineThickness(2);
        rect.setOutlineColor(sf::Color::White)  ;
        BorderCPU.push_back(rect);
        BorderCPU.back().setPosition(x, y);
        if ((i % 3) == 0)
        {
            y = y + 50;
            x = 38.f;
        } else
            x = x + 250;
        if (!i)
            x = 38.f;
    }
    for (size_t i = 0; i < _result.size(); i++)
        window.draw(BorderCPU[i]);
}

void CPUDisplay::createPercentCPU(sf::RenderWindow &window)
{
    int active;
    float x = 206.f;
    float y = 440.f;
    sf::Text PercTxt;
    PercTxt.setFont(this->font);

    std::vector<sf::Text> CPUPercent;
    for (size_t i = 0; i < _result.size(); i++)
    {
        active = this->_result[i].active / 100 * 100;
        PercTxt.setCharacterSize(10);
        PercTxt.setString(std::to_string(active));
        CPUPercent.push_back(PercTxt);
        if (!i)
        CPUPercent.back().setPosition(226, y);
        else
        CPUPercent.back().setPosition(x, y);
        if ((i % 3) == 0)
        {
            y = y + 50;
            x = 206.f;
        } else
            x = x + 250;
    }
    for (size_t i = 0; i < _result.size(); i++)
        window.draw(CPUPercent[i]);
}

void CPUDisplay::createRecMultipleCPU(sf::RenderWindow &window)
{
    float active;
    float x = 36.f;
    float y = 435.f;

    std::vector<sf::RectangleShape> RecCPU;
    for (size_t i = 0; i < _result.size(); i++)
    {
        if (!i) {
            x = 60.f;
        }
        active = this->_result[i].active / 100 * 192;
        sf::RectangleShape rec(sf::Vector2f(active, 20));
        if (active < 80)
            rec.setFillColor(sf::Color::Green);
        else if (active < 120)
            rec.setFillColor(sf::Color(250, 150, 100));
        else
            rec.setFillColor(sf::Color::Red);
        RecCPU.push_back(rec);
        RecCPU.back().setPosition(x, y);
        if ((i % 3) == 0)
        {
            y = y + 50;
            x = 36.f;
        } else
            x = x + 250;
        if (!i)
            x = 36.f;
    }
    for (size_t i = 0; i < _result.size(); i++)
        window.draw(RecCPU[i]);
}

void CPUDisplay::createMultipleCPU(sf::RenderWindow &window)
{
    int nb = -1;
    float x = 15.f;
    float y = 435.f;
    sf::Text bigLopes;
    bigLopes.setFont(this->font);
    bigLopes.setCharacterSize(20);
    bigLopes.setPosition(x + 250, y - 2);
    bigLopes.setString(this->_cpuInfo.c_str());

    std::vector<sf::Text> StackCPU;
    for (size_t i = 0; i < _result.size(); i++)
    {
        if (nb == -1)
        _CPUtxt.setString("total");
        else
        _CPUtxt.setString(std::to_string(nb));
        StackCPU.push_back(_CPUtxt);
        StackCPU.back().setPosition(x, y);
        if ((i % 3) == 0)
        {
            y = y + 50;
            x = 15.f;
        } else
            x = x + 250;
        nb++;    
    }
    for (size_t i = 0; i < _result.size(); i++)
        window.draw(StackCPU[i]);
    window.draw(bigLopes);
}

void CPUDisplay::displayGraphical(sf::RenderWindow &window)
{
    this->getModuleData();
    createRectangle(window);
    _info.setString("CPU Info");
    _info.setPosition(15.f, 395.f);
    window.draw(_info);
    createMultipleCPU(window);
    createRecMultipleCPU(window);
    createBorderLineCPU(window);
    createPercentCPU(window);
  //  std::cout << _result.size() << std::endl;
}

void CPUDisplay::displayTextual()
{
    this->getModuleData();
    init_pair(1, COLOR_BLACK, COLOR_GREEN);
    init_pair(2, COLOR_BLACK, COLOR_YELLOW);
    init_pair(3, COLOR_BLACK, COLOR_RED);
    int intpart;
    for (size_t i = 0; i < this->_firstEntry.size(); i++) {
        if (!i) {
            intpart = (int)this->_result[i].active/10;
            printw("total: active : %.3f [", this->_result[i].active);
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
            printw("]\n");
        }
        else {
            intpart = (int)this->_result[i].active/10;
            printw("cpu%0i: active : %.3f [", i - 1, this->_result[i].active);
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
            printw("]\n");
        }
    } 
}