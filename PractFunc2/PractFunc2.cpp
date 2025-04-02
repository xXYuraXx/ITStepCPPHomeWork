#include <iostream>
#include <Windows.h>

using namespace std;

int Square(int n) {
	return n * n;
}

int Cube(int n) {
	return n * n * n;
}

void printSquareAndCube(int n) {
	for (int i = 1; i < n; ++i) {
		cout << i << "| " << Square(i) << " " << Cube(i) << endl;
	}
	cout << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printSquareAndCube(4);
	printSquareAndCube(8);


}