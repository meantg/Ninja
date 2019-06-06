#include "IHButterfly.h"

IHButterfly::IHButterfly()
{
	_state = STANDING;
	this->AddAnimation(IH_BUTTERFLY, STANDING);
	this->x = 900;
	this->y = 85;
}