#include <iostream>
#include "Dish.h"
#include "Menu.h"

int main() {
  

    Dish* dishes = new Dish[5];
    Menu menu;

    for (std::size_t i = 0; i < 5; ++i)
    {
        std::cin >> dishes[i];

        menu.addDish(dishes[i]);
    }
    std::cout << menu << menu.findBestDish(2);

    return 0;
}
