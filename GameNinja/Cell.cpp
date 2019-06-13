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
	rect.left = xID;
	rect.top = yID;
	rect.right = xID + _cellwidth;
	rect.bottom = yID - _cellheight;
}

bool Cell::isContain(RECT r)
{
	return !((rect.right < r.left) || (rect.left > r.right) || (rect.top < r.bottom) || (rect.bottom > r.top));
}
