#pragma once

#include "GUI_Interaction.h"
#include <array>

class GUIObjectBase {
public:
	GUIObjectBase();

	float getX();
	float getY();
	std::array<float, 2> getPosition();
	float getWidth();
	float getHeight();
	virtual std::array<float, 2> getSize();
	std::array<float, 2> getHalfSize();
	virtual void setPosition(float x, float y);
	virtual void updateGUI(GUIInteractionStruct interactionData);

	void setMinimumSize(float width, float height);
	std::array<float, 2> getMinimumSize();

	virtual bool isGUIWindow();
	void setParent(GUIObjectBase* parent);

	//I personally have a rendering engine that parses all the information from the classes that overide this function.
	virtual void sendGUIRenderingInformation(void* renderer);
protected:
	float x, y;
	float halfWidth, halfHeight;

	float minimumHalfWidth, minimumHalfHeight;
	GUIObjectBase* parent;

	bool landsWithinBounds(float xPos, float yPos);
};