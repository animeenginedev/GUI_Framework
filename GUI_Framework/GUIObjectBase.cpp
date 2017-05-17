#include "GUIObjectBase.h"

#include <cmath>
#include <array>

GUIObjectBase::GUIObjectBase() {
}

float GUIObjectBase::getX() {
	return x;
}

float GUIObjectBase::getY() {
	return y;
}

std::array<float, 2> GUIObjectBase::getPosition() {
	return std::array<float, 2>{ x, y };
}

float GUIObjectBase::getWidth() {
	return halfWidth + halfWidth;
}

float GUIObjectBase::getHeight() {
	return halfHeight + halfHeight;
}

std::array<float, 2> GUIObjectBase::getSize() {
	halfWidth = fmax(halfWidth, minimumHalfWidth);
	halfHeight = fmax(halfHeight, minimumHalfHeight);
	return std::array<float, 2>{ halfWidth + halfWidth, halfHeight + halfHeight };
}

std::array<float, 2> GUIObjectBase::getHalfSize() {
	return std::array<float, 2>{ halfWidth, halfHeight };
}

void GUIObjectBase::setPosition(float x, float y) {
	this->x = x;
	this->y = y;
}

void GUIObjectBase::updateGUI(GUIInteractionStruct interactionData) {
}

void GUIObjectBase::setMinimumSize(float width, float height) {
	this->minimumHalfWidth = width / 2.0f;
	this->minimumHalfHeight = height / 2.0f;
}

std::array<float, 2> GUIObjectBase::getMinimumSize() {
	return std::array<float, 2>{ minimumHalfWidth * 2.0f, minimumHalfHeight * 2.0f };
}

bool GUIObjectBase::isGUIWindow() {
	return false;
}

void GUIObjectBase::setParent(GUIObjectBase * parent) {
	this->parent = parent;
}

void GUIObjectBase::sendGUIRenderingInformation(void * renderer) {
}

bool GUIObjectBase::landsWithinBounds(float xPos, float yPos) {
	return !(xPos > x + halfWidth ||
			 xPos < x - halfWidth ||
			 yPos < y - halfHeight ||
			 yPos > y + halfHeight);
}
