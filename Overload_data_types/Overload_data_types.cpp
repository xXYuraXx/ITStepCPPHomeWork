#include <iostream>
#include <string>

using namespace std;


class Airplane
{
	string model;
	string type;
	int capacity;
	int max_capacity;
public:

	Airplane(string m, string t, int c, int mc) {
		model = m;
		type = t;
		if (c < 0 || mc < 0)
			cout << "Capacity can't be negative!" << endl;
		if (c > mc) {
			cout << "Imposible to fill all people (" << mc - c << " too much), max capacity reached!";
		}
		max_capacity = max(mc, 0);
		capacity = min(max(c, 0), max_capacity);
	}

	int get_capacity() const {
		return capacity;
	}

	void print_info() const {
		cout << "Model: " << model << endl;
		cout << "Type: " << type << endl;
		cout << "Capacity: " << capacity << endl;
		cout << "Max capacity: " << max_capacity << endl;
	}



	friend bool operator==(const Airplane& a1, const Airplane& a2)
	{
		return a1.type == a2.type;
	}

	Airplane& operator++() {
		if ((capacity + 1) > max_capacity) {
			cout << "Can't add, max capacity reached!" << endl;
		}
		else {
			++capacity;
		}
		return *this;
	}

	Airplane& operator--() {
		if ((capacity - 1) < 0) {
			cout << "Can't decrease, capacity can't be less than 0!" << endl;
		}
		else {
			--capacity;
		}
		return *this;
	}

	friend bool operator>(const Airplane& a1, const Airplane& a2) {
		return a1.max_capacity > a2.max_capacity;
	}

	Airplane& operator()(int n) {
		if ((capacity + n) > max_capacity) {
			cout << "Can't add, max capacity reached!" << endl;
		}
		else {
			capacity += n;
		}
		return *this;
	}

	operator string() {
		return model;
	}

	friend ostream& operator<<(ostream& ostr, Airplane& a) {
		ostr	<< "\nModel: " << a.model
			<< "\nType: " << a.type
			<< "\nCapacity: " << a.capacity
			<< "\nMax capacity: " << a.max_capacity << "\n";
		return ostr;
	}

	friend istream& operator>>(istream& istr, Airplane& a) {
		cout << "\nModel: ";
		istr >> a.model;
		cout << "Type: ";
		istr >> a.type;
		cout << "Capacity: ";
		istr >> a.capacity;
		cout << "Max capacity: ";
		istr >> a.max_capacity;
		return istr;
	}

};

class Array {
private:
	long* arr;
	int size;

	void bubble_sort(bool isDecrease = false) {
		bool isChanged = true;
		int end = this->size - 1;
		while (isChanged) {
			isChanged = false;
			for (int i = 0; i < end; ++i) {
				if (isDecrease ? arr[i] < arr[i + 1] : arr[i] > arr[i + 1]) {
					swap(arr[i], arr[i + 1]);
					isChanged = true;
				}
			}
			end--;
		}
	}

public:
	Array()
	{
		this->size = 0;
		this->arr = new long[this->size];
	}
	explicit Array(int size) {
		fillDefault(size);
	}
	Array(const Array& array) {
		this->size = array.size;
		long* second_arr = array.arr;
		arr = new long[this->size];
		for (int i = 0; i < this->size; ++i) {
			this->arr[i] = second_arr[i];
		}
	}
	~Array() {
		delete[] arr;
	}


	void setSize(int size) {
		if (size < 0) {
			cout << "Size can't be less than 0!" << endl;
			return;
		}
		this->size = size;
	}
	void setArr(long* arr) {
		this->arr = arr;
	}

	int getSize() const {
		return this->size;
	}
	long* getArr() const {
		return this->arr;
	}
	long getMin() const {
		long min_val = LONG_MAX;
		for (int i = 0; i < this->size; ++i) {
			min_val = min(arr[i], min_val);
		}
		return min_val;
	}
	long getMax() const {
		long max_val = LONG_MIN;
		for (int i = 0; i < this->size; ++i) {
			max_val = max(arr[i], max_val);
		}
		return max_val;
	}
	double getAvg() const {
		long sum = 0;
		for (int i = 0; i < this->size; ++i) {
			sum += arr[i];
		}
		return (double)sum / this->size;
	}
	void fillRandom(int size) {
		this->size = size;
		arr = new long[this->size];
		for (int i = 0; i < this->size; i++) {
			arr[i] = rand() % 100;
		}
	}
	void fill(int size) {
		this->size = size;
		arr = new long[this->size];
		for (int i = 0; i < this->size; i++) {
			cout << "arr[" << i << "] = ";
			cin >> arr[i];
		}
	}
	void fillDefault(int size) {
		this->size = size;
		arr = new long[this->size];
		for (int i = 0; i < this->size; i++) {
			arr[i] = 0;
		}
	}
	void print() const {
		if (this->size == 0) {
			cout << "Empty." << endl;
			return;
		}

		for (int i = 0; i < this->size; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	void removeByIndex(int idx) {
		if (idx < 0 || idx >= this->size) {
			cout << "Index error!" << endl;
			return;
		}
		long* newArr = new long[this->size - 1];
		for (int i = 0, j = 0; i < this->size; ++i) {
			if (i != idx) {
				newArr[j] = arr[i];
				j++;
			}
		}
		delete[] arr;
		arr = newArr;
		size--;
	}
	int findIndex(long value) const {
		int idx = -1;
		for (int i = 0; i < this->size; ++i) {
			if (arr[i] == value) {
				idx = i;
				break;
			}
		}
		return idx;
	}

	void removeByValue(long value) {
		int idx = findIndex(value);
		if (idx == -1) {
			cout << "Can't find value!" << endl;
			return;
		}
		removeByIndex(idx);
	}
	void sort(bool isDecrease = false) {
		bubble_sort(isDecrease);
	}
	void append(long value) {
		long* newArr = new long[this->size + 1];
		for (int i = 0; i < this->size; ++i) {
			newArr[i] = arr[i];
		}
		newArr[this->size] = value;
		delete[] arr;
		arr = newArr;
		this->size++;
	}

	operator int() {
		int s = 0;
		for (int i = 0; i < this->size; ++i) {
			s += arr[i];
		}
		return s;
	}

	operator string() {
		string s = "";
		for (int i = 0; i < this->size; ++i) {
			s += to_string(arr[i]) + " ";
		}
		return s;
	}


};

class Date
{
protected:
	int day;
	int month;
	int year;

	const int DAYS_IN_DEFAULT_YEAR = 365;
	const int DAYS_IN_LEAP_YEAR = 366;
	const int DAYS_IN_MONTHS_DEFAULT[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	const int DAYS_IN_MONTHS_LEAP[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	const int DAYS_IN_HUNDRED_YEARS = (DAYS_IN_DEFAULT_YEAR * 3 + DAYS_IN_LEAP_YEAR) * 25 - 1;
	const int DAYS_IN_FOUR_YEARS_WITHOUT_HUNDRED = (3 * DAYS_IN_DEFAULT_YEAR + DAYS_IN_LEAP_YEAR);

	int _get_days_in_month(int month_num, bool is_leap_year) const {
		if (month_num < 1 || month_num > 12) {
			cout << "Wrong month number!" << endl;
			return 0;
		}
		if (is_leap_year)
			return DAYS_IN_MONTHS_LEAP[month_num - 1];
		else
			return DAYS_IN_MONTHS_DEFAULT[month_num - 1];
	}

	int _converte_to_days(int day, int month, int year) const {
		if (year < 0) {
			cout << "_converte_to_days: Year can't be less than zero!" << endl;
			return 0;
		}
		if (month < 0) {
			cout << "_converte_to_days: Month can't be less than zero!" << endl;
			return 0;
		}
		if (day < 0) {
			cout << "_converte_to_days: Day can't be less than zero!" << endl;
			return 0;
		}

		int leap_years = year / 4 - year / 100 + year / 400;
		int default_years = year - leap_years;

		int days_before_this_month = 0;

		bool is_year_leap = IsYearLeap(year);
		for (int m_num = 1; m_num < month; ++m_num) {
			days_before_this_month += _get_days_in_month(m_num, is_year_leap);
		}

		int total_days = leap_years * DAYS_IN_LEAP_YEAR + default_years * DAYS_IN_DEFAULT_YEAR + days_before_this_month + day;

		return total_days;
	}

	int _converte_to_days(int day, int month) {
		return _converte_to_days(day, month, 0);
	}
	int _converte_to_days(int day) {
		return _converte_to_days(day, 1, 0);
	}




public:
	Date() : day{ 1 }, month{ 1 }, year{ 0 } {}
	Date(int days) {
		set_date_by_days(days);
	}
	Date(int months, int days) {
		set_date_by_days(_converte_to_days(days, months));
	}
	Date(int years, int months, int days) {
		set_date_by_days(_converte_to_days(days, months, years));
	}

	static bool IsYearLeap(int year) {
		return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
	}

	void set_date_by_days(int days) {
		if (days < 1) {
			cout << "Days can't be less than 1!" << endl;
			return;
		}

		int days_left = days;
		int years_by_hundred = days_left / DAYS_IN_HUNDRED_YEARS;
		if (years_by_hundred > 0)
			days_left %= years_by_hundred * DAYS_IN_HUNDRED_YEARS;

		int years_by_four = days_left / DAYS_IN_FOUR_YEARS_WITHOUT_HUNDRED;
		if (years_by_four > 0)
			days_left %= years_by_four * DAYS_IN_FOUR_YEARS_WITHOUT_HUNDRED;

		int left_years = days_left / DAYS_IN_DEFAULT_YEAR;
		if (left_years > 0)
			days_left %= left_years * DAYS_IN_DEFAULT_YEAR;

		int NEW_year = years_by_hundred * 100 + years_by_four * 4 + left_years;
		this->year = NEW_year;

		int NEW_month = 1;
		bool is_year_leap = IsYearLeap(NEW_year);
		for (int m_num = 1; m_num <= 12; ++m_num) {
			int TEMP_days_in_cur_month = _get_days_in_month(m_num, is_year_leap);
			if (days_left - TEMP_days_in_cur_month <= 0)
				break;
			NEW_month++;
			days_left -= TEMP_days_in_cur_month;
		}
		this->month = NEW_month;
		this->day = days_left;


	}
	

	int get_date_in_days() const {
		return _converte_to_days(day, month, year);
	}
	
	void change_date_by_days(int days) {
		int NEW_days = days + get_date_in_days();
		set_date_by_days(NEW_days);
	}
	void increase_date_by_1_day() {
		change_date_by_days(1);
	}

	string to_string() const {
		string res = "";
		if (year < 10) res += "0";
		if (year < 100) res += "0";
		if (year < 1000) res += "0";
		res += std::to_string(year) + ".";

		if (month < 10) res += "0";
		res += std::to_string(month) + ".";

		if (day < 10) res += "0";
		res += std::to_string(day);

		return res;
	}


	friend ostream& operator<<(ostream& out, const Date& d) {
		out << d.to_string();
		return out;
	}

	Date& operator++(int _);
	Date& operator++();

	Date& operator--(int _);
	Date& operator--();

	friend bool operator==(const Date& d1, const Date& d2) {
		return d1.year == d2.year && d1.month == d2.month && d1.day == d2.day;
	}

	friend bool operator!=(const Date& d1, const Date& d2) {
		return !(d1 == d2);
	}

	friend bool operator>(const Date& d1, const Date& d2) {
		return d1.year > d2.year
			|| (d1.year == d2.year && d1.month > d2.month)
			|| (d1.year == d2.year && d1.month == d2.month && d1.day > d2.day);
	}

	friend bool operator<(const Date& d1, const Date& d2) {
		return d1.year < d2.year
			|| (d1.year == d2.year && d1.month < d2.month)
			|| (d1.year == d2.year && d1.month == d2.month && d1.day < d2.day);
	}

	Date& operator+=(int days) {
		change_date_by_days(days);
		return *this;
	}

	Date& operator-=(int days) {
		change_date_by_days(-days);
		return *this;
	}

	void operator()(int days) {
		change_date_by_days(days);
	}

	void operator()(int months, int days) {
		change_date_by_days(_converte_to_days(days, months+1));
	}

	void operator()(int years, int months, int days) {
		change_date_by_days(_converte_to_days(days, months+1, years));
	}



};

inline Date& Date::operator++(int _) {
	change_date_by_days(1);
	return *this;
}

inline Date& Date::operator++() {
	change_date_by_days(1);
	return *this;
}

inline Date& Date::operator--(int _) {
	change_date_by_days(-1);
	return *this;
}

inline Date& Date::operator--() {
	change_date_by_days(-1);
	return *this;
}

int main()
{
	Airplane a1("Model1", "TypeMain", 6, 12);
	Airplane a2("Model2", "TypeMain", 8, 20);

	Array arr(5);
	arr.fillRandom(arr.getSize());
	cout << (string)arr << endl;
	cout << (int)arr << endl;

	cout << a1;
	cin >> a1;
	cout << a1;

	Date d1(100, 1, 1);

	cout << d1 << endl;
	cout << (d1 += 10) << endl;
	cout << (d1 -= 5) << endl;
	d1++;
	cout << d1 << endl;
	d1--;
	cout << d1 << endl;
	--d1;
	cout << d1 << endl;
	++d1;
	cout << d1 << endl;

	Date d2(50, 6, 16);
	cout << d1 << " " << d2 << endl;
	cout << (d1 == d2) << endl;
	cout << (d1 > d2) << endl;
	cout << (d1 < d2) << endl;

	d1(20);
	cout << d1 << endl;

	d1(1, 1);
	cout << d1 << endl;

	d1(162, 1, 1000000);
	cout << d1 << endl;
	
	


}




