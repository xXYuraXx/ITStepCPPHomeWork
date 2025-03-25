#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    /*int arr[10];
    long long mult = 1;
    for (int i = 0; i < 10; ++i) {
        cout << "Елемент [" << i << "] = ";
        cin >> arr[i];
        mult *= arr[i];
    }
    cout << "Mult = " << mult << endl;*/


    int Arr[10];
    int count_minus = 0;
    int count_plus = 0;
    for (int i = 0; i < 7; ++i) {
        Arr[i] = (rand() % 40) - 20;
    }
    for (int i = 0; i < 7; ++i) {
        cout << Arr[i] << " ";
        if (Arr[i] >= 0)
            count_plus++;
        else
            count_minus++;
    }
    cout << endl;
    cout << "Count plus: " << count_plus << endl;
    cout << "Count minus: " << count_minus << endl;


    int ARr[10];
    int sum_even = 0;
    for (int i = 0; i < 10; ++i) {
        ARr[i] = (rand() % 40) - 20;
    }
    for (int i = 0; i < 10; ++i) {
        cout << ARr[i] << " ";
        if (ARr[i] % 2 == 0)
        {
            sum_even += ARr[i];
        }

    }
    cout << endl;
    cout << "Sum even: " << sum_even << endl;


    int ARR1[10];
    for (int i = 0; i < 10; ++i) {
        ARR1[i] = (rand() % 40) - 20;
    }
    for (int i = 0; i < 10; ++i) {
        cout << ARR1[i] << " ";
    }
    cout << endl;
    cout << "Absoluete values" << endl;
    for (int i = 0; i < 10; ++i) {
        ARR1[i] = abs(ARR1[i]);
        cout << ARR1[i] << " ";
    }
    cout << endl;


    int ARR[10];
    for (int i = 0; i < 10; ++i) {
        ARR[i] = (rand() % 40) - 20;
    }
    for (int i = 0; i < 10; ++i) {
        cout << ARR[i] << " ";
    }
    cout << endl;
    cout << "Absoluete values" << endl;
    for (int i = 0; i < 10; ++i) {
        ARR[i] = abs(ARR[i]);
        cout << ARR[i] << " ";
    }
    cout << endl;

}