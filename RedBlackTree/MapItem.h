//
// Created by timur on 17.12.17.
//

#ifndef REDBLACKTREE_MAPITEM_H
#define REDBLACKTREE_MAPITEM_H

template <class C>
class MapItem {
private:
    C * item = nullptr;
    bool isBlack;
    MapItem<C> * left = nullptr;
    MapItem<C> * right = nullptr;
public:
    C * getItem();
    void setItem(C * item);

    bool getIsBlack();
    void setIsBlack(bool isBlack);

    MapItem * getLeft();
    void setLeft(MapItem * leftChild);

    MapItem * getRight();
    void setRight(MapItem * rightChild);

    MapItem(C * item, bool isBlack);
};



#endif //REDBLACKTREE_MAPITEM_H
