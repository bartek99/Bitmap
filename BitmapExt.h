#pragma once
#include"Bitmap.h"
#include"Exceptions.h"
#include <iostream>

class BitmapExt : public Bitmap {
private:
	unsigned width_;
	unsigned length_;
	bool **tab_;
public:

	BitmapExt(unsigned length, unsigned width);
	unsigned int width() const;
	unsigned int length() const;
	bool& operator() (unsigned x, unsigned y);
	bool operator() (unsigned x, unsigned y) const;
	~BitmapExt();



};