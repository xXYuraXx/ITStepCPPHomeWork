#include <iostream>
#include <Windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int sum_for = 0, sum_while = 0;
    for (int i = 4; i < 50; i += 4) {
        sum_for += i;
    }
    cout << "Сума чисел (for): " << sum_for << endl;

    int i = 4;
    while (i < 50) {
        sum_while += i;
        i += 4;
    }
    cout << "Сума чисел (while): " << sum_while << endl;



    int num;
    cout << "Введіть число: ";
    cin >> num;

    cout << "Числа від 0 до " << num << ": ";
    for (int i = 0; i <= num; i++) {
        cout << i << " ";
    }
    cout << endl;


    int lower, upper;
    cout << "Введіть межі діапазону: ";
    cin >> lower >> upper;

    if (lower > upper) {
        swap(lower, upper);
    }

    cout << "Числа в діапазоні: ";
    for (int i = lower; i <= upper; i++) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Парні числа: ";
    for (int i = lower; i <= upper; i++) {
        if (i % 2 == 0) {
            cout << i << " ";
        }
    }
    cout << endl;

    cout << "Непарні числа: ";
    for (int i = lower; i <= upper; i++) {
        if (i % 2 != 0) {
            cout << i << " ";
        }
    }
    cout << endl;

    cout << "Числа, кратні 7: ";
    for (int i = lower; i <= upper; i++) {
        if (i % 7 == 0) {
            cout << i << " ";
        }
    }
    cout << endl;

    int sum = 0;
    for (int i = lower; i <= upper; i++) {
        sum += i;
    }
    cout << "Сума чисел діапазону: " << sum << endl;



    int user_num, total_sum = 0;
    cout << "Введіть числа. Для завершення введіть 0." << endl;
    do {
        cin >> user_num;
        total_sum += user_num;
    } while (user_num != 0);

    cout << "Сума введених чисел: " << total_sum << endl;
}
