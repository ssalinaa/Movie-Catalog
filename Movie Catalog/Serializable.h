#pragma once
#include <iostream>
#include <fstream>

class Serializable {

public:

	virtual void serialize(std::ofstream& stream) const = 0;
	virtual void deserialize(std::istream& stream) = 0;

};