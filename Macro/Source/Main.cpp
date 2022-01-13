#include <iostream>

#include <Windows.h>

#include "JMacro.hpp"

int main()
{
	std::cout << "Macro away!" << std::endl;

	bool keyDown = false;

	while (true)
	{
		// Alt
		if ((GetKeyState(VK_NUMPAD1) & 0x8000) != 0)
		{
			if (!keyDown)
			{
				keyDown = true;

				std::cout << "Starting Macro" << std::endl;

				JMacro::TypeText("AabBcCdD.>;:/?");
				
				std::cout << "Macro Finished" << std::endl;
			}
		}
		else keyDown = false;
	}
}