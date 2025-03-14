#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const string SEP_CODE = "\n=+=+=+=+=+=+=+=+=+\n\n";

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






    cout << SEP_CODE;

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




    cout << SEP_CODE;

    double num1, num2, num3;

    cout << "����� 1:" << endl;
    cin >> num1;
    cout << "����� 2:" << endl;
    cin >> num2;
    cout << "����� 3:" << endl;
    cin >> num3;

    if (num1 > 0 || num2 > 0 || num3 > 0) {
        cout << "����� ����� � ������" << endl;
    }
    else {
        cout << "����� ����� ���� �������" << endl;
    }




    cout << SEP_CODE;

    double num;

    cout << "�����:" << endl;
    cin >> num;

    if (num >= 2 && num <= 5) {
        cout << "����� ������ �� ����� [2, 5]" << endl;
    }
    else if (num >= -1 && num <= 1) {
        cout << "����� ������ �� ����� [-1, 1]" << endl;
    }
    else {
        cout << "����� �� ������ �� ����� [2, 5] �� [-1, 1]" << endl;
    }





    cout << SEP_CODE;

    double n1, n2, n3;
    cout << "����� 1:" << endl;
    cin >> n1;
    cout << "����� 2:" << endl;
    cin >> n2;
    cout << "����� 3:" << endl;
    cin >> n3;

    if (n1 == n2 && n2 == n3 && n1 == n3) {
        cout << "����� ��� �� �����" << endl;
    }
    else {
        cout << "����� �� ��� �� �����" << endl;
    }






    cout << SEP_CODE;

    double side_fig1, side_fig2, side_fig3, side_fig4;
    cout << "������� 1:" << endl;
    cin >> side_fig1;
    cout << "������� 2:" << endl;
    cin >> side_fig2;

    if (side_fig1 == side_fig2) {
        cout << "����������� � ���������" << endl;
    }
    else {
        cout << "����������� �� � ���������" << endl;
    }




    cout << SEP_CODE;
    
    int age;
    cout << "³�:" << endl;
    cin >> age;

    if (age < 0 || age > 140) {
        cout << "������� ��!" << endl;
    }
    else if (age < 2) {
        cout << "�� ������ � �����" << endl;
    }
    else if (age < 7) {
        cout << "���� ��������� � ��������" << endl;
    }
    else if (age < 18) {
        cout << "���� ��������� � ����" << endl;
    }
    else {
        cout << "���� ���������" << endl;
    }





    cout << SEP_CODE;

    double user_num;

    cout << "�����:" << endl;
    cin >> user_num;

    if (user_num >= 2 && user_num <= 5) {
        cout << "����� ������ �� ����� [2, 5]" << endl;
    }
    else if (user_num >= -1 && user_num <= 1) {
        cout << "����� ������ �� ����� [-1, 1]" << endl;
    }
    else {
        cout << "����� �� ������ �� ����� [2, 5] �� [-1, 1]" << endl;
    }





    cout << SEP_CODE;

    double user_num1, user_num2, user_num3;
    cout << "����� 1:" << endl;
    cin >> user_num1;
    cout << "����� 2:" << endl;
    cin >> user_num2;
    cout << "����� 3:" << endl;
    cin >> user_num3;

    if (
        (user_num1 == user_num2 && (user_num1 != user_num3 && user_num2 != user_num3)) ||
        (user_num1 == user_num3 && (user_num1 != user_num2 && user_num3 != user_num2)) ||
        (user_num2 == user_num3 && (user_num2 != user_num1 && user_num3 != user_num1))
        )
    {
        cout << "ҳ���� ��� ����� ��� �� �����" << endl;
    }
    else {
        cout << "����� \"ҳ���� ��� ����� ��� �� �����\" �� ������" << endl;
    }



    cout << SEP_CODE;

    int my_num1, my_num2, my_num3;
    cout << "����� 1:" << endl;
    cin >> my_num1;
    cout << "����� 2:" << endl;
    cin >> my_num2;
    cout << "����� 3:" << endl;
    cin >> my_num3;

    if ((my_num1 % 2 != 0) && (my_num2 % 2 != 0) && (my_num3 % 2 != 0)) {
        cout << "�� ����� ������" << endl;
    }
    else {
        cout << "�� �� ����� ������" << endl;
    }



    cout << SEP_CODE;

    double number1, number2;
    cout << "����� 1:" << endl;
    cin >> number1;
    cout << "����� 2:" << endl;
    cin >> number2;

    if (number1 != number2) {
        double temp;
        temp = number1;
        number1 = number2;
        number2 = temp;
    }
    cout << number1 << " " << number2 << endl;




    cout << SEP_CODE;

    short user_a;
    cout << "����� a:" << endl;
    cin >> user_a;
    short sum = user_a / 100 + user_a / 10 % 10 + user_a % 10;
    cout << "�����: " << sum << endl;
    cout << "����� �����: " << user_a / 100 << endl;
    cout << "������� �����: " << user_a % 10 << endl;




    
    cout << SEP_CODE;

    short hour;
    cout << "������:" << endl;
    cin >> hour;
    if (hour < 0 || hour > 23) {
        cout << "������ ������!" << endl;
    }
    else if (hour <= 3) {
        cout << "good night" << endl;
    }
    else if (hour <= 11) {
        cout << "good morning" << endl;
    }
    else if (hour <= 17) {
        cout << "good day" << endl;
    }
    else if (hour <= 23) {
        cout << "good evening" << endl;
    }





    cout << SEP_CODE;

    int u_num1, u_num2, u_num3;
    cout << "����� 1:" << endl;
    cin >> u_num1;
    cout << "����� 2:" << endl;
    cin >> u_num2;
    cout << "����� 3:" << endl;
    cin >> u_num3;
    cout << "�������� �����: " << endl;
    if (u_num1 <= u_num2 && u_num1 <= u_num3) {
        cout << u_num1 << endl;
    }
    else if (u_num2 <= u_num1 && u_num2 <= u_num3) {
        cout << u_num2 << endl;
    }
    else {
        cout << u_num3 << endl;
    }
}