#include "GUIButton.h"

//Padding is used here to add a touch more area between the text and button.
GUIButton::GUIButton() : padding(0.0f) {
}

GUIButton::~GUIButton() {
}

void GUIButton::initialise(std::string text) {
}

void GUIButton::sendGUIRenderingInformation(void * renderer) {
}

void GUIButton::setPosition(float x, float y) {
	this->x = x;
	this->y = y;
}

std::array<float, 2> GUIButton::getSize() {
	return GUIObjectBase::getSize();
}

//Concrete class implementation
/*#include "GUIButton.h"

GUIButton::GUIButton() : padding(Unit(0.001)) {
}


GUIButton::~GUIButton() {
}

void GUIButton::initialise(std::string text) {
	buttonText.intialise(FontAsset::getFont("ralewaymed.ttf", 96), text, 0, 0, 0.95f, 0, 0, 0.2f, 0.040f, Colour(0, 0, 0, 255));
	buttonText.setScaleToHeight(true);
	buttonText.setForceRender();

	buttonTexture.intialise(TextureAsset::getTexture("1479649267222.png"), 0, 0, 0.90f, 0, 0, buttonText.getWidth(), buttonText.getHeight(), Colour(255, 255, 255, 255));
}

void GUIButton::sendGUIRenderingInformation(RenderingEngine * renderer) {
	buttonTexture.sendRenderInformation(renderer);
	buttonText.sendRenderInformation(renderer);
}

void GUIButton::setPosition(Unit x, Unit y) {
	this->x = x;
	this->y = y;
	buttonText.setCenter(x, y);
	buttonTexture.setCenter(x, y);
}

std::array<Unit, 2> GUIButton::getSize() {
	halfWidth = (buttonText.getWidth().meter / 2.0f) + padding.meter + padding.meter;
	halfHeight = (buttonText.getHeight().meter / 2.0f) + padding.meter + padding.meter;

	buttonTexture.setSize(halfWidth + halfWidth, halfHeight + halfHeight);

	return GUIObjectBase::getSize();
}
*/