#include<stdio.h>			//for printf and it is unsafe
#using<mscorlib.dll>		//for managed types and it is safe
using namespace System;		//to access system namespace type

//main
void main(void)
{
	printf("Hello World From Native...!\n");		//native printf()
	Console::WriteLine("Hello World From .Net");	//call to Framework Class Library(FCL)
}
