#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double brick_a, brick_b, brick_c;
    double hole_a, hole_b;

    cout << "Сторона цегли 1:" << endl;
    cin >> brick_a;
    cout << "Сторона цегли 2:" << endl;
    cin >> brick_b;
    cout << "Сторона цегли 3:" << endl;
    cin >> brick_c;

    cout << "Розмір отвора 1:" << endl;
    cin >> hole_a;
    cout << "Розмір отвора 2:" << endl;
    cin >> hole_b;

    if ((brick_a <= hole_a && (brick_b <= hole_b || brick_c <= hole_b))
        || (brick_b <= hole_a && (brick_a <= hole_b || brick_c <= hole_b))
        || (brick_c <= hole_a && (brick_a <= hole_b || brick_b <= hole_b))) {
        cout << "Пройде" << endl;
    }
    else {
        cout << "Не пройде" << endl;
    }

}