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

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMesag, WPARAM wparam, LPARAM lparam);

class Window {
public:
	Window();
	Window(const Window&) = delete;
	Window& operator = (const Window&) = delete;
	~Window();

	bool processMsg();
private:
	HINSTANCE m_hinst;
	HWND m_Hwnd;
};