#include <iostream>
#include <vector>
#include <locale>
#include <string>
#include <cmath>

using namespace std;
void Task1(vector<vector<int>>& Matrix) {
    vector<int> columnSums(Matrix[0].size(), 0);
    int totalSum = 0;
    for (int i = 0; i < Matrix.size(); i++) {

        int RowSum = 0;

        for (int j = 0; j < Matrix[0].size(); j++) {
            RowSum += Matrix[i][j];
            columnSums[j] += Matrix[i][j];
        }

        Matrix[i].push_back(RowSum);
        totalSum += RowSum;
    }
    columnSums.push_back(totalSum);

    Matrix.push_back(columnSums);
}

void Task2(vector<vector<int>>& Matrix) {
    int order;
    cout << "Выберите порядок:" << endl << "1. По возрастани." << endl << "2. По убыванию" << endl;
}

int FindLongest(const vector<vector<int>>& Matrix) {
    int MaxSize = 1;
    for (int y = 0; y < Matrix.size(); y++) {
        for (int x = 0; x < Matrix[y].size(); x++) {
            int len = to_string(Matrix[y][x]).size();
            if (MaxSize < len) MaxSize = len;
        }
    }
    return MaxSize;
}

void DrawTable(int MatrixRows, int MatrixColumns, vector<vector<int>>& Matrix) {

    int MaxSize = FindLongest(Matrix);

    string Lt;
    for (int i = 0; i < MaxSize + 2; i++) 
        Lt += "─";

    cout << "┌";
    for (int i = 0; i < MatrixColumns; i++) {
        cout << Lt;
        if (i < MatrixColumns - 1) cout << "┬";
    }
    cout << "┐\n";

    for (int i = 0; i < MatrixRows; i++) {

        cout << "│";

        for (int j = 0; j < MatrixColumns; j++) {

            string value = to_string(Matrix[i][j]);
            int len = value.size();
            int leftPad  = (MaxSize - len) / 2;
            int rightPad = MaxSize - len - leftPad;

            cout << " " << string(leftPad, ' ') << value << string(rightPad, ' ') << " │";
        }

        cout << endl;

        if (i == MatrixRows - 1) break;

        cout << "├";
        for (int j = 0; j < MatrixColumns; j++) {
            cout << Lt;
            if (j < MatrixColumns - 1) cout << "┼";
        }
        cout << "┤\n";
    }
    cout << "└";
    for (int i = 0; i < MatrixColumns; i++) {
        cout << Lt;
        if (i < MatrixColumns - 1) cout << "┴";
    }
    cout << "┘\n";
}

int main() {
    setlocale(LC_ALL, ".UTF8");
    int MatrixRows, MatrixColumns;

    cout << "Matrix columns: "; cin >> MatrixColumns;
    if (MatrixColumns <= 0) { cout << "Columns cannot be lower or equal to zero"; return 0; } // Проверка на кол-во столбцов
    else if (MatrixColumns > 5) { cout << "Its too much columns"; return 0; }

    cout << "Matrix rows: "; cin >> MatrixRows;
    if (MatrixRows <= 0) { cout << "Rows cannot be lower or equal to zero"; return 0; } // Проверка на кол-во строк
    else if (MatrixRows > 5) { cout << "Its too much rows"; return 0; }

    vector<vector<int>> Matrix(MatrixRows, vector<int>(MatrixColumns, 0));

    DrawTable(MatrixRows, MatrixColumns, Matrix);

    for (int y = 0; y < MatrixRows; y++) {
        for (int x = 0; x < MatrixColumns; x++) {
            cout << "\nEnter x" << x+1 << " y" << y+1 << ": ";
            cin >> Matrix[y][x];
            cout << "\033[H\033[J";
            DrawTable(MatrixRows, MatrixColumns, Matrix);
        }
    }

    cout << endl << "Выберите задачу:" << endl 
    << "1.	Суммирование элементов матрицы по строкам и столбцам" << endl 
    << "2.	Сортировка строк матрицы" << endl 
    << "3.	Сортировка столбцов матрицы" << endl 
    << "4.	Перестановка строк матрицы" << endl 
    << "5.	Перестановка столбцов матрицы" << endl 
    << "6.	Поиск минимального элемента в каждой строке" << endl 
    << "7.	Поиск максимального элемента в каждом столбце" << endl 
    << "8.	Сумма главной диагонали матрицы" << endl 
    << "9.	Сумма побочной диагонали матрицы" << endl 
    << "10.	Транспонирование матрицы" << endl;

    int q;
    cin >> q;

    switch (q)
    {
    case 1:
        Task1(Matrix);
        DrawTable(MatrixRows+1, MatrixColumns+1, Matrix);
        break;
    
    default:
        break;
    }

    return 0;   
}


//  ┬ ─ ┘┐┌└