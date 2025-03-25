#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int H;
    cout << "Введіть висоту трикутника: ";
    cin >> H;
    string c = "# ";
    string e = ". ";

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if (i > j)
                cout << c;
            else
                cout << e;
        }
        cout << endl;
    }
    cout << endl << endl;


    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if (i < j)
                cout << c;
            else
                cout << e;
        }
        cout << endl;
    }
    cout << endl << endl;


    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if ((i + j) > (H - 1))
                cout << c;
            else
                cout << e;
        }
        cout << endl;
    }
    cout << endl << endl;


    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if ((i + j) < (H - 1))
                cout << c;
            else
                cout << e;
        }
        cout << endl;
    }
    cout << endl << endl;


    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if (((i + j) > (H - 1)) && (i > j))
                cout << c;
            else
                cout << e;
        }
        cout << endl;
    }
    cout << endl << endl;


    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if (((i + j) < (H - 1)) && (i < j))
                cout << c;
            else
                cout << e;
        }
        cout << endl;
    }
    cout << endl << endl;


    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if ((((i + j) > (H - 1)) && (i > j)) || (((i + j) < (H - 1)) && (i < j)))
                cout << c;
            else
                cout << e;
        }
        cout << endl;
    }
    cout << endl << endl;


    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if ((i > j) && ((i + j) < (H - 1)))
                cout << c;
            else
                cout << e;
        }
        cout << endl;
    }
    cout << endl << endl;


    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if ((i < j) && ((i + j) > (H - 1)))
                cout << c;
            else
                cout << e;
        }
        cout << endl;
    }
    cout << endl << endl;


    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if (((i > j) && ((i + j) < (H - 1))) || ((i < j) && ((i + j) > (H - 1))))
                cout << c;
            else
                cout << e;
        }
        cout << endl;
    }
    cout << endl << endl;
    




    int num, digitCount = 0, sum = 0, zeroCount = 0;
    double average;

    cout << "Введіть число: ";
    cin >> num;

    if (num < 0) {
        num = abs(num);
    }

    while (num > 0) {
        int digit = num % 10;
        sum += digit;
        digitCount++;
        if (digit == 0) {
            zeroCount++;
        }
        num /= 10;
    }

    if (digitCount > 0) {
        average = double(sum) / digitCount;
    }
    else {
        average = 0;
    }

    cout << "Кількість цифр: " << digitCount << endl;
    cout << "Сума цифр: " << sum << endl;
    cout << "Середнє арифметичне: " << average << endl;
    cout << "Кількість нулів: " << zeroCount << endl;






    int cellSize, boardSize;

    cout << "Введіть розмір клітинки: ";
    cin >> cellSize;
    cout << "Введіть розмір шахової дошки: ";
    cin >> boardSize;

    for (int i = 0; i < boardSize * cellSize; i++) {
        for (int j = 0; j < boardSize * cellSize; j++) {
            if (((i / cellSize) + (j / cellSize)) % 2 == 0) {
                cout << "*";
            }
            else {
                cout << "-";
            }
        }
        cout << endl;
    }
}
