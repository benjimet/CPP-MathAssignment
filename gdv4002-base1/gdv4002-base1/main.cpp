#include "Engine.h"

// Function prototypes

void myUpdate(GLFWwindow* window, double tDelta);


int main(void) {

	// Initialise the engine (create window, setup OpenGL backend)
	int initResult = engineInit("GDV4002 - Applied Maths for Games", 1024, 1024);

	// If the engine initialisation failed report error and exit
	if (initResult != 0) {

		printf("Cannot setup game window!!!\n");
		return initResult; // exit if setup failed
	}

	//
	// Setup game scene objects here
	//
	
	addObject("player");
	addObject("player2");

	GameObject2D* player1Object = getObject("player");


	if (player1Object != nullptr) {
		player1Object->position = glm::vec2(-1.0f, 1.0f);
		player1Object->orientation = glm::radians(45.0f);
		player1Object->textureID = loadTexture("Resources\\Textures\\bumblebee.png");

	}

	GameObject2D* player2Object = getObject("player2");

	if (player2Object != nullptr) {
		player2Object->position = glm::vec2(1.5f, 1.0f);
		player2Object->orientation = glm::radians(30.0f);
		player2Object->size = glm::vec2(3.0f, 3.0f);

	}



	// Enter main loop - this handles update and render calls
	setUpdateFunction(myUpdate);
	engineMainLoop();

	// When we quit (close window for example), clean up engine resources
	engineShutdown();

	// return success :)
	return 0;
}

void myUpdate(GLFWwindow* window, double tDelta) {
	GameObject2D* player = getObject("player");
	float anglesPerSecond = glm::radians(45.0f);
	float playerVelocity = 2.0f;
	float playerRotationSpeed = glm::radians(90.0f);
	player->orientation += playerRotationSpeed * tDelta;
	
}


