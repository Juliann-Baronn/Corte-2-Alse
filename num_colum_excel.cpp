#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        
        // Recorremos cada letra de izquierda a derecha
        for (int i = 0; i < columnTitle.length(); i++) {
            // Multiplicamos el resultado actual por 26 (base 26)
            result = result * 26;
            
            // Obtenemos el valor de la letra actual (A=1, B=2, ..., Z=26)
            int valorLetra = columnTitle[i] - 'A' + 1;
            
            // Sumamos el valor al resultado
            result += valorLetra;
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    string columnTitle;
    
    cout << "Ingrese el titulo de la columna (o 'salir' para terminar): ";
    
    while(cin >> columnTitle) {
        if(columnTitle == "salir") {
            break;
        }
        
        int resultado = sol.titleToNumber(columnTitle);
        cout << "Output: " << resultado << endl << endl;
        
        cout << "Ingrese el titulo de la columna (o 'salir' para terminar): ";
    }
    
    cout << "Programa finalizado." << endl;
    return 0;}
    