#pragma once

#include "AABB.h"
#include "GUIObjectBase.h"
#include "GUIObjectBase.h"
#include "GUIBox.h"
#include <deque>

//Windows can only have one child, I reccomend chooseing a box, something that you can embed more and more elements in.
class GUIWindow : public GUIObjectBase {
public:
	GUIWindow();
	~GUIWindow();

	void update(float deltaSeconds);
	void sendGUIRenderingInformation(void* renderer);

	void setChild(GUIBox* obj);
	void destroyChild();

	std::array<float, 2> getSize() override;

	bool isGUIWindow() override;

	void updateGUI(GUIInteractionStruct interactionData) override;
protected:
	GUIBox* child;
};

/*I'll include an outline of what my concrete implementation of this is.
#pragma once

#include "Object.h"

#include "AABB.h"
#include "GUIObjectBase.h"
#include "GUIObjectBase.h"
#include "GUIBox.h"
#include "OrthographicCamera.h"
#include "SimpleRectangle.h"
#include <deque>

class GUIWindow : public Object, public GUIObjectBase {
public:
GUIWindow();
~GUIWindow();

//I use a multithreaded engine base so concurrency is an option.
void concurrentUpdate(float deltaSeconds) override;
void serialUpdate(float deltaSeconds) override;
void sendRenderingInformation(RenderingEngine* renderer) override;
void sendGUIRenderingInformation(RenderingEngine* renderer) override;

void setChild(GUIBox* obj);
void destroyChild();

std::array<Unit, 2> getSize() override;

bool isGUIWindow() override;

void updateGUI(GUIInteractionStruct interactionData) override;
void setCamera(OrthographicCamera* camera);
protected:
GUIBox* child;
OrthographicCamera* camera;

SimpleRectangle background;
};
*/