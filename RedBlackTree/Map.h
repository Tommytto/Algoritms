//
// Created by timur on 17.12.17.
//

#ifndef REDBLACKTREE_MAP_H
#define REDBLACKTREE_MAP_H

#include "MapItem.h"

template <class C>
class Map {
private:
    MapItem<C> * top = nullptr;
public:
    void add(C * item);
    void remove(C * item);
};


#endif //REDBLACKTREE_MAP_H
