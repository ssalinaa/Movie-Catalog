#pragma once
#ifndef MENU_HPP
#define MENU_HPP
#include <iostream>
#include <cstring>
#include "Dish.h"

class Menu {

private:
	Dish* dishes;
	int numberOfDishes;
	int capacity;

public:
	~Menu();
	void addDish(const Dish& dish);
	void removeDish(const std::string& name);
	Dish* findDish(const std::string& name) const;
	Dish* findBestDish(double price) const;

	friend std::ostream& operator<<(std::ostream& os, const Menu& menu);
};

#endif