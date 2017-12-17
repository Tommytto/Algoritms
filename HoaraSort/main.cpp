using namespace std;
#include <iostream>
#include <vector>

//void quickSort(vector<int> &a, int first,int last)
//{
//    int i=first;
//    int j=last;
//    int mid=a[(first+last)/2];
//    while(i<=j)
//    {
//        while(a[i]<mid) i++;
//        while(a[j]>mid) j--;
//        if(i<=j)
//        {
//            swap(a[i],a[j]);
//            i++;
//            j--;
//        }
//    }
//    if(i<last)
//        quickSort(a, i,last);
//    if(first<j)
//        quickSort(a, first,j);
//}

void quickSort(vector<int> & arr, int left, int right) {
    int i = left;
    int j = right;
    int pivot = arr[(left + right)/2];
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            swap(arr[i++], arr[j--]);
        }
    }
    if (i < right) {
        quickSort(arr, i, right);
    }
    if (left < j) {
        quickSort(arr, left, j);
    }
}


int main() {
    const int N = 10;
    vector<int> arr(N);
    srand(time(0));
    for (int i = 0; i < N; ++i) {
        arr[i] = (rand() % 10);
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSort(arr, 0, N - 1);
    for (int i = 0; i < N; ++i) {
        cout << arr[i] << " ";
    }
    return 0;
}