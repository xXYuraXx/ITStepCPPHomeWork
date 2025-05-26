#include <iostream>

using namespace std;

int myLen(char str[]) {
	int len = 0;
	while (str[len] != '\0')
		len++;
	return len;
}

int check_char_in_str(char chr, const char str[]) {
	for (int i = 0; i < strlen(str); ++i) {
		if (tolower(chr) == tolower(str[i]))
			return true;
	}
	return false;
}



int main()
{
	//1.Вводиться рядок.Яких букв у рядку більше ’а’ чи ’о’ ?
	char str1[255];
	cout << "Enter str for task1: ";
	cin.getline(str1, 255);
	int count_a = 0;
	int count_o = 0;
	for (int i = 0; i < strlen(str1); ++i) {
		if (str1[i] == 'a') count_a++;
		if (str1[i] == 'o') count_o++;
	}
	if (count_a > count_o)
		cout << "Count a greater then o" << endl;
	else if(count_a < count_o)
		cout << "Count o greater then a" << endl;
	else
		cout << "Count o equal a" << endl;



	//2.Вводиться рядок.Порахувати кількість латинських букв, цифр та пробілів у рядку.
	int count_al = 0;
	int count_d = 0;
	int count_s = 0;
	char str2[255];
	cout << "Enter str for task2: ";
	cin.getline(str2, 255);
	for (int i = 0; i < strlen(str2); ++i) {
		if (isalpha(str2[i])) count_al++;
		if (isdigit(str2[i])) count_d++;
		if (isspace(str2[i])) count_s++;
	}
	cout << "Count alpha: " << count_al << endl;
	cout << "Count digits: " << count_d << endl;
	cout << "Count spaces: " << count_s << endl;




	//3.Дано рядок.Замінити у рядку всі великі букви на малі і навпаки.
	char str3[255];
	cout << "Enter str for task3: ";
	cin.getline(str3, 255);
	for (int i = 0; i < strlen(str3); ++i) {
		if (isupper(str3[i])) str3[i] = tolower(str3[i]);
		else str3[i] = toupper(str3[i]);
	}
	cout << str3 << endl;



	//4.Написати функцію, яка отримує рядок і повертає довжину рядка.
	//Без використання функції strlen()
	char str4[255];
	cout << "Enter str for task4: ";
	cin.getline(str4, 255);
	cout << "Len is: " << myLen(str4) << endl;



	//5***.Дано рядок. Видалити із рядка заданий символ. Результат розмістити у новому рядку.

	char str5_1[255];
	char str5_2[255];
	char symb;
	cout << "Enter str for task5: ";
	cin.getline(str5_1, 255);
	cout << "Which symb you want to delete?: ";
	symb = getchar();

	int i = 0;
	int j = 0;
	while (str5_1[i] != '\0') {
		if (str5_1[i] == symb) {
			i++;
			continue;
		}
		str5_2[j] = str5_1[i];
		i++;
		j++;
	}
	str5_2[j] = '\0';
	cout << str5_2 << endl;

	cin.ignore();



	//6***.Розробити програму, яка зчитує з екрану рядок, а потім видає статистику: 
	//кількість пробільних символів(whitespaces), голосних, приголосних, знаків пунктуації.
	//Введення передбачається англомовним.

	int space1 = 0;
	int golosni1 = 0;
	int prigolosni1 = 0;
	int punct1 = 0;

	char str6[255];
	cout << "Enter str for task6: ";
	cin.getline(str6, 255);

	for (int i = 0; i < strlen(str6); ++i) {
		if (isspace(str6[i]))
			space1++;
		if (check_char_in_str(str6[i], "aioeu"))
			golosni1++;
		else if (isalpha(str6[i]))
			prigolosni1++;
		if (ispunct(str6[i]))
			punct1++;
	}
	cout << "Spaces: " << space1 << endl;
	cout << "Golosni: " << golosni1 << endl;
	cout << "Prigolosni: " << prigolosni1 << endl;
	cout << "Puncuation: " << punct1 << endl;

	
}