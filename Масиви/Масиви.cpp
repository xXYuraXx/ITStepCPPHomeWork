#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int arr[10];
    long long mult = 1;
    for (int i = 0; i < 10; ++i) {
        cout << "Елемент [" << i << "] = ";
        cin >> arr[i];
        mult *= arr[i];
    }
    cout << "Mult = " << mult << endl;
    cout << endl;


    int Arr[10];
    int count_minus = 0;
    int count_plus = 0;
    for (int i = 0; i < 7; ++i) {
        Arr[i] = (rand() % 63) - 12;
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
    cout << endl;


    long ARr[10];
    long sum_even = 0;
    for (int i = 0; i < 10; ++i) {
        ARr[i] = (rand() % 101);
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
    cout << endl;


    int ARR1[30];
    ARR1[0] = 2;
    for (int i = 1; i < 30; ++i) {
        ARR1[i] = ARR1[i-1] * 2;
    }
    for (int i = 0; i < 30; ++i) {
        cout << ARR1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 30; ++i) {
        cout << ARR1[29 - i] << " ";
    }
    cout << endl;
    cout << endl;


    int ARR[10];
    for (int i = 0; i < 10; ++i) {
        ARR[i] = (rand() % 63) - 12;
    }
    for (int i = 0; i < 10; ++i) {
        cout << ARR[i] << " ";
    }
    cout << endl;
    cout << "Absoluete values" << endl;
    for (int i = 0; i < 10; ++i) {

        if (ARR[i] < 0) ARR[i] = ARR[i] * -1;
        cout << ARR[i] << " ";
    }
    cout << endl;

}