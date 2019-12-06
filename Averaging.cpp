#include "Averaging.h"
#include "Exceptions.h"
void Averaging::transformation(Bitmap &bitmap) {
	try {
		T = createTable<bool>(bitmap.length(), bitmap.width());
	}
	catch (std::exception& error) {
		std::cerr << error.what();
	}
	int neighbor = 0;
	for (int i = 0; i < bitmap.length(); i++) {
		for (int j = 0; j < bitmap.width(); j++) {
			if (i == 0) {
				if (j == 0) {
					if (bitmap(i, j) != bitmap(i + 1, j)) {
						neighbor++;
					}
					if (bitmap(i, j) != bitmap(i, j + 1)) {
						neighbor++;
					}
					if (neighbor > 2) {
						if (bitmap(i, j) == 1) {
							T[i][j] = 0;
						}
						else {
							T[i][j] = 1;
						}
					}
					else {
						T[i][j] = bitmap(i, j);
					}
				}
				else if (j == bitmap.width() - 1) {
					if (bitmap(i, j) != bitmap(i + 1, j)) {
						neighbor++;
					}
					if (bitmap(i, j) != bitmap(i, j - 1)) {
						neighbor++;
					}
					if (neighbor > 2) {
						if (bitmap(i, j) == 1) {
							T[i][j] = 0;
						}
						else {
							T[i][j] = 1;
						}
					}
					else {
						T[i][j] = bitmap(i, j);
					}
				}
				else {
					if (bitmap(i, j) != bitmap(i + 1, j)) {
						neighbor++;
					}
					if (bitmap(i, j) != bitmap(i, j - 1)) {
						neighbor++;
					}
					if (bitmap(i, j) != bitmap(i, j + 1)) {
						neighbor++;
					}
					if (neighbor > 2) {
						if (bitmap(i, j) == 1) {
							T[i][j] = 0;
						}
						else {
							T[i][j] = 1;
						}
					}
					else {
						T[i][j] = bitmap(i, j);
					}
				}
			}
			else if (i == bitmap.length() - 1) {
				if (j == 0) {
					if (bitmap(i, j) != bitmap(i - 1, j)) {
						neighbor++;
					}
					if (bitmap(i, j) != bitmap(i, j + 1)) {
						neighbor++;
					}
					if (neighbor > 2) {
						if (bitmap(i, j) == 1) {
							T[i][j] = 0;
						}
						else {
							T[i][j] = 1;
						}
					}
					else {
						T[i][j] = bitmap(i, j);
					}
				}
				else if (j == bitmap.width() - 1) {
					if (bitmap(i, j) != bitmap(i - 1, j)) {
						neighbor++;
					}
					if (bitmap(i, j) != bitmap(i, j - 1)) {
						neighbor++;
					}
					if (neighbor > 2) {
						if (bitmap(i, j) == 1) {
							T[i][j] = 0;
						}
						else {
							T[i][j] = 1;
						}
					}
					else {
						T[i][j] = bitmap(i, j);
					}
				}
				else {
					if (bitmap(i, j) != bitmap(i - 1, j)) {
						neighbor++;
					}
					if (bitmap(i, j) != bitmap(i, j - 1)) {
						neighbor++;
					}
					if (bitmap(i, j) != bitmap(i, j + 1)) {
						neighbor++;
					}
					if (neighbor > 2) {
						if (bitmap(i, j) == 1) {
							T[i][j] = 0;
						}
						else {
							T[i][j] = 1;
						}
					}
					else {
						T[i][j] = bitmap(i, j);
					}
				}
			}
			else {
				if (j == 0) {
					if (bitmap(i, j) != bitmap(i + 1, j)) {
						neighbor++;
					}
					if (bitmap(i, j) != bitmap(i - 1, j)) {
						neighbor++;
					}
					if (bitmap(i, j) != bitmap(i, j + 1)) {
						neighbor++;
					}
					if (neighbor > 2) {
						if (bitmap(i, j) == 1) {
							T[i][j] = 0;
						}
						else {
							T[i][j] = 1;
						}
					}
					else {
						T[i][j] = bitmap(i, j);
					}
				}
				else if (j == bitmap.width() - 1) {
					if (bitmap(i, j) != bitmap(i + 1, j)) {
						neighbor++;
					}
					if (bitmap(i, j) != bitmap(i - 1, j)) {
						neighbor++;
					}
					if (bitmap(i, j) != bitmap(i, j - 1)) {
						neighbor++;
					}
					if (neighbor > 2) {
						if (bitmap(i, j) == 1) {
							T[i][j] = 0;
						}
						else {
							T[i][j] = 1;
						}
					}
					else {
						T[i][j] = bitmap(i, j);
					}
				}
				else {
					if (bitmap(i, j) != bitmap(i + 1, j)) {
						neighbor++;
					}
					if (bitmap(i, j) != bitmap(i - 1, j)) {
						neighbor++;
					}
					if (bitmap(i, j) != bitmap(i, j - 1)) {
						neighbor++;
					}
					if (bitmap(i, j) != bitmap(i, j + 1)) {
						neighbor++;
					}
					if (neighbor > 2) {
						if (bitmap(i, j) == 1) {
							T[i][j] = 0;
						}
						else {
							T[i][j] = 1;
						}
					}
					else {
						T[i][j] = bitmap(i, j);
					}
				}
			}
			neighbor = 0;
		}
	}
	for (int i = 0; i < bitmap.length(); i++) {
		for (int j = 0; j < bitmap.width(); j++) {
			bitmap(i, j) = T[i][j];
		}
	}
}