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
				std::cout << "Starting Macro" << std::endl;

				for (int i = 1; i < 4; i++)
				{
					for (int i2 = 1; i2 < 4; i2++)
					{
						int z = 0;
						if (i == 1)
							z = -64;
						if (i == 2)
							z = 192;
						if (i == 3)
							z = 704;

						int x = 0;
						if (i2 == 1)
							x = -64;
						if (i2 == 2)
							x = 448;
						if (i2 == 3)
							x = 960;

						// Teleport
						JMacro::Keystroke(KeyCode::BackSlash);
						Sleep(500);
						JMacro::TypeText("tp " + std::to_string(x) + " 200 " + std::to_string(z));
						Sleep(100);
						JMacro::Keystroke(KeyCode::Enter);
						Sleep(10000);

						for (int i3 = 1; i3 < 33; i3++)
						{
							int tempi3 = i3;
							if (i3 == 32)
							{
								tempi3 = 0;
							}
							// Send command
							JMacro::Keystroke(KeyCode::BackSlash);
							Sleep(500);

							JMacro::TypeText("function sm" + std::to_string(i) + "-" + std::to_string(i2) + "/" + std::to_string(tempi3 + 1));
							Sleep(100);
							JMacro::Keystroke(KeyCode::Enter);

							// Wait 3s for command to finish
							Sleep(1500);

							//std::cout << "function sm" + std::to_string(i) + "-" + std::to_string(i2) + "/" + std::to_string(i3 + 1) << std::endl;
						}
					}
				}
				
				std::cout << "Macro Finished" << std::endl;
			}
		}
		else keyDown = false;
	}
}