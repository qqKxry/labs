#include <iostream>
#include <vector>
#include <locale>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstdlib>

using namespace std;

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

    DrawTable(Matrix.size(), Matrix[0].size(), Matrix);
}

void Task2(vector<vector<int>>& Matrix) {
    int MatrixRows = Matrix.size();
    int MatrixColumns = Matrix[0].size();
    int order;
    cout << "Выберите порядок:" << endl << "1. По возрастани." << endl << "2. По убыванию" << endl;

    cin >> order;

    if (order == 1) {
        for (int i = 0; i < MatrixRows; i++) {
            for (int j = 0; j < Matrix[i].size(); j++) {
                sort(Matrix[i].begin(), Matrix[i].end());
            }
        }
        DrawTable(MatrixRows, MatrixColumns, Matrix);
    } else if ( order == 2 ) {
        for (int i = 0; i < MatrixRows; i++) {
            for (int j = 0; j < Matrix[i].size(); j++) {
                sort(Matrix[i].begin(), Matrix[i].end());

                reverse(Matrix[i].begin(), Matrix[i].end());
            }
        }
        DrawTable(MatrixRows, MatrixColumns, Matrix);
    } else {
        cout << "Такой опции не существует." << endl;
    }
}

void Task3(vector<vector<int>>& Matrix) {
    int MatrixRows = Matrix.size();
    int MatrixColumns = Matrix[0].size();
    int order;
    vector<int> tArray;
    cout << "Выберите порядок:" << endl << "1. По возрастани." << endl << "2. По убыванию" << endl;

    cin >> order;

    if (order == 1) {
        for (int i = 0; i < MatrixColumns; i++) {
            for (auto&x : Matrix) {
                tArray.push_back(x[i]); 
            }

            sort(tArray.begin(), tArray.end());

            for (int j = 0; j < MatrixColumns; j++) {
                Matrix[j][i] = tArray[j];
            }
            
            tArray.clear();
        }

        DrawTable(MatrixRows, MatrixColumns, Matrix);

    } else if ( order == 2 ) {
        for (int i = 0; i < MatrixColumns; i++) {
            for (auto&x : Matrix) {
                tArray.push_back(x[i]); 
            }

            for (auto x : tArray) cout << x << ' ';
            cout << endl;

            sort(tArray.begin(), tArray.end());
            reverse(tArray.begin(), tArray.end());
            
            for (int j = 0; j < MatrixColumns; j++) {
                Matrix[j][i] = tArray[j];
            }
            
            tArray.clear();
        }

        DrawTable(MatrixRows, MatrixColumns, Matrix);

    } else {
        cout << "Такой опции не существует." << endl;
    }
}

int Task4(vector<vector<int>>& Matrix) {
    int MatrixRows = Matrix.size();
    int MatrixColumns = Matrix[0].size();
    int reviewed, place;
    cout << "Выберите обозреваемую строку:" << endl;
    cin >> reviewed;

    if (reviewed > MatrixRows) {
        cout << "Такой строки не существует." << endl;
        return 0;
    } if (reviewed < 0) {
        cout << "Номер строки не может быть отрицательным или равным нулю." << endl;
        return 0;
    }

    cout << "Выберите строку для перестановки:" << endl;
    cin >> place;

    if (place > MatrixRows) {
        cout << "Такой строки не существует." << endl;
        return 0;
    } if (place < 0) {
        cout << "Номер строки не может быть отрицательным или равным нулю." << endl;
        return 0;
    }

    Matrix.at(reviewed - 1).swap(Matrix.at(place - 1));
    DrawTable(MatrixRows, MatrixColumns, Matrix);

    return 0;
}

int Task5(vector<vector<int>>& Matrix) {
    int MatrixRows = Matrix.size();
    int MatrixColumns = Matrix[0].size();

    vector<int> tArray1, tArray2;
    int reviewed, place;
    cout << "Выберите обозреваемый столбец:" << endl;
    cin >> reviewed;

    if (reviewed > MatrixRows) {
        cout << "Такого столбца не существует." << endl;
        return 0;
    } if (reviewed < 0) {
        cout << "Номер столбца не может быть отрицательным или равным нулю." << endl;
        return 0;
    }

    cout << "Выберите столбец для перестановки:" << endl;
    cin >> place;

    if (place > MatrixRows) {
        cout << "Такого столбца не существует." << endl;
        return 0;
    } if (place < 0) {
        cout << "Номер столбца не может быть отрицательным или равным нулю." << endl;
        return 0;
    }

    for (int i = 0; i < MatrixRows; i++) {
        tArray1.push_back(Matrix[i][reviewed-1]);
        tArray2.push_back(Matrix[i][place-1]);
    }

    for (int i = 0; i < MatrixRows; i++) {
        Matrix[i][reviewed-1] = tArray2[i];
        Matrix[i][place-1] = tArray1[i];
    }

    DrawTable(MatrixRows, MatrixColumns, Matrix);

    return 0;
}

void Task6(vector<vector<int>>& Matrix) {
    int MatrixRows = Matrix.size();
    int MatrixColumns = Matrix[0].size();
    vector<int> Minimums;

    for (auto& Row : Matrix) {
        sort(Row.begin(), Row.end());
        Minimums.push_back(Row[0]);
    }

    for (int i = 0; i < Minimums.size(); i++) {
        cout << "Минимальный элемент для " << i + 1 << " строки: " << Minimums[i] << endl;
    }
}

void Task7(vector<vector<int>>& Matrix) {
    int MatrixRows = Matrix.size();
    int MatrixColumns = Matrix[0].size();
    vector<int> Maximus;

    for (int i = 0; i < MatrixRows; i++) {
        for (int j = 0; j < MatrixColumns; j++) Maximus.push_back(Matrix[i][j]);

        sort(Maximus.begin(), Maximus.end());

        cout << "Максимальный элемент для " << i + 1 << " столбца: " << Maximus[MatrixColumns - 1] << endl;

        Maximus.clear();
    }
}

void Task8(vector<vector<int>>& Matrix) {
    int MatrixRows = Matrix.size();
    int MatrixColumns = Matrix[0].size();
    int Diagonal = 0;

    for (int s = 0; s < MatrixColumns; s++) {
        for (int a = 0; a < MatrixColumns; a++) {
            for (int b = 0; b < MatrixRows; b++) {
                if (a == b) { 
                    Diagonal += Matrix[b][a]; 
                }
            }
        }
    }
    cout << "Сумма элементов главного диагонали = " << Diagonal << endl;
}

void Task9(vector<vector<int>>& Matrix) {
    int MatrixRows = Matrix.size();
    int MatrixColumns = Matrix[0].size();
    int Diagonal = 0;

    for (int a = 0; a < MatrixColumns; a++) {
        for (int b = 0; b < MatrixRows; b++) {
            if (a + b == MatrixColumns - 1) { 
                Diagonal += Matrix[b][a]; 
            }
        }
    }

    cout << "Сумма элементов побочной диагонали = " << Diagonal << endl;
}

void TaskX(vector<vector<int>>& Matrix) {
    int MatrixRows = Matrix.size();
    int MatrixColumns = Matrix[0].size();

    vector<vector<int>> NewMatrix(MatrixRows, vector<int>(MatrixColumns, 0));
    vector<int> tArray;

    for (int i = 0; i < MatrixRows; i++) {
        for (int j = 0; j < MatrixColumns; j++) {
            tArray.push_back(Matrix[j][i]);
        }
        NewMatrix[i] = tArray;
        tArray.clear();
    }

    DrawTable(MatrixRows, MatrixColumns, NewMatrix);
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
            system("cls");
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
    case 1: Task1(Matrix); break;
    case 2: Task2(Matrix); break;
    case 3: Task3(Matrix); break;
    case 4: Task4(Matrix); break;
    case 5: Task5(Matrix); break;
    case 6: Task6(Matrix); break;
    case 7: Task7(Matrix); break;
    case 8: Task8(Matrix); break;
    case 9: Task9(Matrix); break;
    case 10: TaskX(Matrix); break;
    default:
        break;
    }

    return 0;

    int l;
    cin >> l;
}


//  ┬ ─ ┘┐┌└