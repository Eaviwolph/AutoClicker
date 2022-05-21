#include <Windows.h>
#include <iostream>

using namespace std;

int main()
{
    while (true)
    {
        Sleep(5);
        if (GetAsyncKeyState(VK_NUMPAD2))
        { // leftclick
            INPUT iNPUT = { 0 };
            iNPUT.type = INPUT_MOUSE;
            iNPUT.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
            SendInput(1, &iNPUT, sizeof(iNPUT));
            ZeroMemory(&iNPUT, sizeof(iNPUT));
            iNPUT.type = INPUT_MOUSE;
            iNPUT.mi.dwFlags = MOUSEEVENTF_LEFTUP;
            SendInput(1, &iNPUT, sizeof(iNPUT));
        }
        else if (GetAsyncKeyState(VK_NUMPAD0))
        { // Exit
            return 0;
        }
    }
}