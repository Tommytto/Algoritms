//
// Created by timur on 26.11.17.
//

#ifndef SEARCH_ALGORITMSINUNSORTED_H
#define SEARCH_ALGORITMSINUNSORTED_H

#include <vector>

using namespace std;

template <typename T>
class AlgoritmsInUnsorted {
public:
    static int linearSearch(vector<T> array, T toSearch);
    static int fastLinearSearch(vector<T> array, T toSearch);


};


#endif //SEARCH_ALGORITMSINUNSORTED_H
