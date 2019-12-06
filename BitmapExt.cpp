#include"BitmapExt.h"

BitmapExt::BitmapExt(unsigned length, unsigned width) : length_(length), width_(width) {
	try {
		tab_ = createTable<bool>(length, width);
	}
	catch (std::exception& error) {
		std::cerr << error.what();
	}
	for (unsigned int i = 0; i < length; i++) {
		for (unsigned int j = 0; j < width; j++) {
			tab_[i][j] = false;
		}
	}
}

unsigned int BitmapExt::length() const {
	return length_;
}

unsigned BitmapExt::width() const {
	return width_;
}

bool & BitmapExt::operator()(unsigned x, unsigned y) {
	if (x >= width_ || y >= length_) {
		throw OutOfRangeException();
	}

	return tab_[y][x];
}


bool BitmapExt::operator()(unsigned x, unsigned y) const {
	if (x >= width_ || y >= length_) {
		throw OutOfRangeException();
	}

	return tab_[y][x];
}

BitmapExt::~BitmapExt() {
	for (unsigned int i = 0; i < length_; i++) {
		delete[] tab_[i];
	}
	delete[] tab_;
}