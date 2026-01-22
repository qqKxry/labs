#include <iostream>
#include <math.h>

using namespace std;

template <typename T1>
void First(T1 lenght) {
    cout << "Square's lenght is " << lenght * lenght << endl;
}


template <typename FirstNumber, typename SecondNumber>
void Second(FirstNumber a, SecondNumber b) {
    cout << "Sum: " << a + b << endl;
    cout << "Product: " << a * b << endl;
    cout << "Substraction: " << a - b << endl;
}

template <typename Lenght, typename Base>
void Third(Lenght l, Base b) {
    cout << "Triangle's area is " << (l * b) / 2 << endl;
}

template <typename FirstRib, typename SecondRib, typename Angle>
void Fourth(FirstRib a, SecondRib b, Angle c) {
    double d = c * 3.14 / 180.0;
    cout << "Triangle's area is " << fabs(((a * b) / 2) * sin(d));
}

template <typename Meters>
void Fifth(Meters a) {
    cout << a << " meters is " << a/(1066.8) << " kilometers";
}


void Sixth(double a, double c, double b) {
    cout << "your income after " << b << " days will be " << a * (c / 100) * (b / 365) << '$';
}

void Seventh(double a) {
    cout << a << " is " << a / 1 << " coins and " << fmod(a, 1) * 100 << " tenge";
}

int main() {
    cout << "Choose task:" << endl << "1. (#1)" << endl << "2. (#4)" << endl << "3. (#28)" << endl << "4. (#29)" << endl << "5. (#31)" << endl << "6. (#33)" << endl << "7. (#35)" << endl;

    int option;

    cin >> option;

    switch (option)
    {
    case 1:
        double rib;
        cout << "Enter square rib lenght: "; cin >> rib;
        First(rib);
        break;
    case 2:
        double FirstNumber, SecondNumber;
        cout << "Enter first number: "; cin >> FirstNumber;
        cout << "Enter second number: "; cin >> SecondNumber;
        Second(FirstNumber, SecondNumber);
        break;
    case 3:
        double Lenght, Base;
        cout << "Enter lenght: "; cin >> Lenght;
        cout << "Enter base: "; cin >> Base;
        Third(Lenght, Base);
        break;
    case 4:
        double FirstRibLenght, SecondRibLenght;
        int Angle;
        cout << "Enter first rib's lenght: "; cin >> FirstRibLenght;
        cout << "Enter second rib's lenght: "; cin >> SecondRibLenght;
        cout << "Enter angle: "; cin >> Angle;
        Fourth(FirstRibLenght, SecondRibLenght, Angle);
        break;
    case 5:
        int Meters;
        cout << "Enter meters:"; cin >> Meters;
        Fifth(Meters);
        break;
    case 6:
        double Deposit, Days, Rate;
        cout << "Enter deposit: "; cin >> Deposit;
        cout << "Enter days: "; cin >> Days;
        cout << "Enter rate: "; cin >> Rate;
        Sixth(Deposit, Days, Rate);
        break;
    case 7:
        double Number;
        cout << "Enter number that you wanna transform: ";
        cin >> Number;
        Seventh(Number);
        break;
    
    default:
        cout << "invalid option";
        break;
    }
    cin >> option;
    return 0;
}