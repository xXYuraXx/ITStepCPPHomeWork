#include <iostream>
#include <conio.h>

using namespace std;

int maxOfTwoByPointers(int* num1, int* num2) {
    if (*num1 > *num2) return *num1;
    return *num2;
}

char charOfNum(int* num) {
    if (*num > 0) return '+';
    else if (*num < 0) return '-';
    else return NULL;
}

void swapNums(int* num1, int* num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void myCalc(double num1, double num2, char op) {
    double num;
    cout << endl;
    switch (op)
    {
    case '-':
        num = num1 - num2; break;
    case '+':
        num = num1 + num2; break;
    case '*':
        num = num1 * num2; break;
    case '/':
        if (num2 == 0) {
            cout << "Error, second divide by 0!" << endl;
            return;
        }
        num = num1 / num2;
        break;
    default:
        cout << "Error, can't find operation!" << endl;
        return;
    }
    cout << num1 << " " << op << " " << num2 << " = " << num << endl;
}

void fillArray(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        *(arr + i) = rand() % 30;
    }
}
void printArray(const int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}
int sumOfArray(const int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += *(arr + i);
    }
    return sum;
}

int main()
{
    srand(time(0));
    int num1, num2;
    cout << "num1: ";
    cin >> num1;
    cout << "num2: ";
    cin >> num2;
    cout << "max: " << maxOfTwoByPointers(&num1, &num2) << endl;

    int numForChar;
    cout << "Enter num to discover char: ";
    cin >> numForChar;
    cout << "char: " << charOfNum(&numForChar) << endl;

    int numChange1, numChange2;
    cout << "num1: ";
    cin >> numChange1;
    cout << "num2: ";
    cin >> numChange2;
    cout << "Changing..." << endl;
    swapNums(&numChange1, &numChange2);
    cout << "num1 now: " << numChange1 << endl;
    cout << "num2 now: " << numChange2 << endl;

    double numCalc1, numCalc2;
    char operation;
    cout << "num1: ";
    cin >> numCalc1;
    cout << "num2: ";
    cin >> numCalc2;
    cout << "operation: ";
    operation = _getch();
    myCalc(numCalc1, numCalc2, operation);

    int n;
    cout << "Enter len of array: ";
    cin >> n;
    int* arr = new int[n];
    fillArray(arr, n);
    printArray(arr, n);
    cout << "sum of array: " << sumOfArray(arr, n) << endl;

    delete[] arr;
    

}