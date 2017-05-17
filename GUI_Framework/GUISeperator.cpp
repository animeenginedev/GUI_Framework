#include "GUISeperator.h"

#include "GUIBox.h"

GUISeperator::GUISeperator() {
}

GUISeperator::~GUISeperator() {
}

void GUISeperator::initialise() {
}

void GUISeperator::sendGUIRenderingInformation(void * renderer) {
}

void GUISeperator::setPosition(float x, float y) {
	auto size = parent->getHalfSize();
	//You can always assume a parent is a box,  you should NEVER treat a window as just the parent of a seperator (Or any guiobject tbqh)
	auto alignment = dynamic_cast<GUIBox*>(parent)->getAlignment();
	auto padding = dynamic_cast<GUIBox*>(parent)->getPadding();
	if (alignment == HORIZONTAL) {
		//seperator.setByHeight(x, y, size[1] + size[1] - padding - padding);
	} else {
		//seperator.setByWidth(x, y, size[0] + size[0] - padding - padding);
	}
}

std::array<float, 2> GUISeperator::getSize() {
	return std::array<float, 2>{ 0, 0 };
}

//The concrete implementation fo r this is the most important. A simple line is just a line rendering glyph.
/*#include "GUISeperator.h"

#include "GUIBox.h"

GUISeperator::GUISeperator() {
}

GUISeperator::~GUISeperator() {
}

void GUISeperator::initialise(Colour c) {
	seperator.initialise(0, 0, 0, 0, 0.95, c);
}

void GUISeperator::sendGUIRenderingInformation(RenderingEngine * renderer) {
	seperator.sendRenderInformation(renderer);
}

void GUISeperator::setPosition(Unit x, Unit y) {
	auto size = parent->getHalfSize();
	auto alignment = dynamic_cast<GUIBox*>(parent)->getAlignment();
	auto padding = dynamic_cast<GUIBox*>(parent)->getPadding();
	if (alignment == HORIZONTAL) {
		seperator.setByHeight(x, y, size[1] + size[1] - padding - padding);
	} else {
		seperator.setByWidth(x, y, size[0] + size[0] - padding - padding);
	}
}

std::array<Unit, 2> GUISeperator::getSize() {
	return std::array<Unit, 2>({ 0, 0 });
}
*/