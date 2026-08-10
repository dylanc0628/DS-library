add_executable(
    vector_example
    vector_example.cpp
)

target_link_libraries(
    vector_example
    PRIVATE
        DS::DS
)