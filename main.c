#include "ch.h"
#include "hal.h"
#include "gfx.h"

GListener gl;
GHandle ghLabel1, ghLabel2;
GHandle ghList1, ghList2;

static void createWidgets(void)
{
	GWidgetInit wi;

	// Apply some default values for GWIN
	gwinWidgetClearInit(&wi);
	wi.g.show = TRUE;

	// Create the label for the first list
	wi.g.width = 150; wi.g.height = 20; wi.g.x = 10, wi.g.y = 10;
	wi.text = "List 1: Default";
	ghLabel1 = gwinLabelCreate(0, &wi);

	// Create the label for the second list
	wi.g.width = 150; wi.g.height = 20; wi.g.x = 10, wi.g.y = 170;
	wi.text = "List 2: Smooth";
	ghLabel1 = gwinLabelCreate(0, &wi);

	// The first list widget
	wi.g.width = 150;
	wi.g.height = 110;
	wi.g.y = 35;
	wi.g.x = 10;
	wi.text = "Name of list 1";
	ghList1 = gwinListCreate(0, &wi, FALSE);

	// The second list widget
	wi.g.width = 150;
	wi.g.height = 110;
	wi.g.y = 195;
	wi.g.x = 10;
	wi.text = "Name of list 2";
	ghList2 = gwinListCreate(0, &wi, FALSE);
	gwinListSetScroll(ghList2, scrollSmooth);
}

int main(void)
{
	GEvent* pe;

	gfxInit();

	// Set the widget defaults
	gwinSetDefaultFont(gdispOpenFont("UI2"));
	gwinSetDefaultStyle(&WhiteWidgetStyle, FALSE);
	gdispClear(White);

	// create the widget
	createWidgets();

	// We want to listen for widget events
	geventListenerInit(&gl);
	gwinAttachListener(&gl);

	// Add some items to the first list widget
	gwinListAddItem(ghList1, "Item 0", FALSE);
	gwinListAddItem(ghList1, "Item 1", FALSE);
	gwinListAddItem(ghList1, "Item 2", FALSE);
	gwinListAddItem(ghList1, "Item 3", FALSE);
	gwinListAddItem(ghList1, "Item 4", FALSE);
	gwinListAddItem(ghList1, "Item 5", FALSE);
	gwinListAddItem(ghList1, "Item 6", FALSE);
	gwinListAddItem(ghList1, "Item 7", FALSE);
	gwinListAddItem(ghList1, "Item 8", FALSE);
	gwinListAddItem(ghList1, "Item 9", FALSE);
	gwinListAddItem(ghList1, "Item 10", FALSE);
	gwinListAddItem(ghList1, "Item 11", FALSE);
	gwinListAddItem(ghList1, "Item 12", FALSE);
	gwinListAddItem(ghList1, "Item 13", FALSE);

	// Add some items to the second list widget
	// This time we will disable the render until
	// all the items have been added
	gwinListEnableRender(ghList2, FALSE);
	gwinListAddItem(ghList2, "Item 0", FALSE);
	gwinListAddItem(ghList2, "Item 1", FALSE);
	gwinListAddItem(ghList2, "Item 2", FALSE);
	gwinListAddItem(ghList2, "Item 3", FALSE);
	gwinListAddItem(ghList2, "Item 4", FALSE);
	gwinListAddItem(ghList2, "Item 5", FALSE);
	gwinListAddItem(ghList2, "Item 6", FALSE);
	gwinListAddItem(ghList2, "Item 7", FALSE);
	gwinListAddItem(ghList2, "Item 8", FALSE);
	gwinListAddItem(ghList2, "Item 9", FALSE);
	gwinListAddItem(ghList2, "Item 10", FALSE);
	gwinListAddItem(ghList2, "Item 11", FALSE);
	gwinListAddItem(ghList2, "Item 12", FALSE);
	gwinListAddItem(ghList2, "Item 13", FALSE);
	gwinListEnableRender(ghList2, TRUE);

	while (true) {
		// Get an Event
		pe = geventEventWait(&gl, TIME_INFINITE);
	}
}
