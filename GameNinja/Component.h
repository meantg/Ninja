#pragma once
template <class T>
class Component
{
private:
	T cType;
public:
	Component() {}
	T GetComponentType() { return cType; }
	~Component() {}
};

