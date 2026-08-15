#include <ds/vector.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <utility>

TEST_CASE("Vector construction", "[vector][constructor]") {

    SECTION("Basic constructor") {
        ds::Vector<int> arr;

        REQUIRE(arr.size() == 0);
    }

    SECTION("Constructor with a custom capacity") {
        ds::Vector<int> arr(50);

        REQUIRE(arr.empty() == true);
        REQUIRE(arr.capacity() == 50);
    }

    SECTION("Initialized vector") {
        ds::Vector<int> arr{1, 2, 3};

        REQUIRE(arr.size() == 3);
        REQUIRE(arr.at(0) == 1);
        REQUIRE(arr.at(1) == 2);
        REQUIRE(arr.at(2) == 3);
    }

    SECTION("Copy constructor") {
        ds::Vector<int> arr1{1, 2, 3};

        ds::Vector<int> arr2(arr1);

        REQUIRE(arr1.size() == 3);
        REQUIRE(arr1.at(0) == 1);
        REQUIRE(arr1.at(1) == 2);
        REQUIRE(arr1.at(2) == 3);

        REQUIRE(arr2.size() == 3);
        REQUIRE(arr2.at(0) == arr1.at(0));
        REQUIRE(arr2.at(1) == arr1.at(1));
        REQUIRE(arr2.at(2) == arr1.at(2));
    }

    SECTION("Move constructor") {
        ds::Vector<int> arr1{1, 2, 3};

        ds::Vector<int>arr2(std::move(arr1));

        REQUIRE(arr1.empty() == true);
        REQUIRE(arr2.size() == 3);
        REQUIRE(arr2.at(0) == 1);
        REQUIRE(arr2.at(1) == 2);
        REQUIRE(arr2.at(2) == 3);
    }
}

TEST_CASE("Vectors can take data types", "[vector][push_back]") {
    
    SECTION("Integers") {
        ds::Vector<int> arr;

        arr.push_back(10);
        arr.push_back(20);
        arr.push_back(30);
        arr.push_back(0);
        arr.push_back(-50);

        REQUIRE(arr.size() == 5);
        REQUIRE(arr.at(0) == 10);
        REQUIRE(arr.at(1) == 20);
        REQUIRE(arr.at(2) == 30);
        REQUIRE(arr.at(3) == 0);
        REQUIRE(arr.at(4) == -50);
    }

    SECTION("Floats") {
        ds::Vector<float> arr;

        REQUIRE(arr.size() == 0);

        arr.push_back(3.14f);
        arr.push_back(5.5f);
        arr.push_back(100.001f);

        REQUIRE(arr.size() == 3);
        REQUIRE(arr.at(0) == 3.14f);
        REQUIRE(arr.at(1) == 5.5f);
        REQUIRE(arr.at(2) == 100.001f);
    }

    SECTION("Doubles") {
        ds::Vector<double> arr;

        REQUIRE(arr.size() == 0);

        arr.push_back(2.5);
        arr.push_back(3.14);
        arr.push_back(60.2);

        REQUIRE(arr.size() == 3);
        REQUIRE(arr.at(0) == 2.5);
        REQUIRE(arr.at(1) == 3.14);
        REQUIRE(arr.at(2) == 60.2);
    }

    SECTION("Boolean") {
        ds::Vector<bool> arr;

        REQUIRE(arr.size() == 0);

        arr.push_back(true);
        arr.push_back(true);
        arr.push_back(false);
        arr.push_back(false);

        REQUIRE(arr.size() == 4);
        REQUIRE(arr.at(0) == true);
        REQUIRE(arr.at(1) == true);
        REQUIRE(arr.at(2) == false);
        REQUIRE(arr.at(3) == false);
    }

    SECTION("Characters") {
        ds::Vector<char> arr;

        REQUIRE(arr.size() == 0);

        arr.push_back('a');
        arr.push_back('d');
        arr.push_back('2');

        REQUIRE(arr.size() == 3);
        REQUIRE(arr.at(0) == 'a');
        REQUIRE(arr.at(1) == 'd');
        REQUIRE(arr.at(2) == '2');
    }

    SECTION("Strings") {
        ds::Vector<std::string> arr;

        REQUIRE(arr.size() == 0);

        arr.push_back("abc");
        arr.push_back("xyz");
        arr.push_back("123");

        REQUIRE(arr.size() == 3);
        REQUIRE(arr.at(0) == "abc");
        REQUIRE(arr.at(1) == "xyz");
        REQUIRE(arr.at(2) == "123");
    }

    SECTION("Size_t") {
        ds::Vector<std::size_t> arr;

        REQUIRE(arr.size() == 0);

        arr.push_back(0);
        arr.push_back(1000);
        arr.push_back(500000);

        REQUIRE(arr.size() == 3);
        REQUIRE(arr.at(0) == 0);
        REQUIRE(arr.at(1) == 1000);
        REQUIRE(arr.at(2) == 500000);
    }

    SECTION("User defined objects") {
        struct Test {
            int value;
        };

        ds::Vector<Test> arr{{10}, {20}};

        REQUIRE(arr.size() == 2);
        REQUIRE(arr.at(0).value == 10);
        REQUIRE(arr.at(1).value == 20);
    }
}

TEST_CASE("Vectors returning elements", "[vector][pop_back]") {
    ds::Vector<int> arr{1, 2, 3};

    int x = arr.pop_back();
    REQUIRE(x == 3);
    x = arr.pop_back();
    REQUIRE(x == 2);
    x = arr.pop_back();
    REQUIRE(x == 1);
    REQUIRE(arr.empty() == true);
    REQUIRE_THROWS_AS(arr.pop_back(), std::out_of_range);
        
}

TEST_CASE("Vectors resizing", "[vector][resize]") {

    SECTION("Resize with an empty vector") {
        ds::Vector<int> arr;

        REQUIRE(arr.capacity() == 10);

        for (std::size_t i = 0; i < 15; i++) {
            arr.push_back(i);
        }

        REQUIRE(arr.capacity() == 20);
        REQUIRE_THROWS_AS(arr.resize(5), std::length_error);
    }

    SECTION("Resize with a vector with a custom capacity") {
        ds::Vector<int> arr(12);

        REQUIRE(arr.capacity() == 12);

        for (std::size_t i = 0; i < 15; i++) {
            arr.push_back(i);
        }

        REQUIRE(arr.capacity() == 24);
        REQUIRE_THROWS_AS(arr.resize(2), std::length_error);
    }
}

TEST_CASE("Beginning and ending iterators", "[vector][iterators]") {

    SECTION("Beginning iterator") {
        ds::Vector<int> arr{1,2,3};

        auto x = arr.begin();
        REQUIRE(*x == 1);
        x++;
        REQUIRE(*x == 2);
        x++;
        REQUIRE(*x == 3);
        x++;
        REQUIRE(x == arr.end());
    }

    SECTION("Ending iterator") {
        ds::Vector<int> arr{1,2,3};
        
        auto x = arr.end();
        x--;
        REQUIRE(*x == 3);
        x--;
        REQUIRE(*x == 2);
        x--;
        REQUIRE(x == arr.begin());
    }

    SECTION("For each loop") {
        ds::Vector<int> arr{1,2,3};

        auto it = arr.begin();

        for(int val : arr) {
            REQUIRE(*it == val);
            it++;
        }
    }
}

TEST_CASE("Clearing a vector", "[vector][clear]") {

    ds::Vector<int> arr{1,2,3};

    REQUIRE(arr.empty() == false);
    arr.clear();
    REQUIRE(arr.empty() == true);
}

TEST_CASE("Front and back functions", "[vector][front and back]") {

    ds::Vector<int> arr{1, 2, 3};

    REQUIRE(arr.front() == 1);
    REQUIRE(arr.back() == 3);
    REQUIRE((arr.front() + 1) == (arr.back() - 1));
}

TEST_CASE("At throws exception", "[vector][at]") {
    ds::Vector<int> arr{1,2,3};

    REQUIRE(arr.at(1) == 2);
    REQUIRE_THROWS_AS(arr.at(5), std::out_of_range);
}