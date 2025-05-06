#include <iostream>
#include <conio.h>
using namespace std;

void Test1()
{
	const int size = 5;
	int arr[size];
}
void Test2()
{
	int size = 5;
	int* parr = new int[size];
	delete[]parr;
}

int* CreateArr(int size)//100
{
	int* arr = new int[size];
	return arr;
}

void FillArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		*(arr + i) = rand() % 100;
	}
}
void ShowArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << *(arr + i) << " ";
	}
	cout << endl;
}
int* AddNumber(int* arr, int* size, int number)
{
	(*size)++;//size = 6
	int* temp = new int[*size];
	for (int i = 0; i < (*size) - 1; i++)
	{
		temp[i] = arr[i];
	}
	temp[(*size) - 1] = number;
	delete[]arr;
	arr = temp;
	return arr;
}

int* AddByPosition(int* arr, int* size, int number, int pos)
{
	if (pos >= *size || pos < 0) return arr;
	(*size)++;
	int* temp = new int[*size];
	int i = 0;
	int j = 0;
	while (j < *size) {
		if (j == pos) {
			temp[j] = number;
			j++;
		}
		else {
			temp[j] = arr[i];
			i++;
			j++;
		}
	}

	delete[]arr;
	arr = temp;
	return arr;
}

int* RemoveByPos(int* arr, int* size, int pos) {
	if (pos >= *size || pos < 0) return arr;
	(*size)--;
	int* temp = new int[*size];
	int i = 0;
	int j = 0;
	while (j < *size) {
		if (i == pos) {
			i++;
		}
		else {
			temp[j] = arr[i];
			i++;
			j++;
		}
	}

	delete[]arr;
	arr = temp;
	return arr;
}
int* RemoveFirst(int* arr, int* size) {
	return RemoveByPos(arr, size, 0);
}
int* RemoveLast(int* arr, int* size) {
	return RemoveByPos(arr, size, (*size)-1);
}

int main()
{
	srand(time(0));
	int size = 5;
	int* arr = CreateArr(size);
	FillArr(arr, size);
	ShowArr(arr, size);

	int number;
	int index;
	char choice = 'y';
	while (true)
	{
		system("cls");
		ShowArr(arr, size);
		cout << "Insert number (i) | remove by pos (r) | remove first (f) | remove last (l)?";
		choice = _getch();
		if (choice == 'i') {
			cout << "\nEnter number : ";
			cin >> number;
			cout << "Enter index : ";
			cin >> index;
			arr = AddByPosition(arr, &size, number, index);
		}
		else if (choice == 'r') {
			cout << "\nEnter index : ";
			cin >> index;
			arr = RemoveByPos(arr, &size, index);
		}
		else if (choice == 'f') {
			arr = RemoveFirst(arr, &size);
		}
		else if (choice == 'l') {
			arr = RemoveLast(arr, &size);
		}
		

		

	}

	delete[]arr;
}