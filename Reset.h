#pragma once
#include "Transformation.h"

class Reset :public Transformation {
public:
	void transformation(Bitmap &bitmap);
};