#include <iostream>

using namespace std;

int main()
{

    int arr1[4][3];
    int count_no_zero = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 3; ++j) {
            arr1[i][j] = rand() % 2;
            cout << arr1[i][j] << " ";
            if (arr1[i][j] != 0) count_no_zero++;
        }
        cout << endl;
    }

    cout << endl;
    cout << "Count no zero: " << count_no_zero << endl;
    cout << endl;



    int arr2[3][3];
    int count_zero = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            arr2[i][j] = rand() % 2;
            cout << arr2[i][j] << " ";
            if (arr2[i][j] == 0) count_zero++;
        }
        cout << endl;
    }

    cout << endl;
    cout << "Count zero: " << count_zero << endl;
    cout << endl;



    int arr3[7][3];
    int count_module_less_12 = 0;
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 3; ++j) {
            arr3[i][j] = -20 + rand() % 40;
            cout << arr3[i][j] << " ";
            if (abs(arr3[i][j]) < 12) count_module_less_12++;
        }
        cout << endl;
    }

    cout << endl;
    cout << "Count module less 12: " << count_module_less_12 << endl;
    cout << endl;




    int arr4[4][5];
    int count_plus2 = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 5; ++j) {
            arr4[i][j] = -20 + rand() % 40;
            cout << arr4[i][j] << " ";
            if (arr4[i][j] > 0) count_plus2++;
        }
        cout << endl;
    }

    cout << endl;
    cout << "count_plus: " << count_plus2 << endl;
    cout << endl;




    double arr5[5][4];
    double mult_plus = 1;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 4; ++j) {
            arr5[i][j] = (double)(rand() % 100) / 10 - 5;
            cout << arr5[i][j] << " ";
            if (arr5[i][j] > 0) mult_plus *= arr5[i][j];
        }
        cout << endl;
    }

    cout << endl;
    cout << "mult_plus: " << mult_plus << endl;
    cout << endl;





    double arr6[5][4];
    double mult_minus = 1;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 4; ++j) {
            arr6[i][j] = (double)(rand() % 100)/10 - 5;
            cout << arr6[i][j] << " ";
            if (arr6[i][j] < 0) mult_minus *= arr6[i][j];
        }
        cout << endl;
    }

    cout << endl;
    cout << "mult_minus: " << mult_minus << endl;
    cout << endl;



    int arr7[4][4];
    int module6equal1 = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            arr7[i][j] = rand() % 100;
            arr7[0][0] = 7;
            cout << arr7[i][j] << " ";
            if (arr7[i][j] % 6 == 1) module6equal1++;
        }
        cout << endl;
    }
    

    cout << endl;
    cout << "module13equal1: " << module6equal1 << endl;
    cout << endl;



    int arr8[5][6];
    int min_el = INT_MAX;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 6; ++j) {
            arr8[i][j] = rand() % 200 - 100;
            cout << arr8[i][j] << " ";
            if (arr8[i][j] < min_el) min_el = arr8[i][j];
        }
        cout << endl;
    }


    cout << endl;
    cout << "min_el: " << min_el << endl;
    cout << endl;


    int arr9[5][6];
    int max_el = INT_MIN;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 6; ++j) {
            arr9[i][j] = rand() % 200 - 100;
            cout << arr9[i][j] << " ";
            if (arr9[i][j] > max_el) max_el = arr9[i][j];
        }
        cout << endl;
    }


    cout << endl;
    cout << "max_el: " << max_el << endl;
    cout << endl;


    double arr10[5][4];
    double sum_minus = 1;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 4; ++j) {
            arr10[i][j] = (double)(rand() % 100) / 10 - 5;
            cout << arr10[i][j] << " ";
            if (arr10[i][j] < 0) sum_minus += arr10[i][j];
        }
        cout << endl;
    }

    cout << endl;
    cout << "sum_minus: " << sum_minus << endl;
    cout << endl;
}