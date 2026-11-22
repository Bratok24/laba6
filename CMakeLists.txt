cmake_minimum_required(VERSION 3.10)
project(VectorEditor_MVC)

set(CMAKE_CXX_STANDARD 17)

# Создаем исполняемый файл
add_executable(editor src/main.cpp)

# Указываем, где искать заголовочные файлы
target_include_directories(editor PRIVATE include)