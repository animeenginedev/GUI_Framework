#pragma once

#include "GUIObjectBase.h"
#include "GUIObject.h"
#include "GUI_Interaction.h"
#include "GUI_Alignment.h"
#include <deque>

//honestly this is the most complicated piece of all the gui, it allows you to embed layers of boxes and objects within itself allowing you to create complex and ordered gui.
class GUIBox : public GUIObjectBase {
public:
	//You would want to change the default padding based on how you render the gameworld, it's left at zero for simplicity. (I reccomend ~15pixels) for a simple border thats not too much.
	GUIBox(GUI_Alignment alignment, float padding = 0.0f);
	~GUIBox();

	void packFront(GUIObjectBase* object);
	void packBack(GUIObjectBase* object);
	GUIObjectBase* removeFront();
	GUIObjectBase* removeBack();
	void destroyChildren();

	void setPadding(float padding);
	float getPadding();

	GUI_Alignment getAlignment();

	void setPosition(float x, float y) override;
	std::array<float, 2> getSize() override;
	void updateGUI(GUIInteractionStruct interactionData) override;
	void sendGUIRenderingInformation(void* renderer) override;

	void setExteriorPadding(bool exteriorPadding);
	bool hasExteriorPadding();

protected:
	std::deque<GUIObjectBase*> objects;

	GUI_Alignment alignment;
	float padding;
	bool bExteriorPadding;
};

