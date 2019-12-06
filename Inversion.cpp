#include"Inversion.h"


void Inversion::transformation(Bitmap & bitmap) {
	for (int i = 0; i < bitmap.length(); i++) {
		for (int j = 0; j < bitmap.width(); j++) {
			if (bitmap(i, j) == 0) {
				bitmap(i, j) = 1;
			}
			else {
				bitmap(i, j) = 0;
			}
		}
	}
}