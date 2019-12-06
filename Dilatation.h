#pragma once
#include "Transformation.h"

class Dilatation : public Transformation {
private:
	bool **T;
public:
	void transformation(Bitmap &bitmap);
};