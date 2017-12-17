//
// Created by timur on 17.12.17.
//

#ifndef REDBLACKTREE_PRODUCT_H
#define REDBLACKTREE_PRODUCT_H

#include <iostream>

using namespace std;

class Product {
public:
    Product(string name, float price);
    string getName();
    void setName(string name);

    float getPrice();
    void setPrice(float price);
private:
    string name;
    float price;
};


#endif //REDBLACKTREE_PRODUCT_H
