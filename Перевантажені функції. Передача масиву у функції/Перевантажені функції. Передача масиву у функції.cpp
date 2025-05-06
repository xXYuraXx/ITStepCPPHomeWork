#include <iostream>
#include <cmath>

using namespace std;

const int SIZE_M = 5;
const string END_TASK_TEXT = "==================================";
const string END_MINI_TASK_TEXT = "------------------";

bool isSimple(int n) {
	if (n < 2) return false;
	for (int i = 2; i <= (int)sqrt(n); ++i)
		if (n % i == 0)
			return false;
	return true;
}

void printSimpleNumbers(int left, int right) {
	cout << "Simple numbers from " << left << " to " << right << endl;
	for (int i = left; i <= right; ++i)
		if (isSimple(i))
			cout << i << endl;
}


int countEvenInNumbers(int num1, int num2) {
	return (num1 % 2 == 0) + (num2 % 2 == 0);
}
int countEvenInNumbers(int num1, int num2, int num3) {
	return (num1 % 2 == 0) + (num2 % 2 == 0) + (num3 % 2 == 0);
}

int countEvenInArr(const int arr[], int size) {
	int countEven = 0;
	for (int i = 0; i < size; ++i)
		countEven += arr[i] % 2 == 0;
	return countEven;
}
int countEvenInArr(const int arr[][SIZE_M], int size) {
	int countEven = 0;
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < SIZE_M; ++j)
			countEven += arr[i][j] % 2 == 0;
	return countEven;
}

void printArray(const int arr[], int size) {
	for (int i = 0; i < size; ++i)
		cout << arr[i] << " ";
	cout << endl;
}
void printArray(const int matrix[][SIZE_M], int size) {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < SIZE_M; ++j)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}

void fillArray(int arr[], int size, int randMax = 100, int minus = 0) {
	for (int i = 0; i < size; ++i)
		arr[i] = (rand() % randMax) - minus;
}
void fillArray(int matrix[][SIZE_M], int size, int randMax = 100, int minus = 0) {
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < SIZE_M; ++j)
			matrix[i][j] = (rand() % randMax) - minus;
}

double TriangleArea(double a, double b, double c) {
	if (!(a + b > c && a + c > b && b + c > a)) return 0;

	double p = (a + b + c) / 2;
	double area = sqrt(p * (p - a) * (p - b) * (p - c));
	return area;
}
double TriangleArea(double a, double h) {
	double area = a * h / 2;
	return area;
}

int minusIdxFirst(const int arr[], int size) {
	for (int i = 0; i < size; ++i) {
		if (arr[i] < 0) return i;
	}
}
int minusIdxLast(const int arr[], int size) {
	for (int i = size-1; i >= 0; --i) {
		if (arr[i] < 0) return i;
	}
}
void reversePartArray(int arr[], int left, int right) {
	while (left < right) {
		double temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;
		left++;
		right--;
	}
}

void sumMatrix(const int a[][SIZE_M], const int b[][SIZE_M], int c[][SIZE_M]) {
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			c[i][j] = a[i][j] + b[i][j];
		}
	}
}
void multMatrixByNum(int a[][SIZE_M], int num) {
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			a[i][j] = a[i][j] * num;
		}
	}
}

int main()
{
	printSimpleNumbers(3, 12);
	cout << endl;
	printSimpleNumbers(7, 19);

	cout << END_TASK_TEXT << endl;

	cout << countEvenInNumbers(1, 2) << endl;
	cout << countEvenInNumbers(6, 2) << endl;
	cout << END_MINI_TASK_TEXT << endl;
	cout << countEvenInNumbers(1, 2, 4) << endl;
	cout << countEvenInNumbers(1, 3, 7) << endl;
	cout << END_MINI_TASK_TEXT << endl;

	const int SIZE_ARR1 = 4;
	int arr1[SIZE_ARR1];
	const int SIZE_MATRIX1 = 3;
	int matrix1[SIZE_MATRIX1][SIZE_M];

	fillArray(arr1, SIZE_ARR1);
	printArray(arr1, SIZE_ARR1);
	cout << endl;
	cout << countEvenInArr(arr1, SIZE_ARR1) << endl;
	cout << END_MINI_TASK_TEXT << endl;

	fillArray(matrix1, SIZE_MATRIX1);
	printArray(matrix1, SIZE_MATRIX1);
	cout << endl;
	cout << countEvenInArr(matrix1, SIZE_MATRIX1) << endl;

	cout << END_TASK_TEXT << endl;

	cout << TriangleArea(5, 6) << endl;
	cout << TriangleArea(3, 4, 5) << endl;
	cout << TriangleArea(1, 2, 7) << endl;

	cout << END_TASK_TEXT << endl;
	
	const int SIZE_ARR2 = 8;
	int arr2[SIZE_ARR2];
	fillArray(arr2, SIZE_ARR2, 100, 50);
	printArray(arr2, SIZE_ARR2);
	int left = minusIdxFirst(arr2, SIZE_ARR2);
	int right = minusIdxLast(arr2, SIZE_ARR2);
	reversePartArray(arr2, left, right);
	printArray(arr2, SIZE_ARR2);

	cout << END_TASK_TEXT << endl;

	int matrixA[5][5];
	fillArray(matrixA, 5);
	printArray(matrixA, 5);
	cout << endl;
	int matrixB[5][5];
	fillArray(matrixB, 5);
	printArray(matrixB, 5);
	cout << endl;
	int matrixC[5][5];
	sumMatrix(matrixA, matrixB, matrixC);
	printArray(matrixC, 5);

	cout << endl;
	
	multMatrixByNum(matrixC, 10);
	printArray(matrixC, 5);


}