#include <iostream>
#include "input.h"

Input::Input()
{
	_window = NULL;

	// set every key to false
	for (int i = 0; i < GLFW_KEY_LAST; i++) {
		_keys[i] = false;
		_keysDown[i] = false;
		_keysUp[i] = false;
	}
}

Input::~Input()
{

}

void Input::updateInput(GLFWwindow* window)
{
	_window = window;

	// this wil check for updates on input, window, etc.
	glfwPollEvents(); 

	// 32-97 = ' ' to '`'
	for (int i = 32; i < 97; i++) {
		_checkKey(i);
	}
	// Func + arrows + esc, etc
	for (int i = 255; i < GLFW_KEY_LAST; i++) {
		_checkKey(i);
	}
}

void Input::_checkKey(int key)
{
	if (glfwGetKey(_window, key) == GLFW_PRESS) {
		if (_keys[key] == false) { // if first time pressed down
			_keys[key] = true;
			_keysDown[key] = true;
			//std::cout << "DOWN: " << key << std::endl;
		}
		else {
			// not the first time this is pressed
			// keys[key] is still true;
			_keysDown[key] = false;
		}
	}

	if (glfwGetKey(_window, key) == GLFW_RELEASE) {
		if (_keys[key] == true) { // still pressed
			_keys[key] = false;
			_keysUp[key] = true;
			//std::cout << "UP: " << key << std::endl;
		}
		else {
			// not the first time this is pressed
			// keys[key] is still false;
			_keysUp[key] = false;
		}
	}
}
