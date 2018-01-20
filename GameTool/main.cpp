#include "GameToolGUI.h"
#include <QApplication>
#include <QCoreApplication>
#include <sstream>
#include <windows.h>
#include <iostream>
#include "WindowsCpuControlManager.h"
#include <thread>

#define DebugPrint( s )            \
{                             \
   std::ostringstream os_;    \
   os_ << s;                   \
   OutputDebugStringA( os_.str().c_str() );  \
}

auto GetInt()
{
    return 1;
}

struct HWInfo
{
	int ram;
	int cpu;
};

int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);
    //GameToolGUI w;
    //w.show();

	QCoreApplication a(argc, argv);


	WindowsCpuControlManager cm;

	HWInfo hw_info;

	std::thread t1([&] { while (true) hw_info.cpu = cm.GetTotalCpuUsage(); });
	std::thread t2([&] { while (true) hw_info.ram = cm.GetTotalRamUsage(); });
	std::thread t3([&] { while (true) { DebugPrint("ram: " << hw_info.ram << std::endl << "cpu: " << hw_info.cpu << std::endl); Sleep(1000); } });

	t1.detach();
	t2.detach();
	t3.join();

    return a.exec();
}
