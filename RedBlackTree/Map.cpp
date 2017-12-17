//
// Created by timur on 17.12.17.
//

#include "Map.h"
#include "Product.h"

template <typename C>
void Map<C>::add(C * item) {
    auto * mapItem = new MapItem<C>(item, true);
    if (!this->top) {
        this->top = mapItem;
    }
}

template class Map<Product>;