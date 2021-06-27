#include <Windows.h>
#include <iostream>
#include <Tlhelp32.h>
#include <vector>
#include <string>
#include <thread>
#pragma once

using namespace std;

// --------------------------- Global Variables

string Version = "Assault-Black V0.0";
string WindowName = "AssaultCube";
string HomeColourChoice = "purple";
string sel;
string selec = " --> ";
bool HomeColourIntense = false;
bool VersionColourIntense = false;
bool ShouldRefresh = false;
bool Loop = false;
string LastPressedKey[5] = { "NULL", "NULL", "NULL", "NULL", "NULL" };
string ActiveKey;
string VersionColourChoice = "red";
string DiscordLink = "https://discord.gg/jugeA56U4a";

// Hack Variables

DWORD ProcID = NULL;
HANDLE HProc = NULL;
HWND hwnd;

int CurrentHealth;
int MaxHealth = 100;
int MaxRifleMag = 20;
int MaxGrenades = 3;

int Loopeds[2] = {0, 0};
int CurrentGrenades;
int CurrentRifleMag;
float PlayerHeight;
float LastPlayerHeight;

bool MaxHealthHackIsOn = false;
bool InfinateGrenades = false;
bool InfinateMagAmmo = false;
bool BHOP = false;
bool Strafe = false;

// --------------------------- Memory Addresses

DWORD GrenadesAddress;
DWORD HealthAddress;
DWORD RifleMagAddress;
DWORD HeightAxisAddress;