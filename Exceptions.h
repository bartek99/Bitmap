#pragma once
#include <iostream>
#include <exception>
#include <string>

class LackOfMemory : public std::runtime_error {
public:
	LackOfMemory() : std::runtime_error("Bad alloc error") {

	}

	LackOfMemory(std::string error) : std::runtime_error(error.c_str()) {

	}
};

template <typename T>
T** createTable(unsigned width, unsigned length);

template<typename T>
T** createTable(unsigned length, unsigned width) {
	T** tab = nullptr;
	try {
		tab = new T*[length];
	}
	catch (std::bad_alloc) {
		throw(LackOfMemory("Nie stworzylo [Rows]"));
	}
	for (int i = 0; i < length; i++) {
		try {
			tab[i] = new T[width];
		}
		catch (std::bad_alloc) {
			throw(LackOfMemory("Nie stworzylo [Columns]"));
		}
	}
	return tab;
}