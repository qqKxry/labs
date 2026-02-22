#include <iostream>

using namespace std;

void Task1Value(int A, int B) {
    int c;
    c = B;
    B = A; 
    A = c;

    cout << "A = " << A << endl;
    cout << "B = " << B << endl;
}

void Task1Adress(int* p1, int* p2) {
    int a, b, c;

    a = *p1;
    b = *p2;
    c = a;
    p1 = &b;
    p2 = &c;

    cout << "a = " << *p2 << endl;
    cout << "b = " << *p1 << endl;

}

void Task2(int *Arr, int Elements) {
    for (int i = 0; i < Elements; i++) {
        cout << *Arr << ' ';
        Arr++;
    }
}

void Task3(int Matrix[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << Matrix[i][j];
        }
        cout << endl;
    }
}

int Summ(int A, int B) {
    return A + B;
}

double Summ(double A, double B) {
    return A + B;
}

int Task4(int A, int B) {
    Summ(A, B);
    return 0;
}

int Factorial(int x) {
    if (x == 0) return 1;
    return x * Factorial(x - 1);
}

void Task5(int a) {
    static int CurrentValue = 0;
    CurrentValue = Factorial(a);
    cout << CurrentValue;
}

void Task6(int *Arr, int Elements, int Incremental) {
    int *p = Arr;
    for (int i = 0; i < Elements; i++) *(Arr++) = Incremental;
    for (int i = 0; i < Elements; i++) cout << p[i] << " ";
}

void SwapRows(int (&Matrix)[3][3], int row1, int row2) {

}

void Task7(int Matrix[3][3], int ReviewedRow, int PasteRow) {
    for (int j = 0; j < 3; j++) {
        int tArray = Matrix[ReviewedRow][j];
        Matrix[ReviewedRow][j] = Matrix[PasteRow][j];
        Matrix[PasteRow][j] = tArray;
    }

    Task3(Matrix);
}

void Task8(int Matrix[3][3], int Multiplayer) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Matrix[i][j] *= Multiplayer;
            cout << Matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

double ArrSum(double Arr[], int ArrSize) {
    double Sum = 0.0;
    for (int i = 0; i < ArrSize; i++) {
        Sum += Arr[i];
    }
    return Sum;
}

int ArrSum(int Arr[], int ArrSize) {
    int Sum = 0;
    for (int i = 0; i < ArrSize; i++) {
        Sum += Arr[i];
    }
    return Sum;
}

void TaskX();

int main() {
    setlocale(LC_ALL, ".UTF8");
    int x, a, b, q;
    int *p1, *p2;
    int Arr[4] = {0, 1, 2, 3};
    int *ArrPtr = &Arr[0];
    int Matrix[3][3] = { 
        {1, 2, 3},
        {2, 5, 4},
        {3, 7, 3}
    };

    cout << "Выберите задачу: " << endl 
    << "1.	Передача аргументов в функцию по ссылке и по значению." << endl 
    << "2.	Передача массива в функцию." << endl 
    << "3.	Передача матрицы в функцию." << endl 
    << "4.	Перегрузка функции для работы с различными типами данных." << endl 
    << "5.	Статические переменные в функции." << endl 
    << "6.	Использование ссылок для изменения значений в массиве." << endl 
    << "7.	Использование ссылок для работы с матрицей." << endl 
    << "8.	Передача матрицы по значению." << endl 
    << "9.	Перегрузка функции для работы с разными типами массивов." << endl 
    << "10.	Статическая переменная для подсчета вызовов функции." << endl;
    
    cin >> x;

    switch (x)
    {
    case 1: 
        cout << "Введите первое целое число: " << endl;
        cin >> a;
        cout << "Введите второе целое число: " << endl;
        cin >> b;
    
        p1 = &a;
        p2 = &b;

        Task1Value(a, b); 
        Task1Adress(p1, p2); 
    break;
    case 2: Task2(ArrPtr, sizeof(*ArrPtr)); break;
    case 3: Task3(Matrix); break;
    case 4: 
        cout << "Введите первое целое число: " << endl;
        cin >> a;
        cout << "Введите второе целое число: " << endl;
        cin >> b;

        Task4(a, b); 
    break;
    case 5: 
        cout << "Введите целое число: " << endl;
        cin >> a; 

        Task5(a);
    break;
    case 6: Task6(ArrPtr, sizeof(*ArrPtr), 2); break;
    case 7: Task7(Matrix, 2, 1); break;
    case 8: Task8(Matrix, 4); break;
    case 9: 
        q = ArrSum(Arr, sizeof(*ArrPtr)); 
        cout << q;
        break;
    case 10: TaskX(); break;
    
    default:
        cout << "Такой опции не существует." << endl;
        break;
    }

}

void TaskX() {
    static int Call = 0;
    Call++;
    cout << Call << endl;
    main();
}