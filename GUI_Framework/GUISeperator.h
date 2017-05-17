#pragma once

#include "GUIObject.h"

#include "GUI_Interaction.h"
#include "GUI_Alignment.h"

//seperators are just used to make life a touch easier, thats all really.
class GUISeperator : public GUIObject {
public:
	GUISeperator();
	~GUISeperator();

	void initialise();

	void sendGUIRenderingInformation(void * renderer) override;

	void setPosition(float x, float y) override;
	std::array<float, 2> getSize() override;
};

/*#pragma once

#include "GUIObject.h"

#include "GUIInteraction.h"
#include "GUIAlignment.h"
#include "SimpleLine.h"

class GUISeperator : public GUIObject {
public:
	GUISeperator();
	~GUISeperator();

	void initialise(Colour c);

	void sendGUIRenderingInformation(RenderingEngine * renderer) override;

	void setPosition(Unit x, Unit y) override;
	std::array<Unit, 2> getSize() override;

	SimpleLine seperator;
};

*/