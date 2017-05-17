#pragma once

#include "GUIObject.h"

class GUILabel : public GUIObject {
public:
	GUILabel();
	~GUILabel();

	void initialise(std::string text, float textHeight, float edgePadding);

	void sendGUIRenderingInformation(void * renderer) override;

	void setPosition(float x, float y) override;
	std::array<float, 2> getSize() override;

	float padding;
};

//more concrete implementation
/*#pragma once

#include "GUIObject.h"

#include "SimpleTextRectangle.h"

class GUILabel : public GUIObject {
public:
	GUILabel();
	~GUILabel();

	void initialise(std::string text, Unit textHeight, Unit edgePadding);

	void sendGUIRenderingInformation(RenderingEngine * renderer) override;

	void setPosition(Unit x, Unit y) override;
	std::array<Unit, 2> getSize() override;

	SimpleTextRectangle label;
	Unit padding;
};

*/