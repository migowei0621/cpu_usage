#include <windows.h>
#include <math.h>
#include <stdlib.h> 
#include <iostream>
using namespace std;
const int sampling_count =200; //抽样点数量
const double PI =3.1415926535;//PI 值
const int total_amplitude=300;//每个取样点对应的时间片ms
int main(int argc, char const *argv[])
{

      SYSTEM_INFO info;



	cout<<GetSystemInfo(&info)<<endl;
  DWORD busySpan[sampling_count];
  int amplitude= total_amplitude/2;
  double radian =0.0;
  double radianIncrement=2.0/(double)sampling_count;//抽样弧度的增量
  for (int i = 0; i < sampling_count; ++i)
  {
  	/* code */
  	busySpan[i]=(DWORD)(amplitude+(sin(PI*radian)*amplitude));
  	radian+=radianIncrement;

  }
  DWORD startTime=0;
  for (int i = 0; ; i=(i+1)%sampling_count)
  {
  	/* code */
  	startTime=GetTickCount();
  	while((GetTickCount()-startTime)<=busySpan[i])
  	{}
    Sleep(total_amplitude-busySpan[i]);
  }

	return 0;
}
