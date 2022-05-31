#include <iostream>
#include <vector>

#include <Windows.h>

#include "JMacro.hpp"

int main()
{
	std::cout << "Macro away!" << std::endl;

	bool num7Down = false;
	bool toggle = false;
	std::vector<POINT> points{};
	
	while (true)
	{
		// Alt
		if ((GetAsyncKeyState(0x31) & 0x8000) != 0)
		{
			if (!num7Down)
			{
				num7Down = true;

				POINT point;
				if (GetCursorPos(&point)) {
					points.push_back(point);
					JMacro::MouseInput(MouseButton::LeftMouse);
				}

				/*for (int i = 0; i < 20; i++) 
				{
					JMacro::SetMousePos(566, 427);
					JMacro::MouseInput(MouseButton::LeftMouse);
					Sleep(100);

					JMacro::SetMousePos(530, 407);
					JMacro::MouseInput(MouseButton::LeftMouse);
					Sleep(10);

					JMacro::SetMousePos(570, 510);
					JMacro::MouseInput(MouseButton::LeftMouse);
					Sleep(333);
				}*/

				
				
				std::cout << "Finished" << std::endl;
			}
		}
		else num7Down = false;

		bool num8Down = false;

		if ((GetAsyncKeyState(0x32) & 0x8000) != 0)
		{
			if (!num8Down)
			{
				num8Down = true;

				for (int i = 0; i < 10; i++)
				{
					JMacro::SetMousePos(points[0].x, points[0].y);
					Sleep(20);
					JMacro::MouseInput(MouseButton::LeftMouse);
					Sleep(100);

					JMacro::SetMousePos(points[1].x, points[1].y);
					Sleep(20);
					JMacro::MouseInput(MouseButton::LeftMouse);
					Sleep(50);

					JMacro::SetMousePos(points[2].x, points[2].y);
					Sleep(20);
					JMacro::MouseInput(MouseButton::LeftMouse);
					Sleep(500);
				}
			}
		}
		else num8Down = false;
	}
}