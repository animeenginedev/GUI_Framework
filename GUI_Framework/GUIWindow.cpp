#include "GUIWindow.h"

GUIWindow::GUIWindow() {
}

GUIWindow::~GUIWindow() {
	destroyChild();
}

void GUIWindow::update(float deltaSeconds) {
	child->getSize();
	child->setPosition(x, y);

	GUIInteractionStruct interactionData = GUIInteractionStruct();

	//this is where you phrase inputm you'll need to use your own facilities to do this.
	/*auto mousePos = InputManager::getMouseLocation();
	auto realMousePos = camera->convertScreenToWorld(Unit().setAsPixel(mousePos.x), Unit().setAsPixel(mousePos.y));
	interactionData.mouseX = realMousePos[0];
	interactionData.mouseY = realMousePos[1];

	interactionData.leftMouseJustDown = InputManager::isMouseJustDown(SDL_BUTTON_LEFT);
	interactionData.leftMouseRelease = InputManager::isMouseJustUp(SDL_BUTTON_LEFT);
	interactionData.rightMouseJustDown = InputManager::isMouseJustDown(SDL_BUTTON_RIGHT);
	interactionData.rightMouseRelease = InputManager::isMouseJustUp(SDL_BUTTON_RIGHT);*/
	
	child->updateGUI(interactionData);
}

void GUIWindow::sendGUIRenderingInformation(void * renderer) {
	child->sendGUIRenderingInformation(renderer);
}

void GUIWindow::setChild(GUIBox * obj) {
	child = obj;
	obj->setParent(this);
}

void GUIWindow::destroyChild() {
	delete child;
}

std::array<float, 2> GUIWindow::getSize() {
	return child->getSize();
}

bool GUIWindow::isGUIWindow() {
	return true;
}

void GUIWindow::updateGUI(GUIInteractionStruct interactionData) {
}

/* I've also included my concrete implementation of the inside of my window class.
#include "GUIWindow.h"

#include "InputManager.h"
#include <SDL2\SDL_mouse.h>

#include "GUIInteraction.h"
#include "TextureAsset.h"

GUIWindow::GUIWindow() : Object(false, true, true, false) {
background.intialise(TextureAsset::getTexture("152301-5.jpg"), 0, 0, 0.75f, 0, 0, 0, 0, Colour(255, 255, 255, 255));
}

GUIWindow::~GUIWindow() {
destroyChild();
}

void GUIWindow::concurrentUpdate(float deltaSeconds) {}

void GUIWindow::serialUpdate(float deltaSeconds) {
child->getSize();
child->setPosition(x, y);

GUIInteractionStruct interactionData = GUIInteractionStruct();

auto mousePos = InputManager::getMouseLocation();
auto realMousePos = camera->convertScreenToWorld(Unit().setAsPixel(mousePos.x), Unit().setAsPixel(mousePos.y));
interactionData.mouseX = realMousePos[0];
interactionData.mouseY = realMousePos[1];

interactionData.leftMouseJustDown = InputManager::isMouseJustDown(SDL_BUTTON_LEFT);
interactionData.leftMouseRelease = InputManager::isMouseJustUp(SDL_BUTTON_LEFT);
interactionData.rightMouseJustDown = InputManager::isMouseJustDown(SDL_BUTTON_RIGHT);
interactionData.rightMouseRelease = InputManager::isMouseJustUp(SDL_BUTTON_RIGHT);

background.setCenter(x, y);
background.setSize(child->getHalfSize()[0] * 2.0f, child->getHalfSize()[1] * 2.0f);

child->updateGUI(interactionData);
}

void GUIWindow::sendRenderingInformation(RenderingEngine * renderer) {
background.sendRenderInformation(renderer);
child->sendGUIRenderingInformation(renderer);
}

void GUIWindow::sendGUIRenderingInformation(RenderingEngine * renderer) {
sendRenderingInformation(renderer);
}

void GUIWindow::setChild(GUIBox * obj) {
child = obj;
obj->setParent(this);
}

void GUIWindow::destroyChild() {
delete child;
}

std::array<Unit, 2> GUIWindow::getSize() {
return child->getSize();
}

bool GUIWindow::isGUIWindow() {
return true;
}

void GUIWindow::updateGUI(GUIInteractionStruct interactionData) {
}

void GUIWindow::setCamera(OrthographicCamera * camera) {
this->camera = camera;
}

*/