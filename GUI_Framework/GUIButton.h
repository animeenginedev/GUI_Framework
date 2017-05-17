#pragma once

#include "GUIObject.h"

class GUIButton : public GUIObject {
public:
	GUIButton();
	~GUIButton();

	void initialise(std::string text);

	void sendGUIRenderingInformation(void * renderer) override;

	void setPosition(float x, float y) override;
	std::array<float, 2> getSize() override;

	float padding;
};

//concrete implementation included.
/*#pragma once

#include "GUIObject.h"

#include "SimpleTextRectangle.h"
#include "SimpleRectangle.h"

class GUIButton : public GUIObject {
public:
	GUIButton();
	~GUIButton();
	
	void initialise(std::string text);

	void sendGUIRenderingInformation(RenderingEngine * renderer) override;

	void setPosition(Unit x, Unit y) override;
	std::array<Unit, 2> getSize() override;

	SimpleTextRectangle buttonText;
	SimpleRectangle buttonTexture;
	Unit padding;
};

*/