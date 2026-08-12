#include <ds/vector.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>

TEST_CASE("Vectors can take data types", "[vector][push_back]") {
    
    SECTION("Integers") {
        ds::Vector<int> arr;

        REQUIRE(arr.size() == 0);

        arr.push_back(10);
        arr.push_back(20);
        arr.push_back(30);

        REQUIRE(arr.size() == 3);
        REQUIRE(arr[0] == 10);
        REQUIRE(arr[1] == 20);
        REQUIRE(arr[2] == 30);
    }

    SECTION("Floats") {
        ds::Vector<float> arr;

        REQUIRE(arr.size() == 0);

        arr.push_back(3.14f);
        arr.push_back(5.5f);
        arr.push_back(100.001f);

        REQUIRE(arr.size() == 3);
        REQUIRE(arr[0] == 3.14f);
        REQUIRE(arr[1] == 5.5f);
        REQUIRE(arr[2] == 100.001f);
    }

    SECTION("Doubles") {
        ds::Vector<double> arr;

        REQUIRE(arr.size() == 0);

        arr.push_back(2.5);
        arr.push_back(3.14);
        arr.push_back(60.2);

        REQUIRE(arr.size() == 3);
        REQUIRE(arr[0] == 2.5);
        REQUIRE(arr[1] == 3.14);
        REQUIRE(arr[2] == 60.2);
    }

    SECTION("Boolean") {
        ds::Vector<bool> arr;

        REQUIRE(arr.size() == 0);

        arr.push_back(true);
        arr.push_back(true);
        arr.push_back(false);
        arr.push_back(false);

        REQUIRE(arr.size() == 4);
        REQUIRE(arr[0] == true);
        REQUIRE(arr[1] == true);
        REQUIRE(arr[2] == false);
        REQUIRE(arr[3] == false);
    }

    SECTION("Characters") {
        ds::Vector<char> arr;

        arr.push_back('a');
        arr.push_back('d');
        arr.push_back('2');

        REQUIRE(arr[0] == 'a');
        REQUIRE(arr[1] == 'd');
        REQUIRE(arr[2] == '2');
    }

    SECTION("Strings") {
        ds::Vector<std::string> arr;

        arr.push_back("abc");
        arr.push_back("xyz");
        arr.push_back("123");

        REQUIRE(arr[0] == "abc");
        REQUIRE(arr[1] == "xyz");
        REQUIRE(arr[2] == "123");
    }
}