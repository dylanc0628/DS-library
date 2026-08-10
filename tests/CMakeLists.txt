add_executable(
    vector_tests
    vector_tests.cpp
)

target_link_libraries(
    vector_tests
    PRIVATE
        DS::DS   
)

add_test(
    NAME VectorTests
    COMMAND vector_tests
)