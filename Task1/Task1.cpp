#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const string SEP_CODE = "\n=+=+=+=+=+=+=+=+=+\n\n";

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






    cout << SEP_CODE;

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




    cout << SEP_CODE;

    double num1, num2, num3;

    cout << "Число 1:" << endl;
    cin >> num1;
    cout << "Число 2:" << endl;
    cin >> num2;
    cout << "Число 3:" << endl;
    cin >> num3;

    if (num1 > 0 || num2 > 0 || num3 > 0) {
        cout << "Серед чисел є додатнє" << endl;
    }
    else {
        cout << "Серед чисел нема додатніх" << endl;
    }




    cout << SEP_CODE;

    double num;

    cout << "Число:" << endl;
    cin >> num;

    if (num >= 2 && num <= 5) {
        cout << "Число лежить на межах [2, 5]" << endl;
    }
    else if (num >= -1 && num <= 1) {
        cout << "Число лежить на межах [-1, 1]" << endl;
    }
    else {
        cout << "Число не лежить на межах [2, 5] та [-1, 1]" << endl;
    }





    cout << SEP_CODE;

    double n1, n2, n3;
    cout << "Число 1:" << endl;
    cin >> n1;
    cout << "Число 2:" << endl;
    cin >> n2;
    cout << "Число 3:" << endl;
    cin >> n3;

    if (n1 == n2 && n2 == n3 && n1 == n3) {
        cout << "Числа рівні між собою" << endl;
    }
    else {
        cout << "Числа не рівні між собою" << endl;
    }






    cout << SEP_CODE;

    double side_fig1, side_fig2, side_fig3, side_fig4;
    cout << "Сторона 1:" << endl;
    cin >> side_fig1;
    cout << "Сторона 2:" << endl;
    cin >> side_fig2;

    if (side_fig1 == side_fig2) {
        cout << "Прямокутник є квадратом" << endl;
    }
    else {
        cout << "Прямокутник не є квадратом" << endl;
    }




    cout << SEP_CODE;
    
    int age;
    cout << "Вік:" << endl;
    cin >> age;

    if (age < 0 || age > 140) {
        cout << "Невірний вік!" << endl;
    }
    else if (age < 2) {
        cout << "Ще зарано в садок" << endl;
    }
    else if (age < 7) {
        cout << "Може навчатись в дитсадку" << endl;
    }
    else if (age < 18) {
        cout << "Може навчатись в школі" << endl;
    }
    else {
        cout << "Може працювати" << endl;
    }





    cout << SEP_CODE;

    double user_num;

    cout << "Число:" << endl;
    cin >> user_num;

    if (user_num >= 2 && user_num <= 5) {
        cout << "Число лежить на межах [2, 5]" << endl;
    }
    else if (user_num >= -1 && user_num <= 1) {
        cout << "Число лежить на межах [-1, 1]" << endl;
    }
    else {
        cout << "Число не лежить на межах [2, 5] та [-1, 1]" << endl;
    }





    cout << SEP_CODE;

    double user_num1, user_num2, user_num3;
    cout << "Число 1:" << endl;
    cin >> user_num1;
    cout << "Число 2:" << endl;
    cin >> user_num2;
    cout << "Число 3:" << endl;
    cin >> user_num3;

    if (
        (user_num1 == user_num2 && (user_num1 != user_num3 && user_num2 != user_num3)) ||
        (user_num1 == user_num3 && (user_num1 != user_num2 && user_num3 != user_num2)) ||
        (user_num2 == user_num3 && (user_num2 != user_num1 && user_num3 != user_num1))
        )
    {
        cout << "Тільки два числа рівні між собою" << endl;
    }
    else {
        cout << "Умова \"Тільки два числа рівні між собою\" не працює" << endl;
    }



    cout << SEP_CODE;

    int my_num1, my_num2, my_num3;
    cout << "Число 1:" << endl;
    cin >> my_num1;
    cout << "Число 2:" << endl;
    cin >> my_num2;
    cout << "Число 3:" << endl;
    cin >> my_num3;

    if ((my_num1 % 2 != 0) && (my_num2 % 2 != 0) && (my_num3 % 2 != 0)) {
        cout << "Всі числа непарні" << endl;
    }
    else {
        cout << "Не всі числа непарні" << endl;
    }



    cout << SEP_CODE;

    double number1, number2;
    cout << "Число 1:" << endl;
    cin >> number1;
    cout << "Число 2:" << endl;
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
    cout << "Число a:" << endl;
    cin >> user_a;
    short sum = user_a / 100 + user_a / 10 % 10 + user_a % 10;
    cout << "Сумма: " << sum << endl;
    cout << "Перша цифра: " << user_a / 100 << endl;
    cout << "Остання цифра: " << user_a % 10 << endl;




    
    cout << SEP_CODE;

    short hour;
    cout << "Година:" << endl;
    cin >> hour;
    if (hour < 0 || hour > 23) {
        cout << "Невірна година!" << endl;
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
    cout << "Число 1:" << endl;
    cin >> u_num1;
    cout << "Число 2:" << endl;
    cin >> u_num2;
    cout << "Число 3:" << endl;
    cin >> u_num3;
    cout << "Найменше число: " << endl;
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