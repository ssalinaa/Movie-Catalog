#include <iostream>
#include "Dish.h"
#include "Menu.h"

void Menu::addDish(const Dish& dish) {

	if (numberOfDishes == capacity) {
		
		int newCapacity = capacity * 2;
		Dish* newDishes = new Dish[newCapacity];
		for (size_t i = 0; i < numberOfDishes; i++)
		{
			newDishes[i] = dishes[i];
		}
		delete[] dishes;
		dishes = newDishes;
		capacity = newCapacity;
	}
	dishes[numberOfDishes++] = dish;
}

void Menu::removeDish(const std::string& name) {

	for (size_t i = 0; i < numberOfDishes; i++)
	{
		if (dishes[i].getName() == name) {
			
			delete &dishes[i];
			for (size_t j = 0; j < numberOfDishes - 1; j++)
			{
				dishes[j] = dishes[j + 1];
			}
			numberOfDishes--;
			return;
		}
	}
}

Dish* Menu::findDish(const std::string& name) const {

	for (size_t i = 0; i < numberOfDishes; i++)
	{
		if (dishes[i].getName() == name) {
			
			return &dishes[i];
		}
	}
	return nullptr;
}

Dish* Menu::findBestDish(double price) const {

	Dish* bestDishes = nullptr;
	double bestValue = 0;

	for (size_t i = 0; i < numberOfDishes; i++)
	{
		if (dishes[i].getPrice() <= price) {

			double value = dishes[i].getPrice() / dishes[i].getQuantity();
			if (value > bestValue) {

			bestValue = value;
			bestDishes = &dishes[i];
			}
			else if (dishes[i].getCalories() < bestDishes->getCalories()) {
				bestDishes = &dishes[i];
			}
		}
	}
	return bestDishes;
}

std::ostream& operator<<(std::ostream& os, const Menu& menu) {

	for (size_t i = 0; i < menu.numberOfDishes; i++)
	{
			os << menu.dishes[i].getName() << ": " <<
				menu.dishes[i].getPrice() << " (" << 
				menu.dishes[i].getCalories() << " cal, " <<
				menu.dishes[i].getQuantity() << " g)\n";
	}
	return os;
}

Menu::~Menu() {

	for (size_t i = 0; i < numberOfDishes; i++)
	{
		delete[] &dishes[i];
	}
}