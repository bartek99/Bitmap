#include "Compound.h"

void Compound::transformation(Bitmap& bitmap) {
	for (Transformation &transformation : transformations_) {
		transformation.transformation(bitmap);
		std::cout << bitmap;
		std::cout << std::endl;
	}
}

void Compound::addTransformation(Transformation &transformation) {
	transformations_.push_back(transformation);
}