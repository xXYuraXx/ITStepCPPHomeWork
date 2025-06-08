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
        << setw(10) << b.price << " грн" << endl;
}

void PrintAllBooks(Book* books, int size) {
    if (size == 0) {
        cout << "Бібліотека пуста" << endl;
        return;
    }
    for (int i = 0; i < size; ++i) {
        PrintBook(books[i], i);
    }
}

void AddBook(Book*& books, int& size) {
    Book newBook;
    cout << "Назва: ";
    getline(cin, newBook.title);
    cout << "Автор: ";
    getline(cin, newBook.author);
    cout << "Видавництво: ";
    getline(cin, newBook.publisher);
    cout << "Жанр: ";
    getline(cin, newBook.genre);
    cout << "Рік видання: ";
    cin >> newBook.year;
    cout << "Ціна: ";
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
    cout << "Введіть індекс книги для редагування: ";
    int idx;
    cin >> idx;
    cin.ignore();
    if (idx < 1 || idx > size) {
        cout << "Невірний індекс!" << endl;
        return;
    }
    Book& b = books[idx - 1];

    cout << "Редагування книги: " << b.title << endl;
    cout << "Нова назва: ";
    getline(cin, b.title);
    cout << "Новий автор: ";
    getline(cin, b.author);
    cout << "Нове видавництво: ";
    getline(cin, b.publisher);
    cout << "Новий жанр: ";
    getline(cin, b.genre);
    cout << "Новий рік: ";
    cin >> b.year;
    cout << "Нова ціна: ";
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
        cout << "Помилка створення файлу";
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
        cout << "Файл не знайдено" << endl;
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
        {"Книга 1", "Автор 1", "Вид-во 1", "жанр 1", 2001, 100.0},
        {"12312", "Ім’я", "видав", "жанр", 2010, 89.99},
        {"назва", "автор", "видавництво", "тип", 2005, 75.5},
        {"праврпа", "ен", "лдло", "роман", 2012, 120.0},
        {"...", "...", "...", "...", 1999, 60.0},
        {"кнжка", "хтоcь", "ну ок", "не знаю", 2020, 133.3},
        {"_без_назви_", "ав", "публ", "не визначено", 2000, 50.0},
        {"1", "2", "3", "4", 2015, 44.44},
        {"", "", "", "", 0, 0.0},
        {"якась", "людина", "десь", "шось", 2023, 101.1}
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
        cout << "\n=== МЕНЮ ===" << endl;
        cout << "1.  Додати книгу" << endl;
        cout << "2.  Показати всі книги" << endl;
        cout << "3.  Редагувати книгу" << endl;
        cout << "4.  Пошук за автором" << endl;
        cout << "5.  Пошук за назвою" << endl;
        cout << "6.  Пошук за видавництвом" << endl;
        cout << "7.  Пошук за жанром" << endl;
        cout << "8.  Зберегти у файл" << endl;
        cout << "9.  Завантажити з файлу" << endl;
        cout << "10. ДОДАТИ ТЕСТОВІ 10 ЗАПИСІВ" << endl;
        cout << "0.  Вихід" << endl;
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
            cout << "Введіть автора: ";
            string val;
            getline(cin, val);
            SearchBooks(library, size, "author", val);
            break;
        }
        case 5: {
            cout << "Введіть назву: ";
            string val;
            getline(cin, val);
            SearchBooks(library, size, "title", val);
            break;
        }
        case 6: {
            cout << "Введіть видавництво: ";
            string val;
            getline(cin, val);
            SearchBooks(library, size, "publisher", val);
            break;
        }
        case 7: {
            cout << "Введіть жанр: ";
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
            cout << "Невірний вибір!" << endl;
        }
    }

    delete[] library;
    return 0;
}
