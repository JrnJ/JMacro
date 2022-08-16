#ifndef JMACRO_HPP
#define JMACRO_HPP

#include <string>

enum class KeyCode
{
	// Numbers
	Alpha0, Alpha1, Alpha2, Alpha3, Alpha4, Alpha5, Alpha6, Alpha7, Alpha8, Alpha9,

	// Alphabet
	A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,

	// Special
	BackSlash, ForwardSlash, Space, Dot, Tilde,

	// Actions
	LeftShift, RightShift, LeftCtrl, RightCtrl, LeftAlt, RightAlt, Escape, Tab, Backspace, Enter, CapsLock,

	// Arrows
	ArrowUp, ArrowDown, ArrowLeft, ArrowRight,

	// F-Keys
	F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,
};

enum class MouseButton {
	// Left
	LeftMouse,

	// Right
	RightMouse,

	// Middle
	MiddleMouse,
};

enum class MouseEvent {
	LeftMouseDown, LeftMouseUp,

	RightMouseDown, RightMouseUp,

	MiddleMouseDown, MiddleMouseUp
};

namespace JMacro
{
	// Keyboard
	extern bool Keys[1024];
	extern bool PressedKeys[1024];

	// Get
	const bool GetKey(KeyCode key);
	const bool GetKeyDown(int key);
	const bool GetKeyUp(int key);

	// Set
	const void Keystroke(int key);
	const void KeyDown(int key);
	const void KeyUp(int key);

	// https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
	const void Keystroke(KeyCode key);
	const void KeyDown(KeyCode key);
	const void KeyUp(KeyCode key);
	const void TypeText(std::string text);

	// Mouse Input
	// Get

	// Set
	const void MouseInput(MouseButton button);
	const void MouseButtonDown(int button);
	const void MouseButtonUp(int button);
	const void SetMousePos(int x, int y);
};

#endif 
