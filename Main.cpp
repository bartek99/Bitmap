#include <iostream>
#include "BitmapExt.h"
#include "Inversion.h"
#include "Erosion.h"
#include "Dilatation.h"
#include "Reset.h"
#include "Averaging.h"
#include "Compound.h"

int main() {
	int menu = 0;
	BitmapExt bitmap(7, 7);
	BitmapExt bitmap2(5, 5);
	Compound compound;
	Averaging averaging;
	Dilatation dilatation;
	Erosion erosion;
	Inversion inversion;
	Reset reset;

	while (menu != -1) {
		std::cout << "Co chcesz zrobic?" << std::endl;
		std::cout << "[1] Wczytac przyklad bitmapy 7x7 i wszystkich metod" << std::endl;
		std::cout << "[2] Wczytac przyklad bitmapy 5x5 jako przyklad uzycia" << std::endl;
		std::cout << "Twoj wybor: ";
		std::cin >> menu;
		switch (menu) {
		case 1:
			bitmap(2, 2) = bitmap(3, 2) = bitmap(4, 2) = true;
			bitmap(2, 3) = bitmap(3, 3) = bitmap(4, 3) = true;
			bitmap(2, 4) = bitmap(3, 4) = bitmap(4, 4) = true;
			bitmap(1, 3) = bitmap(3, 1) = bitmap(5, 3) = bitmap(3, 5) = true;
			std::cout << bitmap;
			std::cout << std::endl;
			compound.addTransformation(erosion);
			compound.addTransformation(dilatation);
			compound.addTransformation(averaging);
			compound.addTransformation(reset);
			compound.addTransformation(inversion);
			compound.transformation(bitmap);
			menu = -1;
			break;
		case 2:
			bitmap2(1, 1) = bitmap2(1, 3) = true;
			bitmap2(2, 1) = bitmap2(2, 2) = bitmap2(2, 3) = true;
			bitmap2(3, 1) = bitmap2(3, 3) = true;
			std::cout << bitmap2;
			std::cout << std::endl;
			compound.addTransformation(averaging);
			compound.addTransformation(dilatation);
			compound.transformation(bitmap2);
			menu = -1;
			break;
		default:
			std::cout << "Sprobuj jeszcze raz." << std::endl;
			break;
		}
	}

	getchar();
	getchar();
	return 0;
}