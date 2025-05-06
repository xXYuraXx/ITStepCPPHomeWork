#include <iostream>

using namespace std;

void fillArray(int arr[], int size, int randMax = 100, int randMin = 0) {
    for (int i = 0; i < size; ++i)
        arr[i] = (rand() % (randMax + 1 - randMin)) + randMin;
}

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int _partition(int arr[], int low, int high, bool isZrost) {
    int pivot = arr[high];
    int l = low - 1;

    for (int i = low; i < high; i++) {
        if (isZrost ? arr[i] <= pivot : arr[i] >= pivot) {
            l++;
            swap(arr[l], arr[i]);
        }
    }

    swap(arr[l + 1], arr[high]);
    return l + 1;
}

void _quick_sort(int arr[], int low, int high, bool isZrost) {
    if (low < high) {
        int pivot_idx = _partition(arr, low, high, isZrost);

        _quick_sort(arr, low, pivot_idx - 1, isZrost);
        _quick_sort(arr, pivot_idx + 1, high, isZrost);
    }
}

void quick_sort(int arr[], int size, bool isZrost = true) {
    _quick_sort(arr, 0, size - 1, isZrost);
}

int minusIdxFirst(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] < 0) return i;
    }
    return -1;
}
int minusIdxLast(const int arr[], int size) {
    for (int i = size - 1; i >= 0; --i) {
        if (arr[i] < 0) return i;
    }
    return -1;
}

void makeRangeArr(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = i+1;
    }
}
void shafleArr(int arr[], int size, int times) {
    for (int i = 0; i < times; ++i) {
        swap(arr[rand()%size], arr[rand() % size]);
    }
}
int findElIdx(const int arr[], int size, int el) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == el) return i;
    }
}

int main()
{
    srand(time(0));
    const int SIZE1 = 10;
    int arr1[SIZE1];
    fillArray(arr1, SIZE1);
    quick_sort(arr1, SIZE1, 1);
    printArray(arr1, SIZE1);
    quick_sort(arr1, SIZE1, 0);
    printArray(arr1, SIZE1);

    cout << "==========" << endl;

    const int SIZE2 = 10;
    int arr2[SIZE2];
    fillArray(arr2, SIZE2, 20, -20);
    printArray(arr2, SIZE2);
    int idxFirst = minusIdxFirst(arr2, SIZE2);
    int idxLast = minusIdxLast(arr2, SIZE2);
    if (idxFirst != -1 && idxLast != -1) {
        _quick_sort(arr2, idxFirst+1, idxLast-1, true);
        printArray(arr2, SIZE2);
    }
    else {
        cout << "There is no at least two number less than zero!" << endl;
    }
    
    cout << "==========" << endl;


    const int SIZE3 = 20;
    int arr3[SIZE3];
    makeRangeArr(arr3, SIZE3);
    shafleArr(arr3, SIZE3, 100);
    printArray(arr3, SIZE3);
    int randNum = rand() % 20 + 1;
    int numPos = findElIdx(arr3, SIZE3, randNum);
    cout << "random num: " << randNum << endl;
    cout << "random num pos: " << numPos << endl;
    if (numPos != 0)
        _quick_sort(arr3, 0, numPos-1, false);
    if (numPos != SIZE3 - 1)
        _quick_sort(arr3, numPos+1, SIZE3-1, true);
    printArray(arr3, SIZE3);
    


}