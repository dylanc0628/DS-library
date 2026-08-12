#include <ds/vector.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>

TEST_CASE("Vector construction", "[vector][constructor]") {

    SECTION("Basic constructor") {
        ds::Vector<int> arr;

        REQUIRE(arr.size() == 0);
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
}