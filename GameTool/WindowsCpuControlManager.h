#pragma once



class WindowsCpuControlManager
{
public:
	int GetTotalCpuUsage();
	void GetCpuTemperature();
	void GetCpuFanSpeed();

	unsigned long GetTotalRamUsage();


	//For future implementations
	//void GetCpuUsageList();
	//void SetCpuFanSpeed();
};