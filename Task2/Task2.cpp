#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double brick_a, brick_b, brick_c;
    double hole_a, hole_b;

    cout << "������� ����� 1:" << endl;
    cin >> brick_a;
    cout << "������� ����� 2:" << endl;
    cin >> brick_b;
    cout << "������� ����� 3:" << endl;
    cin >> brick_c;

    cout << "����� ������ 1:" << endl;
    cin >> hole_a;
    cout << "����� ������ 2:" << endl;
    cin >> hole_b;

    if ((brick_a <= hole_a && (brick_b <= hole_b || brick_c <= hole_b))
        || (brick_b <= hole_a && (brick_a <= hole_b || brick_c <= hole_b))
        || (brick_c <= hole_a && (brick_a <= hole_b || brick_b <= hole_b))) {
        cout << "������" << endl;
    }
    else {
        cout << "�� ������" << endl;
    }

}