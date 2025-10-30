# Ejercicio 2: Diagrama UML de Clases

## Descripción del Ejercicio
Este ejercicio consiste en crear un diagrama UML de las clases disponibles en la carpeta `EjemploClases` del repositorio del curso.

**Repositorio fuente:** [ALSE-2025-2-G1/EjemploClases](https://github.com/DanielPalominoS/ALSE-2025-2-G1/tree/main/EjemploClases)

## Archivos del Proyecto

- `diagrama_uml.puml` - Diagrama en formato PlantUML
- `diagrama_uml.md` - Diagrama en formato Mermaid (visualizable en GitHub)
- `README.md` - Este archivo

## Clases Analizadas

### 1. Jerarquía Shape3D (Formas 3D)
```
Shape3D (abstracta)
    └── Cube
```

**Shape3D** - Clase abstracta con métodos virtuales puros
- `getVolume()` - Calcula el volumen
- `getSurfaceArea()` - Calcula el área superficial

**Cube** - Representa un cubo
- Atributos: `length` (longitud del lado)
- Métodos: cálculo de volumen, área, getters/setters

### 2. Jerarquía Vehicle (Vehículos)
```
Vehicle
    ├── Car
    └── AirVehicle
```

**Vehicle** - Clase base para vehículos
- Atributos: `speed` (privado), `brand` (protegido)
- Métodos: getters/setters, display()

**Car** - Representa un automóvil
- Atributos adicionales: `numDoors`, `numWheels`
- Hereda de Vehicle

**AirVehicle** - Representa un vehículo aéreo
- Atributos adicionales: `altitude`, `isMultirotor`
- Hereda de Vehicle

### 3. Clase Independiente

**Complex** - Números complejos
- Atributos: `real`, `imag`, `nombre`
- Sobrecarga de operadores: +, -, *, /, =
- Métodos para operaciones con números complejos

## Relaciones Identificadas

- **Herencia**: Cube hereda de Shape3D
- **Herencia**: Car y AirVehicle heredan de Vehicle
- **Clase independiente**: Complex no tiene relaciones de herencia

## Herramientas Utilizadas

- PlantUML - Para diagramas en formato .puml
- Mermaid - Para visualización directa en GitHub