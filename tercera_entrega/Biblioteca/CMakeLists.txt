
cmake_minimum_required(VERSION 3.10)
project(Biblioteca)

# Especificar el estándar de C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Incluir el directorio de headers
include_directories(include)

# Agregar los archivos fuente
add_executable(biblioteca
    src/main.cpp
    src/Libro.cpp
    src/Biblioteca.cpp
)

# Opcional: Configurar flags de compilación
if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
endif()
