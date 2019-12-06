#include "Bitmap.h"

OutOfRangeException::OutOfRangeException() : std::runtime_error("Out of range error.") {
}

OutOfRangeException::OutOfRangeException(std::string error) : std::runtime_error(error.c_str()) {
}

std::ostream& operator<<(std::ostream& out, const Bitmap& bitmap) {
	for (unsigned int i = 0; i < bitmap.length(); i++) {
		for (unsigned int j = 0; j < bitmap.width(); j++) {
			out << bitmap(i, j) << " ";
		}
		out << "\n";
	}

	return out;
}