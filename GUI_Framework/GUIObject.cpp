#include "GUIObject.h"

GUIObject::GUIObject() {
}

GUIObject::~GUIObject() {
}

void GUIObject::updateGUI(GUIInteractionStruct interactionData) {

	bool wasInsideLast = landsWithinBounds(lastData.mouseX, lastData.mouseY);
	bool isInsideNow = landsWithinBounds(interactionData.mouseX, interactionData.mouseY);

	if (isInsideNow && interactionData.leftMouseJustDown)
		callFunction(MOUSE_LEFT_JUST_DOWN);
	if (isInsideNow && interactionData.rightMouseJustDown)
		callFunction(MOUSE_RIGHT_JUST_DOWN);
	if (isInsideNow && interactionData.leftMouseRelease)
		callFunction(MOUSE_LEFT_RELEASE);
	if (isInsideNow && interactionData.rightMouseRelease)
		callFunction(MOUSE_RIGHT_RELEASE);

	if (!wasInsideLast && isInsideNow)
		callFunction(MOUSE_HOVER_ENTER);
	if (wasInsideLast && !isInsideNow)
		callFunction(MOUSE_HOVER_LEAVE);

	lastData = interactionData;
}

void GUIObject::connectFunction(GUI_InteractionType type, std::function<void()> function) {
	functionCalls.erase(type);
	functionCalls.insert(std::make_pair(type, function));
}

void GUIObject::disconnectFunction(GUI_InteractionType type) {
	functionCalls.erase(type);
}

bool GUIObject::hasFunction(GUI_InteractionType type) {
	return functionCalls.find(type) != functionCalls.end();
}

void GUIObject::sendGUIRenderingInformation(void* renderer) {
}

void GUIObject::callFunction(GUI_InteractionType type) {
	auto it = functionCalls.find(type);
	if (it != functionCalls.end())
		it->second();
}