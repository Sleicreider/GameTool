#pragma once



class WindowsCpuControlManager
{
public:
	void GetTotalCpuUsage();
	void GetCpuTemperature();
	void GetCpuFanSpeed();

	unsigned long GetTotalRamUsage();


	//For future implementations
	//void GetCpuUsageList();
	//void SetCpuFanSpeed();
};