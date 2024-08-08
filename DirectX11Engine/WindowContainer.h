#pragma once
#include "RenderWindow.h"
#include "KeyboardClass.h"

class WindowContainer
{
private:

protected:
	RenderWindow render_window;
	KeyboardClass keyboard;
public:
	LRESULT WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	// WindowProc, KeyBoard, Mouse

};

