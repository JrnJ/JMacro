#include <iostream>

#include <Windows.h>

#include "JMacro.hpp"

int main()
{
	std::cout << "Macro away!" << std::endl;

	bool keyDown = false;
	bool toggle = false;
	
	while (true)
	{
		// Alt
		if ((GetAsyncKeyState(VK_NUMPAD7) & 0x8000) != 0)
		{
			if (!keyDown)
			{
				//keyDown = true;
				//JMacro::Keystroke(KeyCode::A);
				//JMacro::KeyDown(0x41);
				/*INPUT inputs;
				inputs.type = INPUT_KEYBOARD;

				inputs.ki.wScan = 0x3042;
				inputs.ki.time = 0;
				inputs.ki.dwExtraInfo = 0;
				inputs.ki.wVk = 0;
				inputs.ki.dwFlags = KEYEVENTF_UNICODE;
				SendInput(1, &inputs, sizeof(INPUT));*/

				/*toggle = !toggle;

				if (toggle)
					JMacro::MouseButtonDown(MOUSEEVENTF_LEFTDOWN);
				else
					JMacro::MouseButtonDown(MOUSEEVENTF_LEFTUP);*/

				JMacro::SetMousePos(666, 464);
				Sleep(250);
				JMacro::MouseInput(MouseButton::LeftMouse);
				Sleep(1000);

				JMacro::SetMousePos(615, 570);
				Sleep(250);
				JMacro::MouseInput(MouseButton::LeftMouse);
				Sleep(250);

				JMacro::SetMousePos(666, 700);
				Sleep(250);
				JMacro::MouseInput(MouseButton::LeftMouse);
				Sleep(250);
			}
		}
		else keyDown = false;
	}
}