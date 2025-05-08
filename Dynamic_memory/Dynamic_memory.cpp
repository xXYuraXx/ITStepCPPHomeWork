#include <iostream>

using namespace std;

int* Create_arr(int size) {
    int* arr = new int[size];
    return arr;
}

void Fill_arr(int* arr, int size, int randMax = 100, int randMin = 0) {
    for (int i = 0; i < size; ++i) {
        arr[i] = (rand() % (randMax + 1 - randMin)) + randMin;
    }
}

void Print_arr(const int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int* num1 = new int(7);
    float* num2 = new float(5.63f);
    char* num3 = new char('a');
    double mult = (*num2) * (*num1) * (*num3);
    cout << "Multy of 3 dynamic var: " << mult << endl;

    int* arr;
    int n;
    cout << "Enter arr size: ";
    cin >> n;
    arr = Create_arr(n);
    Fill_arr(arr, n);
    Print_arr(arr, n);

    delete[] arr;

}