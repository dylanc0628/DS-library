#include <iostream>
using namespace std;

template <typename T>
class Vector {
    private:
    T arr{};

    public:
    Vector(T arr) {
        this->arr = arr;
    }

    void push_back(T x) {
        arr.append(x);
    }

    bool is_empty() {
        if (arr.size() > 0) {
            return False;
        }
        return True;
    }

    T pop() {
        if (!is_empty) {
            arr.pop_back();
        }
        else {
            cout << "Vector is empty" << endl;
        }
    }
};