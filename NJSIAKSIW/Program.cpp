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

int main() {

	std::cout << "CREATING WINDOW...\n";

	Window* pWindow = new Window;

	bool running = true;
	while (running) {
		if(!pWindow->processMsg()){
			std::cout << "CLOSING WINDOW\n";
			running = false;
		}
		Sleep(10);
	}
	delete pWindow;
	pWindow = NULL;
	return 0;
}
