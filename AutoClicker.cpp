#include <Windows.h>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

int clickLoop()
{
    while (true)
    {
        Sleep(10);
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
    return 0;
}

int main()
{
    std::vector<std::thread> threads;
    for (int i = 0; i < 1; i++)
    {
        threads.push_back(std::thread(clickLoop));
    }

	for (auto& thread : threads)
	{
		thread.join();
	}
}