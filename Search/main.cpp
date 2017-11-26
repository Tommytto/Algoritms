using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include "AlgoritmsInUnsorted.h"

template <typename T>
int fastLinearSearch(vector<T> array, T toSearch) {
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
int linearSearch(vector<T> array, T toSearch) {
    for (int i = 0; i < array.size(); i++) {
        if (array[i] == toSearch) {
            return i;
        }
    }
    return -1;
}

template <typename T>
int sortLinearSearch(vector<T> array, T toSearch) {
    for (int i = 0; i < array.size(); i++) {
        if (array[i] == toSearch) {
            return i;
        } else if (array[i] > toSearch) {
            return -1;
        }
    }
    return -1;
}

template <typename T>
int binarySearch(vector<T> array, T toSearch) {
    unsigned int left = 0;
    unsigned int right  = array.size();
    unsigned int mid;

    while (left <= right) {
        mid = (right+left)/2;
        if (toSearch < array[mid]) {
            right = mid - 1;
        } else if (toSearch > array[mid]) {
            left = mid + 1;
        } else return mid;
    }
    return -1;
}

template <typename T>
int blockSearch(vector<T> array, T toSearch) {
    int index = -1;
    int blockDiv = 4;
    int blockSize = array.size()/blockDiv;
    int lastBlockSize = array.size()%blockDiv;
    bool isAddBLock = 0 != lastBlockSize;
    int blockCount = (isAddBLock ? blockDiv + 1 : blockDiv);

    vector<int> blockVector;
    for (int i = 0; i < blockCount; i++) {
        int curMaxBlock;
        bool isLastAddBlock = i == blockVector.size() - 1 && isAddBLock;
        if (isLastAddBlock) {
            curMaxBlock = array[(blockCount-1) * blockSize + lastBlockSize - 1];
        } else {
            curMaxBlock = array[(i+1) * blockSize - 1];
        }
        if (toSearch <= curMaxBlock) {
            if (i == blockCount - 1) {
                for (int j = blockSize * i; j < array.size(); j++) {
                    blockVector.push_back(array[j]);
                }
            } else {
                for (int j = blockSize * i; j < blockSize * (i+1); j++) {
                    blockVector.push_back(array[j]);
                }
            }
            index = sortLinearSearch(blockVector, toSearch);
            if (-1 != index) {
                index += i * blockSize;
            }
            return index;
        }
    }

//    for (int i = 0; i < blockVector.size(); i++) {
//        cout << blockVector[i] << " ";
//    }
//    cout << endl;

    return -1;
}

vector<int> unsortedArray(unsigned int size) {
    vector<int> unsortedArr(size);
    srand(time(0));
    for (unsigned int i = 0; i < unsortedArr.size(); i++) {
        unsortedArr[i] = rand() % 10;
    }
    return unsortedArr;
}

vector<int> sortedArray(unsigned int size, int multCoef = 1) {
    vector<int> unsortedArr(size);

    for (unsigned int i = 0; i < unsortedArr.size(); i++) {
        unsortedArr[i] = i * multCoef;
    }
    return unsortedArr;
}

template <typename T>
void printArray(vector<T> vector) {
    cout << endl << "Array: ";
    for (int i = 0; i < vector.size(); i++) {
        cout << to_string(vector[i]) << " ";
    }
    cout << endl;
}

template <typename T>
unsigned int trackTime(const T& func) {
    unsigned int startTime = clock();
    func();
    unsigned int stopTime = clock();
    return stopTime - startTime;
}

void firstPart() {
    cout << "Algoritms in unsorted arrays" << endl;
    int toSearch = 4;
    int index;
    cout << "To search: " << toSearch << endl;
    vector<int> arr = unsortedArray(10);
    printArray(arr);

    index = linearSearch(arr, toSearch);
    cout << "Linear: " << index << endl;

    index = fastLinearSearch(arr, toSearch);
    cout << "Fast linear: " << index << endl;
    cout << "-------------------------------" << endl;
}

void secondPart() {
    cout << "Algoritms in sorted arrays" << endl;
    unsigned int time;
    int toSearch = 0;
    int index;
    cout << "To search: " << toSearch << endl;

    vector<int> arr = sortedArray(20, 4);
    printArray(arr);

    index = sortLinearSearch(arr, toSearch);
    cout << "Linear search in sorted array: " << index << endl;
    index = binarySearch(arr, toSearch);
    cout << "Binary search: " << index << endl;
    index = blockSearch(arr, toSearch);
    cout << "Block search: " << index << endl;
    cout << "-------------------------------" << endl;
}

int main() {
    firstPart();
    secondPart();
    return 0;
}

