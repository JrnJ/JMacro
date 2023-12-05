#include "JMacro.hpp"

#include <Windows.h>

bool JMacro::Keys[1024];
bool JMacro::PressedKeys[1024];

const int KeyToValue(KeyCode key)
{
    switch (key)
    {
        // Numbers
    case KeyCode::Alpha0: return 0x30;
    case KeyCode::Alpha1: return 0x31;
    case KeyCode::Alpha2: return 0x32;
    case KeyCode::Alpha3: return 0x33;
    case KeyCode::Alpha4: return 0x34;
    case KeyCode::Alpha5: return 0x35;
    case KeyCode::Alpha6: return 0x36;
    case KeyCode::Alpha7: return 0x37;
    case KeyCode::Alpha8: return 0x38;
    case KeyCode::Alpha9: return 0x39;

        // Alphabet
    case KeyCode::A: return 0x41;
    case KeyCode::B: return 0x42;
    case KeyCode::C: return 0x43;
    case KeyCode::D: return 0x44;
    case KeyCode::E: return 0x45;
    case KeyCode::F: return 0x46;
    case KeyCode::G: return 0x47;
    case KeyCode::H: return 0x48;
    case KeyCode::I: return 0x49;
    case KeyCode::J: return 0x4A;
    case KeyCode::K: return 0x4B;
    case KeyCode::L: return 0x4C;
    case KeyCode::M: return 0x4D;
    case KeyCode::N: return 0x4E;
    case KeyCode::O: return 0x4F;
    case KeyCode::P: return 0x50;
    case KeyCode::Q: return 0x51;
    case KeyCode::R: return 0x52;
    case KeyCode::S: return 0x53;
    case KeyCode::T: return 0x54;
    case KeyCode::U: return 0x55;
    case KeyCode::V: return 0x56;
    case KeyCode::W: return 0x57;
    case KeyCode::X: return 0x58;
    case KeyCode::Y: return 0x58;
    case KeyCode::Z: return 0x5A;

        // Special
    case KeyCode::Backspace: return 0x08;
    case KeyCode::BackSlash: return 0xBF;
    case KeyCode::ForwardSlash: return 0xE2;
    case KeyCode::Dot: return 0xBE;
    case KeyCode::Tilde: return 0xC0;

        // Actions
    case KeyCode::Enter: return 0x0D;
    case KeyCode::LeftShift: return 0x10;
    case KeyCode::RightShift: return 0x10;
    case KeyCode::LeftCtrl: return 0x11;
    case KeyCode::RightCtrl: return 0x11;
    case KeyCode::Space: return 0x20;

        // F
    case KeyCode::F1:  return 0x70;
    case KeyCode::F2:  return 0x71;
    case KeyCode::F3:  return 0x72;
    case KeyCode::F4:  return 0x73;
    case KeyCode::F5:  return 0x74;
    case KeyCode::F6:  return 0x75;
    case KeyCode::F7:  return 0x76;
    case KeyCode::F8:  return 0x77;
    case KeyCode::F9:  return 0x78;
    case KeyCode::F10: return 0x79;
    case KeyCode::F11: return 0x7A;
    case KeyCode::F12: return 0x7B;

        // Key not found
    default:
        return 0x41;
    }
}

const int MouseEventToValue(MouseEvent mouseEvent)
{
    switch (mouseEvent)
    {
        // Left
    case MouseEvent::LeftMouseDown: return 0x0002;
    case MouseEvent::LeftMouseUp: return 0x0004;

        // Right
    case MouseEvent::RightMouseDown: return 0x0008;
    case MouseEvent::RightMouseUp: return 0x0010;

        // Middle
    case MouseEvent::MiddleMouseDown: return 0x0020;
    case MouseEvent::MiddleMouseUp: return 0x0040;
    }
}

const int ButtonToValue(MouseButton button, bool isDown)
{
    switch (button)
    {
        // Left
    case MouseButton::LeftMouse: return isDown ? MouseEventToValue(MouseEvent::LeftMouseDown) : MouseEventToValue(MouseEvent::LeftMouseUp);

        // Right
    case MouseButton::RightMouse: return isDown ? MouseEventToValue(MouseEvent::RightMouseDown) : MouseEventToValue(MouseEvent::RightMouseUp);

        // Middle
    case MouseButton::MiddleMouse: return isDown ? MouseEventToValue(MouseEvent::MiddleMouseDown) : MouseEventToValue(MouseEvent::MiddleMouseUp);
    }
}

const void JMacro::TypeText(std::string text)
{
    for (std::string::size_type i = 0; i < text.size(); i++)
    {
        Keystroke(text[i]);
    }
}

const void JMacro::Keystroke(int key)
{
    KeyDown(key);
    Sleep(10);
    KeyUp(key);
}

const void JMacro::KeyDown(int key)
{
    INPUT inputs{ 0 };
    inputs.type = INPUT_KEYBOARD;

    inputs.ki.wVk = 0;

    inputs.ki.wScan = key;
    inputs.ki.dwFlags = KEYEVENTF_UNICODE;

    inputs.ki.time = 0;
    inputs.ki.dwExtraInfo = 0;

    SendInput(1, &inputs, sizeof(INPUT));
}

const void JMacro::KeyUp(int key)
{
    INPUT inputs{ 0 };
    inputs.type = INPUT_KEYBOARD;

    inputs.ki.wVk = 0;

    inputs.ki.wScan = key;
    inputs.ki.dwFlags = KEYEVENTF_KEYUP;

    inputs.ki.time = 0;
    inputs.ki.dwExtraInfo = 0;

    SendInput(1, &inputs, sizeof(INPUT));
}

const void JMacro::Keystroke(KeyCode key)
{
    KeyDown(key);
    Sleep(20);
    KeyUp(key);
}

const void JMacro::KeyDown(KeyCode key)
{
    int wVk = KeyToValue(key);

    INPUT inputs{ 0 };
    inputs.type = INPUT_KEYBOARD;

    inputs.ki.wVk = wVk;

    inputs.ki.wScan = 0;
    inputs.ki.dwFlags = KEYEVENTF_UNICODE;

    inputs.ki.time = 0;
    inputs.ki.dwExtraInfo = 0;

    SendInput(1, &inputs, sizeof(INPUT));
}

const void JMacro::KeyUp(KeyCode key)
{
    int wVk = KeyToValue(key);

    INPUT inputs{ 0 };
    inputs.type = INPUT_KEYBOARD;

    inputs.ki.wVk = wVk;

    inputs.ki.wScan = 0;
    inputs.ki.dwFlags = KEYEVENTF_KEYUP;

    inputs.ki.time = 0;
    inputs.ki.dwExtraInfo = 0;

    SendInput(1, &inputs, sizeof(INPUT));
}

const bool JMacro::GetKeyDown(int key)
{
    return false;
}

const bool JMacro::GetKeyUp(int key)
{
    return false;
}

const bool JMacro::GetKey(KeyCode keycode)
{
    return false;

    int key = KeyToValue(keycode);

    if ((GetAsyncKeyState(key) & 0x8000) != 0)
    {
        if (!PressedKeys[key])
        {
            return true;
            PressedKeys[key] = true;
        }
    }
    else
    {
        return false;
    }
}

// Mouse //

const void JMacro::MouseInput(MouseButton button)
{
    MouseButtonDown(ButtonToValue(button, true));
    Sleep(20);
    MouseButtonUp(ButtonToValue(button, false));
}

const void JMacro::MouseButtonDown(int button)
{
    INPUT inputs{ 1 };
    inputs.type = INPUT_MOUSE;
    inputs.mi.dwFlags = button;
    SendInput(1, &inputs, sizeof(INPUT));
}

const void JMacro::MouseButtonUp(int button)
{
    INPUT inputs{ 1 };
    inputs.type = INPUT_MOUSE;
    inputs.mi.dwFlags = button;
    SendInput(1, &inputs, sizeof(INPUT));
}

const void JMacro::SetMousePos(int x, int y)
{
    SetCursorPos(x, y);
}

// Mouse //

// <Other> //
const std::string JMacro::GetClipBoardText()
{
    // Try opening the clipboard
    if (!OpenClipboard(nullptr))
    {

    }

    // Get handle of clipboard object for ANSI text
    HANDLE hData = GetClipboardData(CF_TEXT);
    if (hData == nullptr)
    {
        
    }

    // Lock the handle to get the actual text pointer
    char* pszText = static_cast<char*>(GlobalLock(hData));
    if (pszText == nullptr)
    {

    }

    // Save text in a string class instance
    std::string text(pszText);

    // Release the lock
    GlobalUnlock(hData);

    // Release the clipboard
    CloseClipboard();

    return text;
}
// </Other> //