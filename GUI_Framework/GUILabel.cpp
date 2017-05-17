#include "GUILabel.h"

GUILabel::GUILabel() {
}

GUILabel::~GUILabel() {
}

void GUILabel::initialise(std::string text, float textHeight, float edgePadding) {

	this->padding = edgePadding;
}

void GUILabel::sendGUIRenderingInformation(void * renderer) {
}

void GUILabel::setPosition(float x, float y) {
	this->x = x;
	this->y = y;
}

std::array<float, 2> GUILabel::getSize() {
	return GUIObjectBase::getSize();
}

//more concrete
/*#include "GUILabel.h"

GUILabel::GUILabel() {
}


GUILabel::~GUILabel() {
}

void GUILabel::initialise(std::string text, Unit textHeight, Unit edgePadding) {
	label.intialise(FontAsset::getFont("ralewaymed.ttf", 96), text, 0, 0, 0.95f, 0, 0, 0.2f, textHeight, Colour(255, 255, 255, 255));
	label.setScaleToHeight(true);
	label.setForceRender();

	this->padding = edgePadding;
}

void GUILabel::sendGUIRenderingInformation(RenderingEngine * renderer) {
	label.sendRenderInformation(renderer);
}

void GUILabel::setPosition(Unit x, Unit y) {
	this->x = x;
	this->y = y;
	label.setCenter(x, y);
}

std::array<Unit, 2> GUILabel::getSize() {
	halfWidth = (label.getWidth().meter / 2.0f) + padding.meter + padding.meter;
	halfHeight = (label.getHeight().meter / 2.0f) + padding.meter + padding.meter;

	return GUIObjectBase::getSize();
}
*/