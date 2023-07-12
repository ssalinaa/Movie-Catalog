#ifndef DISH_H
#define DISH_H

#include <string>
#include <iostream>

class Dish {
public:

    Dish();
    Dish(const std::string& name, double price, double quantity, int calories);

    const std::string& getName() const;
    double getPrice() const;
    double getQuantity() const;
    int getCalories() const;
    double getPricePerQuantity() const;

    void setName(const std::string& name);
    void setPrice(double price);
    void setQuantity(double quantity);
    void setCalories(int calories);

    friend std::istream& operator>>(std::istream& is, Dish& dish);
    friend std::ostream& operator<<(std::ostream& os, const Dish& dish);


private:
    std::string name;
    double price;
    double quantity;
    int calories;
};

#endif 
