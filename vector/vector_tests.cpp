#include <iostream>
#include "vector.h"

using namespace std;

int main() {

    cout << "VECTOR TESTING" << endl;
    cout << "CONSTRUCTORS" << endl;
    Vector<int> arr{};
    cout << "Initialized vector 1" << endl;
    Vector<char> arr2{};
    cout << "Initialized vector 2" << endl;
    Vector<string> arr3{};
    cout << "Initialized vector 3" << endl;
    Vector<double> arr4{};
    cout << "Initialized vector 4" << endl << endl;

    cout << endl << "PUSH BACK" << endl;
    arr.push_back(10);
    arr.push_back(11);
    arr.push_back(12);
    cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
    cout << "Expected output: 10 11 12" << endl << endl;
    arr2.push_back('a');
    arr2.push_back('B');
    arr2.push_back('z');
    cout << arr2[0] << " " << arr2[1] << " " << arr2[2] << endl;
    cout << "Expected output: a B z" << endl << endl;

    return 0;
}