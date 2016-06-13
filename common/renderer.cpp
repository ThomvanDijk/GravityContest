#include <common/renderer.h>
#include <iostream>

Renderer::Renderer()
{
	// standard window size
	_window_width = 800;
    _window_height = 600;

	_fullscreen = true;

    fragment_shader	= "shaders/line.frag";
    vertex_shader	= "shaders/line.vert";

    this->init();
}

Renderer::~Renderer()
{
    // Cleanup VBO and shader
	glDeleteProgram(programID);
}

int Renderer::init()
{
    // Initialise GLFW
    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

	GLFWmonitor* primary = glfwGetPrimaryMonitor();

	// the video mode also returns width and height
	GLFWvidmode* mode = (GLFWvidmode*)glfwGetVideoMode(glfwGetPrimaryMonitor());

    // Open a window and create its OpenGL context
	// if fullscreen use the screens dimensions
	if (_fullscreen) {
		_window = glfwCreateWindow(mode->width, mode->height, "Gravity Fighters", primary, NULL);

		// change the default width and height for the rest of the renderer
		_window_width = mode->width;
		_window_height = mode->height;
	}
	else {
		_window = glfwCreateWindow(_window_width, _window_height, "Gravity Fighters", NULL, NULL);
	}

    if (_window == NULL) {
        fprintf( stderr, "Failed to open GLFW window.\n" );
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(_window);

    // Initialize GLEW
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        return -1;
    }

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(_window, GLFW_STICKY_KEYS, GL_TRUE);

    // background color
    glClearColor(0.0f, 0.5f, 0.0f, 0.0f);

    // Cull triangles which normal is not towards the camera
    glEnable(GL_CULL_FACE);

    // Create and compile our GLSL program from the shaders
    // see: shader.h/cpp
    programID = loadShaders(vertex_shader.c_str(), fragment_shader.c_str());

    // Get a handle for our buffers
    vertexPosition_modelspaceID = glGetAttribLocation(programID, "vertexPosition_modelspace");

	// Get a handle for our buffers
	colorID = glGetUniformLocation(programID, "color");

    // Get a handle for our "MVP" uniform
    matrixID = glGetUniformLocation(programID, "MVP");

	projectionMatrix = glm::ortho(0.0f, (float)_window_width, (float)_window_height, 0.0f, 0.1f, 100.0f);

    return 0;
}

void Renderer::renderScene(Scene* scene)
{
	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Set model matrix and render the entity with the sprites in it.
	modelMatrix = glm::mat4(1.0f);

	int size = scene->getChildList().size();
	std::vector<Entity*> entityList = scene->getChildList();

	// for each entity
	for (int i = 0; i < size; i++) {
		this->renderEntity(modelMatrix, entityList[i]);
	}

	// Swap buffers
	glfwSwapBuffers(window());
}

void Renderer::renderEntity(glm::mat4& modelMatrix, Entity* entity)
{
	// multiply ModelMatrix for this child with the ModelMatrix of the parent (the caller of this method)
	// the first time we do this (for the root-parent), modelMatrix is identity.
	modelMatrix *= this->_getModelMatrix(entity);

	// Compute the ViewMatrix from keyboard and mouse input (see: camera.h/cpp)
	computeMatricesFromInputs(_window);

	// get from Camera (Camera position and direction)
	glm::mat4 ViewMatrix = getViewMatrix(); 

	// Use our shader
	glUseProgram(programID);

	glm::mat4 MVP = projectionMatrix * ViewMatrix * modelMatrix;

	// Send our transformation to the currently bound shader,
	// in the "MVP" uniform
	glUniformMatrix4fv(matrixID, 1, GL_FALSE, &MVP[0][0]);

	int size = entity->getLineList().size();
	std::vector<Line*> lineList = entity->getLineList();

	// for each line
	for (int i = 0; i < size; i++) {
		this->renderLine(lineList[i]);
	}

	// Render all Children (recursively)
	std::vector<Entity*> children = entity->children();
	std::vector<Entity*>::iterator child;
	for (child = children.begin(); child != children.end(); child++) {
		// Transform child's children...
		this->renderEntity(modelMatrix, *child);
		// ...then reset modelMatrix for siblings to the modelMatrix of the parent.
		modelMatrix = this->_getModelMatrix((*child)->parent());
	}

}

glm::mat4 Renderer::_getModelMatrix(Entity* entity)
{
	// OpenGL doesn't understand our Vector2. Make it glm::vec3 compatible.
	glm::vec3 position = glm::vec3(entity->position.x, entity->position.y, 0.0f);
	glm::vec3 rotation = glm::vec3(0.0f, 0.0f, entity->rotation);
	glm::vec3 scale = glm::vec3(entity->scale.x, entity->scale.y, 1.0f);

	// Build the Model matrix
	glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), position);
	glm::mat4 rotationMatrix = glm::eulerAngleYXZ(0.0f, 0.0f, rotation.z);
	glm::mat4 scalingMatrix = glm::scale(glm::mat4(1.0f), scale);

	glm::mat4 mm = translationMatrix * rotationMatrix * scalingMatrix;

	return mm;
}

void Renderer::renderLine(Line* line)
{
	glm::vec4 color = line->getColor();
	glUniform4f(colorID, color.x, color.y, color.z, color.w); // the alfa channel is not working yet

	// attribute buffer : vertices
	glEnableVertexAttribArray(vertexPosition_modelspaceID);
	glBindBuffer(GL_ARRAY_BUFFER, line->vertexbuffer());

	glVertexAttribPointer(
		vertexPosition_modelspaceID,	// The attribute we want to configure
		3,								// size : x+y+z => 3
		GL_FLOAT,						// type
		GL_FALSE,						// normalized?
		0,								// stride
		(void*)0						// array buffer offset
	);

	// Draw the line!
	glDrawArrays(GL_LINE_LOOP, 0, line->getNumberOfPoints()); // Starting from vertex 0; 2 vertices total -> 1 line
	glDisableVertexAttribArray(vertexPosition_modelspaceID);
}
