/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** CPUModule
*/

#include "CPUModule.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <thread>

CPUModule::CPUModule()
{
    this->_firstEntry = std::vector<Data>();
    this->_secondEntry = std::vector<Data>();
    this->_result = std::vector<CPUResult>();
}

CPUModule::~CPUModule()
{
}


static size_t GetIdleTime(const Data &e)
{
	return	e.times[S_IDLE] + 
			e.times[S_IOWAIT];
}

static size_t GetActiveTime(const Data &e)
{
	return	e.times[S_USER] +
			e.times[S_NICE] +
			e.times[S_SYSTEM] +
			e.times[S_IRQ] +
			e.times[S_SOFTIRQ] +
			e.times[S_STEAL] +
			e.times[S_GUEST] +
			e.times[S_GUEST_NICE];
}

void CPUModule::getCpuName()
{
	std::ifstream fileStat("/proc/cpuinfo");

	std::string line;
	while (std::getline(fileStat, line)) {
		if (line.find("model name", 0) == 0) {
			_cpuInfo = "Model: " + line.substr(13, line.length());
		}
	}
}

void getCPUInfo(std::vector<Data> & entries)
{
	std::ifstream fileStat("/proc/stat");

	std::string line;

	const std::string STR_CPU("cpu");
	const std::size_t LEN_STR_CPU = STR_CPU.size();
	const std::string STR_TOT("tot");

	while(std::getline(fileStat, line))
	{
		if(!line.compare(0, LEN_STR_CPU, STR_CPU))
		{
			std::istringstream ss(line);
			entries.emplace_back(Data());
			Data & entry = entries.back();
			ss >> entry.cpu;
			if(entry.cpu.size() > LEN_STR_CPU)
				entry.cpu.erase(0, LEN_STR_CPU);
			else
				entry.cpu = STR_TOT;
			for(int i = 0; i < 10; ++i)
				ss >> entry.times[i];
		}
	}
}

void CPUModule::getModuleData()
{
    this->_firstEntry = std::vector<Data>();
    this->_secondEntry = std::vector<Data>();
    this->_result = std::vector<CPUResult>();
	this->getCpuName();

    getCPUInfo(this->_firstEntry);
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
    getCPUInfo(this->_secondEntry);
    getCPUResultInfo(this->_firstEntry, this->_secondEntry);
}

void CPUModule::getCPUResultInfo(std::vector<Data> &firstEntry, std::vector<Data> &secondEntry)
{
    for (size_t i = 0; i < firstEntry.size(); i++) {
        const float ACTIVE_TIME	= static_cast<float>(GetActiveTime(secondEntry[i]) - GetActiveTime(firstEntry[i]));
		const float IDLE_TIME	= static_cast<float>(GetIdleTime(secondEntry[i]) - GetIdleTime(firstEntry[i]));
		const float TOTAL_TIME	= ACTIVE_TIME + IDLE_TIME;

        this->_result.push_back(CPUResult());
        CPUResult &newEntry = this->_result.back();
        newEntry.cpu = firstEntry[i].cpu;
        newEntry.active = 100.f * ACTIVE_TIME / TOTAL_TIME;
        if (newEntry.active < 0)
            newEntry.active = 100;
        newEntry.idle = 100.f * IDLE_TIME / TOTAL_TIME;
        if (newEntry.idle < 0)
            newEntry.idle = 100;
    }
}