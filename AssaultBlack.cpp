#include <Windows.h>
#include <iostream>
#include <Tlhelp32.h>
#include <vector>
#include <thread>
#include "Classes and structs.h"
#include "Functions.h"
#include "Variables.h"

int main()
{
    Sys sys;
    Hack hack;
    system("title Assault-Black");
    sys.CreatePaths();
    sys.GetAddressesViaFile();
    hwnd = sys.FindProcessWindow();
    ProcID = sys.FindProcessID();
    HProc = sys.GetProcessHandle();



Home:
    sys.Home();
    //------------------------- Player Hacks
    cout << "\n\n" << purple << "Player Hacks:\n\n" << blue;

    // Max Health Hack
    cout << purple << "[";
    if (LastPressedKey[0] == "VK_F1") {
        cout << green << "F1" << purple;
        MaxHealthHackIsOn = true;
    }
    else {
        cout << red << "F1" << purple;
        MaxHealthHackIsOn = false;
    }
    cout << "]" << darkpurple << " - " << blue << "Max Health " << white << " >>-";
    if (MaxHealthHackIsOn == true) {
        cout << green << "True" << white << "-<<                                                                             " << white << "<" << darkred << "0x" << green << hex << HealthAddress << white << ">" << endl;
    }
    else if (MaxHealthHackIsOn == false) {
        cout << red << "False" << white << "-<<                                                                            " << white << "<" << darkred << "0x" << darkred << hex << HealthAddress << white << ">" << endl;
    }
    
    //------------------------- Movement Hacks
    cout << endl << purple << "Movement Hacks:" << endl << endl;

    // BHOP hack
    cout << purple << "[";
    if (LastPressedKey[3] == "VK_F3") {
        cout << green << "F3" << purple;
        BHOP = true;
    }
    else {
        cout << red << "F3" << purple;
        BHOP = false;
    }
    cout << "]" << darkpurple << " - " << blue << "Auto BHOP " << white << " >>-";
    if (BHOP == true) {
        cout << green << "True" << white << "-<<                                                                              " << white << "<" << darkred << "0x" << green << hex << HeightAxisAddress << white << ">" << endl;
    }
    else if (BHOP == false) {
        cout << red << "False" << white << "-<<                                                                             " << white << "<" << darkred << "0x" << darkred << hex << HeightAxisAddress << white << ">" << endl;
    }

    // Strafe
    /*
    cout << purple << "[";
    if (LastPressedKey[4] == "VK_F4") {
        cout << green << "F4" << purple;
        Strafe = true;
    }
    else {
        cout << red << "F4" << purple;
        Strafe = false;
    }
    cout << "]" << darkpurple << " - " << blue << "Strafe " << white << " >>-";
    if (Strafe == true) {
        cout << green << "True" << white << "-<<" << endl;
    }
    else if (Strafe == false) {
        cout << red << "False" << white << "-<<" << endl;
    }
    */

    //------------------------- Weapon Hacks
    cout << endl << purple << "Weapon Hacks:" << endl << endl;

    // Infinate Assault Rife Magazine
    cout << purple << "[";
    if (LastPressedKey[1] == "VK_F5") {
        cout << green << "F5" << purple;
        InfinateMagAmmo = true;
    }
    else {
        cout << red << "F5" << purple;
        InfinateMagAmmo = false;
    }
    cout << "]" << darkpurple << " - " << blue << "Infinate Rifle Magazine Ammo " << white << " >>-";
    if (InfinateMagAmmo == true) {
        cout << green << "True" << white << "-<<                                                           " << white << "<" << darkred << "0x" << green << hex << RifleMagAddress << white << ">" << endl;
    }
    else if (InfinateMagAmmo == false) {
        cout << red << "False" << white << "-<<                                                          " << white << "<" << darkred << "0x" << darkred << hex << RifleMagAddress << white << ">" << endl;
    }
    
    // Infinate Grenades
    cout << purple << "[";
    if (LastPressedKey[2] == "VK_F8") {
        cout << green << "F8" << purple;
        InfinateGrenades = true;
    }
    else {
        cout << red << "F8" << purple;
        InfinateGrenades = false;
    }
    cout << "]" << darkpurple << " - " << blue << "Infinate Grenades " << white << " >>-";
    if (InfinateGrenades == true) {
        cout << green << "True" << white << "-<<                                                                      " << white << "<" << darkred << "0x" << green << hex << GrenadesAddress << white << ">" << endl;
    }
    else if (InfinateGrenades == false) {
        cout << red << "False" << white << "-<<                                                                     " << white << "<" << darkred << "0x" << darkred << hex << GrenadesAddress << white << ">" << endl;
    }


    // checking if display should refresh and enabling hacks that should be enabled via multithreading
    while (true)
    {
        // Hack execution per process loop
        if (MaxHealthHackIsOn) {
            ReadProcessMemory(HProc, (LPVOID)HealthAddress, &CurrentHealth, sizeof(int), 0);
            if (CurrentHealth < MaxHealth) {
                WriteProcessMemory(HProc, (LPVOID)HealthAddress, &MaxHealth, sizeof(int), 0);
            }
        }
        if (InfinateMagAmmo) {
            ReadProcessMemory(HProc, (LPVOID)RifleMagAddress, &CurrentRifleMag, sizeof(int), 0);
            if (CurrentRifleMag < MaxRifleMag) {
                WriteProcessMemory(HProc, (LPVOID)RifleMagAddress, &MaxRifleMag, sizeof(int), 0);
            }
        }
        if (InfinateGrenades) {
            ReadProcessMemory(HProc, (LPVOID)GrenadesAddress, &CurrentGrenades, sizeof(int), 0);
            if (CurrentGrenades < MaxGrenades) {
                WriteProcessMemory(HProc, (LPVOID)GrenadesAddress, &MaxGrenades, sizeof(int), 0);
            }
        }
        if (BHOP) {
            ReadProcessMemory(HProc, (LPVOID)HeightAxisAddress, &LastPlayerHeight, sizeof(LastPlayerHeight), 0);
            if (Loopeds[0] >= 40) {
                ReadProcessMemory(HProc, (LPVOID)HeightAxisAddress, &PlayerHeight, sizeof(PlayerHeight), 0);
                if (Loopeds[1] == 1 && BHOP) {
                    keybd_event(0x20, 0, KEYEVENTF_KEYUP, 0);
                    Loopeds[1] = 0;
                }
                if (LastPlayerHeight == PlayerHeight && BHOP) {
                    keybd_event(0x20, 0, KEYEVENTF_EXTENDEDKEY, 0);
                    Loopeds[1]++;
                    WriteProcessMemory(HProc, (LPVOID)HealthAddress, (LPVOID)(CurrentHealth + 1), sizeof(CurrentHealth), 0);
                    Loopeds[0] = 0;
                }
            }
                Loopeds[0]++;
        }
        //if (Strafe)
        //{
        //    
        //}

        // Key press checks

        if (GetKeyState(VK_F1) && LastPressedKey[0] != "VK_F1") {
            ShouldRefresh = true;
            LastPressedKey[0] = "VK_F1";
        }
        else if (GetKeyState(VK_F5) && LastPressedKey[1] != "VK_F5") {
            ShouldRefresh = true;
            LastPressedKey[1] = "VK_F5";
        }
        else if (GetKeyState(VK_F8) && LastPressedKey[2] != "VK_F8") {
            ShouldRefresh = true;
            LastPressedKey[2] = "VK_F8";
        }
        else if (GetKeyState(VK_F3) && LastPressedKey[3] != "VK_F3") {
            ShouldRefresh = true;
            LastPressedKey[3] = "VK_F3";
        }
        //else if (GetKeyState(VK_F4) && LastPressedKey[4] != "VK_F4") {
         //   ShouldRefresh = true;
         //   LastPressedKey[4] = "VK_F4";
        //}

        //

        if (!GetKeyState(VK_F1) && LastPressedKey[0] == "VK_F1") {
            ShouldRefresh = true;
            LastPressedKey[0] = "NULL";
        }
        else if (!GetKeyState(VK_F5) && LastPressedKey[1] == "VK_F5") {
            ShouldRefresh = true;
            LastPressedKey[1] = "NULL";
        }
        else if (!GetKeyState(VK_F8) && LastPressedKey[2] == "VK_F8") {
            ShouldRefresh = true;
            LastPressedKey[2] = "NULL";
        }
        else if (!GetKeyState(VK_F3) && LastPressedKey[3] == "VK_F3") {
            ShouldRefresh = true;
            LastPressedKey[3] = "NULL";
        }
        //else if (!GetKeyState(VK_F4) && LastPressedKey[4] == "VK_F4") {
        //    ShouldRefresh = true;
        //    LastPressedKey[4] = "NULL";
        //}

        // if the screen should refresh

        if (ShouldRefresh)
        {
            ShouldRefresh = false;
            goto Home;
        }
        continue;
    }
}
