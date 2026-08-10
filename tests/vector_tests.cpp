#include <ds/vector.hpp>
#include <cassert>

int main() {
    
    ds::Vector<int> num;

    assert(num.empty());

    num.push_back(10);
    num.push_back(20);

    assert(num.size() == 2);
    assert(num.at(0) == 10);
    assert(num.at(1) == 20);

    num.pop_back();
    assert(num.size() == 1);
    assert(num.at(0) == 10);

    num.clear();
    assert(num.empty());

    for (int i = 0; i < 15; i++) {
        num.push_back(i);
    }

    assert(num.capacity() == 20);
    assert(num.front() == 0);
    assert(num.back() == 14);

    return 0;
}