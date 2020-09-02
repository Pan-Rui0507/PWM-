# PWM-
要一次性输4个数，可以输0500这样子的.
显示需要按单片机上的11才可以
懒得做即时显示功能

使用方式：把两个.c .h文件放入你的工程文件夹内
然后形如这样

#include <c8051f020.h>
#include <keyboard.h>
#include <PWM_Generator.h>
....

void main()
{
...(自己的函数)
    keyboard_init();PWM_Init();
	  while(1)
	  {
		  if(setf)
		  {
			  PWM_set(freq);		//输入多少就是多少
			  display();
			  setf = 0;
		  }
      .....(自己的函数)
	  }
  }
