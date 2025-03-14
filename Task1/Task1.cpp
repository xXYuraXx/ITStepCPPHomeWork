#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double a, b, c;

    cout << "Сторона трикутника 1:" << endl;
    cin >> a;
    cout << "Сторона трикутника 2:" << endl;
    cin >> b;
    cout << "Сторона трикутника 3:" << endl;
    cin >> c;

    if (a == b && a == c && b == c) {
        cout << "Рівносторонній трикутник" << endl;
    }
    else if (a == b || b == c || a == c) {
        cout << "Рівнобедренний трикутник" << endl;
    }
    else if (a * a == b * b + c * c || b * b == a * a + c * c || c * c == b * b + a * a) {
        cout << "Прямокутний трикутник" << endl;
    }
    else {
        cout << "Трикутника не існує" << endl;
    }

}