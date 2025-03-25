#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char country;
    cout << "Країна (u - Україна, f - Франція, g - Німеччина, j - Японія, a - США): ";
    cin >> country;
    switch (country) {
        case 'u': cout << "Київ\n"; break;
        case 'f': cout << "Париж\n"; break;
        case 'g': cout << "Берлін\n"; break;
        case 'j': cout << "Токіо\n"; break;
        case 'a': cout << "Вашингтон\n"; break;
        default: cout << "Невідома\n";
    }
        

    int day;
    cout << "День (1-7): ";
    cin >> day;
    switch (day) {
        case 6: case 7: cout << "Вихідний\n"; break;
        case 1: case 2: case 3: case 4: case 5: cout << "Робочий\n"; break;
        default: cout << "Помилка\n";
    }

    char direction;
    cout << "Курс (n, s, w, e): ";
    cin >> direction;
    switch (direction) {
        case 'n': cout << "south\n"; break;
        case 's': cout << "north\n"; break;
        case 'w': cout << "east\n"; break;
        case 'e': cout << "west\n"; break;
        default: cout << "Невідомий\n";
    }

    int animal;
    cout << "Тварина (1-Жираф, 2-Орел, 3-Лев, 4-Кінь, 5-Вовк, 6-Корова, 7-Тигр): ";
    cin >> animal;
    switch (animal) {
        case 1: case 4: case 6: cout << "Травоїдна\n"; break;
        case 2: case 3: case 5: case 7: cout << "Хижак\n"; break;
        default: cout << "Невідомо\n";
    }

        




    int i1 = 1;
    while (i1 <= 100) {
        cout << i1 << " ";
        i1++;
    }
    cout << endl;


    int count1 = 0, num1 = 2;
    while (num1 <= 200) {
        cout << num1 << " ";
        num1 += 2;
        count1++;
    }
    cout << "\nКількість парних чисел: " << count1 << endl;


    int n1, sum1 = 0;
    cout << "Введіть N (N > 0): ";
    cin >> n1;
    int i2 = 1;
    while (i2 <= n1) {
        int num2;
        cout << "Введіть число: ";
        cin >> num2;
        if (num2 % 2 == 0) sum1 += num2;
        i2++;
    }
    cout << "Сума парних чисел: " << sum1 << endl;


    int sum2 = 0, i4 = 1;
    while (i4 <= 10) {
        int num3;
        cout << "Введіть число: ";
        cin >> num3;
        sum2 += num3;
        i4++;
    }
    cout << "Сума чисел: " << sum2 << endl;
    cout << "Середнє арифметичне: " << sum2 / 10.0 << endl;


    int n2, sum3 = 0, i5 = 1;
    cout << "Введіть n: ";
    cin >> n2;
    int count = 0;
    do {
        cout << i5 << " : " << i5 * i5 << endl;
        sum3 += i5 * i5;
        i5 += 2;
        count++;
    } while (count < n2);
    cout << "Сума квадратів: " << sum3 << endl;



    int num4 = 100;
    do {
        cout << num4 << " ";
        num4--;
    } while (num4 >= 1);
    cout << endl;



    int sum4 = 0, i6 = 1, num5;
    do {
        cout << "Введіть число " << i6 << ": ";
        cin >> num5;
        sum4 += num5;
        i6++;
    } while (i6 <= 7);
    cout << "Сума чисел: " << sum4 << endl;



    int num6 = 14;
    while (num6 <= 123) {
        cout << num6 << " ";
        num6++;
    }
    cout << endl;



    int num7 = 1;
    while (num7 <= 100) {
        cout << num7 << " ";
        num7 += 2;
    }
    cout << endl;



}
