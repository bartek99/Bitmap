#pragma once
#include "Bitmap.h"

class Transformation
{
public:
	virtual void transformation(Bitmap&) = 0;
};