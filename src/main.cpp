/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** main
*/

#include "KernelModule.hpp"
#include "MainWindow.hpp"
#include "TimeModule.hpp"

#include "IMonitorDisplay.hpp"

#include <iostream>
#include <string.h>

template<typename T>
int compare(T const &a, T const &b)
{
    if (a < b)
        return -1;
    if (a > b)
        return 1;
    if (a == b)
        return 0;
    return 0;
}

template <>
int compare<const char *>(const char * const &a, const char * const &b)
{
    if (strcmp(a, b) < 0)
        return -1;
    if (strcmp(a,b) > 0)
        return 1;
    return 0;
}

void displayHelp()
{
    std::cout << "Usage : ./MyGKrellm [-g] [-h --help]" << std::endl;
    std::cout << "-g        Display MyGKrellm in a SFML window" << std::endl;
    exit(1);
}

int main(int ac, char **av)
{
    IMonitorDisplay::displayMode mode = IMonitorDisplay::TEXTUAL;
    MainWindow window(mode);

    if (ac > 1) {
        if (!compare<const char*>(av[1], "-h") || !compare<const char*>(av[1], "--help"))
            displayHelp();
        if (!compare<const char*>(av[1], "-g"))
            mode = IMonitorDisplay::GRAPHICAL;
    }
    if (mode == IMonitorDisplay::TEXTUAL)
        window.loopTextual();
    else
        window.loopGraphical();
}