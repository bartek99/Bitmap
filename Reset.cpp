#include "Reset.h"

void Reset::transformation(Bitmap &bitmap) {
	for (int i = 0; i < bitmap.length(); i++) {
		for (int j = 0; j < bitmap.width(); j++) {
			bitmap(i, j) = 0;
		}
	}
}