#include "GUIBox.h"

#include <cmath>

GUIBox::GUIBox(GUI_Alignment alignment, float padding) : alignment(alignment), padding(padding), bExteriorPadding(true) {
}

GUIBox::~GUIBox() {
	destroyChildren();
}

void GUIBox::packFront(GUIObjectBase * object) {
	objects.push_front(object);
	object->setParent(this);
}

void GUIBox::packBack(GUIObjectBase * object) {
	objects.push_back(object);
	object->setParent(this);
}

GUIObjectBase * GUIBox::removeFront() {
	if (objects.size() == 0)
		return nullptr;

	auto front = objects.front();
	objects.pop_front();

	return front;
}

GUIObjectBase * GUIBox::removeBack() {
	if (objects.size() == 0)
		return nullptr;

	auto back = objects.back();
	objects.pop_back();

	return back;
}

void GUIBox::destroyChildren() {
	for (GUIObjectBase* child : objects) {
		delete child;
	}
	objects.clear();
}

void GUIBox::setPadding(float padding) {
	this->padding = padding;
}

float GUIBox::getPadding() {
	return padding;
}

GUI_Alignment GUIBox::getAlignment() {
	return alignment;
}

void GUIBox::setPosition(float x, float y) {
	this->x = x;
	this->y = y;

	float runningX = x; 
	float runningY = y;

	if (alignment == HORIZONTAL) {
		runningX = x - halfWidth;
		if (!bExteriorPadding)
			runningX = runningX - padding;
	}
	if (alignment == VERTICAL) {
		runningY = y + halfHeight;
		if (!bExteriorPadding)
			runningY = runningY + padding;
	}

	for (auto child : objects) {
		auto childSize = child->getHalfSize();
		if (alignment == HORIZONTAL) {
			runningX = runningX + padding + childSize[0];
			child->setPosition(runningX, runningY);
			runningX = runningX + childSize[0];
		} else {
			runningY = runningY - padding - childSize[1];
			child->setPosition(runningX, runningY);
			runningY = runningY - childSize[1];
		}
	}
}

std::array<float, 2> GUIBox::getSize() {
	auto padding2 = padding + padding;
	halfWidth = 0;
	halfHeight = 0;
	for (auto child : objects) {
		auto childSize = child->getSize();
		if (alignment == HORIZONTAL) {
			halfWidth = halfWidth + childSize[0] + padding;
			halfHeight = fmax(halfHeight, childSize[1]);
		} else {
			halfHeight = halfHeight + childSize[1] + padding;
			halfWidth = fmax(halfWidth, childSize[0]);
		}
	}
	if (bExteriorPadding) {
		halfWidth = halfWidth + padding2;
		halfHeight = halfHeight + padding2;
	}
	if (alignment == HORIZONTAL) {
		halfWidth = halfWidth - padding;
	} else {
		halfHeight = halfHeight - padding;
	}

	halfWidth = (halfWidth) / 2.0f;
	halfHeight = (halfHeight) / 2.0f;

	return GUIObjectBase::getSize();
}

void GUIBox::updateGUI(GUIInteractionStruct interactionData) {
	for (auto child : objects) {
		child->updateGUI(interactionData);
	}
}

void GUIBox::sendGUIRenderingInformation(void * renderer) {
	for (auto c : objects)
		c->sendGUIRenderingInformation(renderer);
}

void GUIBox::setExteriorPadding(bool exteriorPadding) {
	this->bExteriorPadding = exteriorPadding;
}

bool GUIBox::hasExteriorPadding() {
	return bExteriorPadding;
}

