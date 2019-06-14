#include "Cell.h"

int Cell::_cellheight = SCREEN_HEIGHT >> 1;
int Cell::_cellwidth = SCREEN_WIDTH >> 1;

void Cell::RemoveObject(Object * obj)
{
	if (objects.find(obj) != objects.end()) {
		objects.erase(obj);
	}
}

Cell::Cell(int xID, int yID)
{
	this->xID = xID;
	this->yID = yID;
	rect.x = xID * _cellwidth;
	rect.y = yID * _cellheight;
	rect.width = _cellwidth;
	rect.height = _cellheight;
}

bool Cell::isContain(Rect r)
{
	return rect.isContain(r);
}
