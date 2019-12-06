#pragma once
#include <iostream>
#include <exception>

class OutOfRangeException : public std::runtime_error {
public:
	OutOfRangeException();
	OutOfRangeException(std::string error);
};

class Bitmap {
public:
	virtual unsigned length() const = 0;
	virtual unsigned width() const = 0;
	virtual bool& operator() (unsigned x, unsigned y) = 0;
	virtual bool operator() (unsigned x, unsigned y) const = 0;
	virtual ~Bitmap() {}
};

std::ostream& operator<<(std::ostream& out, const Bitmap& bitmap);