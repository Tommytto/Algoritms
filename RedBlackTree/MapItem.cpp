//
// Created by timur on 17.12.17.
//

#include "MapItem.h"
#include "Product.h"

template <typename C>
MapItem<C>::MapItem(C * item, bool isBlack) : item(item), isBlack(isBlack) {}

template <typename C>
C * MapItem<C>::getItem() {
    return this->item;
}

template <typename C>
void MapItem<C>::setItem(C * item) {
    this->item = item;
}

template <typename C>
bool MapItem<C>::getIsBlack() {
    return this->isBlack;
}

template <typename C>
void MapItem<C>::setIsBlack(bool isBlack) {
    this->isBlack = isBlack;
}

template <typename C>
MapItem<C> * MapItem<C>::getLeft() {
    return this->left;
}

template <typename C>
void MapItem<C>::setLeft(MapItem<C> *leftChild) {
    this->left = leftChild;
}

template <typename C>
MapItem<C> * MapItem<C>::getRight() {
    return this->right;
}

template <typename C>
void MapItem<C>::setRight(MapItem<C> * rightChild) {
    this->right = rightChild;
}

template class MapItem<Product>;
