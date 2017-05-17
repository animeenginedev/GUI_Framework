#pragma once

#include "GUIObjectBase.h"
#include "GUI_Interaction.h"
#include "AABB.h"
#include <array>
#include <unordered_map>
#include <functional>

class GUIObject : public GUIObjectBase {
public:
	GUIObject();
	~GUIObject();

	//If you want to add custom interactions too all gui objects insert the new interaction types here, otherwise if you only want it on certain types insert it in an overridden updateGUI
	void updateGUI(GUIInteractionStruct interactionData) override;

	void connectFunction(GUI_InteractionType type, std::function<void()> function);
	void disconnectFunction(GUI_InteractionType type);
	bool hasFunction(GUI_InteractionType type);

	void sendGUIRenderingInformation(void * renderer) override;
protected:
	std::unordered_map<GUI_InteractionType, std::function<void()>> functionCalls;

	void callFunction(GUI_InteractionType type);

	GUIInteractionStruct lastData;
};

