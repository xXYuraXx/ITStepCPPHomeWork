#include <iostream>

using namespace std;

struct WashingMachine
{
	char firm[50];
	char color[50];
	float width;
	float lenght;
	float height;
	float power;
	float spin_speed;
	float heating_temp;

	void PrintInfo() {
		cout << "== Washing Machine Info ==" << endl;
		cout << "Firm: " << firm << endl;
		cout << "Color: " << color << endl;
		cout << "Width: " << width << " cm" << endl;
		cout << "Lenght: " << lenght << " cm" << endl;
		cout << "Height: " << height << " cm" << endl;
		cout << "Power: " << power << " watt" << endl;
		cout << "Spin speed: " << spin_speed << " r/m" << endl;
		cout << "Heating temperature: " << heating_temp << endl;
	}
};

struct SteamIron
{
	char firm[50];
	char model[50];
	char color[50];
	float min_temp;
	float max_temp;
	bool is_steam_supply;
	float power;

	void PrintInfo() {
		cout << "== Steam iron Info ==" << endl;
		cout << "Firm: " << firm << endl;
		cout << "Model: " << model << endl;
		cout << "Color: " << color << endl;
		cout << "Min temperature: " << min_temp << " '\C" << endl;
		cout << "Max temperature: " << max_temp << " '\C" << endl;
		cout << "Steam supply: " << (is_steam_supply ? "Yes" : "No") << endl;
		cout << "Power: " << power << " watt" << endl;
	}
};

struct Boiler
{
	char firm[50];
	char color[50];
	float power;
	float volume;
	float heating_temp;

	void PrintInfo() {
		cout << "== Boiler Info ==" << endl;
		cout << "Firm: " << firm << endl;
		cout << "Color: " << color << endl;
		cout << "Power: " << power << " watt" << endl;
		cout << "Volume: " << power << " m^3" << endl;
		cout << "Heating temperature: " << heating_temp << " '\C" << endl;
	}
};

bool isStringDigit(char str[]) {
	for (int i = 0; i < strlen(str); ++i) {
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

struct Car
{
	char color[50];
	char model[50];
	char number[9];

	void Fill() {
		cout << "\n== Fill car field ==" << endl;
		cout << "Color: ";
		cin.getline(color, 50);
		cout << "Model: ";
		cin.getline(model, 50);
		while (true) {
			cout << "Number: ";
			cin.getline(number, 9);
			if (isStringDigit(number)) {
				if (strlen(number) == 5) {
					break;
				}
				else {
					cout << "If number created from digits you need 5 digit!" << endl;
				}
			}
			else {
				if (strlen(number) > 0 && strlen(number) <= 8) {
					break;
				}
				else {
					cout << "If number created from alphas, len must be...\n" << "greater than 0 and less or equal 8" << endl;
				}
			}
		}
	}

	void Print() {
		cout << "| " << color << " | " << model << " | " << number << " |" << endl;
	}
};

void PrintCars(Car cars[]) {
	for (int i = 0; i < sizeof(cars); ++i) {
		cout << i << ". "; cars[i].Print();
	}
}

void EditByIndex(Car cars[], int idx) {
	if (idx < 0 || idx >= sizeof(cars))
		return;

	cars[idx].Fill();
}

void FindCarByNumber(Car cars[], char number[]) {
	for (int i = 0; i < sizeof(cars); ++i) {
		if (strcmp(cars[i].number, number) == 0) {
			cars[i].Print();
		}
	}
}


int main()
{
	WashingMachine washingMachine1 = { "LG", "White", 100, 150, 250, 1000, 10000, 70.6};
	washingMachine1.PrintInfo();
	cout << endl;

	SteamIron steamIron1 = { "PHILIPS", "PTH68900", "Black", 31.8, 126.5, true, 500 };
	steamIron1.PrintInfo();
	cout << endl;

	Boiler boiler1 = { "Atlantic", "Grey", 1200, 600, 106.6 };
	boiler1.PrintInfo();
	cout << endl;

	const int CAR_SIZE1 = 10;
	Car cars[CAR_SIZE1] = {
		{"White", "Model1", "00011"},
		{"Green", "Model2", "11122"},
		{"Yellow", "Model3", "22233"},
		{"Black", "Model4", "Abram"},
		{"Pink", "Model5", "Cool"},
		{"Blue", "Model6", "88991"},
		{"Cyan", "Model7", "43652"},
		{"Purple", "Model8", "F1ne"},
		{"Aqua", "Model9", "Nice"},
		{"Brown", "Model10", "66252"},
	};

	int choise;

	while (true) {
		cout << endl;
		cout << "1. Print all cars" << endl;
		cout << "2. Edit car by index" << endl;
		cout << "3. Find car by number" << endl;
		cout << "0. Exit" << endl;

		cout << ">> "; cin >> choise;
		cin.ignore();

		switch (choise) {
		case 1:
			PrintCars(cars);
			break;
		case 2:
		{
			int idx_to_change;
			cout << "Enter index to change car: "; cin >> idx_to_change;
			cin.ignore();
			EditByIndex(cars, idx_to_change);
			break;
		}
		case 3:
		{
			char number[9];
			cout << "Enter number to find cars: ";
			cin.getline(number, 9);
			FindCarByNumber(cars, number);
			break;
		}
		case 0:
			return 0;
		default:
			break;
		}
	}

}