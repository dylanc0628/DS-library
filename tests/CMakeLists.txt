include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.15.3
    GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(Catch2)

add_executable(
    vector_tests
    vector_tests.cpp
)

target_link_libraries(
    vector_tests
    PRIVATE
        DS::DS  
        Catch2::Catch2WithMain 
)

include(CTest)
include(Catch)

catch_discover_tests(vector_tests)