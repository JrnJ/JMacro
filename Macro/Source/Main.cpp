#include <iostream>
#include <vector>

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
				keyDown = true;

				for (int i = 0; i < 2; ++i)
				{
					JMacro::Keystroke(KeyCode::BackSlash);
					Sleep(20);
					JMacro::TypeText("kill Jeroen");
					Sleep(20);
					JMacro::Keystroke(KeyCode::Enter);

					Sleep(1000);
					JMacro::MouseInput(MouseButton::LeftMouse);

					Sleep(500);
					JMacro::Keystroke(KeyCode::BackSlash);
					Sleep(20);
					JMacro::TypeText("setblock ~ ~-1 ~ bedrock");
					Sleep(20);
					JMacro::Keystroke(KeyCode::Enter);
				}
			}
			else keyDown = false;
		}
	}
}