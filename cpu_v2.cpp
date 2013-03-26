#include <windows.h>
#include <stdlib.h>
#include <stdint.h>
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	const DWORD busyTime =10;
	const DWORD idleTime =busyTime;
    long long startTime =0 ;
	while(true)
	{
		cout<<"running"<<endl;
		DWORD startTime =GetTickCount();

		while((GetTickCount()-startTime)<=busyTime){}
			Sleep(idleTime);
	}
	return 0;
}