#include <iostream>
#include "Map.h"
#include "Product.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    auto * map = new Map<Product>();
    Product * product = new Product("Car", 150);
    map->add(product);

    return 0;
}