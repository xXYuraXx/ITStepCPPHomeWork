#include <iostream>
#include <Windows.h>

using namespace std;

void printArr(const int arr[], const int SIZE) {
	for (int i = 0; i < SIZE; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void rewriteArr(int arr[], const int SIZE) {
	for (int i = 0; i < SIZE; ++i) {
		cout << "arr[" << i << "] = ";
		cin >> arr[i];
	}
}

void increaseArr(int arr[], const int SIZE, const int value) {
	for (int i = 0; i < SIZE; ++i) {
		arr[i] += value;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// ��������� ������� 1) �������� ����� �� ����� 2) ������� ����� � ��������� 3) ������ �� �������� �� ������ ����� value (value - �������� �������)
	//��������� ������ �������.
		//**** �� �������� ������� ���������(����) ��������, ����� �������� ������ �������� �� 1, ����� �������� - �������� �� 1

	const int SIZE = 5;
	int arr[SIZE] = { 5, 7, 4, 12, 45 };
	printArr(arr, SIZE);
	rewriteArr(arr, SIZE);
	printArr(arr, SIZE);
	increaseArr(arr, SIZE / 2, 1);
	printArr(arr, SIZE);
	increaseArr(arr + SIZE / 2, SIZE / 2 + 1, -1);
	printArr(arr, SIZE);


}
// ��������� ������������ ������� ��� ������ ������� ������ ����� ���� �����, ����� ����� �� ������������ �����.