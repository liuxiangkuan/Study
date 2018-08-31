#include<Windows.h>
int main(int argc,char*argv[])
{
	char buf[MAX_PATH];
	HMODULE module;
	module = GetModuleHandle(0);
	GetModuleFileName(module, buf, MAX_PATH);
	CloseHandle((HANDLE)4);
	__asm
	{
		lea eax,buf
		push 0
		push 0
		push eax
		push ExitProcess
		push module
		push DeleteFile
		push UnmapViewOfFile
		ret
	}
	return 0;
}