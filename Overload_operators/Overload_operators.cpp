#include <iostream>

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
			cout << "Imposible to fill all people (" << mc-c << " too much), max capacity reached!";
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



};


int main()
{
	Airplane a1("Model1", "TypeMain", 6, 12);
	Airplane a2("Model2", "TypeMain", 8, 20);

	a1.print_info();
	a2.print_info();

	cout << (a1 == a2) << endl;
	cout << a1.get_capacity() << endl;
	cout << (++a1).get_capacity() << endl;
	cout << (--a1).get_capacity() << endl;
	cout << (a1 > a2) << endl;
	cout << a1.get_capacity() << endl;
	cout << (a1(3)).get_capacity() << endl;
}