#include "GraphView.h"

//! \todo replace with std::string_view
const char* GraphView::VIEW_NAME = "Graph";

GraphView::GraphView(ViewLayout* viewLayout): View(viewLayout) {}

std::string GraphView::getName() const
{
	return VIEW_NAME;
}
