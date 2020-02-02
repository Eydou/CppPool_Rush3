/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** TimeModule
*/

#ifndef TIMEMODULE_HPP_
#define TIMEMODULE_HPP_

#include "IMonitorModule.hpp"

#include <string>

class TimeModule : public virtual IMonitorModule {
	public:
		TimeModule();
		~TimeModule();

        virtual void getModuleData() final;

        const std::string &getDateTime() const;

	protected:
	private:
        std::string _timeString;
};

#endif /* !TIMEMODULE_HPP_ */
