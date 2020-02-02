/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** CPUModule
*/

#ifndef CPUMODULE_HPP_
#define CPUMODULE_HPP_

#include <vector>
#include <string>

#include "IMonitorModule.hpp"

enum CPUStates
{
	S_USER = 0,
	S_NICE,
	S_SYSTEM,
	S_IDLE,
	S_IOWAIT,
	S_IRQ,
	S_SOFTIRQ,
	S_STEAL,
	S_GUEST,
	S_GUEST_NICE
};

typedef struct Data
{
	std::string cpu;
	size_t times[10];
} Data;

typedef struct CPUResData
{
    std::string cpu;
    float active;
    float idle;
} CPUResult;

class CPUModule : public virtual IMonitorModule {
	public:
		CPUModule();
		~CPUModule();

        void getCPUResultInfo(std::vector<Data> &firstEntry, std::vector<Data> &secondEntry);
        virtual void getModuleData() final;
		void getCpuName();

	protected:
        std::vector<Data> _firstEntry;
        std::vector<Data> _secondEntry;
        std::vector<CPUResult> _result;
		std::string _cpuInfo;
	private:
};

#endif /* !CPUMODULE_HPP_ */
