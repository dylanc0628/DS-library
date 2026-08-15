#include <ds/vector.hpp>

int main() {

    //Default constructor initialization
    ds::Vector<int> arr;

    //Constructor w/ initializer list
    ds::Vector<int> nums{1,2,3};

    //Constructor w/ custom capacity
    ds::Vector<int> v(20);

    //Copy constructor initialization
    ds::Vector<int> nums2(nums);

    //Move constructor initialization
    ds::Vector<int> nums3(std::move(nums2));

    //Push back
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);

    for (std::size_t i{4}; i < 10; i++) {
        arr.push_back(i);
    }

    // arr = (1,2,3,4,5,6,7,8,9)

    //Empty
    v.empty(); //true
    arr.empty(); //false

    //Pop back
    int x = arr.pop_back(); //x = 9

    //Resize
    arr.resize(); //Capacity moves from 10 to 20
    arr.resize(15); //Capacity drops to 15

    //Size
    v.size(); //Returns 0

    //Capacity
    v.capacity(); //Returns 10

    //At and subscript
    arr.at(0); //Equals 1
    arr[1]; //Equals 1, just without bounds checking

    //Front, back
    arr.front(); //Returns 1
    arr.back(); //Returns 8

    //Begin, end
    arr.begin(); //Returns a pointer to the first element
    arr.end(); //Returns a pointer to the last element

    //Clear
    arr.clear(); //Reduces size to 0

    return 0;
}