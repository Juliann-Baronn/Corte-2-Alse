# Diagrama UML - Clases de Ejemplo

## Descripción
Diagrama de clases basado en el repositorio [ALSE-2025-2-G1/EjemploClases](https://github.com/DanielPalominoS/ALSE-2025-2-G1/tree/main/EjemploClases)

## Diagrama
```mermaid
classDiagram
    %% Jerarquía Shape3D
    class Shape3D {
        <<abstract>>
        +getVolume() double
        +getSurfaceArea() double
        +~Shape3D()
    }
    
    class Cube {
        -double length
        +Cube(double len)
        +Cube()
        +getVolume() double
        +getSurfaceArea() double
        +setLength(double len) void
        +getLength() double
        +~Cube()
    }
    
    %% Jerarquía Vehicle
    class Vehicle {
        -int speed
        #string brand
        +Vehicle(string b, int s)
        +Vehicle(string b)
        +Vehicle(int s)
        +getSpeed() int
        +setSpeed(int s) void
        +setBrand(string b) void
        +getBrand() string
        +display() void
        +~Vehicle()
    }
    
    class Car {
        -int numDoors
        -int numWheels
        +Car(string b, int s, int doors, int wheels)
        +getNumDoors() int
        +setNumDoors(int doors) void
        +getNumWheels() int
        +setNumWheels(int wheels) void
        +display() void
        +~Car()
    }
    
    class AirVehicle {
        -int altitude
        -bool isMultirotor
        +AirVehicle(string b, int s, int alt)
        +display() void
    }
    
    %% Clase independiente Complex
    class Complex {
        -double real
        -double imag
        +string nombre
        +Complex()
        +Complex(double re, double im)
        +Complex(Complex other)
        +add(double a, double b) float
        +add(int a, int b) int
        +SetData() void
        +SetReal(double re) void
        +SetImag(double im) void
        +GetReal() double
        +GetImag() double
        +operator+(Complex other) Complex
        +operator-(Complex other) Complex
        +operator*(Complex other) Complex
        +operator/(Complex other) Complex
        +operator=(Complex other) Complex
        +display() void
    }
    
    %% Relaciones de herencia
    Shape3D <|-- Cube : hereda
    Vehicle <|-- Car : hereda
    Vehicle <|-- AirVehicle : hereda
```

## Clases identificadas

### Jerarquía Shape3D
- **Shape3D** (clase abstracta)
  - **Cube** (hereda de Shape3D)

### Jerarquía Vehicle
- **Vehicle** (clase base)
  - **Car** (hereda de Vehicle)
  - **AirVehicle** (hereda de Vehicle)

### Clase independiente
- **Complex** (números complejos con sobrecarga de operadores)
