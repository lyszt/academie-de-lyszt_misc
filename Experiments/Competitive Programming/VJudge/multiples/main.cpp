#include <bits/stdc++.h>
using namespace std;

int main(){ 
    int a,b;
    cin >> a >> b;
    // What is the mathematical definition of a multiple?
    if(a % b == 0 || b % a == 0) {
        cout << "Multiples" << "\n";
        return 0;
    }
    cout << "No Multiples" << "\n";
}