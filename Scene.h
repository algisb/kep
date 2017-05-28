#pragma once

#include <glm.hpp>
#include <gtc/matrix_transform.hpp> 
#include <gtc/type_ptr.hpp> 

#include <fstream>
#include <string>
#include <iostream>

#include <SDL.h>
#include <SDL_image.h>
#include "InputManager.h"
#include "Mesh.h"
#include "GameObject.h"
#include "Component.h"
#include "ShaderManager.h"
#include "Light.h"
#include "EventHandler.h"
#include "Particle.h"
#include "PfGen.h"
#define CAM_SPEED 10.0f

class Scene
{
public:
	unsigned int vertexTotal = 0;
	unsigned int faceTotal = 0;
	Scene(SDL_Window *_window, int _winWidth, int _winHeight, InputManager * _inputManager, EventHandler * _eventHandler);
	~Scene();

	void InputInit();

	void Update(float _deltaTs);
	void Draw();
	

protected:
	//frame time gap
	float deltaTs;
	float particleTs;
	InputManager * inputManager;
	EventHandler * eventHandler;
	//stores all object that are drawn every frame
	vector<GameObject*> gameObjects;
	vector<GameObject*> particles;
	//exclusive gameObject referances (need to be accesses in the update loop)

	GameObject * cube[10];
	GameObject * sphere[10];
	GameObject * plane[10];
	GameObject * empty[10];
    Kep::Particle * part;
    Kep::ParticleForceRegistry * pfr;
    Kep::ParticleGravity * pgg;

	vector<Light*> lightObjects;

	//window setting
	SDL_Window *window;
	int winWidth;
	int winHeight;
	//mouse settings
	int mX;
	int mY;
	glm::vec2 mPosNew;
	glm::vec2 mPosOld;
	//cell which the mouse is hovered over

	//models in scene
	Mesh * _cube;
	Mesh * _plane;
	Mesh * _cylinder; 
	Mesh * _sphere;
    GenMesh * _navMesh; 
    
	MeshLine _line;
	MeshPoint _point;
	MeshCircle _circle;

	//camera settigns
	Camera * _mainCam;


	GLuint _texture;//<-------------
	GLuint _texture1;
	GLuint _texture2;
	GLuint _texture3;
	GLuint _texture4;
	GLuint _texture5;


	GLuint _baka;


	//shader programs
	ShaderProgram * shaderProgram;
	ShaderProgram * shaderProgramSimple;
	//shader locations

	////////////////////////////////////////////////////////////////////

	//===========================METHODS=======================================
	void LoadTexture(std::string filename, GLuint  &texLocation);
	void LoadTextureA(std::string filename, GLuint  &texLocation);
	void BuildFBO(GLuint &_fbo, GLuint &_texAtt);
	void renderText(GLuint &texLocation, char * message, char * fontFile, SDL_Color color, int fontSize);
	
};
