#pragma once

//Types of interaction that can occur, add new types here to check them more easily later.
enum GUI_InteractionType {
	MOUSE_HOVER_ENTER,
	MOUSE_HOVER_LEAVE,
	MOUSE_LEFT_JUST_DOWN,
	MOUSE_RIGHT_JUST_DOWN,
	MOUSE_LEFT_RELEASE,
	MOUSE_RIGHT_RELEASE
};

//Data based from gui parents to children, contains information relevent to determining what is happening to the tree of objects.
//I'll make the note here; I use a custom type of float container for mouseX & mouseY that easily converts between ingame Units and Screen Coordinates, so you may want to do the same to make rendering simplier.
struct GUIInteractionStruct {
	GUIInteractionStruct() : mouseX(100000), mouseY(100000), leftMouseJustDown(false), rightMouseJustDown(false), leftMouseRelease(false), rightMouseRelease(false) {
	}

	GUIInteractionStruct(float mouseX, float mouseY, bool leftMouseJustDown, bool rightMouseJustDown, bool leftMouseRelease, bool rightMouseRelease) {
	}

	float mouseX, mouseY;
	bool leftMouseJustDown, rightMouseJustDown;
	bool leftMouseRelease, rightMouseRelease;
};