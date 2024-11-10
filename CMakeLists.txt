cmake_minimum_required(VERSION 3.0)

project("gtest")

# Включаем поддержку тестов
enable_testing()

# Добавляем подкаталог с GoogleTest
add_subdirectory(lib/googletest)

# Добавляем флаги для покрытия кода (GCov или Clang)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage")

# Создаем исполнимые файлы для тестов и связываем их с библиотеками GoogleTest и GoogleMock
add_executable(test1_app test1.cpp)
target_link_libraries(test1_app gtest_main gmock_main)

add_executable(test2_app test2.cpp)
target_link_libraries(test2_app gtest_main gmock_main)

add_executable(test3_app test3.cpp)
target_link_libraries(test3_app gtest_main gmock_main)

add_executable(test4_app test4.cpp)
target_link_libraries(test4_app gtest_main gmock_main)

# Добавляем тесты
add_test(NAME Test1 COMMAND test1_app)
add_test(NAME Test2 COMMAND test2_app)
add_test(NAME Test3 COMMAND test3_app)
add_test(NAME Test4 COMMAND test4_app)


# Настроим сбор данных покрытия
# Запуск CTest с параметрами для сбора покрытия
add_custom_target(
    coverage
    COMMAND ${CMAKE_CTEST_COMMAND} --coverage --output-on-failure
    DEPENDS test1_app test2_app test3_app test4_app
)

# Генерация отчета о покрытии с помощью lcov
add_custom_target(
    gen_coverage_report
    COMMAND lcov --capture --directory . --output-file coverage.info
    COMMAND genhtml coverage.info --output-directory out --ignore-errors mismatch
    DEPENDS coverage
    COMMENT "Generating coverage report"
)
