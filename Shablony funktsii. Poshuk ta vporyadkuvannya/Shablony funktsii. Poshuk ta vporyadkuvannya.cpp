#include <iostream>

using namespace std;


template <typename T>
void selection_sort(T arr[], int size, bool isZrostanna = true) {
    if (size < 1) return;
    for (int i = 0; i < size; ++i) {
        int cur_idx = i;
        for (int j = i + 1; j < size; ++j) {
            if (isZrostanna ? arr[j] < arr[cur_idx] : arr[j] > arr[cur_idx]) {
                cur_idx = j;
            }
        }
        swap(arr[i], arr[cur_idx]);
    }
}

template <typename T>
void bubble_sort(T arr[], int size, bool isZrostanna = true) {
    if (size < 1) return;
    bool isChanged = true;
    while (isChanged) {
        isChanged = false;
        for (int i = 1; i < size; ++i) {
            if (isZrostanna ? arr[i] < arr[i - 1] : arr[i] > arr[i - 1]) {
                isChanged = true;
                swap(arr[i], arr[i-1]);
            }
        }
    }
}

template <typename T>
void part_bubble_sort(T arr[], int size) {
    bubble_sort(arr, size / 2);
    bubble_sort(arr + (size - (size / 2)), size - (size / 2), false);
}


void fillArray(int arr[], int size, int randMax = 100, int minus = 0) {
    for (int i = 0; i < size; ++i)
        arr[i] = (rand() % randMax) - minus;
}

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
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
template<typename T>
void sort_between_minus(T arr, int size) {
    int idxF = minusIdxFirst(arr, size);
    int idxL = minusIdxLast(arr, size);
    if (idxF != -1) {
        bubble_sort(arr + idxF, (idxL + 1) - idxF);
    }
}





const int SIZE_M = 3;
// Не запитую розмір бо по умові має бути квадратна матриця
// але при ініціалізації функції потрібно вказати хочаб один
// з розмірів, але тоді якщо вона квадратна то вони однакові
template<typename T>
void fillMatrixByUser(T matrix[SIZE_M][SIZE_M]) {
    for (int i = 0; i < SIZE_M; ++i)
        for (int j = 0; j < SIZE_M; ++j)
            cin >> matrix[i][j];
}

template<typename T>
void printMatrix(const T matrix[SIZE_M][SIZE_M]) {
    for (int i = 0; i < SIZE_M; ++i) {
        for (int j = 0; j < SIZE_M; ++j)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

template<typename T>
T minMatrixDiag(const T matrix[SIZE_M][SIZE_M]) {
    T min_el = matrix[0][0];
    for (int i = 0; i < SIZE_M; ++i) {
        if (matrix[i][i] < min_el)
            min_el = matrix[i][i];
    }
    return min_el;
}

template<typename T>
T maxMatrixDiag(const T matrix[SIZE_M][SIZE_M]) {
    T max_el = matrix[0][0];
    for (int i = 0; i < SIZE_M; ++i) {
        if (matrix[i][i] > max_el)
            max_el = matrix[i][i];
    }
    return max_el;
}

template<typename T>
void sortMatrix(T matrix[SIZE_M][SIZE_M]) {
    for (int i = 0; i < SIZE_M; ++i) {
        bubble_sort(matrix[i], SIZE_M);
    }
}

template<typename T>
void showMatrixOperations(T matrix[SIZE_M][SIZE_M], string type_name) {
    cout << "Vvedit` matrix !!!" << type_name << "!!! rozmirom " << SIZE_M << "x" << SIZE_M << endl;
    fillMatrixByUser(matrix);
    cout << "Max po golovniy diagonali: " << maxMatrixDiag(matrix) << endl;
    cout << "Min po golovniy diagonali: " << minMatrixDiag(matrix) << endl;
    sortMatrix(matrix);
    printMatrix(matrix);
}


int main()
{
    const int size1 = 8;
    int arr1[size1];
    fillArray(arr1, size1, 100, 50);
    printArray(arr1, size1);
    selection_sort(arr1, size1);
    printArray(arr1, size1);
    selection_sort(arr1, size1, false);
    printArray(arr1, size1);

    cout << endl;

    const int size2 = 9;
    int arr2[size2];
    fillArray(arr2, size2, 100, 50);
    printArray(arr2, size2);
    part_bubble_sort(arr2, size2);
    printArray(arr2, size2);

    cout << endl;

    const int size3 = 9;
    int arr3[size3];
    fillArray(arr3, size3, 41, 20);

    // Щоб було точно видно що самн між відємними числами сортується, тому ставлю невідємні по кінцях
    arr3[0] = rand() % 20; 
    arr3[size3 - 1] = rand() % 20;

    printArray(arr3, size3);
    sort_between_minus(arr3, size3);
    printArray(arr3, size3);

    cout << endl;

    int matrix1[SIZE_M][SIZE_M];
    showMatrixOperations(matrix1, "INT");

    char matrix2[SIZE_M][SIZE_M];
    showMatrixOperations(matrix2, "CHAR");



    



}