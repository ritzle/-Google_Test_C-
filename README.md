# [![Typing SVG](https://readme-typing-svg.herokuapp.com?font=Fira+Code&duration=2500&pause=3&multiline=true&width=435&lines=Google+Test+C_plus_plus)](https://git.io/typing-svg)  

## Установка библиотеки GTest, GMock
<hr style="border: 1px solid red;">
1. Клонируем официальный репозиторий в свой проект либо отдельную папку.

`git clone` https://github.com/google/googletest.git

2. Указываем путь к "локальным" заголовочным файлам:

#include "../googletest/googlemock/include/gmock/gmock.h"   
#include "../googletest/googletest/include/gtest/gtest.h"

p.s. если не находит путь до библиотек, то перезапускаем пк.    
p.s.s. если работаете с наши репозиторием, то библиотеку Google Test клонируйте в папку lib     

## Установка Cmake
<hr style="border: 1px solid red;">
1. Устанавливаем Cmake 

    sudo snap install cmake   

2. Для удобства можно использовать расширения Сmake и CMake Tools    

Extension ID(CMake Tools): ms-vscode.cmake-tools    
Extension ID(CMake): twxs.cmake

### Создание СMakeLists.txt и компиляция
<hr style="border: 1px solid red;">
Для компиляции нужно использовать CMake.

1. Создаем СMakeLists.txt (в точности как написано).

В CMakeLists.txt вставляем следующее:

---------------------------------------------------------
```cmake
cmake_minimum_required(VERSION 3.0)

project("gtest")

<p style="display: inline; color: blue; font-size: 24px;">&#5555;</p>Включаем поддержку тестов  

enable_testing()

 Добавляем подкаталог с GoogleTest  

add_subdirectory(lib/googletest)

 Добавляем флаги для покрытия кода (GCov или Clang)  

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage")

 Создаем исполнимые файлы для тестов и связываем их с библиотеками GoogleTest и GoogleMock  

add_executable(test1_app test1.cpp)
target_link_libraries(test1_app gtest_main gmock_main)

add_executable(test2_app test2.cpp)
target_link_libraries(test2_app gtest_main gmock_main)

add_executable(test3_app test3.cpp)
target_link_libraries(test3_app gtest_main gmock_main)

add_executable(test4_app test4.cpp)
target_link_libraries(test4_app gtest_main gmock_main)

 Добавляем тесты  

add_test(NAME Test1 COMMAND test1_app)
add_test(NAME Test2 COMMAND test2_app)
add_test(NAME Test3 COMMAND test3_app)
add_test(NAME Test4 COMMAND test4_app)


 Настроим сбор данных покрытия
 Запуск CTest с параметрами для сбора покрытия  

add_custom_target(
    coverage
    COMMAND ${CMAKE_CTEST_COMMAND} --coverage --output-on-failure
    DEPENDS test1_app test2_app test3_app test4_app
)

 Генерация отчета о покрытии с помощью lcov  

add_custom_target(
    gen_coverage_report
    COMMAND lcov --capture --directory . --output-file coverage.info
    COMMAND genhtml coverage.info --output-directory out --ignore-errors mismatch
    DEPENDS coverage
    COMMENT "Generating coverage report"
)
```

---------------------------------------------------------

2. Создаем каталог для сборки и переходим в него:

sudo mkdir build    
cd build


3. В этом каталоге запускаем команду:

sudo cmake ..

Две точки рядом с cmake означают, что нужно искать файл сценария CMakeLists.txt в родительском каталоге. Эта команда сгенерирует набор инструкций для компиляции и сборки библиотек gtest и gmock.

4. Далее компилируем с помощью команды:

sudo make


[![Typing SVG](https://readme-typing-svg.herokuapp.com?font=Fira+Code&pause=1000&color=F70202&background=E0FFA000&width=530&lines=%D0%90%D0%91%D1%81-323+%D0%9F%D1%83%D1%88%D0%BA%D0%B0%D1%80%D0%B5%D0%B2+%D0%92%D0%B8%D1%82%D0%B0%D0%BB%D0%B8%D0%B9%2C+%D0%A0%D1%8F%D0%B7%D0%B0%D0%BD%D0%BE%D0%B2+%D0%92%D0%BB%D0%B0%D0%B4%D0%B8%D1%81%D0%BB%D0%B0%D0%B2)](https://git.io/typing-svg)