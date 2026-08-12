#include <ds/vector.hpp>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Vectors can take data types", "[vector][push_back]") {
    
    SECTION("Integers") {
        ds::Vector<int> arr;

        arr.push_back(10);
        arr.push_back(20);
        arr.push_back(30);

        REQUIRE(arr[0] == 10);
        REQUIRE(arr[1] == 20);
        REQUIRE(arr[2] == 30);
    }

    SECTION("Doubles") {
        ds::Vector<double> arr;

        arr.push_back(2.5);
        arr.push_back(3.14);
        arr.push_back(60.2);

        REQUIRE(arr[0] == 2.5);
        REQUIRE(arr[1] == 3.14);
        REQUIRE(arr[2] == 60.2);
    }

    SECTION("Boolean") {
        
    }
}