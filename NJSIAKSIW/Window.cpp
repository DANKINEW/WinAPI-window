#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <Windows.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include "Window.hpp"

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMesag, WPARAM wparam, LPARAM lparam)
{
	switch (uMesag) {
	case WM_CLOSE:

		DestroyWindow(hwnd);
		break;

	case WM_DESTROY:

		PostQuitMessage(0);
		return 0;
		break;

	}
	return DefWindowProc(hwnd, uMesag, wparam, lparam);
}

Window::Window() : m_hinst(GetModuleHandle(nullptr)){

	const wchar_t* CLASS_NAME = L"HELLO WINAPI";
	WNDCLASS wndClass = {};
	wndClass.lpszClassName = CLASS_NAME;
	wndClass.hInstance = m_hinst;
	wndClass.hCursor = LoadCursor(NULL, IDC_HAND);
	wndClass.hIcon = LoadIcon(NULL, IDI_WARNING);
	wndClass.lpfnWndProc = WndProc; //change later

	RegisterClass(&wndClass);

	DWORD style = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU;

	int width = 600;
	int height = 600;

	RECT rect;
	rect.left = 200;
	rect.top = 200;
	rect.right = rect.left + width;
	rect.bottom = rect.top + height;

	AdjustWindowRect(&rect, style, false);

	m_Hwnd = CreateWindowEx(
	
		0,
		CLASS_NAME,
		L"Window",
		style,
		rect.left,
		rect.top,
		rect.right - rect.left,
		rect.bottom - rect.top,
		NULL,
		NULL,
		m_hinst,
		NULL
	
	);

	ShowWindow(m_Hwnd, SW_SHOW);
}

Window::~Window() {

	const wchar_t* CLASS_NAME = L"HELLO WINAPI";
	UnregisterClass(CLASS_NAME, m_hinst);
}

bool Window::processMsg()
{
	MSG msg = {};

	while (PeekMessage(&msg, nullptr, 0u, 0u, PM_REMOVE)) {
		if (msg.message == WM_QUIT) {
			return false;
		}
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return true;
}


