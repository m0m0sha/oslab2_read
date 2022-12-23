#include <iostream>
#include<windows.h>
#include<string>

using namespace std;
void Read();

int main()
{
	Read();
	return 0;
}
void Read()
{
	string FileMap;
	HANDLE HandleMap;
	LPVOID Memory;
	cout << "Enter file name ";
	cin >> FileMap;
	HandleMap = OpenFileMappingA(FILE_MAP_READ | FILE_MAP_WRITE, FALSE, FileMap.c_str());
	Memory = MapViewOfFile(HandleMap, FILE_MAP_ALL_ACCESS, 0, 0, 0); //projecting a fragment of a file into memory
	if (Memory)
	{
		cout << "File contents " << (char*)Memory << endl << endl;
		cout << "Enter any character to complete: ";
		cin >> FileMap;
		UnmapViewOfFile(Memory); //file projection completion
	}
	else
	{
		cout << "ERROR";
	}
}