#include <iostream>

using namespace std;

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
	Array(int size) {
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

	int getSize() {
		return this->size;
	}
	long* getArr() {
		return this->arr;
	}
	long getMin() {
		long min_val = LONG_MAX;
		for (int i = 0; i < this->size; ++i) {
			min_val = min(arr[i], min_val);
		}
		return min_val;
	}
	long getMax() {
		long max_val = LONG_MIN;
		for (int i = 0; i < this->size; ++i) {
			max_val = max(arr[i], max_val);
		}
		return max_val;
	}
	double getAvg() {
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
	void print() {
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
	int findIndex(long value) {
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
	void ExapleRun() {
		cout << "Init array: ";
		print();
		fillDefault(10);
		print();
		fillRandom(10);
		print();
		sort();
		print();
		sort(true);
		print();
		append(50);
		print();
		cout << "Min: " << getMin() << endl;
		cout << "Avg: " << getAvg() << endl;
		cout << "Max: " << getMax() << endl;
	}
	

};

int main()
{
	srand(time(0));
	Array arr = Array();
	arr.ExapleRun();
	Array arr1 = Array(3);
	arr1.ExapleRun();
	Array arr2(arr1);
	cout << "COPY" << endl;
	arr2.print();

	
}