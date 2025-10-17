#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        
        if (numRows == 0) {
            return triangle;
        }
        
        // Primera fila siempre es [1]
        triangle.push_back({1});
        
        // Generar las filas restantes
        for (int i = 1; i < numRows; i++) {
            vector<int> row;
            vector<int> prevRow = triangle[i - 1];
            
            // Primer elemento siempre es 1
            row.push_back(1);
            
            // Elementos del medio: suma de los dos elementos de arriba
            for (int j = 1; j < i; j++) {
                row.push_back(prevRow[j - 1] + prevRow[j]);
            }
            
            // Último elemento siempre es 1
            row.push_back(1);
            
            triangle.push_back(row);
        }
        
        return triangle;
    }
};

int main() {
    Solution sol;
    int numRows;
    
    cout << "Ingrese el numero de filas del triangulo de Pascal: ";
    cin >> numRows;
    
    vector<vector<int>> result = sol.generate(numRows);
    
    // Imprimir en formato de array
    cout << "Output: [";
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j < result[i].size() - 1) {
                cout << ",";
            }
        }
        cout << "]";
        if (i < result.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;
    
    return 0;
}