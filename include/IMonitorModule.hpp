/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** IMonitorModule
*/

#ifndef IMONITORMODULE_HPP_
#define IMONITORMODULE_HPP_

class IMonitorModule {
	public:
		virtual ~IMonitorModule() {};

        virtual void getModuleData() = 0;

	protected:
	private:
};

#endif /* !IMONITORMODULE_HPP_ */
