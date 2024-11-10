# [![Typing SVG](https://readme-typing-svg.herokuapp.com?font=Fira+Code&duration=2500&pause=3&multiline=true&width=435&lines=Google+Test+C_plus_plus;%D0%90%D0%91%D1%81-323%3A;%D0%A0%D1%8F%D0%B7%D0%B0%D0%BD%D0%BE%D0%B2+%D0%92%D0%BB%D0%B0%D0%B4%D0%B8%D1%81%D0%BB%D0%B0%D0%B2;%D0%9F%D1%83%D1%88%D0%BA%D0%B0%D1%80%D0%B5%D0%B2+%D0%92%D0%B8%D1%82%D0%B0%D0%BB%D0%B8%D0%B9)](https://git.io/typing-svg)
## Установка библиотеки GTest, GMock

1. Клонируем официальный репозиторий в свой проект либо отдельную папку.

`git clone` https://github.com/google/googletest.git


2. Указываем путь к "локальным" заголовочным файлам:

#include "../googletest/googlemock/include/gmock/gmock.h"
#include "../googletest/googletest/include/gtest/gtest.h"

p.s. если не находит путь до библиотек, то перезапускаем пк.

### Установка Cmake

1. Устанавливаем Cmake 
<span style="color: red;">
    sudo snap install cmake
</span>
2. Для удобства можно использовать расширения Сmake и CMake Tools

Extension ID(CMake Tools): ms-vscode.cmake-tools 
Extension ID(CMake): twxs.cmake

### Создание СMakeLists.txt и компиляция

Для компиляции нужно использовать CMake.

1. Создаем СMakeLists.txt (в точности как написано).

В CMakeLists.txt вставляем следующее:

---------------------------------------------------------

cmake_minimum_required(VERSION 3.0)

project("gtest")

enable_testing()
add_subdirectory(lib/googletest)

Создаем исполняемый файл для test1.cpp

add_executable(test1_app test1.cpp)
target_link_libraries(test1_app gtest_main gmock_main)

Создаем исполняемый файл для test1.cpp

add_executable(test2_app test2.cpp)
target_link_libraries(test2_app gtest_main gmock_main)

Создаем исполняемый файл

add_executable(test_app main.cpp)
target_link_libraries(test_app gtest_main gmock_main)


---------------------------------------------------------

2. Создаем каталог для сборки и переходим в него:

sudo mkdir build
cd build


3. В этом каталоге запускаем команду:

sudo cmake ..

Две точки рядом с cmake означают, что нужно искать файл сценария CMakeLists.txt в родительском каталоге. Эта команда сгенерирует набор инструкций для компиляции и сборки библиотек gtest и gmock.

4. Далее компилируем с помощью команды:

sudo make

