#pragma once
#include "Transformation.h"

class Erosion :public Transformation {
private:
	bool **T;
public:
	void transformation(Bitmap & bitmap);

};