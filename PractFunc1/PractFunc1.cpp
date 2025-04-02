#include <iostream>
#include <Windows.h>

using namespace std;

void printRectangle(int a, int b, char symb = '*') {
	for (int i = 0; i < a; ++i) {
		for (int j = 0; j < b; ++j) {
			cout << symb << " ";
		}
		cout << endl;
	}
	cout << endl;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Визначити функцію для зображення прямокутника вказаних розмірів та заповненого вказаним символом. По замовчуванню прямокутник малюється симолом '*'

	printRectangle(5, 8);
	printRectangle(5, 8, '=');


}