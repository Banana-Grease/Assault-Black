#include <Windows.h>
#include <iostream>
#include <Tlhelp32.h>
#include <vector>
#include <ostream>
#include <thread>
#include <fstream>
#include <direct.h>
#include <string>
#include "Variables.h"
#include "Functions.h"
#include "ConsoleColour.h"
#pragma once

using namespace std;

// --------------------- Classes

class Sys
{

public:

	void CreatePaths()
	{
		ifstream cinf;
		ofstream coutf;

		_mkdir("d:/ProgramFiles_x64");
		_mkdir("d:/ProgramFiles_x64/shared");
		_mkdir("d:/ProgramFiles_x64/AssaultBlack");
		_mkdir("d:/ProgramFiles_x64/AssaultBlack/AppFiles");
		_mkdir("d:/ProgramFiles_x64/AssaultBlack/AppFiles/MemoryAddresses");
		
		cinf.open("d:/ProgramFiles_x64/AssaultBlack/AppFiles/MemoryAddresses/HealthAddress.txt");
		if (!cinf.is_open()) {
			coutf.open("d:/ProgramFiles_x64/AssaultBlack/AppFiles/MemoryAddresses/HealthAddress.txt");
			coutf.close();
		}
		cinf.close();

		cinf.open("d:/ProgramFiles_x64/AssaultBlack/AppFiles/MemoryAddresses/ARAddress.txt");
		if (!cinf.is_open()) {
			coutf.open("d:/ProgramFiles_x64/AssaultBlack/AppFiles/MemoryAddresses/ARAddress.txt");
			coutf.close();
		}
		cinf.close();

		cinf.open("d:/ProgramFiles_x64/AssaultBlack/AppFiles/MemoryAddresses/GrenadeCountAddress.txt");
		if (!cinf.is_open()) {
			coutf.open("d:/ProgramFiles_x64/AssaultBlack/AppFiles/MemoryAddresses/GrenadeCountAddress.txt");
			coutf.close();
		}
		cinf.close();

		cinf.open("d:/ProgramFiles_x64/AssaultBlack/AppFiles/MemoryAddresses/PlayerHeightAddress.txt");
		if (!cinf.is_open()) {
			coutf.open("d:/ProgramFiles_x64/AssaultBlack/AppFiles/MemoryAddresses/PlayerHeightAddress.txt");
			coutf.close();
		}
	}

	void GetAddressesViaFile()
	{
		ifstream cinf;
		string Temp;
		cinf.open("d:/ProgramFiles_x64/AssaultBlack/AppFiles/MemoryAddresses/HealthAddress.txt");
		while (cinf >> Temp) {}
		HealthAddress = strtol(Temp.c_str(), 0, 0);
		cinf.close();

		cinf.open("d:/ProgramFiles_x64/AssaultBlack/AppFiles/MemoryAddresses/ARAddress.txt");
		while (cinf >> Temp) {}
		RifleMagAddress = strtol(Temp.c_str(), 0, 0);
		cinf.close();

		cinf.open("d:/ProgramFiles_x64/AssaultBlack/AppFiles/MemoryAddresses/GrenadeCountAddress.txt");
		while (cinf >> Temp) {}
		GrenadesAddress = strtol(Temp.c_str(), 0, 0);
		cinf.close();

		cinf.open("d:/ProgramFiles_x64/AssaultBlack/AppFiles/MemoryAddresses/PlayerHeightAddress.txt");
		while (cinf >> Temp) {}
		HeightAxisAddress = strtol(Temp.c_str(), 0, 0);
		cinf.close();
	}

	void Home(string HomeColour = "purple", string VersionColour = "red", bool HomeColourIntense = false, bool VerisonColourIntense = false)
	{
		system("cls");
		if (HomeColour == "purple" && HomeColourIntense == false) {
			cout << darkpurple;
		}
		else if (HomeColour == "purple" && HomeColourIntense == true) {
			cout << purple;
		}
		else if (HomeColour == "blue" && HomeColourIntense == false) {
			cout << darkblue;
		}
		else if (HomeColour == "blue" && HomeColourIntense == true) {
			cout << blue;
		}
		else if (HomeColour == "red" && HomeColourIntense == false) {
			cout << darkred;
		}
		else if (HomeColour == "red" && HomeColourIntense == true) {
			cout << red;
		}
		else if (HomeColour == "green" && HomeColourIntense == false) {
			cout << darkgreen;
		}
		else if (HomeColour == "green" && HomeColourIntense == true) {
			cout << green;
		}
		else if (HomeColour == "yellow" && HomeColourIntense == false) {
			cout << darkyellow;
		}
		else if (HomeColour == "yellow" && HomeColourIntense == true) {
			cout << yellow;
		}
		else if (HomeColour == "white" && HomeColourIntense == false) {
			cout << darkwhite;
		}
		else if (HomeColour == "white" && HomeColourIntense == true) {
			cout << white;
		}

		cout << "     ______                                           __    __            _______   __                      __" << endl;
		cout << "    /      \\        ";
		// code that does the verison colour
		if (VersionColour == "red" && VersionColourIntense == false) {
			cout << darkred;
		}
		else if (VersionColour == "red" && VersionColourIntense == true) {
			cout << red;
		}
		else if (VersionColour == "blue" && VersionColourIntense == false) {
			cout << darkblue;
		}
		else if (VersionColour == "blue" && VersionColourIntense == true) {
			cout << blue;
		}
		else if (VersionColour == "green" && VersionColourIntense == false) {
			cout << darkgreen;
		}
		else if (VersionColour == "green" && VersionColourIntense == true) {
			cout << green;
		}
		else if (VersionColour == "yellow" && VersionColourIntense == false) {
			cout << darkyellow;
		}
		else if (VersionColour == "yellow" && VersionColourIntense == true) {
			cout << yellow;
		}
		else if (VersionColour == "white" && VersionColourIntense == false) {
			cout << darkwhite;
		}
		else if (VersionColour == "white" && VersionColourIntense == true) {
			cout << white;
		}

		cout << Version;
		if (HomeColour == "purple" && HomeColourIntense == false) {
			cout << darkpurple;
		}
		else if (HomeColour == "purple" && HomeColourIntense == true) {
			cout << purple;
		}
		else if (HomeColour == "blue" && HomeColourIntense == false) {
			cout << darkblue;
		}
		else if (HomeColour == "blue" && HomeColourIntense == true) {
			cout << blue;
		}
		else if (HomeColour == "red" && HomeColourIntense == false) {
			cout << darkred;
		}
		else if (HomeColour == "red" && HomeColourIntense == true) {
			cout << red;
		}
		else if (HomeColour == "green" && HomeColourIntense == false) {
			cout << darkgreen;
		}
		else if (HomeColour == "green" && HomeColourIntense == true) {
			cout << green;
		}
		else if (HomeColour == "yellow" && HomeColourIntense == false) {
			cout << darkyellow;
		}
		else if (HomeColour == "yellow" && HomeColourIntense == true) {
			cout << yellow;
		}
		else if (HomeColour == "white" && HomeColourIntense == false) {
			cout << darkwhite;
		}
		else if (HomeColour == "white" && HomeColourIntense == true) {
			cout << white;
		}
		cout << "               |  \\  |  \\          |       \\ |  \\                    |  \\" << endl;
		cout << "   |  $$$$$$\\  _______   _______   ______   __    __ | $$ _| $$_         | $$$$$$$\\| $$  ______    _______ | $$   __" << endl;
		cout << "   | $$__| $$ /       \\ /       \\ |      \\ |  \\  |  \\| $$|   $$ \\        | $$__/ $$| $$ |      \\  /       \\| $$  /  \\" << endl;
		cout << "   | $$    $$|  $$$$$$$|  $$$$$$$  \\$$$$$$\\| $$  | $$| $$ \\$$$$$$        | $$    $$| $$  \\$$$$$$\\|  $$$$$$$| $$_/  $$" << endl;
		cout << "   | $$$$$$$$ \\$$    \\  \\$$    \\  /      $$| $$  | $$| $$  | $$ __       | $$$$$$$\\| $$ /      $$| $$      | $$   $$" << endl;
		cout << "   | $$  | $$ _\\$$$$$$\\ _\\$$$$$$\\|  $$$$$$$| $$__/ $$| $$  | $$|  \\      | $$__/ $$| $$|  $$$$$$$| $$_____ | $$$$$$\\" << endl;
		cout << "   | $$  | $$|       $$|       $$ \\$$    $$ \\$$    $$| $$   \\$$  $$      | $$    $$| $$ \\$$    $$ \\$$     \\| $$  \\$$\\" << endl;
		cout << "    \\$$   \\$$ \\$$$$$$$  \\$$$$$$$   \\$$$$$$$  \\$$$$$$  \\$$    \\$$$$        \\$$$$$$$  \\$$  \\$$$$$$$  \\$$$$$$$ \\$$   \\$$" << endl << endl;
		// paste version colour code here
		// code that does the verison colour
		if (VersionColour == "red" && VersionColourIntense == false) {
			cout << darkred;
		}
		else if (VersionColour == "red" && VersionColourIntense == true) {
			cout << red;
		}
		else if (VersionColour == "blue" && VersionColourIntense == false) {
			cout << darkblue;
		}
		else if (VersionColour == "blue" && VersionColourIntense == true) {
			cout << blue;
		}
		else if (VersionColour == "green" && VersionColourIntense == false) {
			cout << darkgreen;
		}
		else if (VersionColour == "green" && VersionColourIntense == true) {
			cout << green;
		}
		else if (VersionColour == "yellow" && VersionColourIntense == false) {
			cout << darkyellow;
		}
		else if (VersionColour == "yellow" && VersionColourIntense == true) {
			cout << yellow;
		}
		else if (VersionColour == "white" && VersionColourIntense == false) {
			cout << darkwhite;
		}
		else if (VersionColour == "white" && VersionColourIntense == true) {
			cout << white;
		}
		cout << "                                       " << "[[- " << DiscordLink << " -]]" << endl << white;
	}

	void Selection()
	{
		cout << selec; cin >> sel;
	}

	HWND FindProcessWindow()
	{
		hwnd = FindWindowA(NULL, "AssaultCube");
		while (hwnd == NULL) {
			Home();
			cout << darkwhite << "\nError, Failed to find game window. Please start the game if not already started!\nPress any key to retry!\n\n" << darkpurple;
			system("pause");
			HWND hwnd = FindWindowA(NULL, "AssaultCube");
		}
		return hwnd;
	}

	DWORD FindProcessID()
	{
		GetWindowThreadProcessId(hwnd, &ProcID);
		if (ProcID == NULL) {
			Home();
			cout << darkwhite << "\nError, Failed to grab the process ID\n\n" << purple;
			exit(-1);
		}
		return ProcID;
	}

	HANDLE GetProcessHandle()
	{
		HProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, ProcID);
		if (HProc == NULL) {
			Home();
			cout << darkwhite << "\nError, Failed to grab the HANDLE to the process / game\n\n" << purple;
			exit(-1);
		}
		return HProc;
	}
};

class Hack
{

public:

	
};