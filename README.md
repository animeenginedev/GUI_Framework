# GUI_Framework
Some gui framework I've removed from a larger project so I can use it again. Honestly gui sucks i hate it, but i needed something scaleable and complex enough to use in gameplay situations. 

All this framework really does is autoscale guicomponents and allow you to easily attach events to them, but honestly isn't that all we need?

Heres a really unprofressional webm i've made with my main project: https://a.pomf.cat/hdjnej.webm if this webm doesn't stay up just tell me to reupload the gui_framework.webm via email.

*/
	window = new GUIWindow();
	GUIBox* testBox = new GUIBox(VERTICAL, 0.01);
	GUIBox* t2Box = new GUIBox(HORIZONTAL, 0.01);
	GUIBox* t3Box = new GUIBox(VERTICAL, 0.01);
	GUIBox* t4Box = new GUIBox(VERTICAL, 0.01);
	window->setChild(testBox);
	GUILabel* label = new GUILabel();
	GUISeperator* seperator = new GUISeperator();
	GUISeperator* seperator2 = new GUISeperator();
	GUIButton* testButton = new GUIButton();
	GUIButton* test2 = new GUIButton();
	GUIButton* test3 = new GUIButton();
	GUIButton* test4 = new GUIButton();
	GUIButton* test5 = new GUIButton();
	GUIButton* test6 = new GUIButton();
	label->initialise("Main Menu", 0.04f, 0.001f);
	seperator->initialise(Colour(0, 255, 0, 255));
	seperator2->initialise(Colour(0, 0, 255, 255));
	testButton->initialise("Test 1");
	test2->initialise("Test 2");
	test3->initialise("Exit");
	test4->initialise("Test 4");
	test5->initialise("Test 5");
	test6->initialise("Test 6");
	registerObject(window);
	window->setCamera(&camera);
	window->setPosition(0.0, 0.00);

	testBox->packBack(label);
	testBox->packBack(seperator);
	testBox->packBack(testButton);
	testBox->packBack(test2);
	testBox->packBack(t2Box);
	t2Box->packBack(t3Box);
	t2Box->packBack(seperator2);
	t2Box->packBack(t4Box);

	t3Box->packBack(test5);
	t3Box->packBack(test6);
	t4Box->packBack(test4);
	t4Box->packBack(test3);

	t2Box->setExteriorPadding(false);
	t3Box->setExteriorPadding(false);
	t4Box->setExteriorPadding(false);

	testButton->connectFunction(MOUSE_LEFT_RELEASE, std::bind(&MenuState::testFunction, this, 1));
	test2->connectFunction(MOUSE_LEFT_RELEASE, std::bind(&MenuState::testFunction, this, 2));
	test3->connectFunction(MOUSE_LEFT_RELEASE, std::bind(&MenuState::exitFunction, this));
	test4->connectFunction(MOUSE_LEFT_RELEASE, std::bind(&MenuState::testFunction, this, 4));
	test5->connectFunction(MOUSE_LEFT_RELEASE, std::bind(&MenuState::testFunction, this, 5));
	test6->connectFunction(MOUSE_LEFT_RELEASE, std::bind(&MenuState::testFunction, this, 6));
*/

Are the procedures that are used to create that unprofressional webm, obviously i've left out my object processing and rendering but you should be able to manage that much yourself. Testfunction literally just prints "Test Function " + the nummber thats passed to that function.