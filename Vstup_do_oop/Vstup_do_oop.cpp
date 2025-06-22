#include <iostream>
#include <string>

using namespace std;

struct PIB
{
    string name;
    string surname;
    string lastname;

    void Init() {
        name = "NO NAME";
        surname = "NO SURNAME";
        lastname = "NO LASTNAME";
    }

    string ToString() {
        string str;
        str = name + " " + surname + " " + lastname;
        return str;
    }

    void Fill() {
        cout << "Enter name: ";
        getline(cin, this->name);
        cout << "Enter surname: ";
        getline(cin, this->surname);
        cout << "Enter lastname: ";
        getline(cin, this->lastname);
    }


};
struct Date
{
    int day;
    int month;
    int year;

    void Init() {
        day = 0;
        month = 0;
        year = 0;
    }

    string ToString() {
        string str = "";
        str += to_string(day) + (day < 10 ? "0" : "") + ".";
        str += to_string(month) + (month < 10 ? "0" : "") + ".";
        str += to_string(year) + (year < 10 ? "0" : "");
        return str;
    }

    void Fill() {
        cout << "Enter day: ";
        cin >> day;
        cout << "Enter month: ";
        cin >> month;
        cout << "Enter year: ";
        cin >> year;
        cin.ignore();
    }
};
struct University
{
    string name;
    string city;
    string country;

    void Init() {
        name = "NO UNIVERSITY NAME";
        city = "NO UNIVERSITY CITY";
        country = "NO UNIVERSITY COUNTRY";
    }

    void Print() {
        cout << "University name: " << name << endl;
        cout << "University city: " << city << endl;
        cout << "University country: " << country << endl;
    }

    void Fill() {
        cout << "Enter University name: ";
        getline(cin, this->name);
        cout << "Enter University city: ";
        getline(cin, this->city);
        cout << "Enter University country: ";
        getline(cin, this->country);
    }
};
class Student
{
private:
    PIB fullname;
    Date birthdate;
    string tel;
    string city;
    string country;
    University university;
    string group;
    int* marks;
    int markCount;
    float average;


    void setMarkCount(int markCount) {
        if (markCount >= 0)
            this->markCount = markCount;
        else
            cout << "Mark count can't be less than 0!" << endl;
    }
    void setAverage(float average) {
        this->average = average;
    }

public:
    void setFullname(PIB fullname) {
        this->fullname = fullname;
    }
    void setBirthdate(Date birthdate) {
        this->birthdate = birthdate;
    }
    void setTelephone(string tel) {
        this->tel = tel;
    }
    void setCity(string city) {
        this->city = city;
    }
    void setCountry(string country) {
        this->country = country;
    }
    void setUniversity(University university) {
        this->university = university;
    }
    void setGroup(string group) {
        this->group = group;
    }
    void setMarks(int* marks) {
        this->marks = marks;
    }

    PIB getFullname() {
        return this->fullname;
    }
    Date getBirthdate() {
        return this->birthdate;
    }
    string getTelephone() {
        return this->tel;
    }
    string getCity() {
        return this->city;
    }
    string getCountry() {
        return this->country;
    }
    University getUniversity() {
        return this->university;
    }
    string getGroup() {
        return this->group;
    }
    int* getMarks() {
        return this->marks;
    }
    int getMarkCount() {
        return this->markCount;
    }
    float getAverage() {
        return this->average;
    }

    void Init() {
        this->fullname.Init();
        this->birthdate.Init();
        this->city = "NO STUDENT CITY";
        this->country = "NO STUDENT COUNTRY";
        this->university.Init();
        this->group = "NO STUDENT GROUP";
        this->marks = nullptr;
        this->markCount = 0;
        this->average = 0;
    }

    void Print() {
        cout << "Student fullname: " << getFullname().ToString() << endl;
        cout << "Student birthdate: " << getBirthdate().ToString() << endl;
        cout << "Student city: " << getCity() << endl;
        cout << "Student country: " << getCountry() << endl;

        getUniversity().Print();

        cout << "Student group: " << getGroup() << endl;

        cout << "Student Marks: ";
        int* _marks = getMarks();
        for (int i = 0; i < getMarkCount(); ++i) {
            cout << _marks[i] << " ";
        }
        cout << endl;

        cout << "Student average: " << getAverage() << endl;
    }

    void Fill() {
        cout << "== Enter Student fullname ==" << endl;
        PIB _fullname;
        _fullname.Fill();
        setFullname(_fullname);

        cout << "== Enter Student birthdate ==" << endl;
        Date _birthdate;
        _birthdate.Fill();
        setBirthdate(_birthdate);

        cout << "Enter Student city: ";
        string _city;
        getline(cin, _city);
        setCity(_city);

        cout << "Enter Student country: ";
        string _country;
        getline(cin, _country);
        setCountry(_country);

        cout << "== Enter Student University Info ==" << endl; \
            University _university;
        _university.Fill();
        setUniversity(_university);

        cout << "Enter Student group: ";
        string _group;
        getline(cin, _group);
        setGroup(_group);

        cout << "== Enter Student Marks ==" << endl;
        cout << "Enter count: ";
        int _markCount;
        cin >> _markCount;
        cin.ignore();
        setMarkCount(_markCount);

        int* _marks = new int[_markCount];
        for (int i = 0; i < _markCount; ++i) {
            cout << "Mark [" << i + 1 << "/" << _markCount << "] = ";
            cin >> _marks[i];
        }
        setMarks(_marks);
    }

};

int main()
{
    Student student;
    student.Init();
    student.Print();
    student.Fill();
    student.Print();
}