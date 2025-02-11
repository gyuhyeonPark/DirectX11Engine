#include "WindowContainer.h"

LRESULT WindowContainer::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	keyboard.EnableAutoRepeatKeys();
	switch (uMsg)
	{
		case WM_KEYDOWN:
		{
			unsigned char keycode = static_cast<unsigned char>(wParam);		// wParam == The Character code of the key

			if (keyboard.IsKeysAutoRepeat())
			{
				keyboard.OnKeyPressed(keycode);
			}
			else
			{
				const bool wasPressed = lParam & 0x40000000;
				if (!wasPressed)
				{
					keyboard.OnChar(keycode);
				}
			}
			break;
		}
		case WM_KEYUP:
		{
			unsigned char keycode = static_cast<unsigned char>(wParam);		// wParam == The Character code of the key
			keyboard.OnKeyReleased(keycode);
			break;
		}

		case WM_CHAR:
		{
			unsigned char ch = static_cast<unsigned char>(wParam);		// wParam == The Character code of the key
			if (keyboard.IsCharsAutoRepeat())
			{
				keyboard.OnChar(ch);
			}
			else
			{
				const bool wasPressed = lParam & 0x40000000;
				if (!wasPressed)
				{
					keyboard.OnChar(ch);
				}
			}
			break;
		}
		default:
			return DefWindowProc(hwnd, uMsg, wParam, lParam);
			break;
	}

}
