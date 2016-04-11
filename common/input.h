#ifndef INPUT_H
#define INPUT_H

// Include GLFW
#include <glfw3.h>

class Input
{
	public:
		Input();
		virtual ~Input();

		void updateInput(GLFWwindow* window);

		// use int as an argument
		bool getKey(int key) { return _keys[key]; }
		// use a char as an argument
		bool getKey(char key) { return _keys[(int)key]; }

		// use int as an argument
		bool getKeyDown(int key) { return _keysDown[key]; }
		// use a char as an argument
		bool getKeyDown(char key) { return _keysDown[(int)key]; }

		// use int as an argument
		bool getKeyUp(int key) { return _keysUp[key]; }
		// use a char as an argument
		bool getKeyUp(char key) { return _keysUp[(int)key]; }

	private:
		GLFWwindow* _window;

		void _checkKey(int key);

		// make array of bools
		bool _keys[GLFW_KEY_LAST];
		bool _keysDown[GLFW_KEY_LAST];
		bool _keysUp[GLFW_KEY_LAST];
		
};

#endif /* INPUT_H */
