#include <iostream>
#include <fstream>
#include <string>
#include <functional>

using namespace std;

const string SEP_STR = "-=-=-=-\n";

class Menu {
private:
	struct Option {
		string option_name = "";
		function<void()> option_function = nullptr;
	};

	Option *options;
	unsigned int options_count;

	string number_and_text_separator;

	string menu_header_text;
	string input_text;
	string exit_text;
	string error_selection_text;


	void _print_option(unsigned int number, const string& option_name) const {
		cout << number <<
			number_and_text_separator <<
			option_name << "\n";
	}

public:
	Menu() : options(nullptr),
		options_count(0),
		number_and_text_separator(") "),
		menu_header_text("Menu:"),
		input_text("Your choise: "),
		exit_text("Exit"),
		error_selection_text("Wrong choise. Try again.") {}

	~Menu() {
		delete[] options;
	}

	void set_number_and_text_separator(const string& number_and_text_separator) {
		this->number_and_text_separator = number_and_text_separator;
	}
	string get_number_and_text_separator() const {
		return this->number_and_text_separator;
	}

	void set_menu_header_text(const string& menu_header_text) {
		this->menu_header_text = menu_header_text;
	}
	string get_menu_header_text() const {
		return this->menu_header_text;
	}

	void set_input_text(const string& input_text) {
		this->input_text = input_text;
	}
	string get_input_text() const {
		return this->input_text;
	}

	void set_exit_text(const string& exit_text) {
		this->exit_text = exit_text;
	}
	string get_exit_text() const {
		return this->exit_text;
	}

	void set_error_selection_text(const string& error_selection_text) {
		this->error_selection_text = error_selection_text;
	}
	string get_error_selection_text() const {
		return this->error_selection_text;
	}

	void addOption(const string& name, function<void()> func) {
		Option* temp_options = new Option[options_count + 1];

		for (unsigned int i = 0; i < options_count; ++i) {
			temp_options[i] = options[i];
		}

		temp_options[options_count].option_name = name;
		temp_options[options_count].option_function = func;

		options_count++;
		delete[] options;
		options = temp_options;
	}

	void show(bool isShowUntilExit = true) {
		while (true) {
			cout << menu_header_text <<"\n";
			for (unsigned int i = 0; i < options_count; ++i) {
				_print_option(i + 1, options[i].option_name);
			}
			_print_option(0, exit_text);
			cout << input_text;

			unsigned int choice;
			cin >> choice;

			if (choice == 0) {
				cout << "Exit menu...\n";
				break;
			}

			if (choice > 0 && choice <= options_count) {
				options[choice - 1].option_function();
				if (!isShowUntilExit) break;
			}
			else {
				cout << error_selection_text << "\n";
			}
		}
	}
};

class Abonent
{
private:
	struct PIB
	{
		string name = "EMPTY";
		string surname = "EMPTY";
		string patronymic = "EMPTY";

		inline string to_string() const
		{
			return name + " " + surname + " " + patronymic;
		}
	};

	PIB my_PIB;
	string home_phone;
	string mobile_phone;
	string additional_info;

	static int count_abonents;

public:
	Abonent(const PIB& my_PIB, const string& home_phone,
		const string& mobile_phone, const string& additional_info)
		: my_PIB(my_PIB),
		home_phone(home_phone),
		mobile_phone(mobile_phone),
		additional_info(additional_info) { count_abonents++; }

	Abonent(const PIB& my_PIB, const string& home_phone,
		const string& mobile_phone)
		: Abonent(my_PIB, home_phone, mobile_phone, "") {}

	Abonent(const PIB& my_PIB, const string& home_phone)
		: Abonent(my_PIB, home_phone, "") {}

	Abonent(const PIB& my_PIB)
		: Abonent(my_PIB, "") {}

	Abonent()
		: Abonent(PIB()) {}
	
	~Abonent() { count_abonents--; }

	PIB get_PIB() const
	{
		return my_PIB;
	}
	void set_PIB(const PIB& my_PIB)
	{
		this->my_PIB = my_PIB;
	}

	string get_home_phone() const
	{
		return home_phone;
	}
	void set_home_phone(const string& home_phone)
	{
		this->home_phone = home_phone;
	}

	string get_mobile_phone() const
	{
		return mobile_phone;
	}
	void set_mobile_phone(const string& mobile_phone)
	{
		this->mobile_phone = mobile_phone;
	}

	string get_additional_info() const
	{
		return additional_info;
	}
	void set_additional_info(const string& additional_info)
	{
		this->additional_info = additional_info;
	}

	static int GetAbonentCount() {
		return count_abonents;
	}

	Abonent& Fill() {
		PIB new_PIB;
		cin.ignore();
		cout << "== Abonent info ==\n";
		cout << "Name: ";
		getline(cin, new_PIB.name);
		cout << "Surname: ";
		getline(cin, new_PIB.surname);
		cout << "Patronymic: ";
		getline(cin, new_PIB.patronymic);
		my_PIB = new_PIB;

		cout << "Home phone: ";
		getline(cin, home_phone);
		cout << "Mobile phone: ";
		getline(cin, mobile_phone);
		cout << "Additional info: ";
		getline(cin, additional_info);

		return *this;
	}

	string to_string() const
	{
		return "PIB: " + my_PIB.to_string() + "\n" +
			"Home phone: " + home_phone + "\n" +
			"Mobile phone: " + mobile_phone + "\n" +
			"Additional info: " + additional_info;
	}
	void Print() const {
		cout << this->to_string() << endl;
	}

	void SaveToFile(const string& filename) const {
		ofstream out(filename);
		if (!out) {
			cout << "Can't open file!\n";
			return;
		}

		out << my_PIB.name << "\n";
		out << my_PIB.surname << "\n";
		out << my_PIB.patronymic << "\n";
		out << home_phone << "\n";
		out << mobile_phone << "\n";
		out << additional_info << "\n";

		out.close();
	}

	void LoadFromFile(const string& filename) {
		ifstream in(filename);
		if (!in) {
			cout << "Can't open file!\n";
			return;
		}

		getline(in, my_PIB.name);
		getline(in, my_PIB.surname);
		getline(in, my_PIB.patronymic);
		getline(in, home_phone);
		getline(in, mobile_phone);
		getline(in, additional_info);

		in.close();
	}

	
};

int Abonent::count_abonents = 0;

class PhoneBook
{
private:
	Abonent* abonents;
	unsigned int countAbonent;
public:
	PhoneBook() : abonents(nullptr), countAbonent(0) {}
	~PhoneBook() {
		delete[] abonents;
	}
	int GetIdxAbonentByName(const string& name) const {
		int idx = -1;
		for (unsigned int i = 0; i < countAbonent; ++i) {
			if (abonents[i].get_PIB().to_string().compare(name) == 0) {
				idx = i;
				break;
			}
		}
		return idx;
	}

	int GetIdxAbonentByPhone(const string& phone) const {
		int idx = -1;
		for (unsigned int i = 0; i < countAbonent; ++i) {
			if (abonents[i].get_home_phone() == phone || abonents[i].get_mobile_phone() == phone) {
				idx = i;
				break;
			}
		}
		return idx;
	}

	Abonent* GetAbonentByIdx(int idx) const {
		if (idx < 0 || idx >= countAbonent) {
			cout << "Wrong idx!\n";
			return nullptr;
		}
		return &abonents[idx];
	}

	void Add(const Abonent& a) {
		Abonent* temp_abonents = new Abonent[countAbonent + 1];
		
		for (unsigned int i = 0; i < countAbonent; ++i) {
			temp_abonents[i] = abonents[i];
		}
		temp_abonents[countAbonent] = a;

		countAbonent++;
		delete[] abonents;
		abonents = temp_abonents;
	}

	void Delete(const string& phone) {
		int idx_to_delete = GetIdxAbonentByPhone(phone);
		if (idx_to_delete == -1) {
			cout << "Can't find phone " << phone << "!\n";
			return;
		}

		Abonent* temp_abonents = new Abonent[countAbonent - 1];
		bool isDeleted = false;

		for (unsigned int i = 0, j = 0; i < countAbonent; ++i) {
			if (!isDeleted && (abonents[i].get_home_phone() == phone || abonents[i].get_mobile_phone() == phone)) {
				continue;
			}
			temp_abonents[j++] = abonents[i];
		}

		countAbonent--;
		delete[] abonents;
		abonents = temp_abonents;

	}
	void SearchByName(const string& name) const {}
	void SearchByPhone(const string& phone) const {}
	void ShowAll() const {
		if (countAbonent <= 0) return;
		
		for (unsigned int i = 0; i < countAbonent; ++i) {
			cout << SEP_STR;
			abonents[i].Print();
		}
		cout << SEP_STR;
	}
};






void AbonentDeleteByPhoneMenu(PhoneBook &phonebook) {
	cout << "Enter phone number to delete abonent: ";
	cin.ignore();
	string phone;
	getline(cin, phone);
	phonebook.Delete(phone);
}

void AbonentPrintByIdx(const PhoneBook& phonebook, int idx) {
	Abonent* a = phonebook.GetAbonentByIdx(idx);
	cout << SEP_STR;
	a->Print();
	cout << SEP_STR;
}

void AbonentSearchByNameMenu(const PhoneBook& phonebook) {
	cout << "Enter name (PIB) to search abonent: ";
	cin.ignore();
	string name;
	getline(cin, name);
	int idx = phonebook.GetIdxAbonentByName(name);
	if (idx == -1) {
		cout << "Can't find this name (PIB)!\n";
		return;
	}
	AbonentPrintByIdx(phonebook, idx);
}

void AbonentSearchByPhoneMenu(const PhoneBook& phonebook) {
	cout << "Enter phone number to search abonent: ";
	cin.ignore();
	string phone;
	getline(cin, phone);
	int idx = phonebook.GetIdxAbonentByPhone(phone);
	if (idx == -1) {
		cout << "Can't find this phone number!\n";
		return;
	}
	AbonentPrintByIdx(phonebook, idx);
}

void SaveAbonentToFileMenu(const PhoneBook& phonebook) {
	cout << "Enter index of abonent to save: ";
	int idx;
	cin >> idx;
	Abonent* a = phonebook.GetAbonentByIdx(idx);
	if (!a) return;

	string filename;
	cout << "Enter file name to save: ";
	cin.ignore();
	getline(cin, filename);

	a->SaveToFile(filename);
}

void LoadAbonentFromFileMenu(PhoneBook& phonebook) {
	string filename;
	cout << "Enter file name to load: ";
	cin.ignore();
	getline(cin, filename);

	Abonent a;
	a.LoadFromFile(filename);
	phonebook.Add(a);
}

void AbonentPrintCount() {
	cout << "Abonent count: " << Abonent::GetAbonentCount() << " (Counted by static var)\n";
}



int main()
{
	const string PROJECT_NAME = "== Telephone book ==";
	PhoneBook phonebook;

	phonebook.Add({ {"Name", "Name2", "Name3"}, "+123", "+223", "Info"});
	phonebook.Add({ {"Test", "Test2", "Test3"}, "+999", "+888", "InfoInfoInfoInfo"});
	

	Menu my_menu;
	my_menu.set_menu_header_text(PROJECT_NAME);
	my_menu.addOption("Add abonent", [&phonebook]() { phonebook.Add(Abonent().Fill()); });
	my_menu.addOption("Show all", [&phonebook]() { phonebook.ShowAll(); });
	my_menu.addOption("Print count abonents", [&phonebook]() { AbonentPrintCount(); });
	my_menu.addOption("Delete by phone", [&phonebook]() { AbonentDeleteByPhoneMenu(phonebook); });
	my_menu.addOption("Search by name (PIB)", [&phonebook]() { AbonentSearchByNameMenu(phonebook); });
	my_menu.addOption("Save abonent to file", [&phonebook]() { SaveAbonentToFileMenu(phonebook); });
	my_menu.addOption("Load abonent from file", [&phonebook]() { LoadAbonentFromFileMenu(phonebook); });

	my_menu.show();

}