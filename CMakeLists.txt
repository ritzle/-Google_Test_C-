cmake_minimum_required(VERSION 3.0)


project("gtest")

enable_testing()
add_subdirectory(lib/googletest)


# Создаем исполнимый файл для test1.cpp
add_executable(test1_app test1.cpp)
target_link_libraries(test1_app gtest_main gmock_main)

# Создаем исполнимый файл для test2.cpp
add_executable(test_app main.cpp)
target_link_libraries(test_app gtest_main gmock_main)

