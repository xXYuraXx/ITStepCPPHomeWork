#include <iostream>
#include <string>

using namespace std;

class Time {
private:
	int hours;
	int minutes;
	int seconds;

	string _numToString(int value) const {
		return (value < 10 ? "0" : "") + std::to_string(value);
	}

public:
	Time() : hours(0), minutes(0), seconds(0) {}
	explicit Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}
	explicit Time(int s) {
		setTime(s);
	}

	const static int SECONDS_IN_DAY = 86400;

	void setTime(int h, int m, int s) {
		hours = h;
		minutes = m;
		seconds = s;
	}
	void setTime(int s) {
		if (s < 0) {
			s = SECONDS_IN_DAY + s;
		}
		hours = s / 3600;
		minutes = (s % 3600) / 60;
		seconds = s % 60;
	}

	void addTime(int s) {
		long long totalSeconds = getTimeInSeconds() + s;
		int normalSeconds = totalSeconds % SECONDS_IN_DAY;
		setTime(normalSeconds);
	}

	int getTimeInSeconds() const {
		return hours * 3600 + minutes * 60 + seconds;
	}

	string getTimeString() const {
		return _numToString(hours) + ":" + _numToString(minutes) + ":" + _numToString(seconds);
	}

	void operator++(int _) {
		setTime(getTimeInSeconds() + 1);
	}

	Time operator+(const Time& other) const {
		int totalSeconds = this->getTimeInSeconds() + other.getTimeInSeconds();
		return Time(totalSeconds);
	}
	Time operator-(const Time& other) const {
		int totalSeconds = this->getTimeInSeconds() - other.getTimeInSeconds();
		return Time(totalSeconds);
	}
	Time operator*(const Time& other) const {
		long long totalSeconds = (long long)this->getTimeInSeconds() * other.getTimeInSeconds();
		int normalSeconds = totalSeconds % SECONDS_IN_DAY;
		return Time(normalSeconds);
	}
	Time operator/(const Time& other) const {
		if (other.getTimeInSeconds() == 0) {
			cout << "Error: Division by zero." << endl;
			return Time(0);
		}
		int totalSeconds = this->getTimeInSeconds() / other.getTimeInSeconds();
		return Time(totalSeconds);
	}

	bool operator>(const Time& other) const {
		return this->getTimeInSeconds() > other.getTimeInSeconds();
	}
	bool operator<(const Time& other) const {
		return this->getTimeInSeconds() < other.getTimeInSeconds();
	}
	bool operator>=(const Time& other) const {
		return this->getTimeInSeconds() >= other.getTimeInSeconds();
	}
	bool operator<=(const Time& other) const {
		return this->getTimeInSeconds() <= other.getTimeInSeconds();
	}

	bool operator==(const Time& other) const {
		return this->getTimeInSeconds() == other.getTimeInSeconds();
	}
	bool operator!=(const Time& other) const {
		return this->getTimeInSeconds() != other.getTimeInSeconds();
	}

};

int main()
{
	Time t1(2, 30, 45);
	Time t2(3661);
	Time t3(2);

	cout << "Time 1: " << t1.getTimeString() << endl;
	cout << "Time 2: " << t2.getTimeString() << endl;
	cout << "Time 3: " << t3.getTimeString() << endl;
	cout << "t1++: ";
	t1++;
	cout << t1.getTimeString() << endl;
	cout << "t1 + t2: " << (t1 + t2).getTimeString() << endl;
	cout << "t1 - t2: " << (t1 - t2).getTimeString() << endl;
	cout << "t2 - t1: " << (t2 - t1).getTimeString() << endl;
	cout << "t1 * t2: " << (t1 * t2).getTimeString() << endl;
	cout << "t1 * t3: " << (t1 * t3).getTimeString() << endl;
	cout << "t1 / t2: " << (t1 / t2).getTimeString() << endl;
	cout << "t1 > t2: " << (t1 > t2) << endl;
	cout << "t1 < t2: " << (t1 < t2) << endl;
	cout << "t1 >= t2: " << (t1 >= t2) << endl;
	cout << "t1 <= t2: " << (t1 <= t2) << endl;
	cout << "t1 == t2: " << (t1 == t2) << endl;
	cout << "t1 != t2: " << (t1 != t2) << endl;

}