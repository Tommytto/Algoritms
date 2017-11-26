#include <iostream>
#include <vector>
#include <cmath>

class vector;

int binarySearch(std::vector<int> sortedVector, int digitToSearch) {
    const int vectorSize = sortedVector.size();
    int left = 0;
    int right = vectorSize;
    int searchIndex = -1;

    while (1) {
        int midd = (left + right)/2;
        if (digitToSearch < sortedVector[midd]) {
            right = midd - 1;
        } else if (digitToSearch > sortedVector[midd]) {
            left = midd + 1;
        } else {
            return midd;
        }

        if (left > right) {
            return -1;
        }
    }
}

int interpolationSearch(std::vector<int> sortedVector, int digitToSearch) {
    const int vectorSize = sortedVector.size();
    int left = 0;
    int right = vectorSize - 1;
    int x = 0;
    while ((sortedVector[left] < digitToSearch) && (sortedVector[right] > digitToSearch)) {
        x = left + ((digitToSearch - sortedVector[left]) * (right - left)) / (sortedVector[right] - sortedVector[left]);
        if (sortedVector[x] < digitToSearch) {
            left = x + 1;
        } else if (sortedVector[x] > digitToSearch) {
            right = x - 1;
        } else {
            break;
        }
    }

    if (sortedVector[left] == digitToSearch) {
        return left;
    } else if (sortedVector[right] == digitToSearch) {
        return right;
    } else if (sortedVector[x] == digitToSearch) {
        return x;
    } else return -1;
}

int main() {
    int SIZE = 100 * 25;
    int digitToSearch = 9;
    std::vector<int> sortedVector(SIZE);

    for (int i = 0; i < sortedVector.size(); i++) {
        sortedVector[i] = i;
//        std::cout << sortedVector[i];
    }
    unsigned int startTime = clock();
    int index = binarySearch(sortedVector, digitToSearch);
    unsigned int stopTime = clock();

    unsigned int binaryTime = stopTime - startTime;

    startTime = clock();
    int indexInter = interpolationSearch(sortedVector, digitToSearch);
    stopTime = clock();

    unsigned int interTime = stopTime - startTime;

    std::cout << "\n";
    std::cout << "Размер массива: " << SIZE << " (Массив сразу отсортирован как 0,1,2,3,4...N-1)" << std::endl;
    std::cout << "Искомое число: " << digitToSearch << std::endl;
    std::cout << "Результат бинарного поиска: " << index << std::endl;
    std::cout << "Результат интерполяционного поиска: " << indexInter << std::endl;
    std::cout << "Время бинарного поиска: " << binaryTime << std::endl;
    std::cout << "Время интерполяционного поиска: " << interTime << std::endl;

    return 0;
}