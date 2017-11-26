//
// Created by timur on 26.11.17.
//

#include "AlgoritmsInUnsorted.h"

template <typename T>
int AlgoritmsInUnsorted<T>::fastLinearSearch(vector<T> array, T toSearch) {
    array.push_back(toSearch);
    int i = 0;
    while (array[i] != toSearch) {
        i++;
    }
    if(i == array.size() - 1) {
        return -1;
    } else return i;
}

template <typename T>
int AlgoritmsInUnsorted<T>::linearSearch(vector<T> array, T toSearch) {
    for (int i = 0; i < array.size(); i++) {
        if (array[i] == toSearch) {
            return i;
        }
    }
    return -1;
}