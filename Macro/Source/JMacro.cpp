#include "JMacro.hpp"

#include <Windows.h>

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
        case KeyCode::BackSlash: return 0xBF;
        case KeyCode::ForwardSlash: return 0xE2;

        // Actions
        case KeyCode::Enter: return 0x0D;
            
        // Key not found
        default:
            return 0x41;
    }
}
const int CharToValue(char key)
{
    switch (key)
    {
        // Numbers
        case '0': return 0x30;
        case '1': return 0x31;
        case '2': return 0x32;
        case '3': return 0x33;
        case '4': return 0x34;
        case '5': return 0x35;
        case '6': return 0x36;
        case '7': return 0x37;
        case '8': return 0x38;
        case '9': return 0x39;

        // Alphabet
        case 'a': return 0x41;
        case 'b': return 0x42;
        case 'c': return 0x43;
        case 'd': return 0x44;
        case 'e': return 0x45;
        case 'f': return 0x46;
        case 'g': return 0x47;
        case 'h': return 0x48;
        case 'i': return 0x49;
        case 'j': return 0x4A;
        case 'k': return 0x4B;
        case 'l': return 0x4C;
        case 'm': return 0x4D;
        case 'n': return 0x4E;
        case 'o': return 0x4F;
        case 'p': return 0x50;
        case 'q': return 0x51;
        case 'r': return 0x52;
        case 's': return 0x53;
        case 't': return 0x54;
        case 'u': return 0x55;
        case 'v': return 0x56;
        case 'w': return 0x57;
        case 'x': return 0x58;
        case 'y': return 0x58;
        case 'z': return 0x5A;

        // Special
        case '/': return 0xBF;
        case '\\': return 0xE2;
        case ' ': return 0x20;
        case '-': return 0xBD;

        // Key not found
        default:
            return 0x30;
    }
}

const void JMacro::Keystroke(KeyCode key)
{
    INPUT inputs;
    inputs.type = INPUT_KEYBOARD;
    inputs.ki.wScan = 0;
    inputs.ki.time = 0;
    inputs.ki.dwExtraInfo = 0;
    inputs.ki.wVk = KeyToValue(key);
    inputs.ki.dwFlags = 0;
    SendInput(1, &inputs, sizeof(INPUT));
    Sleep(10);

    inputs.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &inputs, sizeof(INPUT));

    return void();
}

const void JMacro::TypeText(std::string text)
{
    for (std::string::size_type i = 0; i < text.size(); i++) 
    {
        // Set Key Down
        INPUT inputs;
        inputs.type = INPUT_KEYBOARD;
        inputs.ki.wScan = 0;
        inputs.ki.time = 0;
        inputs.ki.dwExtraInfo = 0;
        inputs.ki.wVk = CharToValue(text[i]);
        inputs.ki.dwFlags = 0;
        SendInput(1, &inputs, sizeof(INPUT));
        Sleep(10);

        // Send Key Up
        inputs.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &inputs, sizeof(INPUT));
    }
}
