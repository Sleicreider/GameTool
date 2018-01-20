#include "WindowsCpuControlManager.h"
#include <windows.h>
#include <Pdh.h>


#pragma comment(lib, "pdh.lib")
#pragma comment(lib, "IPHLPAPI.lib")

#pragma region CPU
static PDH_HQUERY cpuq;
static PDH_HCOUNTER cpu_total;
PDH_STATUS status;

void init()
{
	PdhOpenQuery(NULL, NULL, &cpuq);
	// You can also use L"\\Processor(*)\\% Processor Time" and get individual CPU values with PdhGetFormattedCounterArray()
	PdhAddEnglishCounter(cpuq, L"\\Processor(_Total)\\% Processor Time", 0, &cpu_total);
	PdhCollectQueryData(cpuq); //not needed? since used anyway
}


bool GetCurrentCpu(double& p_value)
{
	Sleep(500);
	if ((status = PdhCollectQueryData(cpuq)) != ERROR_SUCCESS)
	{
		return false;
	}
	//Sleep(1000);
	PDH_FMT_COUNTERVALUE val;
	//Sleep(1000);
	if (PdhGetFormattedCounterValue(cpu_total, PDH_FMT_DOUBLE, 0, &val) != ERROR_SUCCESS)
	{
		return false;
	}
	//Sleep(1000);
	p_value = val.doubleValue;

	return true;
}

int WindowsCpuControlManager::GetTotalCpuUsage()
{
	static bool check = false;

	if (!check)
	{
		check = true;
		init();
		//Sleep(2000);
	}

	double res;
	if (GetCurrentCpu(res))
	{

	}

	return res;
}


unsigned long WindowsCpuControlManager::GetTotalRamUsage()
{
	#include <windows.h>
	MEMORYSTATUSEX mem_info;
	mem_info.dwLength = sizeof(MEMORYSTATUSEX);
	GlobalMemoryStatusEx(&mem_info);

	//could return total phys - available aswell and calc it ourself
	/*unsigned long long total_virutal_mem = mem_info.ullTotalPageFile;*/

	//return memory usage in percent
	return mem_info.dwMemoryLoad;
}    

