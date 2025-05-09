#include <iostream>
#include <iomanip>

using namespace std;

int Get_num_len(int num) {
    int len = 0;
    while (num) {
        num /= 10;
        len++;
    }
    return len;
}

int* Get_matrix_max_len_of_cols(int** matrix, int n, int m) {
    int* cols_max_lens = new int[m];
    for (int i = 0; i < m; ++i) {
        int max_el = INT_MIN;
        for (int j = 0; j < n; ++j) {
            if (matrix[j][i] > max_el) max_el = matrix[j][i];
        }
        cols_max_lens[i] = Get_num_len(max_el);
    }
    return cols_max_lens;
}

void Print_matrix(int** matrix, int n, int m) {
    int* cols_max_lens = Get_matrix_max_len_of_cols(matrix, n, m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << setw(cols_max_lens[j]) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
int** Create_matrix(int n, int m) {
    int** matrix = new int* [n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[m];
    }
    return matrix;
}
int Get_rand_num(int randMax = 100, int randMin = 0) {
    return (rand() % (randMax + 1 - randMin)) + randMin;
}
void Fill_matrix(int** matrix, int n, int m, int randMax = 100, int randMin = 0) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matrix[i][j] = Get_rand_num(randMax, randMin);
        }
    }
}
int* Create_arr(int size) {
    int* arr = new int[size];
    return arr;
}
void Fill_arr(int* arr, int size, int randMax = 100, int randMin = 0) {
    for (int i = 0; i < size; ++i) {
        arr[i] = Get_rand_num(randMax, randMin);
    }
}

void Delete_matrix(int** matrix, int n, int m) {
    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void Remove_row_matrix_by_pos(int**& matrix, int& n, int m, int n_pos) {
    int** new_matrix = Create_matrix(n - 1, m);
    
    for (int i = 0; i < n_pos; ++i) {
        new_matrix[i] = matrix[i];
    }
    delete[] matrix[n_pos];
    for (int i = n_pos+1; i < n; ++i) {
        new_matrix[i-1] = matrix[i];
    }
    delete[] matrix;
    matrix = new_matrix;
    n--;
}
void Add_col_matrix_by_pos(int**& matrix, int n, int& m, int m_pos) {
    int** new_matrix = Create_matrix(n, m + 1);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m_pos; ++j) {
            new_matrix[i][j] = matrix[i][j];
        }
        new_matrix[i][m_pos] = Get_rand_num(200, 100);
        for (int j = m_pos; j < m; ++j) {
            new_matrix[i][j+1] = matrix[i][j];
        }
    }

    delete[] matrix;
    matrix = new_matrix;
    m++;
}
void Add_row_matrix_start(int**& matrix, int& n, int m) {
    int** new_matrix = Create_matrix(n + 1, m);
    new_matrix[0] = Create_arr(m);
    Fill_arr(new_matrix[0], m, 200, 100);
    for (int i = 0; i < n; ++i) {
        new_matrix[i + 1] = matrix[i];
    }
    delete[] matrix;
    matrix = new_matrix;
    n++;
}
void Remove_row_matrix_start(int**& matrix, int& n, int m) {
    Remove_row_matrix_by_pos(matrix, n, m, 0);
}
void Add_col_matrix_start(int**& matrix, int n, int &m) {
    Add_col_matrix_by_pos(matrix, n, m, 0);
}



int main()
{
    srand(time(0));
    int** matrix;
    int n, m;
    cout << "Enter size N for matrix: ";
    cin >> n;
    cout << "Enter size M for matrix: ";
    cin >> m;
    cout << endl;

    matrix = Create_matrix(n, m);
    Fill_matrix(matrix, n, m, 15);
    cout << "Start matrix" << endl;
    Print_matrix(matrix, n, m);
    cout << endl;

    cout << "Add row on start" << endl;
    Add_row_matrix_start(matrix, n, m);
    Print_matrix(matrix, n, m);
    cout << endl;

    cout << "Remove row from start" << endl;
    Remove_row_matrix_start(matrix, n, m);
    Print_matrix(matrix, n, m);
    cout << endl;

    cout << "Remove row by pos (idx: 1)" << endl;
    Remove_row_matrix_by_pos(matrix, n, m, 1);
    Print_matrix(matrix, n, m);
    cout << endl;

    cout << "Add col by pos (idx: 1)" << endl;
    Add_col_matrix_by_pos(matrix, n, m, 1);
    Print_matrix(matrix, n, m);
    cout << endl;

    cout << "Add col on start" << endl;
    Add_col_matrix_start(matrix, n, m);
    Print_matrix(matrix, n, m);




    
    Delete_matrix(matrix, n, m);
}