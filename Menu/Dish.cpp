#include "Dish.h"

Dish::Dish(const std::string& name, double price, double quantity, int calories)
    : name(name), price(price), quantity(quantity), calories(calories)
{
}

const std::string& Dish::getName() const {
    return name;
}

double Dish::getPrice() const {
    return price;
}

double Dish::getQuantity() const {
    return quantity;
}

int Dish::getCalories() const {
    return calories;
}

double Dish::getPricePerQuantity() const {
    return price / quantity;
}

void Dish::setName(const std::string& name) {
    this->name = name;
}

void Dish::setPrice(double price) {
    this->price = price;
}

void Dish::setQuantity(double quantity) {
    this->quantity = quantity;
}

void Dish::setCalories(int calories) {
    this->calories = calories;
}

std::istream& operator>>(std::istream& is, Dish& dish) {

    std::cout << "Enter name: " << std::endl;
    is >> dish.name;
    std::cout << "Enter price: " << std::endl;
    is >> dish.price;
    std::cout << "Enter quantity: " << std::endl;
    is >> dish.quantity;
    std::cout << "Enter calories: " << std::endl;
    is >> dish.calories;

    return is;
 }


std::ostream& operator<<(std::ostream& os, const Dish& dish) {

    os << "Dish name: " << dish.name << std::endl;
    os << "Dish price: " << dish.price << std::endl;
    os << "Dish quantity: " << dish.quantity << std::endl;
    os << "Dish calories: " << dish.calories << std::endl;

    return os;
 }
