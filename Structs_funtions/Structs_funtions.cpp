#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <iomanip>

using namespace std;

struct Book {
    string title;
    string author;
    string publisher;
    string genre;
    int year;
    double price;
};


void PrintBook(const Book& b, int index) {
    cout << setw(3) << index + 1 << "."
        << setw(15) << b.title << " | "
        << setw(15) << b.author << " | "
        << setw(15) << b.publisher << " | "
        << setw(15) << b.genre << " | "
        << setw(4) << b.year << " | "
        << setw(10) << b.price << " ���" << endl;
}

void PrintAllBooks(Book* books, int size) {
    if (size == 0) {
        cout << "��������� �����" << endl;
        return;
    }
    for (int i = 0; i < size; ++i) {
        PrintBook(books[i], i);
    }
}

void AddBook(Book*& books, int& size) {
    Book newBook;
    cout << "�����: ";
    getline(cin, newBook.title);
    cout << "�����: ";
    getline(cin, newBook.author);
    cout << "�����������: ";
    getline(cin, newBook.publisher);
    cout << "����: ";
    getline(cin, newBook.genre);
    cout << "г� �������: ";
    cin >> newBook.year;
    cout << "ֳ��: ";
    cin >> newBook.price;
    cin.ignore();

    Book* newArr = new Book[size + 1];
    for (int i = 0; i < size; ++i)
        newArr[i] = books[i];

    newArr[size] = newBook;

    delete[] books;
    books = newArr;
    size++;
}

void ChangeData(Book* books, int size) {
    PrintAllBooks(books, size);
    cout << "������ ������ ����� ��� �����������: ";
    int idx;
    cin >> idx;
    cin.ignore();
    if (idx < 1 || idx > size) {
        cout << "������� ������!" << endl;
        return;
    }
    Book& b = books[idx - 1];

    cout << "����������� �����: " << b.title << endl;
    cout << "���� �����: ";
    getline(cin, b.title);
    cout << "����� �����: ";
    getline(cin, b.author);
    cout << "���� �����������: ";
    getline(cin, b.publisher);
    cout << "����� ����: ";
    getline(cin, b.genre);
    cout << "����� ��: ";
    cin >> b.year;
    cout << "���� ����: ";
    cin >> b.price;
    cin.ignore();
}


void SearchBooks(Book* books, int size, const string& field, const string& value) {
    for (int i = 0; i < size; ++i) {
        Book& book = books[i];
        if ((field == "author" && book.author == value) ||
            (field == "title" && book.title == value) ||
            (field == "publisher" && book.publisher == value) ||
            (field == "genre" && book.genre == value)) {
            PrintBook(book, i);
        }
    }
}

void SaveToFile(Book* books, int size, const string& file_name) {
    ofstream fout(file_name);
    if (!fout) {
        cout << "������� ��������� �����";
        return;
    }

    fout << size << endl;
    for (int i = 0; i < size; ++i) {
        Book& b = books[i];
        fout << b.title << "\n" << b.author << "\n" << b.publisher << "\n"
            << b.genre << "\n" << b.year << "\n" << b.price << "\n";
    }

    fout.close();
}

void LoadFromFile(Book*& books, int& size, const string& filename) {
    ifstream fin(filename);
    if (!fin) {
        cout << "���� �� ��������" << endl;
        return;
    }

    int newSize;
    fin >> newSize;
    fin.ignore();

    Book* newArr = new Book[newSize];
    for (int i = 0; i < newSize; ++i) {
        getline(fin, newArr[i].title);
        getline(fin, newArr[i].author);
        getline(fin, newArr[i].publisher);
        getline(fin, newArr[i].genre);
        fin >> newArr[i].year;
        fin >> newArr[i].price;
        fin.ignore();
    }

    delete[] books;
    books = newArr;
    size = newSize;
}

void AddTestData(Book*& books, int& size) {
    const int testCount = 10;
    Book testBooks[testCount] = {
        {"����� 1", "����� 1", "���-�� 1", "���� 1", 2001, 100.0},
        {"12312", "���", "�����", "����", 2010, 89.99},
        {"�����", "�����", "�����������", "���", 2005, 75.5},
        {"�������", "��", "����", "�����", 2012, 120.0},
        {"...", "...", "...", "...", 1999, 60.0},
        {"�����", "���c�", "�� ��", "�� ����", 2020, 133.3},
        {"_���_�����_", "��", "����", "�� ���������", 2000, 50.0},
        {"1", "2", "3", "4", 2015, 44.44},
        {"", "", "", "", 0, 0.0},
        {"�����", "������", "����", "����", 2023, 101.1}
    };

    Book* newArr = new Book[size + testCount];
    for (int i = 0; i < size; ++i)
        newArr[i] = books[i];
    for (int i = 0; i < testCount; ++i)
        newArr[size + i] = testBooks[i];

    delete[] books;
    books = newArr;
    size += testCount;
}



int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Book* library = nullptr;
    int size = 0;
    string filename = "library.txt";

    while (true) {
        cout << "\n=== ���� ===" << endl;
        cout << "1.  ������ �����" << endl;
        cout << "2.  �������� �� �����" << endl;
        cout << "3.  ���������� �����" << endl;
        cout << "4.  ����� �� �������" << endl;
        cout << "5.  ����� �� ������" << endl;
        cout << "6.  ����� �� ������������" << endl;
        cout << "7.  ����� �� ������" << endl;
        cout << "8.  �������� � ����" << endl;
        cout << "9.  ����������� � �����" << endl;
        cout << "10. ������ �����² 10 ����Ѳ�" << endl;
        cout << "0.  �����" << endl;
        cout << ">> ";

        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 0:
            return 0;
        case 1:
            AddBook(library, size);
            break;
        case 2:
            PrintAllBooks(library, size);
            break;
        case 3:
            ChangeData(library, size);
            break;
        case 4: {
            cout << "������ ������: ";
            string val;
            getline(cin, val);
            SearchBooks(library, size, "author", val);
            break;
        }
        case 5: {
            cout << "������ �����: ";
            string val;
            getline(cin, val);
            SearchBooks(library, size, "title", val);
            break;
        }
        case 6: {
            cout << "������ �����������: ";
            string val;
            getline(cin, val);
            SearchBooks(library, size, "publisher", val);
            break;
        }
        case 7: {
            cout << "������ ����: ";
            string val;
            getline(cin, val);
            SearchBooks(library, size, "genre", val);
            break;
        }
        case 8:
            SaveToFile(library, size, filename);
            break;
        case 9:
            LoadFromFile(library, size, filename);
            break;
        case 10:
            AddTestData(library, size);
            break;
        default:
            cout << "������� ����!" << endl;
        }
    }

    delete[] library;
    return 0;
}
