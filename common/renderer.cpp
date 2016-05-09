#include <common/renderer.h>
#include <iostream>

Renderer::Renderer()
{
    window_width = 800;
    window_height = 600;

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

    // Open a window and create its OpenGL context
    _window = glfwCreateWindow(window_width, window_height, "Demo", NULL, NULL);
    if( _window == NULL ){
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
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

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

	projectionMatrix = glm::ortho(0.0f, (float)window_width, (float)window_height, 0.0f, 0.1f, 100.0f);

    return 0;
}

void Renderer::renderScene(Scene* scene)
{
	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Set model matrix and render the entity with the sprites in it.
	//modelMatrix = glm::mat4(1.0f);

	int size = scene->getChildList().size();
	std::vector<Entity*> entityList = scene->getChildList();

	// for each entity
	for (int i = 0; i < size; i++) {
		// multiply ModelMatrix for this child with the ModelMatrix of the parent (the caller of this method)
		// the first time we do this (for the root-parent), modelMatrix is identity.
		//modelMatrix *= this->_getModelMatrix(childList[i]);

		this->renderEntity(entityList[i]);
	}

	// Swap buffers
	glfwSwapBuffers(window());
}

void Renderer::renderEntity(Entity* entity)
{
	// Compute the ViewMatrix from keyboard and mouse input (see: camera.h/cpp)
	computeMatricesFromInputs(_window);

	glm::vec3 cursor = getCursor();
	//printf("(%f,%f)\n",cursor.x, cursor.y);

	glm::mat4 ViewMatrix = getViewMatrix(); // get from Camera (Camera position and direction)
	modelMatrix = glm::mat4(1.0f);

	// Use our shader
	glUseProgram(programID);

	// use spritepos for position
	glm::vec3 position = glm::vec3(entity->position.x, entity->position.y, 0.0f);
	glm::vec3 rotation = glm::vec3(0.0f, 0.0f, entity->rotation);
	glm::vec3 scale = glm::vec3(entity->scale.x, entity->scale.y, 0.0f);

	// Build the Model matrix
	glm::mat4 translationMatrix = glm::translate(modelMatrix, position);
	glm::mat4 rotationMatrix = glm::eulerAngleYXZ(0.0f, 0.0f, rotation.z);
	glm::mat4 scalingMatrix = glm::scale(glm::mat4(1.0f), scale);

	modelMatrix = translationMatrix * rotationMatrix * scalingMatrix;

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

}

//glm::mat4 Renderer::_getModelMatrix(Entity* entity)
//{
//	// OpenGL doesn't understand our Vector2. Make it glm::vec3 compatible.
//	glm::vec3 position = glm::vec3(entity->position.x, entity->position.y, 0.0f);
//	glm::vec3 rotation = glm::vec3(0.0f, 0.0f, entity->rotation);
//	glm::vec3 scale = glm::vec3(entity->scale.x, entity->scale.y, 1.0f);
//
//	// Build the Model matrix
//	glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), position);
//	glm::mat4 rotationMatrix = glm::eulerAngleYXZ(0.0f, 0.0f, rotation.z);
//	glm::mat4 scalingMatrix = glm::scale(glm::mat4(1.0f), scale);
//
//	glm::mat4 mm = translationMatrix * rotationMatrix * scalingMatrix;
//
//	return mm;
//}

void Renderer::renderLine(Line* line)
{
	//glm::vec4 colortest = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	glUniform4f(colorID, 1.0f, 0.0f, 0.0f, 1.0f);

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
	glDrawArrays(GL_LINE_LOOP, 0, 3); // Starting from vertex 0; 2 vertices total -> 1 line
	glDisableVertexAttribArray(vertexPosition_modelspaceID);
}
