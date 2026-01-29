
#include <iostream>
#include <cmath>
#include <thread>

using namespace std;

int main() {
    int a, x, y, z; 
    cout << "Select option: " << endl << "1. " << endl << "2. " << endl << "3. " << endl << "4. " << endl;
    cin >> a;
    cout << "Enter 'x': "; cin >> x; cout << endl;
    cout << "Enter 'y': "; cin >> y; cout << endl;
    cout << "Enter 'z': "; cin >> z; cout << endl;

    switch (a)
    {
    case 1:
        cout << "a = " << (sqrt(fabs(x - 1)) - pow(fabs(y), 1/3)) / (1 + (pow(x, 2) / 2) + (pow(y, 2) / 4)) << endl;
        cout << "b = " << x * (atan(z) + exp(1) - (x + 3)) << endl;
        break;

    case 2:
        cout << "a = " << (3 + pow(exp(1), y-1)) / (1 + pow(x, 2) * fabs(y - tan(z))) << endl;
        cout << "b = " << (1 + fabs(y - x) + (pow((y - x), 3))/2 + (fabs(pow((y - x), 3)))/3) << endl;
        break;

    case 3:
        cout << "a = " << (1 + y) * ((x + (y/(pow(x,2) + 4)))/(pow(exp(1), (-x-2) + (1/(pow(x,2) + 4))))) << endl;
        cout << "b = " << (1 + cos(y - 2))/(pow(x,4)/(2 + pow(sin(z), 2))) << endl;
        break;

    case 4:
        cout << "a = " << y + (x/(pow(y,3) + fabs(x/(y+(pow(x,3)/3))))) << endl;
        cout << "b = " << 1 + (pow(tan(z/2), 2)) << endl;
        break;
    
    default:
        cout << "invalid option";
        break;
    }

    this_thread::sleep_for(chrono::seconds(4));

    return 0;
}
