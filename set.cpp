#include <iostream>
#include <vector>
#include <windows.h>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
using arr = vector<string>;
using prod = pair<string, string>;

pair<arr, arr> two_sets() {
    int set_A_length, set_B_length;

    cout << "Укажите количество элементов во множестве A:" << endl;
    cin >> set_A_length;
    cout << endl << "Укажите количество элементов во множестве B:" << endl;
    cin >> set_B_length;

    arr set_A(set_A_length), set_B(set_B_length);

    for (int i = 0; i < set_A_length; i++) {
        cout << "Введите " << i + 1 << " элемент множества A\r" << endl;
        cin >> set_A[i];
    }

    for (int i = 0; i < set_B_length; i++) {
        cout << "Введите " << i + 1 << " элемент множества B\r" << endl;
        cin >> set_B[i];
    }

    set_A.shrink_to_fit();
    set_B.shrink_to_fit();

    return make_pair(set_A, set_B);
}

arr single_set() {
    int set_A_length;

    cout << "Укажите количество элементов во множестве A:" << endl;
    cin >> set_A_length;

    arr set_A(set_A_length);

    for (int i = 0; i < set_A_length; i++) {
        cout << "Введите " << i + 1 << " элемент множества A\r" << endl;
        cin >> set_A[i];
    }

    set_A.shrink_to_fit();

    return set_A;
}

void remove_duplicate(vector<string>& arr) {

    int arr_length = arr.size();

    for (int i = 0; i < arr_length; i++) {
    
        for(int j = i + 1; j < arr_length; j++) {
            if (arr[j] == arr[i]) {
                
                for(int k = j; k < arr_length - 1; k++) {
                    arr[k] = arr[k + 1];
                }

                arr_length--;
                j--;
            }
        }
    
    }

    arr.resize(arr_length);
}

void join() {

    auto [set_A, set_B] = two_sets();

    arr result(0);

    for (auto&x : set_A) {
        result.push_back(x);
    }

    for (auto&x : set_B) {
        result.push_back(x);
    }

    remove_duplicate(result);

    result.shrink_to_fit();
    cout << "A ^ B = { ";
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << '}' << endl;
}

void intersection() {

    auto [set_A, set_B] = two_sets();

    arr result(0);

    for (int i = 0; i < set_A.size(); i++) {
        string element = set_A[i];

        for (int j = 0; j < set_B.size(); j++) {
            if (element == set_B[j]) {
                result.push_back(element);
            }
        }
    }

    remove_duplicate(result);

    cout << "A v B = { ";
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << '}' << endl;
}

void difference() {

    auto [set_A, set_B] = two_sets();

    for(int i = 0; i < set_A.size(); i++) {
        for(int j = 0; j < set_B.size(); j++) {
            if (set_A[i] == set_B[j]) {
                set_A.erase(set_A.begin() + i);
                i--;
            }
        }
    }

    remove_duplicate(set_A);

    cout << "A - B = { ";
    for(int i = 0; i < set_A.size(); i++) {
        cout << set_A[i] << " ";
    }
    cout << '}' << endl;
}

void symmetric_difference() {

    auto [set_A, set_B] = two_sets();

    arr result;

    for(int i = 0; i < set_A.size(); i++) {
        for(int j = 0; j < set_B.size(); j++) {
            if (set_A[i] == set_B[j]) {
                set_A.erase(set_A.begin() + i);
                set_B.erase(set_B.begin() + j);
                i--;
                j--;
            }
        }
    }

    for(auto&x : set_A) {
        result.push_back(x);
    }

    for(auto&x : set_B) {
        result.push_back(x);
    }

    remove_duplicate(result);

    cout << "A Δ B = { ";
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << '}' << endl;
}

void boolean() {
    arr set_A = single_set();

    remove_duplicate(set_A);

    cout << "P(A) = " << set_A.size() << endl;
}

void сartesian_product() {
    auto [set_A, set_B] = two_sets();

    vector<prod> result;

    for(auto&x : set_A) {
        for(int i = 0; i < set_B.size(); i++) {
            prod pair = {x, set_B[i]};
            result.push_back(pair);
        }
    }

    cout << "A × B = { ";
    for(int i = 0; i < result.size(); i++) {
        cout << '(' << result[i].first << ", " << result[i].second << ") ";
    }
    cout << '}' << endl;
}

int main() {
    SetConsoleOutputCP(65001);
    int option;

    cout << "Выберите операцию:\n1. Объеденение множеств\n2. Пересечение множества\n3. Разность множеств\n4. Симметрическая разность\n5. Булеан\n6. Декартово произведение\n";
    cin >> option; 

    switch (option)
    {
    case 1:
        join();
        break;
    case 2:
        intersection();
        break;
    case 3:
        difference();
        break;
    case 4:
        symmetric_difference();
        break;
    case 5:
        boolean();
        break;
    case 6:
        сartesian_product();
        break;
    
    
    default:
        cout << "Ошибка" << endl;
        break;
    }   
}