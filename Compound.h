#include "Transformation.h"
#include <vector>
#include <functional>

class Compound : public Transformation {
public:
	void transformation(Bitmap& bitmap);

	void addTransformation(Transformation &transformation);

private:
	std::vector<std::reference_wrapper<Transformation>> transformations_;
};