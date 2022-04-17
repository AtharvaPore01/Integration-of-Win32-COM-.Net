To implement properties from 01 to 04 use dll named as:
************************************************************************************************************************************************
ClassFactoryDllServerWithRegFile.dll
************************************************************************************************************************************************

To Implement property 05 use dll named as:
************************************************************************************************************************************************
ServerSumSubtractMultiplyDivide.dll
************************************************************************************************************************************************

BOTH DLLs and ".reg" ARE PLACED IN TWO DIFFERENT FOLDERS NAMED AS "DLL FOR 01 to 04" and "DLL FOR 05"


PLEASE PUT BOTH DLLs IN C:\Windows\SysWow64
Include ".reg" file after putting dlls in aforementioned folder

Each Folder Contains:
-filename.cpp
-filename.obj
-filename.exe
-filename.lib
-filename.h