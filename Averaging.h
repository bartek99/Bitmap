#pragma once
#include "Transformation.h"

class Averaging : public Transformation {
private:
	bool **T;
public:
	void transformation(Bitmap &bitmap);
};