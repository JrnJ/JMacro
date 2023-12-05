#include <iostream>
#include <vector>

#include <Windows.h>
#include <WinUser.h>

#include "JMacro.hpp"
#include "Screenshot.hpp"

int main()
{
	std::cout << "Macro away!" << std::endl;

	int temp = 244;

	bool keyDown = false;
	bool toggle = false;

	while (true)
	{
		// Alt
		if ((GetAsyncKeyState(VK_SHIFT) & 0x8000) != 0)
		{
			if (!keyDown)
			{
				keyDown = true;

				JMacro::Keystroke(KeyCode::W);
				JMacro::Keystroke(KeyCode::W);

				JMacro::Keystroke(KeyCode::S);
				JMacro::Keystroke(KeyCode::S);
				JMacro::Keystroke(KeyCode::S);
				JMacro::Keystroke(KeyCode::S);
				JMacro::Keystroke(KeyCode::S);

				JMacro::Keystroke(KeyCode::W);
				JMacro::Keystroke(KeyCode::W);
				JMacro::Keystroke(KeyCode::W);
				JMacro::Keystroke(KeyCode::W);

				JMacro::Keystroke(KeyCode::D);
				JMacro::Keystroke(KeyCode::D);

				JMacro::Keystroke(KeyCode::W);
				JMacro::Keystroke(KeyCode::W);

				JMacro::Keystroke(KeyCode::S);
				JMacro::Keystroke(KeyCode::S);

				JMacro::Keystroke(KeyCode::D);
				JMacro::Keystroke(KeyCode::D);
				JMacro::Keystroke(KeyCode::D);
				JMacro::Keystroke(KeyCode::D);

				JMacro::Keystroke(KeyCode::A);
				JMacro::Keystroke(KeyCode::A);

				JMacro::Keystroke(KeyCode::S);
				JMacro::Keystroke(KeyCode::S);

				JMacro::Keystroke(KeyCode::D);
				JMacro::Keystroke(KeyCode::D);

				JMacro::Keystroke(KeyCode::S);
				JMacro::Keystroke(KeyCode::S);
				JMacro::Keystroke(KeyCode::S);

				JMacro::Keystroke(KeyCode::W);
				JMacro::Keystroke(KeyCode::W);
				JMacro::Keystroke(KeyCode::W);

				JMacro::Keystroke(KeyCode::D);

				JMacro::Keystroke(KeyCode::W);

				JMacro::Keystroke(KeyCode::D);
				JMacro::Keystroke(KeyCode::D);
				JMacro::Keystroke(KeyCode::D);

				JMacro::Keystroke(KeyCode::W);

				JMacro::Keystroke(KeyCode::D);

				JMacro::Keystroke(KeyCode::D);
				JMacro::Keystroke(KeyCode::W);
				JMacro::Keystroke(KeyCode::S);

				JMacro::Keystroke(KeyCode::D);
				JMacro::Keystroke(KeyCode::A);

				JMacro::Keystroke(KeyCode::S);
				JMacro::Keystroke(KeyCode::S);
				JMacro::Keystroke(KeyCode::S);


				//JMacro::KeyDown(KeyCode::LeftCtrl);
				//Sleep(40);
				//JMacro::KeyDown(KeyCode::Tilde);
				//Sleep(200);
				//JMacro::KeyUp(KeyCode::Tilde);
				//Sleep(40);
				//JMacro::KeyUp(KeyCode::LeftCtrl);
				//std::cout << "Aha" << std::endl;
				

				/*JMacro::MouseInput(MouseButton::RightMouse);
				Sleep(100);
				JMacro::SetMousePos(860, 350);
				Sleep(100);
				JMacro::KeyDown(KeyCode::LeftShift);
				Sleep(100);
				JMacro::MouseInput(MouseButton::LeftMouse);
				Sleep(100);
				JMacro::KeyUp(KeyCode::LeftShift);*/
				// Paste Macro Below

				//for (int i = 0; i < 250; i++)
				//{
				//	/* Preperations
				//	* ctrl + shift + i opens inspector
				//	* Elements Tab
				//	* Resize inspector to 765x929
				//	* 
				//	* Put the chrome window on your main screen
				//	* Open a notepad
				//	* Have windows make it 1/4 of the screen (top-right) of second monitor
				//	* Save a file to the folder where you want it to be, then delete the file
				//	*/

				//	// Load Page
				//	JMacro::SetMousePos(760, 1010);

				//	for (int j = 0; j < 6; j++)
				//	{
				//		JMacro::MouseInput(MouseButton::LeftMouse);
				//		Sleep(20);
				//	}

				//	// Copy Page
				//	JMacro::SetMousePos(1250, 165);
				//	Sleep(10);
				//	JMacro::MouseInput(MouseButton::LeftMouse);
				//	Sleep(10);

				//	JMacro::KeyDown(KeyCode::LeftCtrl);
				//	Sleep(10);
				//	JMacro::KeyDown(KeyCode::C);
				//	Sleep(10);
				//	JMacro::KeyUp(KeyCode::C);
				//	Sleep(10);
				//	JMacro::KeyUp(KeyCode::LeftCtrl);
				//	Sleep(10);

				//	JMacro::SetMousePos(-420, 320);
				//	JMacro::MouseInput(MouseButton::LeftMouse);

				//	JMacro::KeyDown(KeyCode::LeftCtrl);
				//	Sleep(10);
				//	JMacro::KeyDown(KeyCode::A);
				//	Sleep(10);
				//	JMacro::KeyUp(KeyCode::A);
				//	Sleep(10);
				//	JMacro::KeyUp(KeyCode::LeftCtrl);
				//	Sleep(10);

				//	JMacro::KeyDown(KeyCode::LeftCtrl);
				//	Sleep(10);
				//	JMacro::KeyDown(KeyCode::V);
				//	Sleep(10);
				//	JMacro::KeyUp(KeyCode::V);
				//	Sleep(10);
				//	JMacro::KeyUp(KeyCode::LeftCtrl);
				//	Sleep(10);

				//	JMacro::KeyDown(KeyCode::LeftCtrl);
				//	Sleep(10);
				//	JMacro::KeyDown(KeyCode::LeftShift);
				//	Sleep(10);
				//	JMacro::KeyDown(KeyCode::S);
				//	Sleep(10);
				//	JMacro::KeyUp(KeyCode::S);
				//	Sleep(10);
				//	JMacro::KeyUp(KeyCode::LeftShift);
				//	Sleep(10);
				//	JMacro::KeyUp(KeyCode::LeftCtrl);
				//	Sleep(10);

				//	Sleep(1000);
				//	std::string filename = "p";
				//	filename += std::to_string(temp);
				//	JMacro::TypeText(filename);
				//	temp++;
				//	Sleep(1000);

				//	JMacro::Keystroke(KeyCode::Enter);
				//	Sleep(1000);

				//	JMacro::SetMousePos(760, 55);
				//	JMacro::MouseInput(MouseButton::LeftMouse);
				//	Sleep(5);
				//	JMacro::MouseInput(MouseButton::LeftMouse);
				//	Sleep(5);
				//	JMacro::TypeText(std::to_string(temp));
				//	Sleep(10);
				//	JMacro::Keystroke(KeyCode::Enter);
				//	Sleep(1500);
				//}

				// Till Here
			}
			else keyDown = false;
		}
	}
}