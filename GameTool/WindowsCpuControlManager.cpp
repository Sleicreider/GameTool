#include "WindowsCpuControlManager.h"
#include <windows.h>


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