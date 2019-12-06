#include "Dilatation.h"
#include "Exceptions.h"

void Dilatation::transformation(Bitmap &bitmap) {
	try {
		T = createTable<bool>(bitmap.length(), bitmap.width());
	}
	catch (std::exception& error) {
		std::cerr << error.what();
	}
	for (int i = 0; i < bitmap.length(); i++) {
		for (int j = 0; j < bitmap.width(); j++) {
			if (bitmap(i, j) == 0) {
				if (i == 0) {
					if (j == 0) {
						if (bitmap(i + 1, j) == 1) {
							T[i][j] = 1;
							continue;
						}
						if (bitmap(i, j + 1) == 1) {
							T[i][j] = 1;
							continue;
						}
						T[i][j] = bitmap(i, j);
					}
					else if (j == bitmap.width() - 1) {
						if (bitmap(i + 1, j) == 1) {
							T[i][j] = 1;
							continue;
						}
						if (bitmap(i, j - 1) == 1) {
							T[i][j] = 1;
							continue;
						}
						T[i][j] = bitmap(i, j);
					}
					else {
						if (bitmap(i + 1, j) == 1) {
							T[i][j] = 1;
							continue;
						}
						if (bitmap(i, j + 1) == 1) {
							T[i][j] = 1;
							continue;
						}
						if (bitmap(i, j - 1) == 1) {
							T[i][j] = 1;
							continue;
						}
						T[i][j] = bitmap(i, j);
					}
				}
				else if (i == bitmap.length() - 1) {
					if (j == 0) {
						if (bitmap(i - 1, j) == 1) {
							T[i][j] = 1;
							continue;
						}
						if (bitmap(i, j + 1) == 1) {
							T[i][j] = 1;
							continue;
						}
						T[i][j] = bitmap(i, j);
					}
					else if (j == bitmap.width() - 1) {
						if (bitmap(i - 1, j) == 1) {
							T[i][j] = 1;
							continue;
						}
						if (bitmap(i, j - 1) == 1) {
							T[i][j] = 1;
							continue;
						}
						T[i][j] = bitmap(i, j);
					}
					else {
						if (bitmap(i - 1, j) == 1) {
							T[i][j] = 1;
							continue;
						}
						if (bitmap(i, j + 1) == 1) {
							T[i][j] = 1;
							continue;
						}
						if (bitmap(i, j - 1) == 1) {
							T[i][j] = 1;
							continue;
						}
						T[i][j] = bitmap(i, j);
					}
				}
				else {
					if (j == 0) {
						if (bitmap(i + 1, j) == 1) {
							T[i][j] = 1;
							continue;
						}
						if (bitmap(i - 1, j) == 1) {
							T[i][j] = 1;
							continue;
						}
						if (bitmap(i, j + 1) == 1) {
							T[i][j] = 1;
							continue;
						}
						T[i][j] = bitmap(i, j);
					}
					else if (j == bitmap.width() - 1) {
						if (bitmap(i + 1, j) == 1) {
							T[i][j] = 1;
							continue;
						}
						if (bitmap(i - 1, j) == 1) {
							T[i][j] = 1;
							continue;
						}
						if (bitmap(i, j - 1) == 1) {
							T[i][j] = 1;
							continue;
						}
						T[i][j] = bitmap(i, j);
					}
					else {
						if (bitmap(i + 1, j) == 1) {
							T[i][j] = 1;
							continue;
						}
						if (bitmap(i - 1, j) == 1) {
							T[i][j] = 1;
							continue;
						}
						if (bitmap(i, j + 1) == 1) {
							T[i][j] = 1;
							continue;
						}
						if (bitmap(i, j - 1) == 1) {
							T[i][j] = 1;
							continue;
						}
						T[i][j] = bitmap(i, j);
					}
				}
			}
			T[i][j] = bitmap(i, j);
		}
	}
	for (int i = 0; i < bitmap.length(); i++) {
		for (int j = 0; j < bitmap.width(); j++) {
			bitmap(i, j) = T[i][j];
		}
	}
}