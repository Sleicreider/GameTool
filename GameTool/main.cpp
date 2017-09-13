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

int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);
    //GameToolGUI w;
    //w.show();

	QCoreApplication a(argc, argv);


	WindowsCpuControlManager cm;

	std::thread t([&] { while(true)DebugPrint(cm.GetTotalRamUsage() << std::endl)});

	//DebugPrint("test " << cm.GetTotalRamUsage());

	t.join();

    return a.exec();
}
