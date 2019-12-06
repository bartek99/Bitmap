#include"Erosion.h"
#include"Exceptions.h"

void Erosion::transformation(Bitmap & bitmap) {
	try {
		T = createTable<bool>(bitmap.length(), bitmap.width());
	}
	catch (std::exception& error) {
		std::cerr << error.what();
	}
	/*
		for (int i = 0; i < bitmap.length(); i++) {
			for (int j = 0; j < bitmap.width(); j++) {
				if (i > 0 && j > 0 && i < bitmap.length() - 1 && j < bitmap.width() - 1 && bitmap(i, j) == true) {
					if (bitmap(i - 1, j - 1) == false) {
						T[i][j] = false;
					}
					else if (bitmap(i - 1, j) == false) {
						T[i][j] = false;
					}
					else if (bitmap(i - 1, j + 1) == false) {
						T[i][j] = false;
					}
					else if (bitmap(i, j - 1) == false) {
						T[i][j] = false;
					}
					else if (bitmap(i, j + 1) == false) {
						T[i][j] = false;
					}
					else if (bitmap(i + 1, j - 1) == false) {
						T[i][j] = false;
					}
					else if (bitmap(i + 1, j) == false) {
						T[i][j] = false;
					}
					else if (bitmap(i + 1, j + 1) == false) {
						T[i][j] = false;
					}
					else {
						T[i][j] = bitmap(i, j);
					}
				}
				else if (i == 0 && j == 0 && bitmap(i, j) == true) {
					if (bitmap(i, j + 1) == false) {
						T[i, j] = false;
					}
					else if (bitmap(i + 1, j + 1) == false) {
						T[i][j] = false;
					}
					else if (bitmap(i, j + 1) == false) {
						T[i][j] = false;
					}
					else {
						T[i][j] = bitmap(i, j);
					}
				}
				else if (i == 0 && j == bitmap.width() - 1 && bitmap(i, j) == true) {
					if (bitmap(i, j - 1) == false) {
						T[i][j] = false;
					}
					else if (bitmap(i + 1, j - 1) == false) {
						T[i][j] = false;
					}
					else if (bitmap(i + 1, j) == false) {
						T[i][j] = false;
					}
					else {
						T[i][j] = bitmap(i, j);
					}
				}
				else if (i == bitmap.length() - 1 && j == 0 && bitmap(i, j) == true) {
					if (bitmap(i, j + 1) == false) {
						T[i][j] = false;
					}
					else if (bitmap(i - 1, j + 1)) {
						T[i][j] = false;
					}
					else if (bitmap(i - 1, j)) {
						T[i][j] = false;
					}
					else {
						T[i][j] = bitmap(i, j);
					}
				}
				else if (i == bitmap.length() - 1 && j == bitmap.width() - 1 && bitmap(i, j) == true) {
					if (bitmap(i, j - 1) == false) {
						T[i][j] = false;
					}
					else if (bitmap(i - 1, j) == false) {
						T[i][j] = false;
					}
					else if (bitmap(i - 1, j - 1) == false) {
						T[i][j] = false;
					}
					else {
						T[i][j] = bitmap(i, j);
					}
				}
				else if (i == 0 && j > 0 && j < bitmap.width() - 1 && bitmap(i, j) == true) {
					if (bitmap(i, j - 1) == false) {
						T[i][j] = false;
					}
					else if (bitmap(i + 1, j - 1) == false) {
						T[i][j] = false;
					}
					else if (bitmap(i + 1, j) == false) {
						T[i][j] = false;
					}
					else if (bitmap(i + 1, j + 1) == false) {
						T[i][j] = false;
					}
					else if (bitmap(i, j + 1) == false) {
						T[i][j] = false;
					}
					else {
						T[i][j] = bitmap(i, j);
					}
				}
				else if (i == bitmap.length() && j > 0 && j < bitmap.width() - 1 && bitmap(i, j) == true) {
					if (bitmap(i, j - 1) == false) {
						T[i][j] = false;
					}
					else if (bitmap(i - 1, j - 1) == false) {
						T[i][j] = false;
					}
					else if (bitmap(i - 1, j) == false) {
						T[i][j] = false;
					}
					else if (bitmap(i - 1, j + 1) == false) {
						T[i][j] = false;
					}
					else if (bitmap(i, j + 1) == false) {
						T[i][j] = false;
					}
					else {
						T[i][j] = bitmap(i, j);
					}
				}
				else if (j == 0 && i > 0 && i < bitmap.length() - 1 && bitmap(i, j) == true) {
					if (bitmap(i - 1, j) == false) {
						T[i][j] = false;
					}
					else if (bitmap(i - 1, j + 1)) {
						T[i][j] = false;
					}
					else if (bitmap(i, j + 1)) {
						T[i][j] = false;
					}
					else if (bitmap(i + 1, j + 1)) {
						T[i][j] = false;
					}
					else if (bitmap(i + 1, j)) {
						T[i][j] = false;
					}
					else {
						T[i][j] = bitmap(i, j);
					}
				}
				else if (j == bitmap.width() - 1 && i > 0 && i < bitmap.length() - 1 && bitmap(i, j) == true)
					if (bitmap(i - 1, j) == false) {
						T[i][j] = false;
					}
					else if (bitmap(i - 1, j - 1) == false) {
						T[i][j] = false;
					}
					else if (bitmap(i, j - 1) == false) {
						T[i][j] = false;
					}
					else if (bitmap(i + 1, j - 1) == false) {
						T[i][j] = false;
					}
					else if (bitmap(i + 1, j) == false) {
						T[i][j] = false;
					}
					else {
						T[i][j] = bitmap(i, j);
					}

			}
		}
		for (int i = 0; i < bitmap.length(); i++) {
			for (int j = 0; j < bitmap.width(); j++) {
				bitmap(i, j) = T[i][j];
			}
		}
	}
	*/

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
					if (neighbor >= 2) {
						T[i][j] = false;
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
					if (neighbor >= 2) {
						T[i][j] = false;
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
					if (neighbor >= 2) {
						T[i][j] = false;
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
					if (neighbor >= 2) {
						T[i][j] = false;
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
					if (neighbor >= 2) {
						T[i][j] = false;
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
					if (neighbor >= 2) {
						T[i][j] = false
							;
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
					if (neighbor >= 2) {
						T[i][j] = false;
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
					if (neighbor >= 2) {
						T[i][j] = false;
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
					if (neighbor >= 2) {
						T[i][j] = false;
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