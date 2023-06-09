cmake_minimum_required(VERSION 3.1.0)

project(Calculator VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_executable(Calculator
    logic/calculations.cc
    logic/credit_calculations.cc
    logic/parser.cc
    logic/validation.cc
    qcustomplot/qcustomplot.cc
    view/credit_window.cc
    view/graph_window.cc
    view/main_window.cc
    view/main.cc
    view/x_window.cc
    ui/credit_window.ui
    ui/graph_window.ui
    ui/main_window.ui
    ui/x_window.ui
    logic/calculations.h
    logic/credit_calculations.h
    logic/parser.h
    logic/validation.h
    logic/lexeme.h
    qcustomplot/qcustomplot.h
    view/credit_window.h
    view/graph_window.h
    view/main_window.h
    view/x_window.h
)

target_link_libraries(Calculator Qt6::Widgets Qt6::Core)