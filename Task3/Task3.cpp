#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double a, b, c;

    cout << "����� 1:" << endl;
    cin >> a;
    cout << "����� 2:" << endl;
    cin >> b;
    cout << "����� 3:" << endl;
    cin >> c;

    if (a > 0 || b > 0 || c > 0) {
        cout << "����� ����� � ������" << endl;
    }
    else {
        cout << "����� ����� ���� �������" << endl;
    }

}