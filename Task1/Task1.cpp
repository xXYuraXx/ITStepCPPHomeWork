#include <iostream>
#include <fstream>

using namespace std;

/*
Завдання №2
Реалізуйте клас «Точка». Необхідно зберігати координати
x, y, z в змінних-членах класу. Реалізуйте функції-члени
класу для введення даних, виведення даних, реалізуйте
аксесор для доступу до змінних-членів, реалізуйте збе-
реження в файл і завантаження даних з файлу.
*/


class Point {
private:
    double x, y, z;

public:
    void setX(double newX) {
        x = newX;
    }
    double getX() {
        return x;
    }
    void setY(double newY) {
        y = newY;
    }
    double getY() {
        return y;
    }
    void setZ(double newZ) {
        z = newZ;
    }
    double getZ() {
        return z;
    }

    void PrintInfo() {
        cout << "(x : " << x << "; y : " << y << "; z : " << z << ")";
    }
    void InputData() {
        double newX;
        cout << "Enter x: "; cin >> newX;
        setX(newX);

        double newY;
        cout << "Enter Y: "; cin >> newY;
        setY(newY);

        double newZ;
        cout << "Enter Z: "; cin >> newZ;
        setZ(newZ);

    }
    void SaveToFile(const string& filename) {
        ofstream outFile(filename);
        if (!outFile.is_open()) {
            cout << "Error opening file!" << endl;
            return; 
        }
        outFile << x << " " << y << " " << z << endl;
        outFile.close();
    }

    void LoadFromFile(const string& filename) {
        ifstream inFile(filename);
        if (!inFile.is_open()) {
            cout << "Error opening file!" << endl;
            return;
        }
        inFile >> x >> y >> z;
        if (inFile.fail()) {
            cout << "Error reading data!" << endl;
            return;
        }
        inFile.close();
    }

};

const string FILE_NAME = "point_data.txt";

int main()
{
    Point p1;
    int choise;
    while (true) {
        cout << "-- Menu --" << endl;
        cout << "1. Load form file" << endl;
        cout << "2. Enter new point and save to file" << endl;
        cout << "0. Exit" << endl;

        cin >> choise;

        switch (choise) {
        case 1:
            p1.LoadFromFile(FILE_NAME);
            p1.PrintInfo();
            break;
        case 2:
            p1.InputData();
            p1.PrintInfo();
            p1.SaveToFile(FILE_NAME);
            break;
        case 0:
            return 0;
        default:
            break;
        }
        cout << endl;
    }
    
}