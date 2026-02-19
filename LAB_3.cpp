#include <iostream>
#include <cmath>

using namespace std;

template <typename Number>
bool IsPositive(Number x) {
    if (x < 0) return false;
    else return true;
}

void Task8(int x) { 
    if (x <= 0) cout << 2 * x; 
} 

void Task9(int x) {
    if (x < 0) x++; cout << x;
}

void Task10(int x) {
    if (x > 0) x++; else x += 2; 
    cout << x;
}

void Nullify(double x, double y, double z) {
    x = 0;
    y = 0;
    z = 0;
}
void Taks18(double x, double y, double z) {
    if (fmod(x, y) == 0) {
        if (fmod(y, z) == 0 ) {
            x++; y++; z++;
        } else Nullify(x, y, z);
    } else Nullify(x, y, z);
}

int Task19(int k, int l, int m) {
    int Sum, NegativeNumbers;
    if (IsPositive(k)) Sum += k*k; else cout << "k отрицательное число";
    if (IsPositive(l)) Sum += l*l; else cout << "l отрицательное число";
    if (IsPositive(m)) Sum += m*m; else cout << "m отрицательное число";
    return Sum;
}

void Taks20(int x1, int y1, int x2, int y2) {
    if (sqrt((x1*x1 + y1*y1)) < sqrt((x2*x2 + y2*y2))) cout << "Первая точка ближе" << endl ;
    if (sqrt((x1*x1 + y1*y1)) > sqrt((x2*x2 + y2*y2))) cout << "Вторая точка ближе" << endl ;
    if (sqrt((x1*x1 + y1*y1)) == sqrt((x2*x2 + y2*y2))) cout << "Обе точки одинаково близки" << endl ;
}

int Task28(int x) {
    if (x < 2) {
        return ((exp(1)*(sin(x)/2) + sin(pow(exp(1), x/4)))/x*x + 2);
    } else {
        return (2*x*x+(1/sqrt(3*x)));
    }
}

int Task29(int x) {
    if (x == 3) {
        cout << "no condition"; 
        return 0;
    }

    if ( x < -1) {
        return (sqrt((sin(x) + 1)) + log10(x*x));
    } else if ( x > 3) {
        return (pow(exp(1), -sin(x)) + sin(x));
    } else {
        return ((sin(x) + cos(x))/cos(x));
    }
}

int Task30(int x) {
    if (x < 1) {
        return (5 * sin(x) + cos(x));
    } else if ( x >= 4) {
        return (sqrt(x*x + 5) + log10(x));
    } else {
        return ((x*x - 2*x - 5)/pow(exp(1), x));
    }
}

int main() {
    short t;
    int x1, x2, x3, x4;
    setlocale(LC_ALL, "UTF-8");
    cout << "Choose task:" << endl
    << "8. Дано целое число x. Если x ≤ 0, найдите значение функции f (x) = 2·x." << endl 
    << "9. Дано целое число. Если это положительное число, добавьте к этому числу 1 и отобразите его. В противном случае отобразите само данное число." << endl 
    << "10. Дано целое число. Если это положительное число, добавьте к этому числу 1 и отобразите его. В противном случае вычтите 2 из заданного числа и отобразитеполученное значение." << endl
    << "18. Даны действительные числа x, y, z. Если x делится на y без остатка, а y делится на z без остатка, то прибавляйте 1 ко всем числам, в противном случае приравняйте все числа к нулю." << endl
    << "19. Даны целые числа k, l, m. Вычислите сумму квадратов положительных чисел. Если положительного числа нет, выведите информацию о нем." << endl
    << "20. На плоскости даны две точки N (x1,y1) и M(x2,y2). Создайте программу, определяющую, котора из них ближе всего к началу координат." << endl
    << "28. Вычислить значение функции у" << endl
    << "29. Вычислить значение функции у" << endl
    << "30. Вычислить значение функции у" << endl;

    cin >> t;
    
    switch (t)
    {
    case 8:
        cout << "Введите целое число x: ";
        cin >> x1; cout << endl;
        Task8(x1);
        break;
    case 9:
        cout << "Введите целое число x: ";
        cin >> x1; cout << endl;
        Task9(x1);
        break;
    case 10:
        cout << "Введите целое число x: ";
        cin >> x1; cout << endl;
        Task10(x1);
        break;
    case 18:
        cout << "Введите целое число x, y, z:" << endl;
        cin >> x1 >> x2 >> x3; cout << endl;
        Taks18(x1, x2, x3);
        break;
    case 19:
        cout << "Введите целое число k, l, m:" << endl;
        cin >> x1 >> x2 >> x3; cout << endl;
        Task19(x1, x2, x3);
        break;
    case 20:
        cout << "Введите дданый первой точки x1, y1:" << endl;
        cin >> x1 >> x2; cout << endl;
        cout << "Введите дданый первой точки x2, y2:" << endl;
        cin >> x3 >> x4; cout << endl;
        Taks20(x1, x2, x3, x4);
        break;
    case 28:
        cout << "Введите x: ";
        cin >> x1;
        Task28(x1);
        break;
    case 29:
        cout << "Введите x: ";
        cin >> x1;
        Task29(x1);
        break;
    case 30:
        cout << "Введите x: ";
        cin >> x1;
        Task30(x1);
        break;
    
    
    default:
        cout << "invalid task";
        break;
    }


    return 0;
}