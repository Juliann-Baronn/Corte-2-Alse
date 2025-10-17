#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }
            
            int profit = prices[i] - minPrice;
            
            if (profit > maxProfit) {
                maxProfit = profit;
            }
        }
        
        return maxProfit;
    }
};

int main() {
    Solution sol;
    int n;
    
    cout << "Ingrese la cantidad de dias: ";
    cin >> n;
    
    vector<int> prices(n);
    
    cout << "Ingrese los precios de cada dia:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Dia " << (i + 1) << ": ";
        cin >> prices[i];
    }
    
    int resultado = sol.maxProfit(prices);
    
    cout << "\nMaxima ganancia: " << resultado << endl;
    
    return 0;
}