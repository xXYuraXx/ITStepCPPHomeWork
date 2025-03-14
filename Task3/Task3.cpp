#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double a, b, c;

    cout << "Число 1:" << endl;
    cin >> a;
    cout << "Число 2:" << endl;
    cin >> b;
    cout << "Число 3:" << endl;
    cin >> c;

    if (a > 0 || b > 0 || c > 0) {
        cout << "Серед чисел є додатнє" << endl;
    }
    else {
        cout << "Серед чисел нема додатніх" << endl;
    }

}