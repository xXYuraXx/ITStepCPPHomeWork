#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double a, b, c;

    cout << "������� ���������� 1:" << endl;
    cin >> a;
    cout << "������� ���������� 2:" << endl;
    cin >> b;
    cout << "������� ���������� 3:" << endl;
    cin >> c;

    if (a == b && a == c && b == c) {
        cout << "г����������� ���������" << endl;
    }
    else if (a == b || b == c || a == c) {
        cout << "г������������ ���������" << endl;
    }
    else if (a * a == b * b + c * c || b * b == a * a + c * c || c * c == b * b + a * a) {
        cout << "����������� ���������" << endl;
    }
    else {
        cout << "���������� �� ����" << endl;
    }

}