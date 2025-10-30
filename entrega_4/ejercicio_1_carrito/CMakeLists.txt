cmake_minimum_required(VERSION 3.10)
project(CarritoCompras)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_executable(carrito
    src/main.cpp
    src/Producto.cpp
    src/ItemCarrito.cpp
    src/CarritoCompras.cpp
    src/Usuario.cpp
)

# Habilitar warnings
if(MSVC)
    target_compile_options(carrito PRIVATE /W4)
else()
    target_compile_options(carrito PRIVATE -Wall -Wextra -pedantic)
endif()
